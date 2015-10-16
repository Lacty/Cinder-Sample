
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;


class Enemy {
private:
  Vec3f pos;
  Vec3f size;
public:
  Enemy(Vec3f pos, Vec3f size) {
    this->pos  = pos;
    this->size = size;
  }
  void update() {}
  void draw() {
    gl::color(Color(1, 1, 1));
    gl::drawCube(pos, size);
  }
  
  Vec3f getPos()  const { return pos; }
  Vec3f getSize() const { return size; }
};

class Bullet {
private:
  bool  is_dead;
  Vec3f pos;
  Vec3f size;
public:
  Bullet(Vec3f pos, Vec3f size) {
    this->is_dead = false;
    this->pos  = pos;
    this->size = size;
  }
  void update() {
    pos.z += 5.f;
  }
  void draw() {
    gl::color(Color(0, 0, 0));
    gl::drawCube(pos, size);
  }
  // この関数が呼ばれたら死亡扱いとする
  void hit() {
    this->is_dead = true;
  }
  bool isDead() {
    return is_dead;
  }
};


// 当たり判定用関数
// 引数の型をクラスにすると引数が減って楽
// ただし汎用性が減る
bool collision(Enemy& enemy, Bullet& bullet) {
  return true;
}

class CollisionTestApp : public AppNative {
private:
  list<Enemy>  enemies;
  list<Bullet> bullets;
  
public:
  void setup();
  void mouseDown(MouseEvent event);
  void update();
  void draw();
};

void CollisionTestApp::setup() {
  enemies.push_back({Vec3f(getWindowCenter().x, getWindowCenter().y, 0), Vec3f(10, 10, 10)});
}

void CollisionTestApp::mouseDown(MouseEvent event) {
  bullets.push_back({Vec3f(getWindowCenter().x, getWindowCenter().y, 0), Vec3f(10, 10, 10)});
}

void CollisionTestApp::update() {
  // 弾の移動処理
  for (auto& bullet : bullets) {
    bullet.update();
  }
  
  // Enemyも移動するのであればupdateを呼ぶ
  //for (auto& enemy : enemies) {
  //  enemy.update();
  //}
  
  // 弾とEnemyの当たり判定
  for (auto& bullet : bullets) {
    for (auto& enemy : enemies) {
      if (collision(enemy, bullet)) {
        bullet.hit();
      }
    }
  }
  
  // イテレータ取得
  auto bullet_itr = bullets.begin();
  
  // 死亡していたらリストから消去
  while (bullet_itr != bullets.end()) {
    if (bullet_itr->isDead()) {
      bullet_itr = bullets.erase(bullet_itr);
    }
    else {
      bullet_itr++;
    }
  }
  
  // Enemyも死亡フラグを所持していれば同じように消去できる、ω、
}

void CollisionTestApp::draw() {
	gl::clear(Color(0.4, 0.4, 0.4));
  
  for (auto& enemy : enemies) {
    enemy.draw();
  }
  for (auto& bullet : bullets) {
    bullet.draw();
  }
}

CINDER_APP_NATIVE( CollisionTestApp, RendererGl )
