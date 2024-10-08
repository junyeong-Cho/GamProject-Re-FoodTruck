/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Anteater.cpp
Project:    GAM150
Author:     Junyeong Cho
Created:    May 24, 2023
*/

#include "Anteater.h"

Anteater::Anteater(Customor* front)
	:Customor(front)
{
	sprite.Load("Assets/Characters/Anteater.spt");
	Set_Oreder_recipe(RecipeName::AntSalad);
}