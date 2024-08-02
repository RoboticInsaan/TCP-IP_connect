#include "DeviceManager.h"

DeviceManager::~DeviceManager() {
    for (Device* device : devices) {
        delete device;
    }
}

void DeviceManager::addDevice(Device* device) {
    devices.push_back(device);
}

void DeviceManager::removeDevice(Device* device) {
    devices.erase(std::remove(devices.begin(), devices.end(), device), devices.end());
}

bool DeviceManager::connectDevices() {
    bool allConnected = true;
    for (Device* device : devices) {
        if (!device->connect("127.0.0.1", 8080)) {
            allConnected = false;
            break;
        }
    }
    return allConnected;
}

void DeviceManager::disconnectDevices() {
    for (Device* device : devices) {
        device->disconnect();
    }
}
