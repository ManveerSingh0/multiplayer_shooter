add_executable(main main.cpp)
add_library(
  game_engine
  game.cpp
  player.cpp
  map.cpp
)


add_custom_command(
  TARGET main POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different 
      "${CMAKE_SOURCE_DIR}/assets/knight.png" 
      "$<TARGET_FILE_DIR:main>/bin/knight.png"
  COMMENT "Copying knight.png to the binary directory"
)


add_custom_command(
  TARGET main POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different 
      "${CMAKE_SOURCE_DIR}/assets/basic_pack" 
      "$<TARGET_FILE_DIR:main>/bin/assets/basic_pack"
  COMMENT "copying basic_pack directory to bin/assets folder"
)


target_link_libraries(game_engine PUBLIC SFML::Graphics)
target_include_directories(game_engine PUBLIC "${CMAKE_SOURCE_DIR}/client/include")


target_link_libraries(main PRIVATE SFML::Graphics game_engine)

