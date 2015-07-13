//
//  Rock.h
//  JumpAction
//
//  Created by 楜澤圭史 on 2015/07/13.
//
//

#ifndef __ROCK_H__
#define __ROCK_H__

#include "cocos2d.h"

class Rock : public cocos2d::Node
{
private:
    // スプライト
    cocos2d::Sprite* sprite;
    //マップインデックス
    int mapIndex;
    
public:
    //インスタンスの生成
    static Rock* create(cocos2d::Layer* layer, float posx);
    //初期化
    bool init(cocos2d::Layer* layer, float posX);
    // get
    int getMapIndex()
    {
        return mapIndex;
    }
    // set
    void setMapIndex(int mapIndex)
    {
        this->mapIndex = mapIndex;
    }
};

#endif //  __ROCK_H__