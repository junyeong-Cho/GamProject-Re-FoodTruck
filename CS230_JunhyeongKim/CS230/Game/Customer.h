/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Customer.h
Project:    CS230 Engine
Author:     Junhyeong Kim
Created:    March 2, 2023
*/

#pragma once
#include "..\Engine\GameObject.h"
#include "Button.h"

class Customor : public CS230::GameObject
{
public:
    Customor(Customor* front);

    virtual void Update(double dt) override;
    void Draw(Math::TransformationMatrix camera_matrix) override;
    const bool Get_can_order() const { return can_order; }
    virtual std::string Order_text() { return "hello!"; }
    virtual std::string Grade_bad_text() { return "hello!"; }
    virtual std::string Grade_soso_text() { return "hello!"; }
    virtual std::string Grade_good_text() { return "hello!"; }

private:
    void update_x_velocity(double dt);

    //state Waiting
    class State_Waiting : public State
    {
    public:
        virtual void Enter(GameObject*) override;
        virtual void Update(GameObject*, double dt) override;
        virtual void CheckExit(GameObject*) override;
        std::string GetName() override { return "Waiting"; }
    };
    State_Waiting state_waiting;

    //state Order
    class State_Order : public State
    {
    public:
        virtual void Enter(GameObject*) override;
        virtual void Update(GameObject*, double dt) override;
        virtual void CheckExit(GameObject*) override;
        std::string GetName() override { return "Order"; }
    };
    State_Order state_order;

    //state Food waiting
    class State_Fwaiting : public State
    {
    public:
        virtual void Enter(GameObject*) override;
        virtual void Update(GameObject*, double dt) override;
        virtual void CheckExit(GameObject*) override;
        std::string GetName() override { return "Fwaiting"; }
    };
    State_Fwaiting state_fwaiting;

    //state Evaluate
    class State_Evaluate : public State
    {
    public:
        virtual void Enter(GameObject*) override;
        virtual void Update(GameObject*, double dt) override;
        virtual void CheckExit(GameObject*) override;
        std::string GetName() override { return "Evaluate"; }
    };
    State_Evaluate state_evaluate;



    //state Leaving
    class State_Leaving : public State
    {
    public:
        virtual void Enter(GameObject*) override;
        virtual void Update(GameObject*, double dt) override;
        virtual void CheckExit(GameObject*) override;
        std::string GetName() override { return "Leaving"; }
    };
    State_Leaving state_leaving;


    Customor* front_customor = nullptr;
    Customor* first_ticket = nullptr;

    //Button
    Button Yes;
    Button No;
    Button evalue;

    double button_timer{ 0 };
    //앞으로 왔을 때
    bool can_order = false;
    //number ticket
    unsigned int number_ticket = 1;
    //음식 받음
    bool get_food = false;
    //evaluating
    bool evaluating = false;
    unsigned int grade = 0;

};