#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include "Device.h"
#include <vector>

class DeviceManager {
private:
    std::vector<Device*> devices;

public:
    ~DeviceManager();
    void addDevice(Device* device);
    void removeDevice(Device* device);
    bool connectDevices();
    void disconnectDevices();
};

#endif // DEVICEMANAGER_H
