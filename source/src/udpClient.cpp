#include "udpClient.hpp"


UdpClient::UdpClient(std::string server_addr, int server_port)
                                            :m_server_addr(server_addr),
                                             m_server_port(server_port)
{
    m_socket.bind(5001);
    m_socket.setBlocking(false);
}

void UdpClient::send(sf::Packet & packet)
{
    m_socket.send(packet,m_server_addr,m_server_port);
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
