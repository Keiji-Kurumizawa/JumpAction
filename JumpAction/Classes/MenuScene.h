//
//  MenuScene.h
//  JumpAction
//
//  Created by 楜澤圭史 on 2015/07/09.
//
//

#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"
#include "ui/cocosGUI.h"

class MenuScene : public cocos2d::Layer
{
public:
    // cppにはidがないので、クラスのインスタンスのポインタ返し
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(MenuScene);
};

#endif // __MENU_SCENE_H__
