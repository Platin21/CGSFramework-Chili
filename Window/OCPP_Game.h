//
//  OCPP_Game.h
//  Window
//
//  Created by Armin Hamar on 18.06.17.
//  Copyright © 2017 ProjektBlue. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Game.hpp"

@interface Game_OBJCPP : NSObject;

    + (void) CPP_Draw;
    + (void) CPP_Update;
    + (void) CPP_Transform;
@end
