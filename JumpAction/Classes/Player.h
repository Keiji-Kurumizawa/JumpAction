//
//  Player.h
//  JumpAction
//
//  Created by 楜澤圭史 on 2015/07/17.
//
//

#ifndef __JumpAction__Player__
#define __JumpAction__Player__

#include "cocos2d.h"

class Player : public cocos2d::Sprite
{
public:
    
    static Player* create();
    
    virtual bool initWithFile(const std::string& filename);
    
    bool init();
};

#endif /* defined(__JumpAction__Player__) */