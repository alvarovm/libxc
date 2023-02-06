# Handle LIBXC_MAX_DERIV, DISABLE_VXC, DISABLE_FXC, DISABLE_KXC, DISABLE_LXC

if ((DEFINED DISABLE_VXC) OR (DEFINED DISABLE_FXC) OR (DEFINED DISABLE_KXC) OR (DEFINED DISABLE_LXC))
    message(WARNING "Using DISABLE_VXC/DISABLE_FXC/DISABLE_KXC/DISABLE_LXC instead of LIBXC_MAX_DERIV is deprecated could be removed as soon as v1.8")
    if ((DEFINED DISABLE_LXC) AND (NOT DISABLE_LXC))
        set(_deriv "4")
    elseif ((DEFINED DISABLE_KXC) AND (NOT DISABLE_KXC))
        set(_deriv "3")
    elseif ((DEFINED DISABLE_FXC) AND (NOT DISABLE_FXC))
        set(_deriv "2")
    elseif ((DEFINED DISABLE_VXC) AND (NOT DISABLE_VXC))
        set(_deriv "1")
    endif()
else()
    if ((LIBXC_MAX_DERIV STREQUAL "0") OR
        (LIBXC_MAX_DERIV STREQUAL "1") OR
        (LIBXC_MAX_DERIV STREQUAL "2") OR
        (LIBXC_MAX_DERIV STREQUAL "3") OR
        (LIBXC_MAX_DERIV STREQUAL "4e") OR
        (LIBXC_MAX_DERIV STREQUAL "4E") OR
        (LIBXC_MAX_DERIV STREQUAL "4"))
          string(TOLOWER "${LIBXC_MAX_DERIV}" _deriv)
    else()
        message(FATAL_ERROR "Invalid value for LIBXC_MAX_DERIV (${LIBXC_MAX_DERIV})")
    endif()
endif()

set(LIBXC_MAX_DERIV "${_deriv}")

if (LIBXC_MAX_DERIV STREQUAL "0")
    set(Libxc_DERIV_COMPONENTS "xc_d0")
elseif (LIBXC_MAX_DERIV STREQUAL "1")
    set(Libxc_DERIV_COMPONENTS "xc_d0;xc_d1")
elseif (LIBXC_MAX_DERIV STREQUAL "2")
    set(Libxc_DERIV_COMPONENTS "xc_d0;xc_d1;xc_d2")
elseif (LIBXC_MAX_DERIV STREQUAL "3")
    set(Libxc_DERIV_COMPONENTS "xc_d0;xc_d1;xc_d2;xc_d3")
elseif ((LIBXC_MAX_DERIV STREQUAL "4e") OR (LIBXC_MAX_DERIV STREQUAL "4"))
    set(Libxc_DERIV_COMPONENTS "xc_d0;xc_d1;xc_d2;xc_d3;xc_d4")
endif()

message(STATUS "Final Maximum Derivative: ${LIBXC_MAX_DERIV}")
message(STATUS "Library will satisfy XC DERIV components: ${Libxc_DERIV_COMPONENTS}")
