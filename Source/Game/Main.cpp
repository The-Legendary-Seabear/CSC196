#include "Math/Math.h"
#include "Math/Vector2.h"
#include "Core/Random.h"
#include "Core/Time.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"

#include <SDL3/SDL.h>
#include <iostream>
#include <Renderer/Renderer.h>
#include <vector>
#include <fmod.hpp>

#define NAME "Alex"

// if you want to you can use using namespace viper;

int main(int argc, char* argv[]) {
    //initialize engine systems
    viper::Time time;

    viper::Renderer renderer;
    renderer.Initialize();
    renderer.CreateWindow("Viper Engine", 1280, 1024);

    viper::InputSystem input;
	input.Initialize();

    //create audio system
    viper::AudioSystem audio;
    audio.Inititalize();

    /*FMOD::System* audio;
    FMOD::System_Create(&audio);

    void* extradriverdata = nullptr;
    audio->init(32, FMOD_INIT_NORMAL, extradriverdata);*/


    //create objects

    /*
    FMOD::Sound* sound = nullptr;
    audio->createSound("test.wav", FMOD_DEFAULT, 0, &sound);

    audio->playSound(sound, 0, false, nullptr);
    */

    //initialize sounds
	audio.AddSound("test.wav", "testSound");

    //create stars
    std::vector<viper::vec2> stars;
    for (int i = 0; i < 100; i++) {
        stars.push_back(viper::vec2{ viper::random::getRandomFloat() * 1280, viper::random::getRandomFloat() * 1280 });
    }


    SDL_Event e;
    bool quit = false;

    std::vector<viper::vec2> points;

    //Main Loop
    while (!quit) {
        time.Tick();
        //audio->update();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        //update engine systems
		input.Update();

        //play drum sounds
        

        //get input 
        

        if (input.GetMouseButtonPressed(viper::InputSystem::MouseButton::Left)) {
            points.push_back(input.GetMousePosition());
        }

        if (input.GetMouseButtonDown(viper::InputSystem::MouseButton::Left)) {
            viper::vec2 position = input.GetMousePosition();
            if (points.empty()) points.push_back(position);
            else if ((position - points.back()).Length() > 10) points.push_back(position);
        }


        //play drum sounds

        

        //draw
        renderer.SetColor(0, 0, 0);
        renderer.Clear();

        
        
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

        renderer.Present();

}

    renderer.Shutdown();
	audio.Shutdown();

    return 0;
}