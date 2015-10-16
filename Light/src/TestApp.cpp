
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/Camera.h"
#include "cinder/params/Params.h"

#include "cinder/gl/Light.h"

using namespace ci;
using namespace ci::app;

class TestApp : public AppNative {
public:
  void prepareSettings( Settings*  setting ) override;
  void keyDown(         KeyEvent   event   ) override;
  void setup();
  void mouseDown(       MouseEvent event   ) override;
  void update();
  void draw();

private:
  enum WindowSize {
    WIDTH = 500,
    HEIGHT = 500
  };
  ColorA obj_color;
  CameraPersp camera;
  Quatf camera_rotate;
  Vec3f rotate;
  cinder::params::InterfaceGl param;

  cinder::gl::Light* light;
};

void TestApp::prepareSettings(Settings* setting) {
  setting->setWindowSize(WIDTH, HEIGHT);
}

void TestApp::setup()
{
  gl::enableDepthRead();
  //gl::enableDepthWrite();
  //gl::enableAlphaBlending();

  light = new gl::Light(gl::Light::DIRECTIONAL, 0);
  light->lookAt(Vec3f(0, -100, 0), Vec3f(0, -1, 0));
  light->enable();

  gl::enable(GL_LIGHTING);


  param = cinder::params::InterfaceGl("Test Param", Vec2i(255, 200));

  param.addParam("Camera", &camera_rotate);
  param.addParam("Rotate", &rotate);
  // param.addParam("Light",  light);

  camera.setPerspective(60.0f, getWindowAspectRatio(), 5.0f, 2000.0f);
  camera.lookAt(Vec3f(0, 0, 100), Vec3f::zero(), Vec3f::yAxis());
}

void TestApp::mouseDown(MouseEvent event)
{
}

void TestApp::keyDown(KeyEvent event) {

  if (event.getCode() == KeyEvent::KEY_w)
  {
    static float s_rotate = 0.0f;
    s_rotate += M_PI * 0.03f;
    camera_rotate = Quatf(Vec3f::yAxis(), M_PI * 0.9f * s_rotate);
  }
  else if (event.getCode() == KeyEvent::KEY_a)
  {
    camera_rotate = Quatf(Vec3f::yAxis(), M_PI * 0.5f);
  }
}

void TestApp::update()
{
  gl::setMatrices(camera);
  gl::rotate(camera_rotate);
  light->update(camera);

  // 何秒たったか
  auto second = getElapsedSeconds();

  // 何フレームたったか
  auto frame = getElapsedFrames();

  // デバッグ出力
  console() << camera.getCenterOfInterestPoint() << std::endl;
}

void TestApp::draw()
{
  gl::clear();
  param.draw();

  gl::pushModelView();

  obj_color = ColorA(0, 0, 0, 0.5f);
  gl::color(obj_color);
  gl::drawCube(Vec3f(0, 0, 0),    Vec3f(30, 30, 60));
  obj_color = ColorA(0, 0, 0, 0.5f);
  gl::color(obj_color);
  gl::drawCube(Vec3f(0, 30, -60), Vec3f(30, 50, 80));

  gl::popModelView();
}

CINDER_APP_NATIVE(TestApp, RendererGl)
