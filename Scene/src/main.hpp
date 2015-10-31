
#pragma once
#include "scene.hpp"


class Main : public Scene {
public:
  Main();
  
  void update(bool isTouched);
  void draw();
};