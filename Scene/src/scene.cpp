
#include "scene.hpp"


void Scene::updateObject() {}

void Scene::drawObject() {}


void Scene::setNextScene(const SceneType& type) {
  this->type = type;
}

SceneType Scene::getSceneType() const {
  return type;
}