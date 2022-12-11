cmake_policy(SET CMP0048 NEW)  # project_VERSION* variables populated from project(... VERSION x.x.x) string
project(Libxc
  LANGUAGES C)
set(Libxc_AUTHORS      "Miguel A.L. Marques and others")
set(Libxc_DESCRIPTION  "Exchange-correlation functionals for density-functional theory")
set(Libxc_EMAIL        "libxc@tddft.org")
set(Libxc_URL          "http://www.tddft.org/programs/Libxc")
set(Libxc_LICENSE      "Mozilla Public License, version 2.0 (MPL-2.0)")

cmake_minimum_required(VERSION 3.1)
set(CMAKE_C_STANDARD 99)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

if(ENABLE_CUDA)
  cmake_minimum_required(VERSION 3.8)
  set(CMAKE_VERBOSE_MAKEFILE ON)
  enable_language(CUDA)
  set(CMAKE_CUDA_STANDARD 98)
  if(POLICY CMP0104)
    cmake_policy(SET CMP0104 OLD)
  endif()
endif()

################################### Options ####################################
include(psi4OptionsTools)
option_with_default(CMAKE_BUILD_TYPE "Build type" Release)
option_with_print(BUILD_SHARED_LIBS "Build final library as shared, not static. For Windows, also add CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS=ON" OFF)
option_with_print(BUILD_TESTING "Compile the testing infrastructure" ON)
option_with_default(BUILD_FPIC "Libraries will be compiled with position independent code" ON)
if((${BUILD_SHARED_LIBS}) AND NOT ${BUILD_FPIC})
  message(FATAL_ERROR "BUILD_SHARED_LIBS ON and BUILD_FPIC OFF are incompatible, as shared library requires position independent code")
endif()
option_with_default(NAMESPACE_INSTALL_INCLUDEDIR "Location within CMAKE_INSTALL_INCLUDEDIR to which headers are installed (e.g., /libxc)" /)
option_with_print(ENABLE_GENERIC "Enable mostly static linking in shared library" OFF)
option_with_print(ENABLE_FORTRAN "Build Fortran 2003 interface" OFF)
option_with_print(ENABLE_PYTHON "Install Python API interface" OFF)
if(${ENABLE_PYTHON} AND NOT ${BUILD_SHARED_LIBS})
  message(FATAL_ERROR "ENABLE_PYTHON ON requires BUILD_SHARED_LIBS ON because only shared libraries can be dynamically loaded")
endif()
include(xhost)  # defines: option(ENABLE_XHOST "Enable processor-specific optimization" ON)
option_with_print(DISABLE_VXC "Don't compile first derivative code" OFF)
option_with_print(DISABLE_FXC "Don't compile second derivative code" OFF)
option_with_print(DISABLE_KXC "Don't compile third derivative code" ON)
option_with_print(DISABLE_LXC "Don't compile fourth derivative code" ON)
option_with_print(DISABLE_FHC "Disable enforcement of Fermi hole curvature?" OFF)

######################### Process & Validate Options ###########################
include(autocmake_safeguards)
include(custom_static_library)

################################# Main Project #################################
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(PN ${PROJECT_NAME})

# Need BASH to run test suite
find_program(BASH_EXECUTABLE bash)

# link -lm only if necessary
find_package(StandardMathLibraryC)
# check if cbrt exists and declare HAVE_CBRT if it does
check_c_source_compiles (
  "#include <math.h>
int main() {
  return (int)(cbrt(0.8));
}" HAVE_CBRT)
if (HAVE_CBRT)
  add_definitions (-DHAVE_CBRT)
endif (HAVE_CBRT)

# Turn off derivative code
if(DISABLE_VXC)
  add_definitions (-DXC_DONT_COMPILE_VXC)
  add_definitions (-DXC_DONT_COMPILE_FXC)
  add_definitions (-DXC_DONT_COMPILE_KXC)
  add_definitions (-DXC_DONT_COMPILE_LXC)
endif(DISABLE_VXC)
if(DISABLE_FXC)
  add_definitions (-DXC_DONT_COMPILE_FXC)
  add_definitions (-DXC_DONT_COMPILE_KXC)
  add_definitions (-DXC_DONT_COMPILE_LXC)
endif(DISABLE_FXC)
if(DISABLE_KXC)
  add_definitions (-DXC_DONT_COMPILE_KXC)
  add_definitions (-DXC_DONT_COMPILE_LXC)
endif(DISABLE_KXC)
if(DISABLE_LXC)
  add_definitions (-DXC_DONT_COMPILE_LXC)
endif(DISABLE_LXC)
if(NOT DISABLE_FHC)
  add_definitions (-DXC_ENFORCE_FERMI_HOLE_CURVATURE)
endif(NOT DISABLE_FHC)

# <<<  Build  >>>

# extract project version from source
file(STRINGS "configure.ac" _libxc_configure_ac
     REGEX "AC_INIT")
foreach(ver ${_libxc_configure_ac})
    if (ver MATCHES "^AC_INIT..libxc...([0-9]+).([0-9]+).([0-9]+).*$")
        set(PROJECT_VERSION_MAJOR ${CMAKE_MATCH_1})
        set(PROJECT_VERSION_MINOR ${CMAKE_MATCH_2})
        set(PROJECT_VERSION_MICRO ${CMAKE_MATCH_3})
    endif()
endforeach()

set(PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_MICRO})
message(STATUS "Version: Full ${PROJECT_VERSION}")

