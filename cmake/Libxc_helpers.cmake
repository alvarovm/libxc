# Additional helper macros and functions defined by Libxc

function(deprecate_option _old_option _new_option)
	# Announce that a setting is deprecated and instead one should use the new variable
	#
	# Function variables::
	#   _old_option (string): Old option that is deprecated
	#   _new_option (string): New option that is preferred
	# Options ::
	#   MAYBE_NAME_CLASH:   Whether `_old_option` can have a name clash with other options
	#
	# Example::
	#   deprecate_option(ENABLE_FORTRAN LIBXC_ENABLE_FORTRAN MAYBE_NAME_CLASH)
	#
	# Notes::
	#   There is an ambiguity if the user has already changed the setting to use non-deprecated options or not
	#	By default this will always overwrite the value of `_old_option` onto `_new_option` whenever `_old_option` is
	#   defined. This is problematic if the user has defined something like `ENABLE_FORTRAN`, but it was intended for
	#   a different package. We use an extra option `LIBXC_IGNORE_DEPRECATED` to override this behaviour, i.e. if it is
	#   set, do not change the value of `_new_option` even if `_old_option` is defined.
	#   This behaviour is only relevant if there could be some name-clashing, so it is disabled by default and one needs
	#   to enable it by passing `MAYBE_NAME_CLASH`. E.g. this option is not necessary if the option is already prefixed
	#   by `LIBXC_`.

	cmake_parse_arguments(ARGS
			"MAYBE_NAME_CLASH"  # Options
			""  # Single-value arguments
			""  # Multiple-value arguments
			${ARGN})

	if (DEFINED ${_old_option})
		# Only relevant if `_old_option` is defined, otherwise can ignore
		if (ARGS_MAYBE_NAME_CLASH)
			# If there is a possible name clash check LIBXC_IGNORE_DEPRECATED
			if (LIBXC_IGNORE_DEPRECATED)
				# If we were instructed to ignore deprecated options, do nothing
				return()
			else ()
				# Otherwise display a detailed warning
				message(WARNING
						"${_old_option} is deprecated on Libxc. This option might be used by other packages.\n"
						"It is ambiguous if you have setup the new option ${_new_option} correctly or not.\n"
						"Please pass -DLIBXC_IGNORE_DEPRECATED=ON to confirm that you are using ${_new_option}.")
			endif ()
		endif ()
		message(DEPRECATION
				"${_old_option} is deprecated. Please use ${_new_option} instead.\n"
				"Setting ${_new_option}=${${_old_option}}")
		set(${_new_option} ${${_old_option}} PARENT_SCOPE)
	endif ()
endfunction()