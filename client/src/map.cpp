#include <SFML/Graphics/PrimitiveType.hpp>
#include <map.hpp>


Map::Map() {}


bool Map::load(std::filesystem::path &tile_path, sf::Vector2u tile_size,
               const int *tiles, uint32_t width, uint32_t height) {

  if(!m_tile_set.loadFromFile(tile_path)){
    return false;
  }

  m_tile_verticies.setPrimitiveType(sf::PrimitiveType::Triangles);
  m_tile_verticies.resize(width * height * 6);
}

