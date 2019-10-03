#include "chunkBuffer.hpp"

ChunkBuffer::ChunkBuffer(int minSize,int maxSize):m_minSize(minSize),m_maxSize(maxSize)
{
    m_activeChunk = std::make_pair(1,1);
}

void ChunkBuffer::updateBuffer(int x, int y)
{
    for (int i= -m_minSize; i<= m_minSize; i++)
    {
        for (int j= -m_minSize; j<= m_minSize; j++)
        {
            if (x+i < 0 || y+j < 0)
            {
                continue;
            }

            loadCloseChunk(x+i,y+j);
        }
    }
}


void ChunkBuffer::removeFarChunk(int x, int y)
{

}

void ChunkBuffer::loadCloseChunk(int x, int y)
{
    std::pair <int,int> coord(x,y);

    if (m_chunkBuffer.count(coord) == 0)
    {
        m_chunkBuffer.insert(std::pair<std::pair<int,int>,Chunk>(coord,Chunk(x,y)));
    }
    
}

mapBuffer& ChunkBuffer::getMapBuffer()
{
    return this->m_chunkBuffer;
}

Chunk& ChunkBuffer::getChunkFromMap(int x, int y)
{
    std::pair <int,int> coord(x,y);
    mapBuffer::iterator it;
    it = m_chunkBuffer.find(coord);

    if (it != m_chunkBuffer.end())
    {
        return it->second;
    }

}


int ChunkBuffer::getMinSize()
{
    return this->m_minSize;
}

std::pair<int,int> ChunkBuffer::getActiveChunk()
{
    return m_activeChunk;
}