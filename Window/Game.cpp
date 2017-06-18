#include "Game.hpp"
using namespace CGS;


void Game::Draw()
{
    std::cout << "Draw" << std::endl;
}

void Game::Update()
{
    Mouse::Event e = mouse.Read();
    if(!e.IsInvalid())
    {
        std::cout << "Update\n\t"
                  << e.IsInWindow()
                  << " PosX:"
                  << e.getPosX()
        << std::endl;
    }
}
void Game::Transform()
{
    std::cout << "Transform" << std::endl;
}
