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
    
    //マップファイル1
    map1 = TMXTiledMap::create("map3.tmx");
    map1->setAnchorPoint(Vec2::ZERO);
    map1->setPosition(Vec2::ZERO);
    addChild(map1);
    //マップの幅を取得
    auto map1Size = map1->getContentSize();
    //幅を格納
    mapWidth = map1Size.width;
    
    //マップファイル2
    map2 = TMXTiledMap::create("map3.tmx");
    //マップ2をマップ1の右隣に設定
    map2->setPosition(mapWidth, 0);
    addChild(map2);
    
    loadObjects(map1, 0);
    //loadObjects(map2, 1);
    
    //横スクロール
    //auto move = MoveTo::create(10, Vec2(-800, 0));
    //map1->runAction(move);
    //map2->runAction(move);
    
    return true;
}

void BackgroundLayer::loadObjects(TMXTiledMap* map, int mapIndex)
{
    //岩のオブジェクトグループを作成
    auto rockGroup = map->getObjectGroup("rock");
    //岩のオブジェクトの配列を取得する
    auto rockArray = rockGroup->getObjects();
    //岩オブジェクトをリストに登録
    for(int i = 0; i < rockArray.size(); i++)
    {
        //オブジェクト取得
        Value object = rockArray.at(i);
        //オブジェクトのプロパティを取得
        ValueMap objectInfo = object.asValueMap();
        //岩オブジェクト作成
        auto rock = Rock::create(this, objectInfo.at("x").asFloat() + mapWidth * mapIndex);
        //岩オブジェクトのマップインデックスを設定
        rock->setMapIndex(mapIndex);
        //岩オブジェクトをリストに追加
        objects.pushBack(rock);
    }
}
