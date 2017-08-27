#include <SFML/Graphics.hpp>
#include <string>
#include "Weapon.hpp"


Weapon::Weapon()
{
	
}

void Weapon::setName(std::string name)
{
	this->m_Name = name;
}

std::string Weapon::getName()
{
	return this->m_Name;
}

w_Modifier Weapon::primary()
{
	w_Modifier init = {0,0,sf::Vector2f(0,0),0};
	return init;
}

w_Modifier Weapon::secondary()
{
	w_Modifier init = {0,0,sf::Vector2f(0,0),0};
	return init;
}

