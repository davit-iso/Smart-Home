#ifndef HUB
#define HUB
#include <string>
#include "vector"
#include <memory>
#include "devices.hpp"

class Device;

class Hub
{
    std::string name;
    std::vector<std::shared_ptr<Device>> devices;
    public:
    Hub(std::string name):name(name){};
    void addDevice(std::shared_ptr<Device>);
    void removeDevice(std::string name);
    void notify(std::string, std::string);
    // void turn_on_light(Light*);
    // void turn_off_light(Light*);
    // void set_temp(Thermostat*);

};

#endif