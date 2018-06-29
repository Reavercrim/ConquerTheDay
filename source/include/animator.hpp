#ifndef ANIMATOR_HPP
#define ANIMATOR_HPP

#include <list>
#include <string>
#include <SFML/Graphics.hpp>
#include "animation.hpp"

class Animator
{

public:

	Animator(sf::Sprite& sprite);

	Animation& CreateAnimation(std::string const& name,
		std::string const& textureName, sf::Time const& duration, bool loop = false);

	void Update(sf::Time const& dt);

	//Returns if the switch was successful
	bool SwitchAnimation(std::string const& name);

	std::string GetCurrentAnimationName() const;



private:
	//Returns the animation with the passed name
	//Returns nullptr if no such animation is found
	Animation* FindAnimation(std::string const& name);

	void SwitchAnimation(Animation* animation);

	//Reference to the sprite
	sf::Sprite& m_Sprite;
	sf::Time m_CurrentTime;
	std::list<Animation> m_Animations;
    Animation* m_CurrentAnimation;

};

#endif //ANIMATOR_HPP
