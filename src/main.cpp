#include <iostream>
#include <string>
#include "hub.hpp"
#include "vector"
#include <memory>
#include "devices.hpp"

class Hub;

int main()
{
    Hub* hub = new Hub("SmartHome_1");
    std::shared_ptr<Device> light = std::make_shared<createLight>() -> factoryDevice(hub,"kitchen");
    std::shared_ptr<Device> door = std::make_shared<createDoorLock>() -> factoryDevice(hub,"kitchen");
    std::shared_ptr<Device> con = std::make_shared<createConditioner>() -> factoryDevice(hub,"kitchen");
    std::shared_ptr<Device> term = std::make_shared<createThermostat>() -> factoryDevice(hub,"kitchen");
    std::shared_ptr<Device> mots = std::make_shared<createMotionSensor>() -> factoryDevice(hub,"kitchen");

    hub -> addDevice(light);
    hub -> addDevice(door);
    hub -> addDevice(term);
    hub -> addDevice(con);
    hub -> addDevice(mots);

    std::dynamic_pointer_cast<MotionSensor>(mots) -> move();
    std::dynamic_pointer_cast<Thermostat>(term) -> set_temp(27.8);
    delete hub;
    return 0;
}