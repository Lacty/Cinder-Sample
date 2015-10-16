
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/Camera.h"
#include "cinder/gl/Light.h"
#include "cinder/gl/Material.h"

#include <memory>

using namespace ci;
using namespace ci::app;


class MaterialApp : public AppNative {
private:
  Font font;
  
  Vec3f rotate;
  
  Vec3f eye;
  Vec3f target;
  CameraPersp camera;
  
  std::unique_ptr<gl::Light> light;
  
  gl::Material material;
  
public:
  void setup();
  
  void update();
  void draw();
};

void MaterialApp::setup(){
  font = Font(loadAsset("player1up.ttf"), 20);
  
  rotate = Vec3f::zero();
  
  eye = Vec3f(0, 0, 700);
  target = Vec3f::zero();
  camera = CameraPersp(getWindowWidth(), getWindowWidth(), 35.0f, 0.5f, 800.f);
  camera.lookAt(eye, target);
  
  light = std::make_unique<gl::Light>(gl::Light::DIRECTIONAL, 0);
  light->setAmbient(Color(0.6f, 0.6f, 0.6f));
  light->setDiffuse(Color(1.f, 1.f, 1.f));
  light->setDirection(Vec3f::zAxis());
  
  material.setAmbient(Color(0.3f, 0.3f, 0.3f));
  material.setDiffuse(Color(0.6f, 0.6f, 0.6f));
  material.setShininess(60);
  material.setEmission(Color(0.f, 0.f, 0.f));
  
  //gl::enable(GL_LIGHTING);
  gl::enable(GL_CULL_FACE);
  gl::enableDepthRead();
  gl::enableDepthWrite();
}

void MaterialApp::update(){
  rotate += Vec3f(0.6f, 0.6f, 0.f);
}

void MaterialApp::draw()
{
  gl::clear(Color(0, 0, 0));
  gl::setMatrices(camera);
  
  gl::pushModelView();
  gl::translate(Vec2f(0, 100));
  gl::rotate(Vec3f(180, 0, 0));
  //gl::scale(Vec2f(0.2, 0.2));
  gl::drawStringCentered("Cinder Gl Ligting!", Vec2f::zero(), ColorA::white(), font);
  gl::popModelView();
  
  
  //light->enable();
  //material.apply();
  gl::color(1, 1, 1);
  
  gl::pushModelView();
  gl::translate(Vec3f(-100, 0, 0));
  gl::rotate(rotate);
  gl::drawCube(Vec3f::zero(), Vec3f(50, 50, 50));
  gl::popModelView();
  
}

CINDER_APP_NATIVE( MaterialApp, RendererGl )
