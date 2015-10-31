
#include "scene_maker.hpp"
#include "title.hpp"
#include "main.hpp"

#include <functional>
#include <unordered_map>


std::unique_ptr<Scene> SceneMaker::create(const SceneType& type) const {
  using namespace std;
  unordered_map<SceneType, function<unique_ptr<Scene>()>> list = {
    {
      SceneType::Title,
      []{ return make_unique<Title>(); }
    },
    
    {
      SceneType::Main,
      []{ return make_unique<Main>(); }
    }
  };
  
  return std::move((list.find(type)->second)());
}