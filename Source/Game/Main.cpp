
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
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include "Core/File.h"

#include "Game/Player.h"
#include "Game/SpaceGame.h"
#include "Framework/Game.h"

#include <SDL3/SDL.h>
#include <iostream>
#include <Renderer/Renderer.h>
#include <vector>
#include <fmod.hpp>
#include <memory>



int main(int argc, char* argv[]) {
    // Test getInt() variants
    std::cout << "Integer Functions:\n";
    std::cout << "getInt(): " << viper::random::getInt() << "\n";
    std::cout << "getInt(): " << viper::random::getInt() << "\n";
    std::cout << "getInt(10): " << viper::random::getInt(10) << "\n";
    std::cout << "getInt(10): " << viper::random::getInt(10) << "\n";
    std::cout << "getInt(5, 15): " << viper::random::getInt(5, 15) << "\n";
    std::cout << "getInt(5, 15): " << viper::random::getInt(5, 15) << "\n";
    std::cout << "getInt(-10, 10): " << viper::random::getInt(-10, 10) << "\n\n";

    // Test getReal() variants with float
    std::cout << "Float Functions:\n";
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "getReal<float>(): " << viper::random::getReal<float>() << "\n";
    std::cout << "getReal<float>(): " << viper::random::getReal<float>() << "\n";
    std::cout << "getReal<float>(5.0f): " << viper::random::getReal<float>(5.0f) << "\n";
    std::cout << "getReal<float>(2.5f, 7.5f): " << viper::random::getReal<float>(2.5f, 7.5f) << "\n";
    std::cout << "getReal<float>(-1.0f, 1.0f): " << viper::random::getReal<float>(-1.0f, 1.0f) << "\n\n";

    // Test getReal() variants with double
    std::cout << "Double Functions:\n";
    std::cout << std::setprecision(10);
    std::cout << "getReal<double>(): " << viper::random::getReal<double>() << "\n";
    std::cout << "getReal<double>(100.0): " << viper::random::getReal<double>(100.0) << "\n";
    std::cout << "getReal<double>(0.0, 2.0): " << viper::random::getReal<double>(0.0, 2.0) << "\n\n";

    // Test getBool()
    std::cout << "Boolean Functions:\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << "getBool(): " << std::boolalpha << viper::random::getBool() << "\n";
    }
    std::cout << "\n";

    return 0;




    // Get current directory path
    std::cout << "Directory Operations:\n";
    std::cout << "Current directory: " << viper::GetCurrentDirectory() << "\n";

    // Set current directory path (current path + "Assets")
    std::cout << "Setting directory to 'Assets'...\n";
    viper::SetCurrentDirectory("Assets");
    std::cout << "New directory: " << viper::GetCurrentDirectory() << "\n\n";

    // Get filenames in the current directory
    std::cout << "Files in Directory:\n";
    auto filenames = viper::GetFilesInDirectory(viper::GetCurrentDirectory());
    for (const auto& filename : filenames) {
        std::cout << filename << "\n";
    }
    std::cout << "\n";

    // Get filename (filename.extension) only
    if (!filenames.empty()) {
        std::cout << "Path Analysis:\n";
        std::string filename = viper::GetFilename(filenames[0]);
        std::cout << "Filename only: " << filename << "\n";

        // Get extension only
        std::string ext = viper::GetExtension(filenames[0]);
        std::cout << "Extension: " << ext << "\n\n";
    }

    // Read and display text file
    std::cout << "Text File Reading:\n";
    std::string str;
    bool success = viper::ReadTextFile("test.txt", str);
    if (success) {
        std::cout << "Contents of test.txt:\n";
        std::cout << str << "\n";
    }
    else {
        std::cout << "Failed to read test.txt\n";
    }

   //initialize engine
    viper::GetEngine().Initialize();

    //Initialize Game
    std::unique_ptr<SpaceGame> game = std::make_unique<SpaceGame>();
    game->Initialize();

    //create objects

	//viper::Scene scene = viper::Scene();

    viper::Font* font = new viper::Font();
    font->Load("Archeologicaps.ttf", 20);

    //viper::Text* text = new viper::Text(font);
    //text->Create(viper::GetEngine().GetRenderer(), "Hello World", viper::vec3{ 1, 1, 1});

    
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
        //scene.Update(viper::GetEngine().GetTime().GetDeltaTime());

        game->Update(viper::GetEngine().GetTime().GetDeltaTime());

        if (viper::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_ESCAPE)) quit = true;
        

        
      
        
        

        //get input 
       

        

        //draw
        viper::vec3 color{ 0, 0, 0 };

        viper::GetEngine().GetRenderer().SetColor((float)color.r, (float)color.g, (float)color.b);
        viper::GetEngine().GetRenderer().Clear();

		//model.Draw(renderer, input.GetMousePosition(), time.GetTime(), 10);
        
        
        //scene.Draw(viper::GetEngine().GetRenderer());

        //Draw
        //text->Draw(viper::GetEngine().GetRenderer(), 40.0f, 40.0f);
		game->Draw();


        //present
        viper::GetEngine().GetRenderer().Present();

}

    game->Shutdown();
    game.release();
    viper::GetEngine().Shutdown();

    return 0;
}
