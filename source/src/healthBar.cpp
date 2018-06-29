#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "healthBar.hpp"

HealthBar::HealthBar(int curHp,int maxHp,int offset):
		m_Hp(curHp),m_MaxHp(maxHp)
{
	m_Background = sf::RectangleShape(sf::Vector2f(m_MaxHp+2,7));
	m_Background.setPosition(5,5+8*offset);
	m_Background.setFillColor(sf::Color::Black);

	m_Bar = sf::RectangleShape(sf::Vector2f(m_Hp,5));
	m_Bar.setPosition(6,6+8*offset);
	m_Bar.setFillColor(this->getColor());

}

void HealthBar::setHp(int hp)
{
	this->m_Hp = hp;

	if (this->m_Hp > this->m_MaxHp)
		this->m_Hp = this->m_MaxHp;

	this->updateColor();
	this->m_Bar.setSize(sf::Vector2f(this->m_Hp,5));
	this->m_Bar.setFillColor(this->getColor());
}

void HealthBar::updateColor()
{
	this->m_Color = this->getColor();
}

int HealthBar::getHp()
{
	return this->m_Hp;
}


void HealthBar::nextHp()
{
	if(this->m_Hp == this->m_MaxHp)
		this->setHp(1);

	this->setHp(this->getHp()+1);
}


sf::Color HealthBar::getColor()
{
	int r,g;
	double ratio = double(this->m_Hp) / double(this->m_MaxHp);

	if(ratio < 0.5)
	{
		r = 255;
		g = round(2*ratio*255);
	}
	else
	{
		r = round(255-(255*(2*(ratio-0.5))));
		g = 255;

		if(ratio > 0.85)
			g = round(255-(255*(ratio-0.75)));
	}


	return sf::Color(r,g,0);
}
