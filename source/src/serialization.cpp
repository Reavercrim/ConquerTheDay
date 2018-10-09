#include "serialization.hpp"

#include <iostream>

std::string Serialization::tilemapToHex(std::vector<int> &tileMap)
{
    std::stringstream stream;


    for (auto it = tileMap.cbegin(); it != tileMap.cend(); ++it)
    {
        stream << std::setfill ('0') << std::setw(2);
        stream << std::hex << *it;
    }


    return stream.str();
}
