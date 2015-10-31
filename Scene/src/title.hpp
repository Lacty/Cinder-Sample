
#pragma once
#include "scene.hpp"


class Title : public Scene {
private:
public:
  Title();
  
  void update(bool isTouched);
  void draw();
};