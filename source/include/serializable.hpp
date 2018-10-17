#ifndef SERIALIZABLE_HPP
#define SERIALIZABLE_HPP

#include <iostream>

class Serializable
{
public:
    Serializable(){}
    virtual ~Serializable(){}

    virtual void serialize(std::stringstream& stream) = 0;
    virtual void deserialize(std::stringstream& stream) = 0;
    virtual void toFile(std::string path) = 0;
};


#endif //SERIALIZABLE_HPP
