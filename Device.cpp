#include "Device.h"

Device::Device(Protocol* protocol) : protocol(protocol) {}

Device::~Device() {
    delete protocol;
}

bool Device::connect(const std::string& ip, int port) {
    return protocol->connect(ip, port);
}

bool Device::disconnect() {
    return protocol->disconnect();
}

bool Device::readData(std::string& data) {
    return protocol->readData(data);
}

bool Device::writeData(const std::string& data) {
    return protocol->writeData(data);
}
