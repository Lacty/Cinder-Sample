
#include "scene_manager.hpp"


SceneManager::SceneManager(const SceneType& type) {
  this->type = type;
  create(type);
}

void SceneManager::create(const SceneType& type) {
  scene = maker.create(type);
}


void SceneManager::update(bool isTouched) {
  scene->update(isTouched);
  if (type == scene->getSceneType()) return;
  type = scene->getSceneType();
  create(type);
}

void SceneManager::draw() {
  scene->draw();
}