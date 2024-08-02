#ifndef TCPPROTOCOL_H
#define TCPPROTOCOL_H

#include "Protocol.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>

#pragma comment(lib, "Ws2_32.lib")

class TCPProtocol : public Protocol {
private:
    SOCKET sock;
    sockaddr_in serverAddr;

public:
    TCPProtocol();
    ~TCPProtocol();
    bool connect(const std::string& ip, int port) override;
    bool disconnect() override;
    bool readData(std::string& data) override;
    bool writeData(const std::string& data) override;
};

#endif // TCPPROTOCOL_H
