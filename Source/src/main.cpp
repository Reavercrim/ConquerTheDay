#include <SFML/Graphics.hpp>
#include <iostream>
#include "AssetManager.hpp"
#include "TileMap.hpp"
#include "Animator.hpp"
#include "HealthBar.hpp"
#include "Weapon.hpp"
#include "Sword.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(480, 480), "CTD");
    AssetManager manager;
    
    Weapon *w(nullptr);
    w = new Sword;
    
    std::cout << w->primary().damage <<std::endl;
    std::cout << w->secondary().damage <<std::endl;
    
    const int level[] =
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };

    // on crée la tilemap avec le niveau précédemment défini
    TileMap map;
    if (!map.load("data/ressource/g1.png", sf::Vector2u(32, 32), level, 15, 15))
        return -1;
        
    sf::Vector2i spriteSize(32,64);
    
    sf::Vector2i spriteSizeT(32,64);
    sf::Vector2i spriteSizeA(64,64);
    
    
    sf::Sprite sprite;
    Animator animator(sprite);
    
    auto& idleAnimation = animator.CreateAnimation("Idle", "data/ressource/red.png", sf::seconds(0.5f), true);
    idleAnimation.addFrames(sf::Vector2i(0,0),spriteSizeT,4);
    
    auto& atkAnimation = animator.CreateAnimation("Atk", "data/ressource/red.png", sf::seconds(0.5f), true);
    atkAnimation.addFrames(sf::Vector2i(0,64),spriteSizeA,5);
    
    /*auto& idleAnimation = animator.CreateAnimation("Idle", "ressource/sprite.png", sf::seconds(0.5f), true);
    idleAnimation.addFrames(sf::Vector2i(0,0),spriteSize,2);
    
    auto& upAnimation = animator.CreateAnimation("Up", "ressource/sprite.png", sf::seconds(0.5f), true);
    upAnimation.addFrames(sf::Vector2i(64,64),spriteSize,4);
    
    auto& downAnimation = animator.CreateAnimation("Down", "ressource/sprite.png", sf::seconds(0.5f), true);
    downAnimation.addFrames(sf::Vector2i(64,0),spriteSize,4);
    
    auto& leftAnimation = animator.CreateAnimation("Left", "ressource/sprite.png", sf::seconds(0.5f), true);
    leftAnimation.addFrames(sf::Vector2i(64,128),spriteSize,4);
    
    auto& rightAnimation = animator.CreateAnimation("Right", "ressource/sprite.png", sf::seconds(0.5f), true);
    rightAnimation.addFrames(sf::Vector2i(64,192),spriteSize,4);
    */
    
    
    
    sf::Clock clock;
    sf::Time elapsed;


	HealthBar hp(1,256,0);
	HealthBar hp1(4,256,1);
	HealthBar hp2(64,256,2);
	HealthBar hp3(128,256,3);
	HealthBar hp4(192,256,4);
	HealthBar hp5(256,256,5);
	

    while (window.isOpen())
    {
		
        //Game loop
		hp.nextHp();
		
		//std::cout << hp.getHp() << std::endl;

		sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
       

        sf::Time deltaTime = clock.restart();
        animator.Update(deltaTime);
        
        float dt = deltaTime.asSeconds();
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (animator.GetCurrentAnimationName() != "Up")
				animator.SwitchAnimation("Up");
			sprite.move(sf::Vector2f(0, -60*dt));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (animator.GetCurrentAnimationName() != "Down")
				animator.SwitchAnimation("Down");
			sprite.move(sf::Vector2f(0, 60*dt));
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (animator.GetCurrentAnimationName() != "Left")
				animator.SwitchAnimation("Left");
			sprite.move(sf::Vector2f(-60*dt, 0));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (animator.GetCurrentAnimationName() != "Right")
				animator.SwitchAnimation("Right");
			sprite.move(sf::Vector2f(60*dt, 0));
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (animator.GetCurrentAnimationName() != "Atk")
				animator.SwitchAnimation("Atk");
		}
		else
		{
			if (animator.GetCurrentAnimationName() != "Idle")
				animator.SwitchAnimation("Idle");
        }
        
        window.clear(sf::Color::Black);
        //window.draw(map);
        window.draw(sprite);
        window.draw(hp);
        window.draw(hp1);
        window.draw(hp2);
        window.draw(hp3);
        window.draw(hp4);
        window.draw(hp5);
        window.display();
    }

    return 0;
}
