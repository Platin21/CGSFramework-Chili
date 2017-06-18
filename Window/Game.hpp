#pragma once
#include <iostream>
#include "Input.hpp"

namespace CGS
{
    class Game
    {
    public:
        Keyboard keyboard;
        Mouse mouse;
    public:
        void Draw();
        void Update();
        void Transform();
    };
}

