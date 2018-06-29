#include "sword.hpp"

Sword::Sword()
{

}

w_Modifier Sword::primary()
{
	return Sword::s_WAttack[this->m_Primary];
}

w_Modifier Sword::secondary()
{
	return Sword::s_WAttack[this->m_Secondary];
}



// Definition

w_Modifier slash = {1.5,1.2,sf::Vector2f(1.5,2.0),1.0};
w_Modifier thrust = {2.0,1.0,sf::Vector2f(1.5,2.0),1.0};


std::vector<w_Modifier> Sword::s_WAttack = {slash,thrust};
