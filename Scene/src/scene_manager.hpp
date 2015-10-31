
#pragma once
#include <memory>
#include "scene.hpp"
#include "scene_maker.hpp"


class SceneManager {
private:
  SceneType type;
  SceneMaker maker;
  std::unique_ptr<Scene> scene;
  
  void create(const SceneType& type);

public:
  SceneManager() = default;
  
  // 起動して初めに実行されるシーンを設定
  SceneManager(const SceneType& type);
  
  void update(bool isTouched);
  void draw();
};