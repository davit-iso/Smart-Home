#include "devices.hpp"
#include <iostream>
#include <thread>
#include <chrono>

//--------------Device
std::string Device::get_name()
{
    return name;
}

//--------------Light
void Light::turn_off()
{
    std::cout<<"Light is turned off - "<<name<<"!"<<std::endl;
    turn = false;
}

void Light::turn_on()
{
    turn = true;
    std::cout<<"Light is turned on - "<<name<<"!"<<std::endl;
}

void Light::sendMessage()
{
    hub -> notify("Light", name);
}

bool Light::get_turn() const
{
    return turn;
}

//--------------Thermostat
float Thermostat::get_temp_c() const
{
    return temperature;
}

float Thermostat::get_temp_f() const
{
    return (temperature*9/5)+32;
}

void Thermostat::set_temp(float f)
{
    temperature = f;
    //std::cout<<"Temperature was changed without conditioner\n"  ;
    if(f < 15.0 || f > 25.0)
    {
        std::cout<<"Degree is out of norm"<<std::endl;
        sendMessage();
        std::cout<<"Temperature is - "<<temperature<<std::endl;
    }
}

void Thermostat::sendMessage()
{
    hub -> notify("Temp", name);
}

//-----------------DoorLock
void DoorLock::sendMessage()
{
    hub -> notify("DL", name);
}

void DoorLock::dopen()
{
    open = true;
}

void DoorLock::close()
{
    open = false;
    sendMessage();
}

bool DoorLock::is_open()
{
    return open;
}

//-----------------MotionSensor
void MotionSensor::sendMessage()
{
    hub -> notify("MS", name);
}

void MotionSensor::move()
{
    std::cout<<"Movement is detected - "<<name<<std::endl;
    sendMessage();
}

//-------------------Conditioner
void Conditioner::set_temp_c()
{
    std::cout<<"Conditioner is working - "<<name<<"!"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout<<"The air conditioner has finished its work - "<<name<<"!!"<<std::endl;
}

void Conditioner::sendMessage()
{

}

//--------------------Factory Methods
std::shared_ptr<Device> createLight::factoryDevice(Hub* hub, std::string name)
{
    return std::make_shared<Light>(hub,name);
}

std::shared_ptr<Device> createThermostat::factoryDevice(Hub* hub, std::string name)
{
    return std::make_shared<Thermostat>(hub,name);
}

std::shared_ptr<Device> createDoorLock::factoryDevice(Hub* hub, std::string name)
{
    return std::make_shared<DoorLock>(hub,name);
}

std::shared_ptr<Device> createMotionSensor::factoryDevice(Hub* hub, std::string name)
{
    return std::make_shared<MotionSensor>(hub,name);
}

std::shared_ptr<Device> createConditioner::factoryDevice(Hub* hub, std::string name)
{
    return std::make_shared<Conditioner>(hub,name);
}