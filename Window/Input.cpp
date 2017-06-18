//  Input.cpp
#include "Input.hpp"

using namespace CGS;

void Keyboard::addEvent(Int32 keyCode,Event::Type type)
{
    if(type == Event::Type::Pressed)
    {
        keystate.set(keyCode);
    }
    else if(type == Event::Type::Released)
    {
        keystate.reset(keyCode);
    }
    keyQueue.push(Event(type,keyCode));
};

Bool Keyboard::isEmpty()
{
    if(keyQueue.size() != 0)
    {
        return true;
    }
    return false;
}

Keyboard::Event Keyboard::Read()
{
    if(keyQueue.size() != 0)
    {
        Keyboard::Event e = keyQueue.front();
        keyQueue.pop();
        return e;
    }
    
    return Keyboard::Event();
}

void Mouse::addEvent(Int64 y, Int64 x,Mouse::Event::Type type,Bool inWindow)
{
    PointQueue.push(Mouse::Event(y,x,type,inWindow));
}

Bool Mouse::isEmpty()
{
    if(PointQueue.size() != 0)
    {
        return true;
    }
    return false;
}

Bool Mouse::LeftIsPressed()
{
    return PointQueue.front().IsLeftButtonPressed();
};

Bool Mouse::RightIsPressed()
{
    return PointQueue.front().IsRightButtonPressed();
};

Bool Mouse::ScrollIsPressed()
{
    return PointQueue.front().IsScrollWheelPressed();
};

Bool Mouse::isInWindow()
{
    return PointQueue.front().IsInWindow();
};

Mouse::Event Mouse::Read()
{
    if(PointQueue.size() != 0)
    {
        Mouse::Event e = PointQueue.front();
        PointQueue.pop();
        return e;
    }
    
    return Mouse::Event();
}

