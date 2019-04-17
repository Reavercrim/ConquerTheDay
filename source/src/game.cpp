#include "game.hpp"
#include "chunk.hpp"
#include "animator.hpp"

Game::Game(): m_window(sf::VideoMode(480, 480), "CTD"),
              m_udp_client(std::string("127.0.0.1"),5000),
              m_view(sf::FloatRect(0, 0, 480, 480)),
              m_rect(sf::Vector2f(32.f, 32.f))
{

    Chunk ch("chunk.dat");

    if(m_map.load("data/ressource/gt.png", sf::Vector2u(32, 32), ch.getTiles().data(), 15, 15))
        std::cout << "map: OK" << std::endl;


}


void Game::run()
{
    m_udp_client.connectToServer();

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(1.f/30);

    while (m_window.isOpen())
    {

        bool repaint = false;

        timeSinceLastUpdate += clock.restart();
        if (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            repaint = true;
        }



        if(repaint)
        {
            processEvents();
            update();
            render();
        }

    }
}

//send input to server
void Game::processEvents()
{
    sf::Event event;

    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_window.close();
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        sf::Packet packet;
        std::string c = "u";
        packet << c;
        m_udp_client.send(packet);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        sf::Packet packet;
        std::string c = "d";
        packet << c;
        m_udp_client.send(packet);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        sf::Packet packet;
        std::string c = "l";
        packet << c;
        m_udp_client.send(packet);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        sf::Packet packet;
        std::string c = "r";
        packet << c;
        m_udp_client.send(packet);
    }

}

void Game::update()
{
    sf::Packet p;
    sf::IpAddress sender;
    unsigned short port;

    if (m_udp_client.getSocket().receive(p,sender,port) == sf::Socket::Done)
    {
        float x,y;
        p >> x >> y;
        m_rect.setPosition(x,y);
    }
}

void Game::render()
{
    m_window.setView(m_view);
    m_window.clear(sf::Color::Black);
    m_window.draw(m_map);
    m_window.draw(m_rect);
    m_window.display();
}
