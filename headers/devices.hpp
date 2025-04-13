#ifndef DEVICES
#define DEVICES
#include <string>
#include "hub.hpp"

class Hub;

class Device
{
    protected:
    Hub* hub;
    std::string name;
    public:
    Device(Hub* hub, std::string name) : hub(hub),name(name){};
    virtual void sendMessage() = 0;
    std::string get_name();
    virtual ~Device(){};
};

class Light : public Device
{
    bool turn;
    public:
    Light(Hub* hub, std::string name) : Device(hub,name),turn(false){};
    void sendMessage() override;
    void turn_on();
    void turn_off();
    bool get_turn() const;
};

class Thermostat : public Device
{
    float temperature;
    public:
    Thermostat(Hub* hub, std::string name) : Device(hub,name),temperature(0){};
    float get_temp_c() const;
    float get_temp_f() const;
    void set_temp(float);
    void sendMessage() override;
};

class DoorLock : public Device
{
    bool open;
    public:
    DoorLock(Hub* hub, std::string name):Device(hub,name),open(false){};
    void dopen();
    void close();
    void sendMessage() override;
    bool is_open();
};

class MotionSensor : public Device
{
    public:
    MotionSensor(Hub* hub, std::string name) : Device(hub,name){};
    void move();
    void sendMessage() override;
};

class Conditioner : public Device
{
    public:
    Conditioner(Hub* hub, std::string name) : Device(hub,name){};
    void set_temp_c();
    void sendMessage() override;
};

class createDevice
{
    public:
    virtual std::shared_ptr<Device> factoryDevice(Hub* hub, std::string name) = 0;
};

class createLight : public createDevice
{
    public:
    std::shared_ptr<Device> factoryDevice(Hub* hub, std::string name) override;
};

class createThermostat : public createDevice
{
    public:
    std::shared_ptr<Device> factoryDevice(Hub* hub, std::string name) override;
};

class createDoorLock : public createDevice
{
    public:
    std::shared_ptr<Device> factoryDevice(Hub* hub, std::string name) override;
};

class createMotionSensor : public createDevice
{
    public:
    std::shared_ptr<Device> factoryDevice(Hub* hub, std::string name) override;
};

class createConditioner : public createDevice
{
    public:
    std::shared_ptr<Device> factoryDevice(Hub* hub, std::string name) override;
};

#endif