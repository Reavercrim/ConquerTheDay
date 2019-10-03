#include <SFML/Graphics.hpp>
#include "tileMap.hpp"
#include "assetManager.hpp"

TileMap::TileMap(const std::string& tileset, sf::Vector2u tileSize):m_tileSize(tileSize)
{
	// on charge la texture du tileset
	m_tileset.loadFromFile(tileset);
	m_chunkBuffer.updateBuffer(1,1);

	this->drawMap();
	
}

bool TileMap::drawMap()
{
	int minSize = m_chunkBuffer.getMinSize();
	std::pair<int,int> pos = m_chunkBuffer.getActiveChunk();


	// on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
	int width = m_tileSize.x;
	int height = m_tileSize.y;
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4 * (2*minSize+1)*(2*minSize+1));


	for (int i= -minSize; i<= minSize; i++)
    {
        for (int j= -minSize; j<= minSize; j++)
        {
            if (pos.first+i < 0 || pos.second+j < 0)
            {
                continue;
            }

			
            drawChunk(pos.first+i,pos.second+j,i+minSize,j+minSize);
        }
    }

	return true;
}


void TileMap::drawChunk(int x,int y, int k,int l)
{
	

	int width = m_tileSize.x;
	int height = m_tileSize.y;

	uint16_t *tiles = m_chunkBuffer.getChunkFromMap(x,y).getTiles().data();

	int minSize = m_chunkBuffer.getMinSize();
	

	int ox = k*32;
	int oy = l*32;

	// on remplit le tableau de vertex, avec un quad par tuile

	//std::cout << ox << ":" << oy  << std::endl;

	for (int i = 0; i < width; ++i)
		for (int j = 0; j < height; ++j)
		{

			// on récupère le numéro de tuile courant
			int tileNumber = tiles[i + j * width];

			// on en déduit sa position dans la texture du tileset
			int tu = tileNumber % (m_tileset.getSize().x / m_tileSize.x);
			int tv = tileNumber / (m_tileset.getSize().x / m_tileSize.x);

			// on récupère un pointeur vers le quad à définir dans le tableau de vertex
			//sf::Vertex* quad = &m_vertices[(i + j * width) * 4];
			sf::Vertex* quad = &m_vertices[(32*(ox+oy*(2*minSize+1))+(i + j * width)) * 4];

			// on définit ses quatre coins
			
			quad[0].position = sf::Vector2f((ox + i) * m_tileSize.x,    (oy + j) * m_tileSize.y);
			quad[1].position = sf::Vector2f((ox + i + 1) * m_tileSize.x,(oy + j) * m_tileSize.y);
			quad[2].position = sf::Vector2f((ox + i + 1) * m_tileSize.x,(oy + j + 1) * m_tileSize.y);
			quad[3].position = sf::Vector2f((ox + i) * m_tileSize.x,    (oy + j + 1) * m_tileSize.y);

			// on définit ses quatre coordonnées de texture
			quad[0].texCoords = sf::Vector2f(tu * m_tileSize.x, tv * m_tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * m_tileSize.x, tv * m_tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * m_tileSize.x, (tv + 1) * m_tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * m_tileSize.x, (tv + 1) * m_tileSize.y);
				
		}
	
}


void TileMap::update(int x,int y)
{
	m_chunkBuffer.updateBuffer(x,y);
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// on applique la transformation
	states.transform *= getTransform();

	// on applique la texture du tileset
	states.texture = &m_tileset;

	// et on dessine enfin le tableau de vertex
	target.draw(m_vertices, states);
}
