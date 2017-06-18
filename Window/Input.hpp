//  Input.hpp
#pragma once
#include "Types.hpp"
#include <queue>
#include <bitset>

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
                Error
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
            
            Bool IsInvalid() const
            {
                return type == Type::Error;
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
                type = Type::Error;
                code = 255;
            }
        };
    private:
        std::queue<Event>keyQueue;
        std::bitset<265>keystate;
    public:
        Keyboard() = default;
        void addEvent(Int32 keyCode,Event::Type type);
        
        Bool isEmpty();
        Bool KeyIsPressed(Int32 keyCode);
        Event Read();
    };
    
    class Mouse
    {
    public:
        class Event
        {
        public:
            enum class Type : Int8
            {
                Pressed_LeftButton,
                Pressed_RightButton,
                Pressed_ScrollWheel,
                
                Rleased_LeftButton,
                Rleased_RightButton,
                Rleased_ScrollWheel,
                Moved,
                
                Error
            };
        private:
            Int64 x,y;
            Type type;
            Bool inWindow;
        public:
            
            Event(Int64 x,Int64 y,Type type,Bool inWindow)
            {
                this->x = x;
                this->y = y;
                this->type = type;
                this->inWindow = inWindow;
            }
            
            Bool IsLeftButtonPressed() const
            {
                return type == Type::Pressed_LeftButton;
            }
            Bool IsRightButtonPressed() const
            {
                return type == Type::Pressed_RightButton;
            };
            
            Bool IsScrollWheelPressed() const
            {
                return type == Type::Pressed_ScrollWheel;
            }
            
            Bool IsScrollWheelReleased() const
            {
                return type == Type::Rleased_ScrollWheel;
            }
            
            Bool IsLeftButtonReleased() const
            {
                return type == Type::Rleased_LeftButton;
            }
            Bool IsRightButtonReleased() const
            {
                return type == Type::Rleased_RightButton;
            };
            
            Bool IsInWindow() const
            {
                return inWindow;
            }
            
            Int64 getPosX()
            {
                return x;
            };
            
            Int64 getPosY()
            {
                return y;
            };
        };
    private:
        std::queue<Event>PointQueue;
    public:
        Mouse() = default;
        void addEvent(Int64 y,Int64 x,Event::Type type,Bool inWindow);
        
        Bool isEmpty();
        Bool LeftIsPressed();
        Bool RightIsPressed();
        Bool ScrollIsPressed();
        Bool isInWindow();
        
        Event Read();
    };
    
}

