//
//  GameOverLayer.h
//  JumpAction
//
//  Created by 楜澤圭史 on 2015/07/14.
//
//

#ifndef __JumpAction__GameOverLayer__
#define __JumpAction__GameOverLayer__

#include "cocos2d.h"

class GameOverLayer : public cocos2d::LayerColor
{
public:
    virtual bool init();
    static cocos2d::Scene *createScene();
    CREATE_FUNC(GameOverLayer);
    
    void onRestart(Ref* pSender);
};

#endif /* defined(__JumpAction__GameOverLayer__) */