#ifndef DEVICE_H
#define DEVICE_H

#include "Protocol.h"
#include <string>

class Device {
private:
    Protocol* protocol;

public:
    Device(Protocol* protocol);
    ~Device();
    bool connect(const std::string& ip, int port);
    bool disconnect();
    bool readData(std::string& data);
    bool writeData(const std::string& data);
};

#endif // DEVICE_H
