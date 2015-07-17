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
    
    CREATE_FUNC(GameplayLayer);
    
    //定期更新
    void update(float delta);
    
    cocos2d::Sprite* chara;
};

#endif // __GAME_PLAY_LAYER_H__