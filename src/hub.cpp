#include "hub.hpp"
#include <iostream>
#include <thread>
#include <chrono>

void Hub::addDevice(std::shared_ptr<Device> dev)
{
    devices.push_back(dev);
}

// void Hub::removeDevice(std::string name)
// {
//     for(int i = 0; i < devices.size(); ++i)
//     {
//         if(devices[i] -> get_name() == name)
//         {
//             devices.erase(devices.begin() + i);
//             std::cout<<"Device "<<name<<" was removed!"<<std::endl;
//             return;
//         }
//     }
// }

void Hub::notify(std::string type, std::string name)
{
    if(type == "Temp")
    {
        for(size_t i = 0; i < devices.size(); ++i)
        {
           if(devices[i] -> get_name() == name && std::dynamic_pointer_cast<Conditioner>(devices[i]))
           {
                std::shared_ptr<Conditioner> con = std::dynamic_pointer_cast<Conditioner>(devices[i]);
                con -> set_temp_c();
                break;
           }
        }
        for(size_t i = 0; i < devices.size(); ++i)
        {
            if(devices[i] -> get_name() == name && std::dynamic_pointer_cast<Thermostat>(devices[i]))
            {
                std::shared_ptr<Thermostat> term = std::dynamic_pointer_cast<Thermostat>(devices[i]);
                term -> set_temp(18.0);
                break;
            }
        }
    }
    else if(type == "MS")
    {
        for(size_t i = 0; i < devices.size(); ++i)
        {
            if(devices[i] -> get_name() == name && std::dynamic_pointer_cast<Light>(devices[i]))
            {
                std::shared_ptr<Light> l = std::dynamic_pointer_cast<Light>(devices[i]);
                if(l -> get_turn())
                {
                    std::cout<<"Light is already turned on!"<<std::endl;
                }
                else
                {
                    l -> turn_on();
                    std::this_thread::sleep_for(std::chrono::seconds(4));
                    l -> turn_off();
                }
                break;
            }
        }
    }
    else if(type == "DL")
    {
        for(size_t i = 0; i < devices.size(); ++i)
        {
            if(devices[i] -> get_name() == name && std::dynamic_pointer_cast<DoorLock>(devices[i]))
            {
                std::shared_ptr<DoorLock> dl = std::dynamic_pointer_cast<DoorLock>(devices[i]);
                if(dl -> is_open())
                {
                    std::this_thread::sleep_for(std::chrono::seconds(5));
                    dl -> close();
                }
                else
                {
                    std::cout<<"The door is already closed!!"<<std::endl;
                }
            }
        }
    }
    else
    {
        std::cout<<"Wrong notification!!"<<std::endl;
    }
}

// void Hub::removeDevice(std::string name)
// {
//     for(int i = 0; i < devices.size(); ++i)
//     {
//         if(devices[i] -> get_name() == name)
//         {
//             devices.erase(devices.begin() + i);
//             --i;
//         }
//     }
// }