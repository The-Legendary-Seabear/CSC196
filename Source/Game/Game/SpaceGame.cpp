#include "SpaceGame.h"
#include "Framework/Scene.h"
#include "Core/Random.h"
#include "Math/Vector2.h"
#include "Renderer/Model.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine.h"
#include "Renderer/Renderer.h"

#include <vector>

bool SpaceGame::Initialize() {
    m_scene = std::make_unique<viper::Scene>();

    std::vector<viper::vec2> points{
        {5, 0},
        {-4, -3},
        {-2, 0},
        {-4, 3},
        {5, 0},
    };

    std::shared_ptr<viper::Model> model = std::make_shared <viper::Model>(points, viper::vec3{ 0.0f, 0.4f, 1.0f });
    
    
    viper::Transform transform{ viper::vec2{viper::GetEngine().GetRenderer().GetWidth() * 0.5f, viper::GetEngine().GetRenderer().GetHeight() * 0.5f}, 0, 3};
    std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
    player->speed = 500.0f;
    player->rotationRate = 180.0f;
    player->damping = 0.5f;
    player->name = "player";
    m_scene->AddActor(std::move(player));
    
    std::shared_ptr<viper::Model> enemyModel = std::make_shared <viper::Model>(points, viper::vec3{ 1.0f, 1.0f, 0.0f });
    for (int i = 0; i < 5; i ++) {
    viper::Transform transform{ viper::vec2{viper::GetEngine().GetRenderer().GetWidth() * 0.5f, viper::GetEngine().GetRenderer().GetHeight() * 0.5f}, 0, 6};
    std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>( transform, enemyModel );
	enemy->damping = 0.5f;
    enemy->speed = 200;
    m_scene->AddActor(std::move(enemy));
    }

    return true;
}

void SpaceGame::Update() {
    m_scene->Update(viper::GetEngine().GetTime().GetDeltaTime());
}

void SpaceGame::Shutdown() {
}

void SpaceGame::Draw() {
    m_scene->Draw(viper::GetEngine().GetRenderer());

}
