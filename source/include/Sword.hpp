#ifndef SWORD_HPP
#define SWORD_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Weapon.hpp"

class Sword : public Weapon
{
	public:
	
	static std::vector<w_Modifier> s_WAttack;
	
	Sword();
	
	virtual w_Modifier primary();
	virtual w_Modifier secondary();
	
	private:
	
	int m_Primary = 0;
	int m_Secondary = 1;
};


#endif //SWORD_HPP
