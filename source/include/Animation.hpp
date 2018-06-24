#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <string>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Animation
{
	public:

	Animation(std::string const& name, std::string const& textureName,
			  sf::Time const& duration, bool looping);

	void addFrames(sf::Vector2i const& startFrom,
				   sf::Vector2i const& frameSize, unsigned int frames);
	
	//getter			   
	std::string getName();
	std::string getTextureName();
	sf::Time getDuration();
	std::vector<sf::IntRect> getFrames();
	bool isLooping();

	private:

	std::string m_Name;
	std::string m_TextureName;
	std::vector<sf::IntRect> m_Frames;
	sf::Time m_Duration;
	bool m_Looping;

};


#endif //ANIMATION_HPP
