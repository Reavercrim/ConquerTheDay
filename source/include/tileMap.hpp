#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include "chunkBuffer.hpp"

class TileMap : public sf::Drawable, public sf::Transformable
{
public:

    TileMap(const std::string& tileset, sf::Vector2u tileSize);

    bool drawMap();
    void update(int x,int y);
    void drawChunk(int x,int y,int k,int l);
    


private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::Texture m_tileset;
    sf::Vector2u m_tileSize;
    sf::VertexArray m_vertices;
    ChunkBuffer m_chunkBuffer;

};


#endif //TILEMAP_HPP
