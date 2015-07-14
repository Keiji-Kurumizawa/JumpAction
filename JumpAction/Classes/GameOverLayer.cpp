//
//  GameOverLayer.cpp
//  JumpAction
//
//  Created by 楜澤圭史 on 2015/07/14.
//
//

#include "GameOverLayer.h"
#include "MenuScene.h"

using namespace cocos2d;

Scene* GameOverLayer::createScene() {
	auto scene = Scene::create();
	auto layer = GameOverLayer::create();
	scene->addChild(layer);
	
    return scene;
}

bool GameOverLayer::init()
{
    if (!LayerColor::initWithColor(Color4B(0, 0, 0, 150)))
    {
        return false;
    }
    
    //ディレクタの取得
    auto director = Director::getInstance();
    //ウィンドウサイズの取得
    auto winSize = director->getWinSize();
    //中心の位置を計算
    auto centerPos = Vec2(winSize.width / 2.0f, winSize.height / 2.0f);
    //タイトルへ戻るメニュー作成
    auto menuItemTitle = MenuItemSprite::create(
        Sprite::create("back.png"),
        Sprite::create("back.png"),
        CC_CALLBACK_1(GameOverLayer::onRestart, this));
    auto menu = Menu::create(menuItemTitle, NULL);
    //メニューの位置設定
    menu->setPosition(centerPos);
    //メニューをレイヤーに追加
    addChild(menu);
    
    return true;
}

void GameOverLayer::onRestart(Ref* pSender)
{
    //タイトルシーン作成
    auto titleScene = MenuScene::createScene();
    //ディレクタの取得
    auto director = Director::getInstance();
    //再開
    director->resume();
    //シーンの変更
    director->replaceScene(titleScene);
}