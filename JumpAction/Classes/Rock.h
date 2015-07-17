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

class Rock : public cocos2d::Sprite
{
public:
    
    static Rock* create(float posx);
    
    virtual bool initWithFile(const std::string& filename);
    
    bool init(float posX);
};

#endif //  __ROCK_H__