#ifndef UDPCLIENT_HPP
#define UDPCLIENT_HPP

#include <SFML/Network.hpp>


class UdpClient
{
public:
    UdpClient(std::string server_addr, int server_port);
    void send(sf::Packet & packet);
    sf::UdpSocket& getSocket();
    void connectToServer();

private:
    sf::UdpSocket m_socket;
    std::string m_server_addr;
    int m_server_port;
    int client_port;
};


#endif //UDPCLIENT_HPP
