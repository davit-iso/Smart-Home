#include <gtest/gtest.h>
#include "devices.hpp"
#include <iostream>
#include "hub.hpp"
// #include <thread>
// #include <chrono>

TEST(LightTest, TurnOnOff) {
    Hub hub("name");
    Light light(&hub, "Living Room");

    light.turn_on();
    EXPECT_TRUE(light.get_turn());

    light.turn_off();
    EXPECT_FALSE(light.get_turn());
}

TEST(MotionTest, Move) {
    Hub hub("name");
    std::shared_ptr<MotionSensor> tmp = std::make_shared<MotionSensor>(&hub,"room");
    std::shared_ptr<Light> l = std::make_shared<Light>(&hub,"room");

    hub.addDevice(tmp);
    hub.addDevice(l);

    tmp -> move();
    EXPECT_FALSE(l -> get_turn());
}