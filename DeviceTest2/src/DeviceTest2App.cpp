
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "../blocks/MotionManager/src/cinder/MotionImplCoreMotion.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class DeviceTest2App : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void DeviceTest2App::setup()
{
  
}

void DeviceTest2App::mouseDown( MouseEvent event )
{
}

void DeviceTest2App::update()
{
  console() << MotionManager::getRotation() << std::endl;
}

void DeviceTest2App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
  gl::pushModelView();
  gl::translate(getWindowCenter());
  gl::rotate(MotionManager::getRotation());
  gl::color(Color(1, 1, 1));
  gl::drawCube(Vec3f::zero(), Vec3f(100, 100, 100));
  gl::popModelView();
}

CINDER_APP_NATIVE( DeviceTest2App, RendererGl )
