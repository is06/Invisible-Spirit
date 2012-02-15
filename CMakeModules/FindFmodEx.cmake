find_path(
  FMODEX_INCLUDE_DIR
	NAMES
		fmod.h
  PATH_SUFFIXES
		fmod
		fmodex
)

find_library(
	FMODEX_LIBRARY
  NAMES
		fmodex
	PATH_SUFFIXES
		fmod
		fmodex
)

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(
	FMODEX DEFAULT_MSG
	FMODEX_INCLUDE_DIR
	FMODEX_LIBRARY
)

mark_as_advanced(FMODEX_INCLUDE_DIR FMODEX_LIBRARY)