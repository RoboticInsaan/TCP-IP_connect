#include "TestStub.h"

bool TestStub::connect(const std::string& ip, int port) {
    return true;
}

bool TestStub::disconnect() {
    return true;
}

bool TestStub::readData(std::string& data) {
    data = "Test data";
    return true;
}

bool TestStub::writeData(const std::string& data) {
    return true;
}
