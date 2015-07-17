//
//  Global.cpp
//  JumpAction
//
//  グローバル変数の格納(地面の高さ、プレイヤー)
//  Created by 楜澤圭史 on 2015/07/10.
//
//

#include "Global.h"

using namespace cocos2d;

//地面の高さ
const float Global::g_groundHeight = 97.0f;

//プレイヤーの最初のX座標
const float Global::g_playerStartX = -10.0f;

//ステージ横
const float Global::g_stageWidth = 730.0f;

//ジャンプ量
const float Global::g_jumpPower = 200.0f;

//加速
const float Global::g_acceleration = 15.0f;