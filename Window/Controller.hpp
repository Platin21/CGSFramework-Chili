//  Controller.hpp
#pragma once
#include "Input.hpp"

namespace CGS
{
    class Controller
    {
    private:
        Keyboard keyboard;
        Mouse mouse;
    public:
        void addEvent(Int32 keyCode,CGS::Keyboard::Event::Type type);
        void addEvent(Int64 y,Int64 x,CGS::Mouse::Event::Type type,Bool inWindow);
    }; 
}
