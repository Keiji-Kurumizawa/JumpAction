//
//  GameplayLayer.cpp
//  JumpAction
//
//  Created by 楜澤圭史 on 2015/07/09.
//
//

#include "GameplayLayer.h"
#include "Global.h"

using namespace cocos2d;

Scene* GameplayLayer::createScene()
{
    // 'scene' はautoreleaseオブジェクト
    //重力判定
    auto scene = Scene::createWithPhysics();
    
    Vect gravity;
    gravity.setPoint(0, -50);
    
    scene->getPhysicsWorld()->setGravity(gravity);
    scene->getPhysicsWorld()->setSpeed(6.0f);
    
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
    
    //キャラクターのスプライト作成
    auto player = Sprite::create("chara.png");
    //キャラクターサイズ取得
    auto playerSize = player->getContentSize();
    //キャラクター位置設定
    player->setPosition(Vec2(Global::g_playerStartX, Global::g_groundHeight));
    
    //マテリアル作成
    auto material = PHYSICSBODY_MATERIAL_DEFAULT;
    //密度
    material.density = 1.0f;
    //反発係数
    material.restitution = 0.0f;
    //摩擦係数
    material.friction = 0.0f;
    //剛体作成
    auto body = PhysicsBody::createBox(playerSize, material);
    //重さの設定
    body->setMass(1.0f);
    //回転しない
    body->setRotationEnable(false);
    //重力の影響
    body->setGravityEnable(true);
    //衝突
    body->setContactTestBitmask(true);
    //撃力
    body->applyImpulse(Vect(0, 0), Point(0, 0));
    
    //剛体の設定
    player->setPhysicsBody(body);
    
    //キャラクターの移動
    //auto move = MoveTo::create(8, Vec2(700, 110));
    auto move = MoveBy::create(8, Vec2(900, 110));
    player->runAction(move);
    
    //ジャンプ仮設定
    auto menuItemPlay = MenuItemImage::create("Charactor.png", "Charactor.png", [this,player](Ref* sender){
        player->getPhysicsBody()->applyImpulse(Vect(0,220.0f), Point(0, player->getContentSize().height));
        return;
    });
    auto menu = Menu::create(menuItemPlay, NULL);
    addChild(menu);
    
    addChild(player, 0);
    
    this->scheduleUpdate();
    
    return true;
}

void GameplayLayer::update(float delta)
{
    //ここにプレイヤー移動処理を加える
    //プレイヤーの移動設定
    //if(player->getPositionX() > 800)
    //{
    //    player->setPosition(Vec2(0, Global::g_groundHeight));
    //}
}