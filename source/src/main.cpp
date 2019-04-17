#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <vector>

#include "game.hpp"
#include "assetManager.hpp"
#include "tileMap.hpp"
#include "animator.hpp"
#include "chunk.hpp"

int main()
{

    Game game;

    // std::vector<uint16_t> v_test = {
    // 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    // 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    // 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    // 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    // 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    // 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    // 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    // 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    // 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    // 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    // 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0,
    // 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    // 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    // 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    // 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

    /*Chunk ch(15,v_test);
    std::stringstream stream;
    ch.serialize(stream);

    std::cout << "stream " << stream.str() << std::endl;
    ch.toFile("chunk.dat");

    Chunk ch2(stream);*/



    // on crée la tilemap avec le niveau précédemment défini




    // sf::Vector2i spriteSizeT(64,64);
    //sf::Vector2i spriteSizeA(64,64);


    // sf::Sprite sprite;
    // Animator animator(sprite);
    //
    // auto& idleAnimation = animator.CreateAnimation("Idle", "data/ressource/knight.png", sf::seconds(0.5f), true);
    // idleAnimation.addFrames(sf::Vector2i(0,0),spriteSizeT,4);






    game.run();

        //Game loop




    // sprite.setPosition(window.mapPixelToCoords(sf::Vector2i(240,240)));
    //
    // window.setView(view);
    //
    // window.clear(sf::Color::Black);
    // window.draw(map);
    // window.draw(sprite);
    //
    // window.display();

    return 0;
}
