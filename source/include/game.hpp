#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "udpClient.hpp"
#include "tileMap.hpp"
#include "assetManager.hpp"

class Game
{
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow m_window;
    UdpClient m_udp_client;
    TileMap m_map;
    AssetManager m_manager;
    sf::View m_view;
    sf::RectangleShape m_rect;


};

#endif //GAME_HPP
