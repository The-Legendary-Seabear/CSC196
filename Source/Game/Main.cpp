
#include "Math/Math.h"
#include "Math/Vector2.h"
#include "Core/Random.h"
#include "Core/Time.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include "Math/Vector3.h"
#include "Renderer/Model.h"
#include "Math/Transform.h"
#include "Framework/Actor.h"
#include "Framework/Scene.h"
#include "Engine.h"

#include "Game/Player.h"
#include "Game/SpaceGame.h"

#include <SDL3/SDL.h>
#include <iostream>
#include <Renderer/Renderer.h>
#include <vector>
#include <fmod.hpp>
#include <memory>



int main(int argc, char* argv[]) {

   //initialize engine
    viper::GetEngine().Initialize();

    //Initialize Game
    std::unique_ptr<SpaceGame> game = std::make_unique<SpaceGame>();
    game->Initialize();

    //create objects



    
    FMOD::Sound* sound = nullptr;
    
    std::vector<FMOD::Sound*> sounds;
   

    //create stars
    /*std::vector<viper::vec2> stars;
    for (int i = 0; i < 100; i++) {
        stars.push_back(viper::vec2{ viper::random::getRandomFloat() * 1280, viper::random::getRandomFloat() * 1280 });
    }*/


    SDL_Event e;
    bool quit = false;

    //std::vector<viper::vec2> points;

    //Main Loop
    while (!quit) {
        
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        viper::GetEngine().Update();
        scene.Update(viper::GetEngine().GetTime().GetDeltaTime());

		scene.Draw(viper::GetEngine().GetRenderer());

        if (viper::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_ESCAPE)) quit = true;
        

        
      
        
        

        //get input 
       

        

        //draw
        viper::vec3 color{ 0, 0, 0 };

        viper::GetEngine().GetRenderer().SetColor((float)color.r, (float)color.g, (float)color.b);
        viper::GetEngine().GetRenderer().Clear();

		//model.Draw(renderer, input.GetMousePosition(), time.GetTime(), 10);
        
        
        scene.Draw(viper::GetEngine().GetRenderer());

        viper::GetEngine().GetRenderer().Present();

}

    viper::GetEngine().Shutdown();

    return 0;
}
