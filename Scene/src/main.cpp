
#include "main.hpp"
#include "cinder/gl/gl.h"


Main::Main() {
  type = SceneType::Main;
}


void Main::update(bool isTouched) {}

void Main::draw() {
  ci::gl::pushModelView();
  ci::gl::translate(ci::app::getWindowCenter());
  ci::gl::color(ci::Color(1, 0, 0));
  ci::gl::drawCube(ci::Vec3f::zero(), ci::Vec3f(100, 100, 100));
  ci::gl::popModelView();
}