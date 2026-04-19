add_executable(main main.cpp)
add_library(player
  player.cpp
  game.cpp
)
target_include_directories(
  player PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/
) 





target_link_libraries(player PRIVATE raylib nlohmann_json::nlohmann_json)
target_link_libraries(main PUBLIC raylib player)
