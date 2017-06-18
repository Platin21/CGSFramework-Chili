//
//  OCPP_Game.h
//  Window
//
//  Created by Armin Hamar on 18.06.17.
//  Copyright © 2017 ProjektBlue. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CPP_CGSGame : NSObject
- (void) CPP_Draw;
- (void) CPP_Update;
- (void) CPP_Transform;

- (void) CPP_AddKeyEvent:(long)key
                       released:(bool)released
                       pressed:(bool)pressed;

- (void) CPP_AddMouseEvent:(long)y
                         _:(long)x
                         _:(bool)lbnt
                         _:(bool)rbnt;
@end
