//
//  PlaySecene.cpp
//  JumpAction
//
//  Created by 楜澤圭史 on 2015/07/09.
//
//

#include "PlayScene.h"
#include "BackgroundLayer.h"
#include "GameplayLayer.h"
#include "Global.h"

using namespace cocos2d;

USING_NS_CC;

Scene* PlayScene::createScene()
{
    // 物理空間が付いたシーンの作成
    auto scene = Scene::createWithPhysics();
    
    //物理空間
    auto world = scene->getPhysicsWorld();
    
    //重力の設定
    world->setGravity(Vec2(0, -350));
    
    /* デバック */
    world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    /* デバック */
    
    // 'layer' はautoreleaseオブジェクト
    auto layer = PlayScene::create();
    
    // レイヤーをシーンの子として追加
    scene->addChild(layer);
    
    // シーンを戻す
    return scene;
}

bool PlayScene::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    //物理エンジン初期化
    initPhysics();
    
    //レイヤー追加(BackGround)
    auto backgroundLayer = BackgroundLayer::createScene();
    addChild(backgroundLayer);
    backgroundLayer->setTag(TagOfLayer::BACKGROUND_LAYER);

    //レイヤー追加(BackGround)
    auto gameplayLayer = GameplayLayer::createScene();
    addChild(gameplayLayer);
    gameplayLayer->setTag(TagOfLayer::GAMEPLAY_LAYER);
    
    return true;
}

bool PlayScene::initPhysics()
{
    //地面の作成
    auto ground = Node::create();
    addChild(ground);
    
    //アンカーポイント
    ground->setAnchorPoint(Vec2::ZERO);
    //位置
    ground->setPosition(Vec2::ZERO);
    //左右方向に大きなサイズにする
    ground->setContentSize(Size(10000000, Global::g_groundHeight * 2));
    
    //マテリアルの作成
    auto material = PHYSICSBODY_MATERIAL_DEFAULT;
    //密度
    material.density = 1.0f;
    //反発係数
    material.restitution = 0.0f;
    //摩擦係数
    material.friction = 0.0f;
    //剛体作成
    auto body = PhysicsBody::createBox(ground->getContentSize(), material);
    //重力の影響
    body->setDynamic(false);
    //衝突
    body->setContactTestBitmask(true);
    
    //剛体の設定
    ground->setPhysicsBody(body);
    
    //プレイヤーとオブジェクトとの衝突判定を作成
    auto collisionCoinListener = EventListenerPhysicsContact::create();
    collisionCoinListener->onContactBegin = CC_CALLBACK_1(PlayScene::onCollisionBegin, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(collisionCoinListener, this);
    
    
    return true;
}

bool PlayScene::onCollisionBegin(cocos2d::PhysicsContact &contact)
{
    //一つ目の衝突形状を取得する
    auto shapeA = contact.getShapeA();
    auto nodeA = shapeA->getBody()->getNode();
    
    //二つ目の衝突形状を取得
    auto shapeB = contact.getShapeB();
    auto nodeB = shapeB->getBody()->getNode();
    
    if(nodeA->getTag() < 0 || nodeB->getTag() < 0)
    {
        //タグが付与されていなければ、衝突判定の必要がないもの。判定を行わない。
        return true;
    }
    
    else if(nodeA->getTag() == TagOfSprite::ROCK_SPRITE
        ||  nodeB->getTag() == TagOfSprite::ROCK_SPRITE)
    {
        log("==gameover");
    }
    return true;
}