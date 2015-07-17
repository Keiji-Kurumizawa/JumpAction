//
//  BackgroundLayer.h
//  JumpAction
//
//  Created by 楜澤圭史 on 2015/07/09.
//
//

#ifndef __BACK_GROUND_LAYER_H__
#define __BACK_GROUND_LAYER_H__

#include "cocos2d.h"
#include "ui/cocosGUI.h"
#include "Rock.h"

class BackgroundLayer : public cocos2d::Layer
{
public:
    
    //背景マップ
    cocos2d::TMXTiledMap* map;
    
    // cppにはidがないので、クラスのインスタンスのポインタ返し
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    void loadObjects(cocos2d::TMXTiledMap* map);
    
    CREATE_FUNC(BackgroundLayer);
};

#endif // __BACK_GROUND_LAYER_H__