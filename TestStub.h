#ifndef TESTSTUB_H
#define TESTSTUB_H

#include "Protocol.h"

class TestStub : public Protocol {
public:
    bool connect(const std::string& ip, int port) override;
    bool disconnect() override;
    bool readData(std::string& data) override;
    bool writeData(const std::string& data) override;
};

#endif // TESTSTUB_H
