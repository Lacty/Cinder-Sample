
#pragma once
#include "scene.hpp"
#include <memory>


class SceneMaker {
public:
  SceneMaker() = default;
  
  std::unique_ptr<Scene> create(const SceneType& type) const;
};