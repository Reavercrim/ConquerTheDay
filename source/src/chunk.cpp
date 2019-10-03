#include "chunk.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

Chunk::Chunk(int size, std::vector<uint16_t> tiles):m_size(size),m_tiles(tiles)
{

}

Chunk::Chunk(std::stringstream& stream)
{
    this->deserialize(stream);
}

Chunk::Chunk(std::string path)
{
    //this->fromFile(0,0);
}

Chunk::Chunk(int x, int y)
{
    this->fromFile(x,y);
}

int Chunk::getSize()
{
    return this->m_size;
}

std::vector<uint16_t> &Chunk::getTiles()
{
    return this->m_tiles;
}

void Chunk::setSize(int size)
{
    this->m_size = size;
}

void Chunk::setTiles(std::vector<uint16_t> tiles)
{
    this->m_tiles = tiles;
}

void Chunk::serialize(std::stringstream& stream)
{
    int size = this->getSize();
    stream << size;

    for (auto it = this->getTiles().cbegin(); it != this->getTiles().cend(); ++it)
    {
        stream << " " << *it;
    }

}

void Chunk::deserialize(std::stringstream& stream)
{
    int size;
    stream >> size;

    this->setSize(size);

    std::vector<uint16_t> tiles;
    tiles.reserve(size*size);

    uint16_t tile;
    int i = 0;

    while(stream >> tile)
    {
        tiles.push_back(tile);
        i++;
    }

    this->setTiles(tiles);
}

void Chunk::toFile(std::string path)
{
    std::ofstream outf(path);
    std::stringstream stream;
    this->serialize(stream);

    outf << stream.str() << std::endl;

}

void Chunk::fromFile(int x, int y)
{
    m_tiles.reserve(32*32*2);

    char* p = reinterpret_cast<char*>(m_tiles.data());

    std::ifstream is("data/chunk/a.dat", std::ifstream::binary);

    is.seekg((x+32*y)*32*32*2);

    is.read(p,32*32*2);

    is.close();
    //is.close();

}
