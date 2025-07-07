#include "Math/Math.h"
#include "Core/Random.h"
#include <SDL3/SDL.h>
#include <iostream>

#define NAME "Alex"

// if you want to you can use using namespace viper;

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("SDL3 Project", 1280, 1024, 0);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    SDL_Event e;
    bool quit = false;

    // Define a rectangle
    SDL_FRect greenSquare{ 270, 190, 200, 200 };

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }


        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set render draw color to black
        SDL_RenderClear(renderer); // Clear the renderer

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

    return 0;
}

/*
int main() {

	//const float deg = viper::radToDeg(viper::pi);

	viper::math::min(5, 3);
	viper::math::clamp(2, 3, 5);

	std::cout << NAME << std::endl;
	std::cout << "Hello World!" << std::endl;
	std::cout << viper::math::pi << std::endl;

	for (int i = 0; i < 10; i++) {
		std::cout << viper::random::getRandomFloat() << std::endl;
	}
}
*/