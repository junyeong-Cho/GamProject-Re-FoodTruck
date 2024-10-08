/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  main.cpp
Project:    GAM150
Author:     Junyeong Cho, Junhyeong Kim, Yeaseul Lim
Created:    March 8, 2023
Updated:    June 13, 2023
*/

#include <iostream>

#include <SFML/Audio.hpp>

#include "Engine/Engine.h"

#include "Game/Splash.h"
#include "Game/MainMenu.h"
#include "Game/Counter.h"
#include "Game/Kitchen.h"
#include "Game/Ending.h"
#include "Game/Day_end.h"
#include "Game/Credit.h"
#include "Game/Tutorial.h"


int main() {
    try {
        Engine& engine = Engine::Instance();
        engine.Start("Re : Food Truck");

        Splash splash;
        engine.GetGameStateManager().AddGameState(splash);
        MainMenu mainmenu;
        engine.GetGameStateManager().AddGameState(mainmenu);
        Counter counter;
        engine.GetGameStateManager().AddGameState(counter);
        Kitchen kitchen;
        engine.GetGameStateManager().AddGameState(kitchen);
        Ending ending;
        engine.GetGameStateManager().AddGameState(ending);
        Day_end day_end;
        engine.GetGameStateManager().AddGameState(day_end);
        Credit credit;
        engine.GetGameStateManager().AddGameState(credit);
        Tutorial tutorial;
        engine.GetGameStateManager().AddGameState(tutorial);
        

        

        while (engine.HasGameEnded() == false) 
        {
            engine.Update();
        }


        engine.Stop();

        return 0;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << "\n";
        return -1;
    }
}

