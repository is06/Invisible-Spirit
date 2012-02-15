IF(NEWTON_LIBRARIES AND NEWTON_INCLUDE_DIRS)
  set(NEWTON_FOUND TRUE)
ELSE(NEWTON_LIBRARIES AND NEWTON_INCLUDE_DIRS)
  find_path(
    NEWTON_INCLUDE_DIR
    NAMES
      Newton.h
    PATHS
      ${CMAKE_INCLUDE_PATH}
      ${CMAKE_INCLUDE_PATH}/newton
      /usr/include
      /usr/include/newton
      /usr/local/include
      /usr/local/include/newton
      /opt/local/include
      /sw/include
  )
  find_library(
    NEWTON_LIBRARY
      NAMES
    Newton
      PATHS
      ${CMAKE_LIBRARY_PATH}
      ${CMAKE_LIBRARY_PATH}/newton
      /usr/lib
      /usr/lib/newton
      /usr/local/lib
      /usr/local/lib/newton
      /opt/local/lib
      /sw/lib
  )
  
  IF(NEWTON_LIBRARY)
    set(NEWTON_FOUND TRUE)
  ENDIF(NEWTON_LIBRARY)

  set(NEWTON_INCLUDE_DIRS ${NEWTON_INCLUDE_DIR})

  IF(NEWTON_FOUND)
    set(NEWTON_LIBRARIES ${NEWTON_LIBRARIES} ${NEWTON_LIBRARY})
  ELSE(NEWTON_FOUND)
    message(FATAL_ERROR "Newton not found!")
  ENDIF(NEWTON_FOUND)

  IF(NEWTON_INCLUDE_DIRS AND NEWTON_LIBRARIES)
    set(NEWTON_FOUND TRUE)
  ENDIF(NEWTON_INCLUDE_DIRS AND NEWTON_LIBRARIES)

  mark_as_advanced(NEWTON_INCLUDE_DIRS NEWTON_LIBRARIES)
ENDIF(NEWTON_LIBRARIES AND NEWTON_INCLUDE_DIRS) 