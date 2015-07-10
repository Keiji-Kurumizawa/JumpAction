//
//  BackgroundLayer.cpp
//  JumpAction
//
//  Created by 楜澤圭史 on 2015/07/09.
//
//

#include "BackgroundLayer.h"

using namespace cocos2d;

Scene* BackgroundLayer::createScene()
{
    // 'scene' はautoreleaseオブジェクト
    auto scene = Scene::create();
    
    // 'layer' はautoreleaseオブジェクト
    auto layer = BackgroundLayer::create();
    
    // レイヤーをシーンの子として追加
    scene->addChild(layer);
    
    // シーンを戻す
    return scene;
}

bool BackgroundLayer::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    //画面サイズの取得
    //Size visibleSize = Director::getInstance()->getVisibleSize();
    
    //中心計算
    //auto centerpos = visibleSize / 2;
    
    //マップファイル1
    TMXTiledMap *map1 = TMXTiledMap::create("map1.tmx");
    map1->setAnchorPoint(Vec2::ZERO);
    map1->setPosition(Vec2::ZERO);
    addChild(map1);
    //マップの幅を取得
    auto map1Size = map1->getContentSize();
    //幅を格納
    mapWidth = map1Size.width;
    
    //マップファイル2
    TMXTiledMap *map2 = TMXTiledMap::create("map2.tmx");
    //マップ2をマップ1の右隣に設定
    map2->setPosition(mapWidth, 0);
    addChild(map2);
    
    //横スクロール
    auto move = MoveTo::create(10, Vec2(-1600, 0));
    map1->runAction(move);
    
    return true;
}

