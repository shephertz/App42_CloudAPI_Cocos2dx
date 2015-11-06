#include "AppDelegate.h"

#include "TestUserService.h"


USING_NS_CC;

#define API_KEY    "b7915f2fca1fb7f53f4f519d6d79dae11b7c948ccc5511ef5ad9d19eceb6376f"
#define SECRET_KEY "f5f1d84b849d459ef3217ef12ffd2931474379783402711c23908b464629ecdf"

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }
    
    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    /***
     * App42 API Initialization
     */
    App42API::Initialize(API_KEY, SECRET_KEY);
    
    // create a scene. it's an autorelease object
    auto scene = TestUserService::createScene();
    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
