
#pragma once

#include "cinder/params/Params.h"
#include <string>


namespace dowa {

class Param {
private:
  std::string name;
  std::string file_path;
  cinder::params::InterfaceGl param;
  
  cinder::Vec3f &pos;
  cinder::Vec3f &size;
  cinder::ColorA &color;
  
  void save();
  void reset();
  
public:
  Param(const std::string &name,
        const std::string &filePath,
        cinder::Vec3f &pos,
        cinder::Vec3f &size,
        cinder::ColorA & color);
  
  void draw();
  
  std::string getName() const;
};

}
