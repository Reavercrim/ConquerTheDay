#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "udpClient.hpp"
#include "tileMap.hpp"
#include "assetManager.hpp"
#include "animator.hpp"
#include "animation.hpp"

class Game
{
public:
    Game();
    void run();

private:
    void processEvents();
    void update(sf::Time timeSinceLastUpdate);
    void render();

    sf::RenderWindow m_window;
    UdpClient m_udp_client;
    TileMap m_map;
    AssetManager m_manager;
    sf::View m_view;
    std::vector<sf::Sprite> m_player;
    std::vector<Animator> m_animator;
    sf::Uint16 m_playerIndex;

};

#endif //GAME_HPP
