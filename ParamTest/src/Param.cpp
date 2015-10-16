
#include "Param.hpp"
#include "cinder/Json.h"


using namespace std;
using namespace cinder;
using namespace cinder::app;
using namespace dowa;

Param::Param(const std::string &name,
             const std::string &filePath,
             cinder::Vec3f &pos,
             cinder::Vec3f &size,
             cinder::ColorA & color) :
name(name),
file_path(filePath),
param(name, cinder::Vec2f::zero()),
pos(pos),
size(size),
color(color)
{
  param.addParam("Position", &pos);
  param.addParam("Size", &size);
  param.addParam("Color", &color);
  
  param.addButton("Reset", std::bind(&Param::reset, this));
  param.addButton("Save", std::bind(&Param::save, this));
}


void Param::save() {
  JsonTree Position;
  Position = JsonTree::makeObject("Position");
  Position.addChild(JsonTree("x", pos.x));
  Position.addChild(JsonTree("y", pos.y));
  Position.addChild(JsonTree("z", pos.z));
  
  JsonTree Size;
  Size = JsonTree::makeObject("Size");
  Size.addChild(JsonTree("x", size.x));
  Size.addChild(JsonTree("y", size.y));
  Size.addChild(JsonTree("z", size.z));
  
  JsonTree Color;
  Color = JsonTree::makeObject("Color");
  Color.addChild(JsonTree("r", color.r));
  Color.addChild(JsonTree("g", color.g));
  Color.addChild(JsonTree("b", color.b));
  Color.addChild(JsonTree("a", color.a));
  
  JsonTree data;
  data = JsonTree::makeObject(name);
  data.addChild(Position);
  data.addChild(Size);
  data.addChild(Color);
}

void Param::reset() {
  JsonTree data(loadAsset(file_path));
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
}


void Param::draw() {
  param.draw();
}


std::string Param::getName() const {
  return name;
}