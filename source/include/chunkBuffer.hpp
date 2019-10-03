#ifndef CHUNKBUFFER_HPP
#define CHUNKBUFFER_HPP

#include <SFML/Graphics.hpp>
#include "chunk.hpp"
#include <utility>
#include <map>

typedef std::map<std::pair<int,int>,Chunk> mapBuffer;

class ChunkBuffer
{
    public:
        ChunkBuffer(int minSize=1,int maxSize=5);
        void updateBuffer(int x, int y);
        void removeFarChunk(int x, int y);
        void loadCloseChunk(int x, int y);
        mapBuffer& getMapBuffer();
        Chunk& getChunkFromMap(int x,int y);
        int getMinSize();
        std::pair<int,int> getActiveChunk();

    private:
        mapBuffer m_chunkBuffer;
        std::pair<int,int> m_activeChunk;
        int m_minSize;
        int m_maxSize;

};



#endif //CHUNKBUFFER_HPP