
#pragma once


enum class SceneType {
  Title,
  Main,
  Result
};

class Scene {
private:
  SceneType type;
  
  void updateObject();
  void drawObject();
  
public:
  void setNextScene(const SceneType& type);
  SceneType getSceneType() const;
  
  virtual void update() = 0;
  virtual void draw() = 0;
};
