//
//  main.swift
//  Window
//
//  Created by Armin Hamar on 20.02.17.
//  Copyright © 2017 ProjektBlue. All rights reserved.
//

//import AppKit


func main()
{
    let game:CPP_CGSGame = CPP_CGSGame();
    
    while(true)
    {
        game.cpp_Update()
        game.cpp_Transform()
        game.cpp_Draw()
    }
    
}

main();