# repurpose xc_version from Make for CMake
set(VERSION ${PROJECT_VERSION})
set(XC_MAJOR_VERSION ${PROJECT_VERSION_MAJOR})
set(XC_MINOR_VERSION ${PROJECT_VERSION_MINOR})
set(XC_MICRO_VERSION ${PROJECT_VERSION_MICRO})
configure_file(xc_version.h.in xc_version.h @ONLY)

# create dummy config.h
configure_file(config.h.cmake.in config.h @ONLY)

# special substitutions for pkgconfig files
include(JoinPaths)
join_paths(libdir_for_pc_file "\${exec_prefix}" "${CMAKE_INSTALL_LIBDIR}")
join_paths(includedir_for_pc_file "\${prefix}" "${CMAKE_INSTALL_INCLUDEDIR}")
configure_file(cmake/libxc.pc.in libxc.pc @ONLY)

# extract project soversion from source
file(STRINGS "configure.ac" _libxc_configure_ac
  REGEX "XC_(CURRENT|REVISION|AGE)=")
foreach(ver ${_libxc_configure_ac})
  if (ver MATCHES "XC_(CURRENT|REVISION|AGE)=+([^ ]+)$")
    set(XC_${CMAKE_MATCH_1} "${CMAKE_MATCH_2}" CACHE INTERNAL "")
  endif()
endforeach()
set(${PROJECT_NAME}_SOVERSION ${XC_CURRENT}:${XC_REVISION}:${XC_AGE})
math(EXPR ${PROJECT_NAME}_SOMAJOR "${XC_CURRENT} - ${XC_AGE}")
message(STATUS "SO Version: Full ${${PROJECT_NAME}_SOVERSION} Major ${${PROJECT_NAME}_SOMAJOR}")

set(raw_sources_list
  bessel.c
  expint_e1.c
  faddeeva.c
  func_info.c
  func_reference.c
  integrate.c
  mix_func.c
  deorbitalize_func.c
  references.c
  special_functions.c
  math_brent.c
  util.c
  version.c
  )

set(src_prefix "src/")
string(REGEX REPLACE "([^;]+)" "${src_prefix}\\1" sources_list "${raw_sources_list}")

set(SOURCES)
add_subdirectory(src/functionals)
list(APPEND sources_list ${SOURCES})


if(ENABLE_CUDA)
  set_source_files_properties(${sources_list} PROPERTIES LANGUAGE CUDA)
endif()

set(raw_sources_list_f90
  src/libxc_master.F90
  )

# when headers namespaced, xc_version include in xc.h needs to be local, not
#   system to be found
file(READ ${src_prefix}xc.h _src_contents)
string(REPLACE "<xc_version.h>" "\"xc_version.h\"" _quoted_src "${_src_contents}")
file(WRITE ${PROJECT_BINARY_DIR}/${src_prefix}xc.h "${_quoted_src}")

# provide basic installed rpath, so Fortran lib can find C lib
if (APPLE)
    set(base "@loader_path")
else()
    set(base "$ORIGIN")
endif()
file(RELATIVE_PATH relDir ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}
                          ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_INSTALL_RPATH ${base} ${base}/${relDir})

# STATIC/SHARED on below governed by BUILD_SHARED_LIBS
add_library(xc ${sources_list})
set_target_properties(xc PROPERTIES CUDA_SEPARABLE_COMPILATION ON)
target_link_libraries(xc INTERFACE ${STANDARD_MATH_LIBRARY})
set_target_properties(xc PROPERTIES POSITION_INDEPENDENT_CODE ${BUILD_FPIC}
  SOVERSION ${${PROJECT_NAME}_SOMAJOR})
if(${BUILD_SHARED_LIBS})
  target_link_libraries(xc PRIVATE ${LIBC_INTERJECT})
  if(APPLE)
    set_target_properties(xc PROPERTIES LINK_FLAGS "-undefined dynamic_lookup")
  endif()
endif()

