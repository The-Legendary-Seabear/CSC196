#include "SpaceGame.h"
#include "Framework/Scene.h"
#include "Core/Random.h"
#include "Math/Vector2.h"
#include "Renderer/Model.h"
#include "Player.h"

#include <vector>

bool SpaceGame::Initialize() {
    m_scene = std::make_unique<viper::Scene>();

    std::vector<viper::vec2> points{
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

    /*
    for (int i = 0; i < 10; i ++) {
    viper::Transform transform{ viper::vec2{viper::random::getRandomFloat() * 1280, viper::random::getRandomFloat() * 1040}, 0, 20};
    std::unique_ptr<Player> player = std::make_unique<Player>( transform, model );
    scene.AddActor(std::move(player));
    }
    */

    viper::Transform transform{ viper::vec2{640, 520}, 0, 20 };
    std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
    m_scene->AddActor(std::move(player));

    return true;
}

void SpaceGame::Update() {

}

void SpaceGame::Shutdown() {

}

void SpaceGame::Draw() {

}
