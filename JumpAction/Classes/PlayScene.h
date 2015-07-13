//
//  PlaySecene.h
//  JumpAction
//
//  Created by 楜澤圭史 on 2015/07/09.
//
//

#ifndef __PLAY_SCENE_H__
#define __PLAY_SCENE_H__

#include "cocos2d.h"
#include "ui/cocosGUI.h"

class PlayScene : public cocos2d::Layer
{
public:
    // cppにはidがないので、クラスのインスタンスのポインタ返し
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(PlayScene);
    
    bool initPhysics();
    
    bool onCollisionBegin(cocos2d::PhysicsContact &contact);
};

#endif // __PLAY_SCENE_H__