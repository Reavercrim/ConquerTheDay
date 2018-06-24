#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>
#include "Status.hpp"

class Creature
{
	public:
	
	Creature();
	
	//getter
	std::string getName();
	
	Status getStatus();
	int getCurrentHealth();
	
	int getConstitution();
	int getStrength();
	int getAgility();
	
	
	
	//setter
	void setName(std::string name);

	void setStatus(Status status);
	void setCurrentHealth(int health);
	
	void setConstitution(int constitution);
	void setStrength(int strength);
	void setAgility(int agility);
	
	
	
	private:
	
	std::string m_Name;
	
	Status m_Status;
	
	int m_CurrentHealth;
	int m_Constitution;
	int m_Strength;
	int m_Agility;
	
};


#endif //CREATURE_HPP
