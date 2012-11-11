# CMakeList.txt

# Compilation on Mac System not yet tested, please contact us at http://www.is06.com/contact.php
# if you want to participate! :)

cmake_minimum_required(VERSION 2.6)

project(Invisible-Spirit)

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeModules")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s -O2 -Wall -pedantic")

find_package(Irrlicht REQUIRED)
find_package(FmodEx REQUIRED)
find_package(Newton REQUIRED)
find_package(Boost REQUIRED)

file(
  GLOB_RECURSE
  source_files
  src/*.cpp
)

add_executable(
  Invisible-Spirit
  ${source_files}
)

IF(WIN32)
  target_link_libraries(
    Invisible-Spirit
    boost_thread
    ${IRRLICHT_LIBRARY}
    ${FMODEX_LIBRARY}
    ${NEWTON_LIBRARY}
  )
ELSE(WIN32)
  target_link_libraries(
    Invisible-Spirit
    ${IRRLICHT_LIBRARY}
    GL
    GLU
    Xxf86vm
    Xext
    X11
    boost_thread
    ${FMODEX_LIBRARY}
    ${NEWTON_LIBRARY}
  )
ENDIF(WIN32)
