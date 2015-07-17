//
//  Player.cpp
//  JumpAction
//
//  Created by 楜澤圭史 on 2015/07/17.
//
//

#include "Player.h"
#include "Global.h"

using namespace cocos2d;

Player* Player::create()
{
    Player* plr = new Player();
    if(plr && plr->initWithFile("chara.png"))
    {
        plr->init();
        plr->autorelease();
        return plr;
    }
    else
    {
        delete plr;
        plr = NULL;
        return NULL;
    }
}

bool Player::initWithFile(const std::string& filename) {
    return Sprite::initWithFile(filename);
}

bool Player::init()
{
    //キャラクターのスプライト作成
//    auto player = Sprite::create("chara.png");
    //キャラクターサイズ取得
    auto playerSize = getContentSize();
    //キャラクター位置設定
    setPosition(Vec2(Global::g_playerStartX, Global::g_groundHeight + playerSize.height / 2.0f));
    
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
    body->applyImpulse(Vect(100, 0), Point(0, 0));
    
    //剛体の設定
    setPhysicsBody(body);
    
    return true;
}

