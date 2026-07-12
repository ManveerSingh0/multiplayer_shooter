#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>


#include <filesystem>
#include <cstdint>


class Map : public sf::Drawable , public sf::Transform{

public:
  Map();
  bool load(std::filesystem::path& tile_path, sf::Vector2u tile_size, const int* tiles,  uint32_t width, uint32_t height);

private:
  sf::Texture m_tile_set;
  sf::VertexArray m_tile_verticies;

};
