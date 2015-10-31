
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "scene_manager.hpp"


using namespace ci;
using namespace ci::app;

class SceneApp : public AppNative {
private:
  SceneManager scene;
  bool isTouched;
  
public:
  void setup();
  void mouseDown(MouseEvent event);
  void touchesBegan(TouchEvent event);
  void touchesEnded(TouchEvent event);
  void update();
  void draw();
};

void SceneApp::setup() {
  scene = SceneManager(SceneType::Title);
  isTouched = false;
}

void SceneApp::mouseDown(MouseEvent event) {}

void SceneApp::touchesBegan(TouchEvent event) {
  isTouched = true;
}

void SceneApp::touchesEnded(TouchEvent event) {
  isTouched = false;
}

void SceneApp::update() {
  scene.update(isTouched);
}

void SceneApp::draw() {
	gl::clear(Color(0, 0, 0));
  scene.draw();
}

CINDER_APP_NATIVE(SceneApp, RendererGl)
