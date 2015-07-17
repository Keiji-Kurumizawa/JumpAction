//
//  Rock.cpp
//  JumpAction
//
//  Created by 楜澤圭史 on 2015/07/13.
//
//

#include "Rock.h"
#include "Global.h"

using namespace cocos2d;

Rock* Rock::create(float posX)
{
    Rock* pRet = new Rock();
    if(pRet && pRet->initWithFile("rock.png"))
    {
        pRet->init(posX);
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

bool Rock::initWithFile(const std::string& filename) {
    return Sprite::initWithFile(filename);
}

bool Rock::init(float posX)
{
    if(!Node::init())
    {
        return false;
    }
    
    setTag(TagOfSprite::ROCK_SPRITE);
    
    auto constentSize = getContentSize();
    
    setPosition(posX, constentSize.height / 2 + Global::g_groundHeight);
    
    //マテリアル設定
    auto material = PHYSICSBODY_MATERIAL_DEFAULT;
    //密度を設定
    material.density = 1.0f;
    //反発係数を設定
    material.restitution = 0.0f;
    //摩擦係数を設定
    material.friction = 0.0f;
    
    //剛体を作成
    auto body = PhysicsBody::createBox(constentSize,material);
    //重力の影響を受けない
    body->setGravityEnable(false);
    //衝突を検出
    body->setContactTestBitmask(true);
    //動かない
    body->setDynamic(false);
    
    //スプライトと剛体を関連付ける
    setPhysicsBody(body);
    
    return true;
    
}