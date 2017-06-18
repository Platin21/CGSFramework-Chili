//  Controller.cpp
#include "Controller.hpp"

using namespace CGS;

void Controller::addEvent(Int32 keyCode, Keyboard::Event::Type type)
{
    keyboard.addEvent(keyCode,type);
}

void Controller::addEvent(Int64 y,Int64 x,CGS::Mouse::Event::Type type,Bool inWindow)
{
    mouse.addEvent(y, x, type,inWindow);
};
