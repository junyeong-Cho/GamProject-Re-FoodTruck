/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Unload_manager.cpp
Project:    GAM150
Author:     Junhyeong Kim
Created:    March 8, 2023
*/

#include "Unload_manager.h"
#include "Engine.h"
namespace CS230
{


	void Unload_manager::Unload()
	{
		counter_ObjectManager.Unload();
		current_customor = nullptr;
		food_grad = 0;
	}

	void Unload_manager::Reset()
	{
		first_load = true;
		food_complete = false;
		money = 30;
		rate = 100;
		day = 1;
	
	}
}
