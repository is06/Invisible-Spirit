# CMakeList.txt

# Compilation on Mac System not yet tested, please contact us at http://www.is06.com/contact.php
# if you want to participate! :)

cmake_minimum_required(VERSION 2.6)

project(Invisible-Spirit)

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeModules")

find_package(Irrlicht REQUIRED)
find_package(FmodEx REQUIRED)
find_package(Newton REQUIRED)
find_package(OpenGL)
find_package(X11)

file(
  GLOB_RECURSE
  source_files
  src/*.cpp
)

add_executable(
  Invisible-Spirit
  ${source_files}
)

target_link_libraries(
  Invisible-Spirit
  ${OPENGL_LIBRARIES}
  ${X11_X11_LIB}
  ${IRRLICHT_LIBRARY}
  ${FMODEX_LIBRARY}
  ${NEWTON_LIBRARY}
)
