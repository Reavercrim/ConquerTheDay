#ifndef HEALTHBAR_HPP
#define HEALTHBAR_HPP



class HealthBar : public sf::Drawable
{
	
public:
	
	HealthBar(int curHp,int maxHp,int offset);
	
	void setHp(int hp);
	
	void nextHp();
	
	int getHp();
	
	void updateColor();
	
	
	
	sf::Color getColor();
	

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(m_Background, states);
		target.draw(m_Bar, states);
	}

	sf::RectangleShape m_Background;
	sf::RectangleShape m_Bar;
	
	int m_Hp;
	int m_MaxHp;
	sf::Color m_Color;
	
	
		
};
		

#endif //HEALTHBAR_HPP
