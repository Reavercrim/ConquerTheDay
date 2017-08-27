#include <string>
#include "Creature.hpp"

//constructor
//---------------------------
Creature::Creature()
{
	
}

//getter
//-----------------------------
std::string Creature::getName()
{
	return this->m_Name;
}

int Creature::getConstitution()
{
	return this->m_Constitution;
}

int Creature::getStrength()
{
	return this->m_Strength;
}

int Creature::getAgility()
{
	return this->m_Agility;
}

//setter
//-------------------------------------
void Creature::setName(std::string name)
{
	this->m_Name = name;
}

void Creature::setConstitution(int constitution)
{
	this->m_Constitution = constitution;
}

void Creature::setStrength(int strength)
{
	this->m_Strength = strength;
}

void Creature::setAgility(int agility)
{
	this->m_Agility = agility;
}

