//
//  MenuScene.cpp
//  JumpAction
//
//  Created by 楜澤圭史 on 2015/07/09.
//
//
#include "MenuScene.h"
#include "PlayScene.h"
#include "BackgroundLayer.h"
#include "GameOverLayer.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
    // 'scene' はautoreleaseオブジェクト
    auto scene = Scene::create();
    
    // 'layer' はautoreleaseオブジェクト
    auto layer = MenuScene::create();
    
    // レイヤーをシーンの子として追加
    scene->addChild(layer);
    
    // シーンを戻す
    return scene;
}

// "init" ではインスタンスの初期化
bool MenuScene::init()
{
    //親クラスの初期化
    if (!Layer::init())
    {
        return false;
    }
    
    //画面サイズ取得
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //中心を計算
    auto centerpos = visibleSize / 2;
    
    //背景の設定、位置と中心の設定
    auto spritebg = Sprite::create("title.png");
    spritebg->setPosition(centerpos);
    addChild(spritebg);
    
    //メニューアイテムの作成
    auto menuItemPlay = MenuItemImage::create("start.png", "start.png", [this](Ref* sender){
        log("err");
        Director::getInstance()->replaceScene(PlayScene::createScene());
    });
    
    auto menu = Menu::create(menuItemPlay, NULL);
    addChild(menu);
    
    return true;
}
