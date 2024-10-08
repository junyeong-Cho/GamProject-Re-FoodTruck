/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  GameObject.h
Project:    GAM150
Author:     Jonathan Holmes
Created:    March 8, 2023
*/

#pragma once

#include "ComponentManager.h"
#include "Sprite.h"


namespace Math { class TransformationMatrix; }



enum class GameObjectTypes;


namespace CS230 
{
    
    class Component;
    

    class GameObject 
    {
    public:
        GameObject(Math::vec2 position);
        GameObject(Math::vec2 position, double rotation, Math::vec2 scale);
        virtual ~GameObject() {}

        virtual void Update(double dt);
        virtual void Draw(Math::TransformationMatrix camera_matrix);

        const Math::TransformationMatrix& GetMatrix();
        const Math::vec2& GetPosition() const;
        const Math::vec2& GetVelocity() const;
        const Math::vec2& GetScale() const;
        double GetRotation() const;

        std::string Get_State_Name()
        {
            return current_state->GetName();
        }


        void SetPosition(Math::vec2 new_position);

        template<typename T>
        T* GetGOComponent() {
            return componentmanagers.GetComponent<T>();
        }



    protected:
        //void SetPosition(Math::vec2 new_position);
        void UpdatePosition(Math::vec2 delta);

        void SetVelocity(Math::vec2 new_position);
        void UpdateVelocity(Math::vec2 delta);

        void SetScale(Math::vec2 new_scale);
        void UpdateScale(Math::vec2 delta);

        void SetRotation(double new_rotation);
        void UpdateRotation(double delta);


        void AddGOComponent(Component* component)
        {
            componentmanagers.AddComponent(component);
        }

        template<typename T>
        void RemoveGOComponent()
        {
            componentmanagers.RemoveComponent<T>();
        }
        void ClearGOComponents()
        {
            componentmanagers.Clear();
        }
        void UpdateGOComponents(double dt)
        {
            componentmanagers.UpdateAll(dt);
        }



        Sprite sprite;
        
        //State
        class State
        {
        public:
            virtual void Enter(GameObject* object) = 0;
            virtual void Update(GameObject* object, double dt) = 0;
            virtual void CheckExit(GameObject* object) = 0;
            virtual std::string GetName() = 0;
        };
        State* prev_state = &state_none;

        //State_None
        class State_None : public State {
        public:
            void Enter(GameObject*) override {}
            void Update(GameObject*, double) override {}
            void CheckExit(GameObject*) override {}
            std::string GetName() { return ""; }
        };
        State_None state_none;
        State* current_state = &state_none;

        void change_state(State* new_state);


    private:
        Math::TransformationMatrix object_matrix;


        bool matrix_outdated = true;

        double rotation;
        Math::vec2 scale;
        Math::vec2 position;
        Math::vec2 velocity;


        ComponentManager componentmanagers;
    };
}
