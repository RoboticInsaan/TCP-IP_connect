#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <string>

class Protocol {
public:
    virtual ~Protocol() {}
    virtual bool connect(const std::string& ip, int port) = 0;
    virtual bool disconnect() = 0;
    virtual bool readData(std::string& data) = 0;
    virtual bool writeData(const std::string& data) = 0;
};

#endif // PROTOCOL_H
