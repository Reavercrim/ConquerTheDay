#include <string>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "animation.hpp"


Animation::Animation(std::string const& name, std::string const& textureName,
		  sf::Time const& duration, bool looping):
		  m_Name(name),m_TextureName(textureName),
		  m_Duration(duration),m_Looping(looping)
{ }

std::string Animation::getName()
{
	return m_Name;
}

std::string Animation::getTextureName()
{
	return m_TextureName;
}

sf::Time Animation::getDuration()
{
	return m_Duration;
}

std::vector<sf::IntRect> Animation::getFrames()
{
	return m_Frames;
}

bool Animation::isLooping()
{
	return m_Looping;
}

//Add frames in frames member
void Animation::addFrames(sf::Vector2i const& startFrom,
			   sf::Vector2i const& frameSize, unsigned int frames)
{
	sf::Vector2i current = startFrom;
	for(unsigned int i=0;i<frames;i++)
	{
		m_Frames.push_back(sf::IntRect(current.x,current.y,frameSize.x,frameSize.y));

		current.x += frameSize.x;
	}
}
