cmake_minimum_required(VERSION 3.1)
project(multiplayer_game)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


include(FetchContent)

FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG        5.5 # This is the latest stable version
)

FetchContent_MakeAvailable(raylib)


add_executable(main main.cpp)



target_link_libraries(main PRIVATE raylib)
