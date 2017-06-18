//
//  OCPP_Game.mm
//  Window
//
//  Created by Armin Hamar on 18.06.17.
//  Copyright © 2017 ProjektBlue. All rights reserved.
//

#import "OCPP_Game.h"
#import "Game.hpp"
#import "Input.hpp"

@implementation CPP_CGSGame
//[ Instance Varibales
{
    CGS::Game* game;
};
//] Instance Varibales

- (id)init
{
    self = [super init];
    if( self )
    {
        game = new CGS::Game();
    }
    return self;
}

- (void)CPP_Draw
{
    self->game->Draw();
}


- (void) CPP_Update
{
    self->game->Update();
}


- (void) CPP_Transform
{
    self->game->Transform();
}

- (void) CPP_AddKeyEvent:(long)key State:(CGS::Char)state
{
    switch (state)
    {
        case 1:
            self->game->keyboard.addEvent(key, CGS::Keyboard::Event::Type::Released);
            break;
        case 2:
            self->game->keyboard.addEvent(key, CGS::Keyboard::Event::Type::Pressed);
            break;
        default:
            self->game->keyboard.addEvent(key, CGS::Keyboard::Event::Type::Error);
            break;
    }
};

- (void) CPP_AddMouseEvent:(long)y
                 xPosition:(long)x
                     State:(unsigned char)state

{
    switch (state) {
        case 0:
            self->game->mouse.addEvent(y,x, CGS::Mouse::Event::Type::Error,false);
            break;
        case 1:
            self->game->mouse.addEvent(y,x, CGS::Mouse::Event::Type::Moved,false);
            break;
        case 2:
            self->game->mouse.addEvent(y,x,CGS::Mouse::Event::Type::Pressed_ScrollWheel,false);
            break;
        case 3:
            self->game->mouse.addEvent(y,x,CGS::Mouse::Event::Type::Pressed_RightButton,false);
            break;
        case 4:
            self->game->mouse.addEvent(y,x,CGS::Mouse::Event::Type::Pressed_LeftButton,false);
            break;
        case 5:
            self->game->mouse.addEvent(y,x,CGS::Mouse::Event::Type::Rleased_ScrollWheel,false);
            break;
        case 6:
            self->game->mouse.addEvent(y,x,CGS::Mouse::Event::Type::Rleased_RightButton,false);
            break;
        case 7:
            self->game->mouse.addEvent(y,x,CGS::Mouse::Event::Type::Rleased_LeftButton,false);
            break;
        default:
            self->game->mouse.addEvent(y,x,CGS::Mouse::Event::Type::Error,false);
            break;
    }
};

- (void) dealloc
{
    delete game;
}

@end
