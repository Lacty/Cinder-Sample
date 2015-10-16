
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/Camera.h"
#include "cinder/gl/Light.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class VectorMouseApp : public AppNative {
private:
  Vec3f eye;
  Vec3f target;
  CameraPersp camera;

  unique_ptr<gl::Light> light;

  float angle;

public:
  void setup();

  void mouseDown(MouseEvent event);
  void mouseDrag(MouseEvent event);

  void update();
  void draw();
};

void VectorMouseApp::setup() {
  eye = Vec3f::zero();
  target = Vec3f(0, 0, 500);
  camera = CameraPersp(getWindowWidth(), getWindowHeight(),
                       35.f, 0.5f, 600.f);
  camera.lookAt(eye, target);
  camera.setWorldUp(Vec3f::yAxis());
  
  light = make_unique<gl::Light>(gl::Light::DIRECTIONAL, 0);
  light->setAmbient(Color(0.6f, 0.6f, 0.6f));
  light->setDiffuse(Color(0.6f, 0.6f, 0.6f));
  light->setDirection(Vec3f::zAxis());

  gl::enable(GL_LIGHTING);
  gl::enable(GL_CULL_FACE);
  gl::enableDepthRead();
  
  angle = 0.f;
}

void VectorMouseApp::mouseDown(MouseEvent event) {}

void VectorMouseApp::mouseDrag(MouseEvent event) {}

void VectorMouseApp::update() {
  angle += 0.01f;

  Quatf orientation = Quatf(Vec3f::yAxis(), angle);
  camera.setOrientation(orientation);
}

void VectorMouseApp::draw() {
  gl::clear(Color(0, 0, 0));
  gl::setMatrices(camera);
  light->enable();

  gl::drawCube(Vec3f(0, 0, 500), Vec3f(50, 50, 50));
  gl::drawCube(Vec3f(0, 0, -500), Vec3f(50, 50, 50));
  gl::drawCube(Vec3f(500, 0, 0), Vec3f(50, 50, 50));
  gl::drawCube(Vec3f(-500, 0, 0), Vec3f(50, 50, 50));
}

CINDER_APP_NATIVE(VectorMouseApp, RendererGl)
