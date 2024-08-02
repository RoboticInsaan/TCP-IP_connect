#include "TCPProtocol.h"

TCPProtocol::TCPProtocol() : sock(INVALID_SOCKET) {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
}

TCPProtocol::~TCPProtocol() {
    WSACleanup();
}

bool TCPProtocol::connect(const std::string& ip, int port) {
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) {
        return false;
    }
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &serverAddr.sin_addr);
    return ::connect(sock, (sockaddr*)&serverAddr, sizeof(serverAddr)) != SOCKET_ERROR;
}

bool TCPProtocol::disconnect() {
    return closesocket(sock) != SOCKET_ERROR;
}

bool TCPProtocol::readData(std::string& data) {
    char buffer[512];
    int bytesReceived = recv(sock, buffer, sizeof(buffer), 0);
    if (bytesReceived > 0) {
        data.assign(buffer, bytesReceived);
        return true;
    }
    return false;
}

bool TCPProtocol::writeData(const std::string& data) {
    return send(sock, data.c_str(), data.length(), 0) != SOCKET_ERROR;
}