if(ENABLE_FORTRAN)
  enable_language(Fortran)
  add_library(xcf03 ${raw_sources_list_f90})
  target_link_libraries(xcf03 xc)
  set_target_properties(xcf03 PROPERTIES POSITION_INDEPENDENT_CODE ${BUILD_FPIC}
    SOVERSION ${${PROJECT_NAME}_SOMAJOR})
endif()

add_executable(xc-info "${src_prefix}/xc-info.c")
if(ENABLE_CUDA)
  set_source_files_properties("${src_prefix}/xc-info.c" PROPERTIES LANGUAGE CUDA)
endif()
target_link_libraries(xc-info xc)

add_executable(xc-threshold "${src_prefix}/xc-threshold.c")
if(ENABLE_CUDA)
  set_source_files_properties("${src_prefix}/xc-threshold.c" PROPERTIES LANGUAGE CUDA)
endif()
target_link_libraries(xc-threshold xc)


include_directories(${PROJECT_SOURCE_DIR}/${src_prefix}  # for util.h
  ${PROJECT_BINARY_DIR}/${src_prefix}  # for xc.h
  ${PROJECT_BINARY_DIR}  # for xc_version.h, config.h
)

if(BUILD_TESTING)
  find_program(BZip2_EXECUTABLE
    NAMES bzip2
    DOC "Path to zipping utility")
  if(BZip2_EXECUTABLE)
    enable_testing ()
    add_subdirectory(testsuite)  
  else()
    message(FATAL_ERROR "Install `bzip2` command to enable tests")
  endif()
endif()

# <<<  Install  >>>

# by default, headers NOT namespace protected
install(FILES ${PROJECT_BINARY_DIR}/${src_prefix}/xc.h
  ${PROJECT_SOURCE_DIR}/${src_prefix}/xc_funcs.h
  ${PROJECT_SOURCE_DIR}/${src_prefix}/xc_funcs_worker.h
  ${PROJECT_SOURCE_DIR}/${src_prefix}/xc_funcs_removed.h
  ${PROJECT_BINARY_DIR}/xc_version.h
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}${NAMESPACE_INSTALL_INCLUDEDIR})
install(TARGETS xc-info
  OPTIONAL
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(TARGETS xc
  EXPORT c_interface
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

if(ENABLE_FORTRAN)
  configure_file(cmake/libxcf03.pc.in libxcf03.pc @ONLY)
  install(TARGETS xc xcf03
    EXPORT f_interface
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
  install(FILES "${PROJECT_BINARY_DIR}/xc_f03_lib_m.mod"
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}${NAMESPACE_INSTALL_INCLUDEDIR})
  if(NOT MSVC)
    install(FILES ${PROJECT_BINARY_DIR}/libxcf03.pc
      DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig/)
  endif()
endif()

# <<<  Export Interface  >>>

target_compile_definitions(xc INTERFACE USING_${PN})
target_include_directories(xc INTERFACE
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# <<<  Export Config  >>>

set(CMAKECONFIG_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/${PN}")
configure_package_config_file(cmake/${PN}Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/${PN}Config.cmake"
  INSTALL_DESTINATION ${CMAKECONFIG_INSTALL_DIR})
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/${PN}ConfigVersion.cmake
  VERSION ${${PN}_VERSION}
  COMPATIBILITY SameMajorVersion)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PN}Config.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/${PN}ConfigVersion.cmake
  DESTINATION ${CMAKECONFIG_INSTALL_DIR})
install(EXPORT c_interface
  NAMESPACE "${PN}::"
  FILE "${PN}Targets-C.cmake"
  DESTINATION ${CMAKECONFIG_INSTALL_DIR})

if(ENABLE_FORTRAN)
    install(EXPORT f_interface
      NAMESPACE "${PN}::"
      FILE "${PN}Targets-Fortran.cmake"
      DESTINATION ${CMAKECONFIG_INSTALL_DIR})
endif()

if(ENABLE_PYTHON)
  set(SOURCE_PYTHON_API
    pylibxc/__init__.py
    pylibxc/core.py
    pylibxc/flags.py
    pylibxc/functional.py
    pylibxc/structs.py
    pylibxc/util.py
    pylibxc/version.py
  )
  install(
    FILES ${SOURCE_PYTHON_API}
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pylibxc
  )
  if(UNIX)
    install(CODE "execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink \
      ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/libxc.so.${${PROJECT_NAME}_SOMAJOR} \
      ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/pylibxc/libxc.so)")
  endif()
endif()

export(EXPORT c_interface
    NAMESPACE "${PN}::"
    FILE "${PROJECT_BINARY_DIR}/${PN}Targets.cmake")

if(NOT MSVC)
  install(FILES ${PROJECT_BINARY_DIR}/libxc.pc
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig/)
endif()
