#include "game.hpp"
#include "chunk.hpp"
#include "animator.hpp"

Game::Game(): m_window(sf::VideoMode(1800, 800), "CTD"),
              m_udp_client(std::string("127.0.0.1"),5000),
              m_map("data/ressource/gt.png",sf::Vector2u(32, 32)),
              m_view(sf::FloatRect(0, 0, 1800, 800))
              
{
    m_view.zoom(1.0f);
    m_player.reserve(64);
    m_animator.reserve(64);


    /* if(m_map.load("data/ressource/gt.png", sf::Vector2u(32, 32), 32, 32))
        std::cout << "map: OK" << std::endl; */
    

    sf::Sprite sprite;
    m_player.push_back(sf::Sprite());

    m_animator.push_back(Animator(m_player[0]));

    auto& idleAnimation = m_animator.at(0).CreateAnimation("Idle", "data/ressource/sprite.png", sf::seconds(0.5f), true);
    idleAnimation.addFrames(sf::Vector2i(64,192),sf::Vector2i(32,64),3);

    m_animator.at(0).SwitchAnimation("Idle");

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
            update(TimePerFrame);
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

    if (m_window.hasFocus())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            m_udp_client.sendInput("u");
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            m_udp_client.sendInput("d");
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            m_udp_client.sendInput("l");
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            m_udp_client.sendInput("r");
        }
    }

    if (event.type == sf::Event::Resized)
    {
        // update the view to the new size of the window
        m_view.setSize(sf::Vector2f(event.size.width, event.size.height));
    }
}

void Game::update(sf::Time timeSinceLastUpdate)
{
    sf::Packet p;
    sf::IpAddress sender;
    unsigned short port;

    if (m_udp_client.getSocket().receive(p,sender,port) == sf::Socket::Done)
    {
        sf::Uint16 size;
        p >> size;
        //std::cout << "size: " << size << std::endl;

        float x,y;


        for(int i=0; i<size; i++)
        {
            p >> x >> y;
            m_player.at(i).setPosition(sf::Vector2f(x,y));
        }

        p >> m_playerIndex;
        //std::cout << "index: " << m_playerIndex << std::endl;

        m_view.setCenter(sf::Vector2f(x+16, y+32));
        
    }

    m_animator.at(0).Update(timeSinceLastUpdate);
}

void Game::render()
{
    m_window.setView(m_view);
    m_window.clear(sf::Color::Black);
    m_window.draw(m_map);

    for(auto it = m_player.begin(); it != m_player.end(); it++)
        m_window.draw(*it);

    m_window.display();
}