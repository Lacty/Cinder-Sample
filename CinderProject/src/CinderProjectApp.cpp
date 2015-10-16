
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/Camera.h"
#include "cinder/gl/Light.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CinderProjectApp : public AppNative {
private:
  CameraPersp camera;
  
public:
  void setup();
  void mouseDown(MouseEvent event);
  void update();
  void draw();
};

void CinderProjectApp::setup() {
  camera = CameraPersp(getWindowWidth(), getWindowHeight(),
                       35.0, 0.5, 600.f);
  camera.lookAt(Vec3f(0, 0, 500), Vec3f(0, 0, 0));
}

void CinderProjectApp::mouseDown(MouseEvent event) {}

void CinderProjectApp::update() {}

void CinderProjectApp::draw() {
  // clear out the window with black
  gl::clear(Color(0, 0, 0));
  //light->enable();
  gl::setMatrices(camera);
  
  
  gl::color(Color::white());
  gl::drawCube(Vec3f(0, 0, 200), Vec3f(50, 50, 50));
}

CINDER_APP_NATIVE(CinderProjectApp, RendererGl)
