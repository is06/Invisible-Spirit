IF(FMODEX_LIBRARIES AND FMODEX_INCLUDE_DIRS)
  set(FMODEX_FOUND TRUE)
ELSE(FMODEX_LIBRARIES AND FMODEX_INCLUDE_DIRS)
  find_path(
    FMODEX_INCLUDE_DIR
    NAMES
      fmod.h
    PATHS
      ${CMAKE_INCLUDE_PATH}
      ${CMAKE_INCLUDE_PATH}/fmod
      ${CMAKE_INCLUDE_PATH}/fmodex
      /usr/include
      /usr/include/fmod
      /usr/include/fmodex
      /usr/local/include
      /usr/local/include/fmod
      /usr/local/include/fmodex
      /opt/local/include
      /sw/include
  )
  find_library(
    FMODEX_LIBRARY
    NAMES
      FmodEx
      fmod
    PATHS
      ${CMAKE_LIBRARY_PATH}
      ${CMAKE_LIBRARY_PATH}/fmod
      ${CMAKE_LIBRARY_PATH}/fmodex
      /usr/lib
      /usr/lib/fmod
      /usr/lib/fmodex
      /usr/local/lib
      /usr/local/lib/fmod
      /usr/local/lib/fmodex
      /opt/local/lib
      /sw/lib
  )

  IF(FMODEX_LIBRARY)
    set(FMODEX_FOUND TRUE)
  ENDIF(FMODEX_LIBRARY)

  set(FMODEX_INCLUDE_DIRS ${FMODEX_INCLUDE_DIR})

  IF(FMODEX_FOUND)
    set(FMODEX_LIBRARIES ${FMODEX_LIBRARIES} ${FMODEX_LIBRARY})
  ELSE(FMODEX_FOUND)
    message(FATAL_ERROR "FmodEx not found!")
  ENDIF(FMODEX_FOUND)

  IF(FMODEX_INCLUDE_DIRS AND FMODEX_LIBRARIES)
    set(FMODEX_FOUND TRUE)
  ENDIF(FMODEX_INCLUDE_DIRS AND FMODEX_LIBRARIES)

  mark_as_advanced(FMODEX_INCLUDE_DIRS FMODEX_LIBRARIES)
ENDIF(FMODEX_LIBRARIES AND FMODEX_INCLUDE_DIRS) 