//  Input.hpp
#pragma once
#include "Types.hpp"
#include <queue>

namespace CGS
{
    class Keyboard
    {
    public:
        class Event
        {
        public:
            enum class Type : Int8
            {
                Pressed,
                Released,
            };
        private:
            Type type;
            Char code;
        public:
            Bool IsReleased() const
            {
                return type == Type::Released;
            }
            
            Bool IsPressed() const
            {
                return type == Type::Pressed;
            }
            
            Char GetCode() const
            {
                return code;
            }
            
            Event(Type typ,Char keyCode)
            {
                type = typ;
                code = keyCode;
            }
            
            Event()
            {
                type = Type::Pressed;
                code = 255;
            }
        };
        
        std::queue<Event>keyQueue;
    public:
        void addEvent(Int32 keyCode,Bool relased,Bool pressed);
    };
    
    class Mouse
    {
    public:
        struct Event
        {
            enum class Type : Int8
            {
                LeftButton,
                RightButton,
                ScrollWheel
            };
            Type type;
            Int64 x,y;
        };
    private:
        std::queue<Event>keyQueue;
    public:
        void addEvent(Int64 y,Int64 x,Bool LButton,Bool RButton);
        
    };
    
}

