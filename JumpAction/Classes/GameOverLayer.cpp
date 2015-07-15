//
//  GameOverLayer.cpp
//  JumpAction
//
//  Created by 楜澤圭史 on 2015/07/14.
//
//

#include "GameOverLayer.h"
#include "MenuScene.h"
#include "PlayScene.h"

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
        CC_CALLBACK_1(GameOverLayer::onTitle, this));
    auto menuTitle = Menu::create(menuItemTitle, NULL);
    //メニューの位置設定
    menuTitle->setPosition(Vec2(centerPos.x / 2.0f, centerPos.y));
    //メニューをレイヤーに追加
    addChild(menuTitle);
    
    //リスタートメニュー作成
    auto menuItemRestart = MenuItemSprite::create(
        Sprite::create("restart.png"),
        Sprite::create("restart.png"),
        CC_CALLBACK_1(GameOverLayer::onRestart, this));
    auto menuRestart = Menu::create(menuItemRestart, NULL);
    //メニューの位置設定
    menuRestart->setPosition(Vec2((centerPos.x / 2.0f) * 3.0f, centerPos.y));
    //メニューをレイヤーに追加
    addChild(menuRestart);
    
    return true;
}

void GameOverLayer::onTitle(Ref* pSender)
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

void GameOverLayer::onRestart(Ref* pSender)
{
    //タイトルシーン作成
    auto playScene = PlayScene::createScene();
    //ディレクタの取得
    auto director = Director::getInstance();
    //再開
    director->resume();
    //シーンの変更
    director->replaceScene(playScene);
}