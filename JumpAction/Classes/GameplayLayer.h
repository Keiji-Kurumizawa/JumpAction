//
//  GameplayLayer.h
//  JumpAction
//
//  Created by 楜澤圭史 on 2015/07/09.
//
//

#ifndef __GAME_PLAY_LAYER_H__
#define __GAME_PLAY_LAYER_H__

#include "cocos2d.h"
#include "ui/cocosGUI.h"

class GameplayLayer : public cocos2d::Layer
{
public:
    // cppにはidがないので、クラスのインスタンスのポインタ返し
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    float getEyeX();
    
    CREATE_FUNC(GameplayLayer);
    
    
    //タッチ開始
    //void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *event);
};

#endif // __GAME_PLAY_LAYER_H__