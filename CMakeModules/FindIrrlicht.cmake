IF(IRRLICHT_LIBRARIES AND IRRLICHT_INCLUDE_DIRS)
  set(IRRLICHT_FOUND TRUE)
ELSE(IRRLICHT_LIBRARIES AND IRRLICHT_INCLUDE_DIRS)
  find_path(
    IRRLICHT_INCLUDE_DIR
    NAMES
      irrlicht.h
    PATHS
      ${CMAKE_INCLUDE_PATH}
      ${CMAKE_INCLUDE_PATH}/irr
      ${CMAKE_INCLUDE_PATH}/irrlicht
      /usr/include
      /usr/include/irr
      /usr/include/irrlicht
      /usr/local/include
      /usr/local/include/irr
      /usr/local/include/irrlicht
      /opt/local/include
      /sw/include
  )
  find_library(
    IRRLICHT_LIBRARY
    NAMES
      Irrlicht
    PATHS
      ${CMAKE_LIBRARY_PATH}
      ${CMAKE_LIBRARY_PATH}/irr
      ${CMAKE_LIBRARY_PATH}/irrlicht
      /usr/lib
      /usr/lib/irr
      /usr/lib/irrlicht
      /usr/local/lib
      /opt/local/lib
      /sw/lib
  )
  IF(IRRLICHT_LIBRARY)
    set(IRRLICHT_FOUND TRUE)
  ENDIF(IRRLICHT_LIBRARY)

  set(IRRLICHT_INCLUDE_DIRS ${IRRLICHT_INCLUDE_DIR})

  IF(IRRLICHT_FOUND)
    set(IRRLICHT_LIBRARIES ${IRRLICHT_LIBRARIES} ${IRRLICHT_LIBRARY})
  ELSE(IRRLICHT_FOUND)
    message(FATAL_ERROR "Irrlicht not found!")
  ENDIF(IRRLICHT_FOUND)

  IF(IRRLICHT_INCLUDE_DIRS AND IRRLICHT_LIBRARIES)
    set(IRRLICHT_FOUND TRUE)
  ENDIF(IRRLICHT_INCLUDE_DIRS AND IRRLICHT_LIBRARIES)

  mark_as_advanced(IRRLICHT_INCLUDE_DIRS IRRLICHT_LIBRARIES)
ENDIF(IRRLICHT_LIBRARIES AND IRRLICHT_INCLUDE_DIRS) 