if (CMAKE_HOST_WIN32)
    cmake_minimum_required(VERSION 3.13)  # create_symlink for windows
else()
    cmake_minimum_required(VERSION 3.8)
endif()
cmake_policy(SET CMP0079 NEW)

project(pylibxc LANGUAGES NONE)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../cmake)

################################### Options ####################################
include(psi4OptionsTools)
option_with_default(PYLIBXC_INSTALL_PYMODDIR "Location within CMAKE_INSTALL_PREFIX to which the Python module is installed. Empty string queries Python interpreter. Don't start with '/'" prefix)

################################# Main Project #################################

#  <<<  Build  >>>

if (PYLIBXC_INSTALL_PYMODDIR STREQUAL "prefix")

    if (NOT TARGET Python::Module)
        find_package(Python COMPONENTS Interpreter Development REQUIRED)
    endif()

    # Note that this block is *Linux-style* install to `CMAKE_INSTALL_PREFIX` not *Python-style* install to `Python_EXECUTABLE`'s site-packages.

    execute_process(
      COMMAND ${Python_EXECUTABLE} -c
        "import os, sys, sysconfig as s; spdir = s.get_path('platlib'); print(spdir.replace(os.path.commonpath([sys.prefix, spdir]), '').lstrip(os.path.sep));"
      OUTPUT_VARIABLE PYLIBXC_INSTALL_PYMODDIR
      OUTPUT_STRIP_TRAILING_WHITESPACE
      )
endif()
message(STATUS "Showing option PYLIBXC_INSTALL_PYMODDIR: ${PYLIBXC_INSTALL_PYMODDIR}")

if(TARGET xc)
    get_target_property(_loc xc LOCATION)
else()
    find_package(Libxc REQUIRED COMPONENTS C shared)
    get_target_property(_loc Libxc::xc LOCATION)
endif()

message("_loc ${_loc}")

#  <<<  Install  >>>

install(
  FILES
    __init__.py
    core.py
    flags.py
    functional.py
    structs.py
    util.py
    version.py
  COMPONENT Libxc_Python
  DESTINATION ${PYLIBXC_INSTALL_PYMODDIR}/pylibxc
  )

if (UNIX)
  install(CODE
    "execute_process(COMMAND ${CMAKE_COMMAND} -v -E create_symlink ${_loc} \
       ${CMAKE_INSTALL_PREFIX}/${PYLIBXC_INSTALL_PYMODDIR}/pylibxc/libxc.so)")
endif()

