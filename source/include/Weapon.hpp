#ifndef WEAPON_HPP
#define WEAPON_HPP

struct w_Modifier
{
	float damage;
	float speed;
	sf::Vector2f hitBoxM;
	float mitigation;
};


class Weapon
{
	
	public:
	
	
	Weapon();
	
	//getter

	std::string getName();
	
	
	//setter
	
	void setName(std::string name);
	
	virtual w_Modifier primary();
	
	virtual w_Modifier secondary();
	
	
	private:
	
	std::string m_Name;
	
	
};


#endif //WEAPON_HPP
