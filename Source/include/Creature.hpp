#ifndef CREATURE_HPP
#define CREATURE_HPP


class Creature
{
	public:
	
	Creature();
	
	//getter
	std::string getName();
	
	int getConstitution();
	int getStrength();
	int getAgility();
	
	//setter
	void setName(std::string name);

	void setConstitution(int constitution);
	void setStrength(int strength);
	void setAgility(int agility);
	
	
	private:
	
	std::string m_Name;
	
	
	int m_Constitution;
	int m_Strength;
	int m_Agility;
	
};


#endif //CREATURE_HPP
