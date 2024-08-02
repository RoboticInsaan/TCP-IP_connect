#include "Device.h"
#include "DeviceManager.h"
#include "TCPProtocol.h"
#include <iostream>

int main() {
    TCPProtocol tcpProtocol;
    Device device1(&tcpProtocol);
    Device device2(new TCPProtocol()); // Creating another device with TCP protocol

    DeviceManager manager;
    manager.addDevice(&device1);
    manager.addDevice(&device2);

    if (manager.connectDevices()) {
        std::string data;
        if (device1.readData(data)) {
            std::cout << "Device 1 read data: " << data << std::endl;
        }
        if (device2.writeData("Hello from device 2")) {
            std::cout << "Device 2 wrote data successfully." << std::endl;
        }
    }

    manager.disconnectDevices();

    return 0;
}
