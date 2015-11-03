#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class DeviceTest3App : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void DeviceTest3App::setup()
{
}

void DeviceTest3App::mouseDown( MouseEvent event )
{
}

void DeviceTest3App::update()
{
}

void DeviceTest3App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( DeviceTest3App, RendererGl )
