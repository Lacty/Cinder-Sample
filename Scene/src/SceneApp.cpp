
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "scene_manager.hpp"


using namespace ci;
using namespace ci::app;

class SceneApp : public AppNative {
private:
  SceneManager scene;
  
public:
  void setup();
  void mouseDown(MouseEvent event);
  void update();
  void draw();
};

void SceneApp::setup() {
  scene = SceneManager(SceneType::Title);
}

void SceneApp::mouseDown(MouseEvent event) {}

void SceneApp::update() {
  scene.update();
}

void SceneApp::draw() {
	gl::clear(Color(0, 0, 0));
  scene.draw();
}

CINDER_APP_NATIVE(SceneApp, RendererGl)
