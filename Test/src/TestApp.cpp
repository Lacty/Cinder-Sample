
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;


class TestApp : public AppNative {
private:
  Font font;
  float angle;
  ColorA color;
  Vec3f rotate;
  
public:
  void setup();
  void quit() final;
  
  void mouseDown( MouseEvent event );
  
  void prepareSettings(Settings* settings);
  
  void update();
  void draw();
};

void TestApp::prepareSettings(Settings* settings) {
  settings->disableFrameRate();
}

void TestApp::setup() {
  font = Font(loadAsset("player1up.ttf"), 50);
  color = ColorA::white();
  angle = 0;
  gl::enableAlphaBlending();
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void TestApp::quit() {}

void TestApp::mouseDown( MouseEvent event ) {}

void TestApp::update() {
  rotate += Vec3f(0.5, 0.2, 0);
  angle += 0.01f;
  color.a = std::sin(angle);
}

void TestApp::draw() {
  gl::clear( Color( 0, 0, 0 ) );
  
  gl::color(color);
  gl::drawCube(Vec3f(getWindowCenter(), 0), Vec3f(800, 500, 0));
}

CINDER_APP_NATIVE( TestApp, RendererGl )
