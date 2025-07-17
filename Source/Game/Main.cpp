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

#define NAME "Alex"

// if you want to you can use using namespace viper;

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

   /* FMOD::System* audio;
    FMOD::System_Create(&audio);

    void* extradriverdata = nullptr;
    audio->init(32, FMOD_INIT_NORMAL, extradriverdata);*/


    //create objects
    std::vector<viper::vec2> points{
        {-5, -5},
        {5, -5},
        {5, 5 },
        {-5, 5},
        {-5, -5},
    };

    std::shared_ptr<viper::Model> model = std::make_shared <viper::Model>(points, viper::vec3{ 0, 0, 1 });
    //viper::Model* model = new viper::Model{ points, {0, 0, 1} };

    viper::Scene scene;

    
    for (int i = 0; i < 10; i ++) {
    viper::Transform transform{ viper::vec2{viper::random::getRandomFloat() * 1280, viper::random::getRandomFloat() * 1040}, 0, 20};
    std::unique_ptr<Player> player = std::make_unique<Player>( transform, model );
    scene.AddActor(std::move(player));
    }



    
    FMOD::Sound* sound = nullptr;
    
    std::vector<FMOD::Sound*> sounds;
   /* audio->createSound("bass.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    audio->createSound("snare.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    audio->createSound("open-hat.wav", FMOD_DEFAULT, 0, &sound);
	sounds.push_back(sound);*/

    //initialize sounds
	//audio.AddSound("test.wav", "testSound");

    //create stars
    std::vector<viper::vec2> stars;
    for (int i = 0; i < 100; i++) {
        stars.push_back(viper::vec2{ viper::random::getRandomFloat() * 1280, viper::random::getRandomFloat() * 1280 });
    }


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
		input->Update();

        //play drum sounds
        
		/*if (input.GetKeyDown(SDL_SCANCODE_Q) && !input.GetPreviousKeyDown(SDL_SCANCODE_Q)) audio->playSound(sounds[0], nullptr, false, nullptr);
		if (input.GetKeyDown(SDL_SCANCODE_W) && !input.GetPreviousKeyDown(SDL_SCANCODE_W)) audio->playSound(sounds[1], nullptr, false, nullptr);
		if (input.GetKeyDown(SDL_SCANCODE_E) && !input.GetPreviousKeyDown(SDL_SCANCODE_E)) audio->playSound(sounds[2], nullptr, false, nullptr);
    */
    
        //if (input.GetKeyDown(SDL_SCANCODE_A)) transform.rotation += viper::math::degToRad(90) * time.GetDeltaTime();
        //if (input.GetKeyDown(SDL_SCANCODE_D)) transform.rotation -= viper::math::degToRad(90) * time.GetDeltaTime();

        float speed = 200;

        viper::vec2 direction{ 0, 0 };
        if (input->GetKeyDown(SDL_SCANCODE_W)) direction.y -= 100;
        if (input->GetKeyDown(SDL_SCANCODE_S)) direction.y += 100;
        if (input->GetKeyDown(SDL_SCANCODE_A)) direction.x -= 100;
        if (input->GetKeyDown(SDL_SCANCODE_D)) direction.x += 100;
        
        if (direction.LengthSqr() < 0) { 
        direction = direction.Normalized();
        /*for (auto& actor : actors) {
        actor->GetTransform().position += (direction * speed) * time.GetDeltaTime();
        }*/
        }
        

        //get input 
        

       /* if (input.GetMouseButtonPressed(viper::InputSystem::MouseButton::Left)) {
            points.push_back(input.GetMousePosition());
        }

        if (input.GetMouseButtonDown(viper::InputSystem::MouseButton::Left)) {
            viper::vec2 position = input.GetMousePosition();
            if (points.empty()) points.push_back(position);
            else if ((position - points.back()).Length() > 10) points.push_back(position);
        }*/


        //play drum sounds

        

        //draw
        viper::vec3 color{ 0, 0, 1 };

        renderer->SetColor((float)color.r, (float)color.g, (float)color.b);
        renderer->Clear();

		//model.Draw(renderer, input.GetMousePosition(), time.GetTime(), 10);
        
        
        scene.Draw(*renderer);

        /*
        viper::vec2 speed{ 200.0f, 0.0f };
        float length = speed.Length();
        for (auto& star : stars) {
            star += speed * time.GetDeltaTime();
            //star = star - speed;
            //star = star * speed;
            //star = star / speed;
            if (star[0] > 1280) star[0] = 0;
            if (star[0] < 0) star[0] = 1280;
            renderer.SetColor(viper::random::getRandomInt(0, 256), viper::random::getRandomInt(0, 256), viper::random::getRandomInt(0, 256));
            renderer.DrawPoint(star.x, star.y);
        }
        

        for (int i = 0; i < (int)points.size() - 1; i++) {
			renderer.SetColor(viper::random::getRandomInt(0, 256), viper::random::getRandomInt(0, 256), viper::random::getRandomInt(0, 256));
            renderer.DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
        }
        */

        renderer->Present();

}

    
    renderer->Shutdown();
	audio->Shutdown();

    return 0;
}