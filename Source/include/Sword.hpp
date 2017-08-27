#ifndef SWORD_HPP
#define SWORD_HPP

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
