find_path(
  NEWTON_INCLUDE_DIR
	NAMES
		Newton.h
  PATH_SUFFIXES
		newton
)

find_library(
	NEWTON_LIBRARY
  NAMES
		Newton
	PATH_SUFFIXES
		newton
)

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(
	NEWTON DEFAULT_MSG
	NEWTON_INCLUDE_DIR
	NEWTON_LIBRARY
)

mark_as_advanced(NEWTON_INCLUDE_DIR NEWTON_LIBRARY)