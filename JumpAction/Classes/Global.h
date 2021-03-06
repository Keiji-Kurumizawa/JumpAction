//
//  Global.h
//  JumpAction
//
//  Created by 楜澤圭史 on 2015/07/10.
//
//

#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include "cocos2d.h"

enum TagOfLayer
{
    BACKGROUND_LAYER = 0,
    GAMEPLAY_LAYER = 1
};
enum TagOfSprite
{
    ROCK_SPRITE = 0
};
class Global
{
public:
    //地面の高さ
    static const float g_groundHeight;
    //プレイヤーの最初のX座標
    static const float g_playerStartX;
    //ステージ横
    static const float g_stageWidth;
    //ジャンプ量
    static const float g_jumpPower;
    //加速
    static const float g_acceleration;
    

};

#endif // __GLOBAL_H__