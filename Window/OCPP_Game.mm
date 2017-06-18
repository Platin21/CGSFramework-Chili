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

- (void) CPP_AddKeyEvent:(long)key
                released:(bool)released
                 pressed:(bool)pressed
{
    self->game->addEvent(key,released,pressed);
};

- (void) CPP_AddMouseEvent:(long)y
                         _:(long)x
                         _:(bool)lbnt
                         _:(bool)rbnt
{
    self->game->addEvent(y,x,lbnt,rbnt);
};

- (void) dealloc
{
    delete game;
}

@end
