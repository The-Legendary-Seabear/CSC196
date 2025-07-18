
#include "Math/Math.h"
#include "Math/Vector2.h"
#include "Core/Random.h"
#include "Core/Time.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include "Math/Vector3.h"
#include "Renderer/Model.h"
#include "Math/Transform.h"
#include "Game/Actor.h"
#include "Game/Scene.h"

#include "Game/Player.h"

#include <SDL3/SDL.h>
#include <iostream>
#include <Renderer/Renderer.h>
#include <vector>
#include <fmod.hpp>
#include <memory>



int main(int argc, char* argv[]) {

    

    //initialize engine systems
    viper::Time time;

    std::unique_ptr<viper::Renderer> renderer = std::make_unique<viper::Renderer>();
    renderer->Initialize();
    renderer->CreateWindow("Viper Engine", 1280, 1024);

    std::unique_ptr<viper::InputSystem> input = std::make_unique<viper::InputSystem>();
	input->Initialize();

    //create audio system
    std::unique_ptr<viper::AudioSystem> audio = std::make_unique<viper::AudioSystem>();
    audio->Inititalize();

   


    //create objects
    std::vector<viper::vec2> points{
        /*{-5, -5},
        {5, -5},
        {5, 5 },
        {-5, 5},
        {-5, -5},*/
        {4, 0},
        {0, 10},
        {3, 7},
		{6, 4},
		{9, 0},
		{6, -4},
        {3, -7},
        {0, -10},
        {4, 0},
    };

    std::shared_ptr<viper::Model> model = std::make_shared <viper::Model>(points, viper::vec3{ 0, 0, 1 });
    

    viper::Scene scene;

    /*
    for (int i = 0; i < 10; i ++) {
    viper::Transform transform{ viper::vec2{viper::random::getRandomFloat() * 1280, viper::random::getRandomFloat() * 1040}, 0, 20};
    std::unique_ptr<Player> player = std::make_unique<Player>( transform, model );
    scene.AddActor(std::move(player));
    }
    */

    viper::Transform transform{ viper::vec2{640, 520}, 0, 20 };
    std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
    scene.AddActor(std::move(player));



    
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
        time.Tick();
        //audio->update();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        if (input->GetKeyPressed(SDL_SCANCODE_ESCAPE)) quit = true;


        //update engine systems
        audio->Update();
		input->Update();

        //play drum sounds
        

        viper::vec2 direction{ 0, 0 };
        if (input->GetKeyDown(SDL_SCANCODE_W)) direction.y -= 100;
        if (input->GetKeyDown(SDL_SCANCODE_S)) direction.y += 100;
        if (input->GetKeyDown(SDL_SCANCODE_A)) direction.x -= 100;
        if (input->GetKeyDown(SDL_SCANCODE_D)) direction.x += 100;
        
        if (direction.LengthSqr() < 0) { 
        direction = direction.Normalized();
      
        }
        

        //get input 
       

        

        //draw
        viper::vec3 color{ 0, 0, 0 };

        renderer->SetColor((float)color.r, (float)color.g, (float)color.b);
        renderer->Clear();

		//model.Draw(renderer, input.GetMousePosition(), time.GetTime(), 10);
        
        
        scene.Draw(*renderer);

        renderer->Present();

}

    
    renderer->Shutdown();
	audio->Shutdown();

    return 0;
}
