#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/Json.h"
#include "Param.hpp"

#include <memory>

using namespace ci;
using namespace ci::app;
using namespace std;

class ParamsTestApp : public AppNative {
private:
  Vec3f pos;
  Vec3f size;
  ColorA color;
  
  std::unique_ptr<dowa::Param> param;
  
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void ParamsTestApp::setup()
{
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
  
  param = std::make_unique<dowa::Param>("Player", "player.json", pos, size, color);
}

void ParamsTestApp::mouseDown( MouseEvent event )
{
}

void ParamsTestApp::update()
{
}

void ParamsTestApp::draw()
{
  gl::clear(Color(0.4f, 0.4f, 0.4f));
  
  param->draw();
  
  gl::pushModelView();
  gl::translate(pos);
  gl::color(color);
  gl::drawCube(Vec3f::zero(), size);
  gl::popModelView();
}

CINDER_APP_NATIVE( ParamsTestApp, RendererGl )
