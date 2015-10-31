
#include "scene_manager.hpp"


SceneManager::SceneManager(const SceneType& type) {
  create(type);
}

void SceneManager::create(const SceneType& type) {
  scene = maker.create(type);
}


void SceneManager::update() {
  scene->update();
}

void SceneManager::draw() {
  scene->draw();
}