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

Rock* Rock::create(Layer* layer, float posX)
{
    Rock* pRet = new Rock();
    if(pRet && pRet->init(layer, posX))
    {
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

bool Rock::init(Layer* layer, float posX)
{
    if(!Node::init())
    {
        return false;
    }
    
    sprite = Sprite::create();
    sprite->setTag(TagOfSprite::ROCK_SPRITE);
    
    auto constentSize = sprite->getContentSize();
    
    sprite->setPosition(posX, constentSize.height / 2 + Global::g_groundHeight);
    
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
    sprite->setPhysicsBody(body);
    
    //レイヤーにスプライトを追加
    layer->addChild(sprite, 1);
    
    return true;
    
}