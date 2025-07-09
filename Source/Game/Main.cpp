#include "Math/Math.h"
#include "Math/Vector2.h"
#include "Core/Random.h"
#include <SDL3/SDL.h>
#include <iostream>
#include <Renderer/Renderer.h>
#include <vector>
#include "Core/Time.h"
#include "Input/InputSystem.h"

#define NAME "Alex"

// if you want to you can use using namespace viper;

int main(int argc, char* argv[]) {
    viper::Time time;

    viper::Renderer renderer;
    renderer.Initialize();
    renderer.CreateWindow("Viper Engine", 1280, 1024);

    viper::InputSystem input;
	input.Initialize();

    SDL_Event e;
    bool quit = false;

    //create stars
    std::vector<viper::vec2> stars;
    for (int i = 0; i < 100; i++) {
        stars.push_back(viper::vec2{ viper::random::getRandomFloat() * 1280, viper::random::getRandomFloat() * 1280 });
    }
    //vec2 v(30, 40);

    //Main Loop
    while (!quit) {
        time.Tick();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }
		input.Update();

        if (input.GetKeyReleased(SDL_SCANCODE_A)) {
            std::cout << "pressed\n";
        }

        if (input.GetMouseButtonDown(0)) {
			std::cout << "mouse pressed\n";
        }

        viper::vec2 mouse = input.GetMousePosition();
        std::cout << mouse.x << " " << mouse.y << std::endl;

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

        /*for (int i = 0; i < 10; i++) {
            renderer.SetColor(viper::random::getRandomInt(0, 256), viper::random::getRandomInt(0, 256), viper::random::getRandomInt(0, 256));
            renderer.DrawLine(viper::random::getRandomFloat() * 1280, viper::random::getRandomFloat() * 1280, viper::random::getRandomFloat() * 1280, viper::random::getRandomFloat() * 1280);
        }

        for (int i = 0; i < 20; i++) {
            renderer.SetColor(viper::random::getRandomInt(0, 256), viper::random::getRandomInt(0, 256), viper::random::getRandomInt(0, 256));
            renderer.DrawPoint(viper::random::getRandomFloat() * 1280, viper::random::getRandomFloat() * 1280);
        }

        renderer.SetColor(viper::random::getRandomInt(0, 256), viper::random::getRandomInt(0, 256), viper::random::getRandomInt(0, 256));
        renderer.DrawPoint(v.x, v.y);*/

        renderer.Present();

}

    renderer.Shutdown();

    return 0;
}
        /*
        Code from before class today:
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Set render draw color to green
        //SDL_RenderFillRect(renderer, &greenSquare); // Render the rectangle

        // Random Lines
        for (int i = 0; i < 10; i++) {
            //SDL_RenderLine(renderer, 55, 22, 53, 229);
            //SDL_RenderLine(renderer, viper::random::getRandomFloat(), viper::random::getRandomFloat(), viper::random::getRandomFloat(), viper::random::getRandomFloat());
            SDL_SetRenderDrawColor(renderer, viper::random::getRandomInt(0, 255), viper::random::getRandomInt(0, 255), viper::random::getRandomInt(0, 255), viper::random::getRandomInt(0, 255));
            SDL_RenderLine(renderer, viper::random::getRandomInt(0, 1000), viper::random::getRandomInt(0, 1000), viper::random::getRandomInt(0, 1000), viper::random::getRandomInt(0, 1000));
        }

        //Random dots
        for (int i = 0; i < 20; i++) {
            SDL_SetRenderDrawColor(renderer, viper::random::getRandomInt(0, 255), viper::random::getRandomInt(0, 255), viper::random::getRandomInt(0, 255), viper::random::getRandomInt(0, 255));
            SDL_RenderPoint(renderer, viper::random::getRandomInt(0, 1000), viper::random::getRandomInt(0, 1000));
        }

        SDL_RenderPresent(renderer); // Render the screen
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    */