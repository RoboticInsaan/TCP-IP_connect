#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Device.h"
#include "DeviceManager.h"
#include "TestStub.h" // You can create a TestStub protocol for testing purposes

TEST_CASE("Device Communication Test", "[device]") {
    TestStub testProtocol;
    Device device(&testProtocol);

    REQUIRE(device.connect("127.0.0.1", 8080) == true);

    std::string testData = "Test Data";
    REQUIRE(device.writeData(testData) == true);

    std::string receivedData;
    REQUIRE(device.readData(receivedData) == true);
    REQUIRE(receivedData == "Response");

    REQUIRE(device.disconnect() == true);
}

TEST_CASE("Device Manager Test", "[manager]") {
    TestStub testProtocol1, testProtocol2;
    Device device1(&testProtocol1), device2(&testProtocol2);

    DeviceManager manager;
    manager.addDevice(&device1);
    manager.addDevice(&device2);

    REQUIRE(manager.connectDevices() == true);

    std::string data;
    REQUIRE(device1.readData(data) == true);
    REQUIRE(data == "Response");

    REQUIRE(device2.writeData("Hello from device 2") == true);

    manager.disconnectDevices();
}
