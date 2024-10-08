/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Counter.h
Project:    Gam150
Author:     Junhyeong Kim
Created:    April 30, 2023
*/


#include "../Engine/GameObjectManager.h"
#include "../Engine/ComponentManager.h"
#include "../Engine/GameObject.h"
#include "../Engine/GameState.h"
#include "../Engine/Texture.h"
#include "../Engine/Sprite.h"

#include "Counter_Background.h"
#include "Reputation.h"
#include "Button.h"
#include "Frame.h"
#include "Sound.h"


class Customor;

class Counter : public CS230::GameState
{
public:


    Counter();
    void Load() override;
    void Update(double dt) override;
    void Draw() override;
    void Unload() override;
    void Clear();
    void Draw_UI();
    void DrawFood();

    std::string GetName() override { return "Counter"; }
private:

    //Draw frames
    CS230::GameObjectManager gameobjectmanager;

    Reputation* refutation;

    Customor* front_customor = nullptr;
    Button yes_button;
    Counter_Background counter_Screen;
    Counter_Background background;
    int customors = 30;
    std::vector<CS230::Texture*> foodTexture;

    int ranCustomerNum;
    int kind_customer = 9;
};