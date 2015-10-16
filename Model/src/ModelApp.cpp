
#include "MyLib/common.h"
#include "MyLib/graph.h"


class ModelApp : public AppNative {
private:
  struct Line {
    Vec3f begin;
    Vec3f end;
  };
  std::vector<Line> lines;

  float angle;

public:
  void setup();
  void mouseDown(MouseEvent event);
  void update();
  void draw();
};

void ModelApp::setup() {
  // ‘¤–Ê
  lines.push_back({ { -0.5f, 2.f, 0.f }, { 0.5f, 2.f, 0.f } }); // a-b
  lines.push_back({ { 0.5f, 2.f, 0.f }, { 2.f, -2.5f, 0.f } }); // b-c
  lines.push_back({ { 2.f, -2.5f, 0.f }, { -2.f, -2.5f, 0.f } }); // c-d
  lines.push_back({ { -2.f, -2.5f, 0.f }, { -0.5f, 2.f, 0.f } }); // d-a

  lines.push_back({ { -0.5f, 2.f, 0.f }, { -0.5f, -2.5f, -1.f } }); // a-e
  lines.push_back({ { 0.5f, 2.f, 0.f }, { 0.5f, -2.5f, -1.f } }); // b-f
  lines.push_back({ { 2.f, -2.5f, 0.f }, { 0.5f, -2.5f, -1.f } }); // c-f
  lines.push_back({ { -2.f, -2.5f, 0.f }, { -0.5f, -2.5f, -1.f } }); // d-e
  lines.push_back({ { -0.5f, -2.5f, -1.f }, { 0.5f, -2.5f, -1.f } }); // e-f

  angle = 0.f;
}

void ModelApp::mouseDown(MouseEvent event) {}

void ModelApp::update() {
  angle += 0.01f;
}

void ModelApp::draw() {
  // clear out the window with black
  gl::clear();

  Matrix44f translate = Matrix44f::createTranslation(Vec3f(0.f, 0.f, 2000.f));
  Matrix44f scale = Matrix44f::createScale(Vec3f(50.f, -50.f, 50.f));
  Matrix44f rotate = Matrix44f::createRotation(Vec3f(0.f, angle, 0.f));

  const float viewing_angle = 0.0004f;

  gl::pushModelView();
  gl::translate(getWindowCenter());

  for (auto pos : lines) {
    auto begin = pos.begin;
    auto end   = pos.end;

    begin = translate * rotate * scale * begin;
    end = translate * rotate * scale * end;

    ly::drawLine(begin.xy() / (begin.z * viewing_angle),
                 end.xy() / (end.z * viewing_angle),
                 Color(0.f, 1.f, 1.f));
  }

  gl::popModelView();
}

CINDER_APP_NATIVE(ModelApp, RendererGl)
