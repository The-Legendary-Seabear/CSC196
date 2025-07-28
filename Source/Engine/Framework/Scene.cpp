#include "Scene.h"
#include "Actor.h"
#include "../Core/StringHelper.h"
#include "../Renderer/Renderer.h"

namespace viper {
	void Scene::Update(float dt) {
		for (auto& actor : m_actors) {
			actor->Update(dt);
		}
	}

	void Scene::Draw(class Renderer& renderer) {
		for (auto& actor : m_actors) {
			actor->Draw(renderer);

		}
	}

	void Scene::AddActor(std::unique_ptr<class Actor> actor) {
		actor->scene = this;
		m_actors.push_back(std::move(actor));
	}
	Actor* Scene::GetActorByName(const std::string& name) {
		for (auto& actor : m_actors) {
			if (toLower(actor->name) == toLower(name)) {
				return actor.get();
			}
		}


		return nullptr;
	}
}