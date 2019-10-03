#include "udpClient.hpp"


UdpClient::UdpClient(std::string server_addr, int server_port)
                                            :m_server_addr(server_addr),
                                             m_server_port(server_port)
{
    m_socket.bind(sf::Socket::AnyPort);
    m_socket.setBlocking(false);
}

void UdpClient::send(sf::Packet & packet)
{
    m_socket.send(packet,m_server_addr,m_server_port);
}

void UdpClient::sendInput(std::string input)
{
    sf::Packet packet;
    sf::Uint16 code(10);
    packet << code;
    packet << input;
    this->send(packet);
}

sf::UdpSocket& UdpClient::getSocket()
{
    return m_socket;
}

void UdpClient::connectToServer()
{
    sf::Packet packet;
    sf::Uint16 code(1);
    packet << code;
    send(packet);
}
