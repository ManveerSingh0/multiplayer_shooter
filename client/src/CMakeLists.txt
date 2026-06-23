add_executable(main main.cpp)
add_library(
  game_engine
  game.cpp
)


target_link_libraries(game_engine PUBLIC SFML::Graphics)
target_include_directories(game_engine PUBLIC "${CMAKE_SOURCE_DIR}/client/include")


target_link_libraries(main PRIVATE SFML::Graphics game_engine)

