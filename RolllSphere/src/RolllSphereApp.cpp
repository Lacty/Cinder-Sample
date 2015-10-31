
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/gl/Material.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/Light.h"
#include "cinder/ImageIo.h"
#include "cinder/Camera.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class RolllSphereApp : public AppNative {
private:
  Vec3f eye;
  Vec3f target;
  
  CameraPersp camera;
  std::unique_ptr<gl::Light> light;
  gl::Material material;
  
  gl::Texture image_bg;
  gl::Texture image_ball;
  
public:
  void setup();
  void mouseDown(MouseEvent event);
  void update();
  void draw();
};

void RolllSphereApp::setup() {
  eye = Vec3f(0, 0, 500);
  target = Vec3f::zero();
  camera = CameraPersp(getWindowWidth(), getWindowHeight(),
                       35.0f, 0.5f, 600);
  camera.lookAt(eye, target);
  
  light = std::make_unique<gl::Light>(gl::Light::DIRECTIONAL, 0);
  light->setAmbient(Color(0.4f, 0.4f, 0.4f));
  light->setDiffuse(Color(1, 1, 1));
  light->setDirection(Vec3f(0, 0, 1));
  
  material.setAmbient(Color(0.5f, 0.5f, 0.5f));
  material.setDiffuse(Color(0.3f, 0.3f, 0.3f));
  material.setSpecular(Color(0.3f, 0.3f, 0.3f));
  material.setShininess(60.f);
  material.setEmission(Color(0.5f, 0.5f, 0.5f));
  
  //image_bg = loadImage(loadAsset());
}

void RolllSphereApp::mouseDown(MouseEvent event) {}

void RolllSphereApp::update() {}

void RolllSphereApp::draw() {
	gl::clear(Color(0, 0, 0));
}

CINDER_APP_NATIVE(RolllSphereApp, RendererGl)
