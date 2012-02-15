find_path(
  IRRLICHT_INCLUDE_DIR
	NAMES
		irrlicht.h
  PATH_SUFFIXES
		irr
		irrlicht
)

find_library(
	IRRLICHT_LIBRARY
  NAMES
		Irrlicht
	PATH_SUFFIXES
		irr
		irrlicht
)

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(
	IRRLICHT DEFAULT_MSG
	IRRLICHT_INCLUDE_DIR
	IRRLICHT_LIBRARY
)

mark_as_advanced(IRRLICHT_INCLUDE_DIR IRRLICHT_LIBRARY)