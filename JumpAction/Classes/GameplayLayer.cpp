//
//  GameplayLayer.cpp
//  JumpAction
//
//  Created by 楜澤圭史 on 2015/07/09.
//
//

#include "GameplayLayer.h"
#include "Global.h"
#include "Player.h"

using namespace cocos2d;

Scene* GameplayLayer::createScene()
{
    // 'scene' はautoreleaseオブジェクト
    auto scene = Scene::create();
    
    // 'layer' はautoreleaseオブジェクト
    auto layer = GameplayLayer::create();
    
    // レイヤーをシーンの子として追加
    scene->addChild(layer);
    
    // シーンを戻す
    return scene;
}

bool GameplayLayer::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    chara = Player::create();
    
    //ジャンプ設定
    auto menuItemPlay = MenuItemImage::create("jump.png", "jump.png", [this](Ref* sender){
        if(chara->getPositionY() <= Global::g_groundHeight + chara->getContentSize().height / 2.0f)
        {
            chara->getPhysicsBody()->applyImpulse(Vect(0,Global::g_jumpPower), Point(0, chara->getContentSize().height));
        }
        return;
    });
    auto menu = Menu::create(menuItemPlay, NULL);
    addChild(menu);

    addChild(chara);

    scheduleUpdate();
    
    return true;
}

void GameplayLayer::update(float delta)
{
    //プレイヤーの移動設定
    if(chara->getPositionX() > Global::g_stageWidth)
    {
        chara->setPosition(Vec2(Global::g_playerStartX, chara->getPositionY()));
        
        chara->getPhysicsBody()->applyImpulse(Vect(Global::g_acceleration, 0));
    }
}
