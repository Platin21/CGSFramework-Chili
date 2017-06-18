#pragma once
#include <iostream>
#include "Controller.hpp"

namespace CGS
{
    class Game : public Controller
    {
    public:
        void Draw();
        void Update();
        void Transform();
    };
}

