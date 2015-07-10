#include "AppDelegate.h"
#include "MenuScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
    
    GLView::setGLContextAttrs(glContextAttrs);
}

// If you want to use packages manager to install more packages,
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}


//ローンチ完了後に呼び出し
bool AppDelegate::applicationDidFinishLaunching() {
    // Directorの初期化
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("My Game");
        director->setOpenGLView(glview);
    }

    // ゲームの仮想画面のサイズ設定
    glview->setDesignResolutionSize(720, 480, kResolutionShowAll);
    
    //スケール設定
    //director->setContentScaleFactor(2.0f);
    
    // FPSの表示
    director->setDisplayStats(false);

    // FPSの設定
    director->setAnimationInterval(1.0 / 60);
    
    register_all_packages();

    // シーンの作成
    auto scene = MenuScene::createScene();

    // シーンの実行
    director->runWithScene(scene);

    return true;
}

// アプリケーションがアクティブでなくなった時に呼び出し
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// アプリケーションが再アクティブになった時に呼び出し
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
