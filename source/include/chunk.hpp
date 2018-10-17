#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <vector>
#include "serializable.hpp"


/*
Map Chunk
*/
class Chunk : public Serializable
{
public:
    Chunk(int size,std::vector<uint16_t> tiles);
    Chunk(std::stringstream& stream);

    int getSize();
    std::vector<uint16_t> &getTiles();

    void setSize(int size);
    void setTiles(std::vector<uint16_t> tiles);

    virtual void serialize(std::stringstream& stream);
    virtual void deserialize(std::stringstream& stream);
    virtual void toFile(std::string path);

private:
    int m_size;
    std::vector<uint16_t> m_tiles;

};


#endif //CHUNK_HPP
