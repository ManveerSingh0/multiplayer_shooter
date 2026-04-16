include(FetchContent)

FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG        5.5 # This is the latest stable version
)

FetchContent_MakeAvailable(raylib)

FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json
  GIT_TAG v3.12.0
)



add_executable(main main.cpp)
add_library(player
  player.cpp
  game.cpp
)
target_include_directories(
  player PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/
) 





target_link_libraries(player PRIVATE raylib)
target_link_libraries(main PRIVATE raylib player)
