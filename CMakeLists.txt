# CMakeList.txt

# Compilation on Mac System not yet tested, please contact us at http://www.is06.com/contact.php
# if you want to participate! :)

cmake_minimum_required(VERSION 2.6)

project(Invisible-Spirit)

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
set(CMAKE_MODULE_PATH CMakeModules)

find_package(Irrlicht)
find_package(FmodEx)
find_package(Newton)

file(
  GLOB_RECURSE
  source_files
  src/*.cpp
)

add_executable(
  Invisible-Spirit
  ${source_files}
)

IF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  target_link_libraries(
    Invisible-Spirit
    Irrlicht
    Newton
    FmodEx
  )
ELSE(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    target_link_libraries(
      Invisible-Spirit
      GL
      Xxf86vm
      Irrlicht
      Newton
      FmodEx
    )
  ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
