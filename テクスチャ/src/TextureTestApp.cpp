//
// テクスチャサンプル
//

#include "cinder/app/AppNative.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/Light.h"


using namespace ci;
using namespace ci::app;

class TextureTestApp : public AppNative {
  // テクスチャを扱う変数
  gl::Texture image;

  // ライト(スマポで用意)
  std::unique_ptr<gl::Light> light;
  
  // カメラ
  CameraPersp camera;

  // モデルをくるくる回す用
  float rx;
  float ry;
  float rz;


public:
	void setup();
	void update();
	void draw();
};


void TextureTestApp::setup()
{
  // assetフォルダから画像を読み込む
  // 幅と高さは２のべき乗でなくてもよい
  image = loadImage(loadAsset("imagesFH4XK5GD.jpg"));

  // 平行光源を１つ用意
  light = std::unique_ptr<gl::Light>(new gl::Light(gl::Light::DIRECTIONAL, 0));
  light->setAmbient(Color(0.0, 0.0, 0.0));
  light->setDiffuse(Color(1.0, 1.0, 1.0));
  light->setDirection(Vec3f(0.0, 0.0, 1.0));

  // カメラの準備
  camera = CameraPersp(getWindowWidth(), getWindowHeight(),
                       35.0, 0.5, 1000.0);

  camera.lookAt(Vec3f(0.0, 0.0, 700.0),
                Vec3f(0.0, 0.0, 0.0));

 
  // テクスチャON
  gl::enable(GL_TEXTURE_2D);
 
  // カリングON
  gl::enable(GL_CULL_FACE);

  // gl::color or 頂点カラーを対象にしてライティングの計算を行う
  gl::enable(GL_COLOR_MATERIAL);
  
  // ライティングON
  gl::enable(GL_LIGHTING);
  // 法線を正規化する
  gl::enable(GL_NORMALIZE);

  gl::enableDepthRead();
  gl::enableDepthWrite();


  // ブレンディングゆうこう
  gl::enableAlphaBlending(true);


  rx = ry = rz = 0.0;
}

void TextureTestApp::update()
{
  //rx += 1.0;
  ry += 1.0;
}

void TextureTestApp::draw()
{
	gl::clear(Color(0.2f, 0.2f, 0.2f));

  // カメラの状態から行列を作成
  // 視点座標変換用と正規化デバイス座標変換用の２つを用意する
  gl::setMatrices(camera);

  // ライティング開始
  light->enable();

  // ローカル→ワールド変換行列を用意
  gl::scale(100.0, 100.0, 100.0);
  gl::rotate(Vec3f(rx, ry, rz));

  gl::pushModelView();
  // テクスチャを拘束
  image.bind();
  gl::translate(Vec3f(1.5f, 0, 0));
  gl::color(Color::white());
  // ポリゴンを描画
  gl::drawCube(Vec3f(0.0, 0.0, 0.0), Vec3f(2.0, 2.0, 2.0));
  //gl::drawCylinder(1, 2, 2, 12, 2);

  // 拘束を解除
  image.unbind();
  gl::popModelView();

  gl::pushModelView();
  gl::color(Color(1, 0, 0));
  gl::translate(Vec3f(-3, 0, 0));
  gl::drawCube(Vec3f(1, 0, 0), Vec3f(2.f, 2.f, 2.f));
  gl::popModelView();

}

CINDER_APP_NATIVE( TextureTestApp, RendererGl )
