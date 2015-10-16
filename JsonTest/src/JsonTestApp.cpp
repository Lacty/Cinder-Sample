#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/Json.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class JsonTestApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void JsonTestApp::setup()
{
}

void JsonTestApp::mouseDown( MouseEvent event )
{
  JsonTree data;
  data = JsonTree::makeObject();
  data.addChild(JsonTree("x", 1));
  data.write(getAppPath() / "../../../../assets/data.json", JsonTree::WriteOptions().createDocument(true));
}

void JsonTestApp::update()
{
}

void JsonTestApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( JsonTestApp, RendererGl )
