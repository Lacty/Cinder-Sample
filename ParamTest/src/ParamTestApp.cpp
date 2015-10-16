
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Json.h"

#include "cinder/params/Params.h"

#include "Param.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace dowa;

class ParamTestApp : public AppNative {
private:
  Vec3f pos;
  Vec3f size;
  ColorA color;
  
  Param param;
  
public:
  void setup();
  void mouseDown(MouseEvent event);
  void update();
  void draw();
};

void ParamTestApp::setup() {
  JsonTree data(loadAsset("player.json"));
  pos.x = data["Player"]["Position"]["x"].getValue<float>();
  pos.y = data["Player"]["Position"]["y"].getValue<float>();
  pos.z = data["Player"]["Position"]["z"].getValue<float>();
  
  size.x = data["Player"]["Size"]["x"].getValue<float>();
  size.y = data["Player"]["Size"]["y"].getValue<float>();
  size.z = data["Player"]["Size"]["z"].getValue<float>();
  
  color.r = data["Player"]["Color"]["r"].getValue<float>();
  color.g = data["Player"]["Color"]["g"].getValue<float>();
  color.b = data["Player"]["Color"]["b"].getValue<float>();
  color.a = data["Player"]["Color"]["a"].getValue<float>();
  
  param = Param("Player", "player.json", pos, size, color);
}

void ParamTestApp::mouseDown(MouseEvent event) {}

void ParamTestApp::update() {}

void ParamTestApp::draw() {
	// clear out the window with black
	gl::clear(Color(0.4f, 0.4f, 0.4f));
  
  gl::pushModelView();
  gl::translate(pos);
  gl::color(color);
  gl::drawCube(Vec3f::zero(), size);
  gl::popModelView();
}

CINDER_APP_NATIVE(ParamTestApp, RendererGl)
