
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Material.h"
#include "cinder/gl/Light.h"
#include "cinder/gl/Texture.h"
#include "cinder/Camera.h"
#include "cinder/ImageIo.h"
#include "cinder/ObjLoader.h"
#include "cinder/TriMesh.h"

using namespace ci;
using namespace ci::app;
using namespace std;


class ModelLoadApp : public AppNative {
private:
  CameraPersp camera;
  gl::Light* light;
  
  gl::Material material;
  gl::Texture texture;
  
  std::vector<TriMesh> mesh;
  
  float rx, ry, rz;
  
public:
  void setup();
  void mouseDown(MouseEvent event);
  void update();
  void draw();
};

void ModelLoadApp::setup() {
  camera = CameraPersp(getWindowWidth(), getWindowHeight(),
                       35.0f,
                       0.01f, 50.0f);
  camera.lookAt(Vec3f(0.0f, 0.0f, 3.0f),
                Vec3f::zero());
  
  light = new gl::Light(gl::Light::DIRECTIONAL, 0);
  light->setAmbient(Color(0.2f, 0.2f, 0.2f));
  light->setDiffuse(Color(0.8f, 0.8f, 0.8f));
  light->setSpecular(Color(0.8f, 0.8f, 0.8f));
  
  material.setAmbient(Color(1.0f, 1.0f, 1.0f));
  material.setDiffuse(Color(1.0f, 1.0f, 1.0f));
  material.setSpecular(Color(1.0f, 1.0f, 1.0f));
  material.setShininess(80.0f);
  material.setEmission(Color(0.0f, 0.0f, 0.0f));
  
  texture = loadImage(loadAsset("miku.png"));
  gl::enableAlphaBlending(false);
  
  glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);
  
  ObjLoader loader = ObjLoader(loadAsset("negimiku2.obj"));
  
  size_t group_num = loader.getNumGroups();
  mesh.resize(group_num);
  for (size_t i = 0; i < group_num; ++i) {
    loader.load(i, &mesh[i],
                boost::logic::indeterminate, boost::logic::indeterminate,
                false);
  }
  
  rx = ry = rz = 0.0f;
  
  gl::enable(GL_LIGHTING);
  gl::enable(GL_TEXTURE_2D);
  gl::enable(GL_CULL_FACE);
  
  gl::enableDepthWrite();
  gl::enableDepthRead();
}

void ModelLoadApp::mouseDown(MouseEvent event) {}

void ModelLoadApp::update() {
  //rx += 0.5f;
  ry += 0.5f;
}

void ModelLoadApp::draw() {
	gl::clear(Color(0.4, 0.4, 0.4));
  
  gl::setMatrices(camera);
  
  light->enable();
  material.apply();
  texture.bind();
  
  gl::rotate(Vec3f(rx, ry, rz));
  
  for (const auto& m : mesh) {
    gl::draw(m);
  }
}

CINDER_APP_NATIVE( ModelLoadApp, RendererGl )
