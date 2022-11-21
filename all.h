#ifndef ALL_H
#define ALL_H

//******************************************************************************
//
//
//      all.h
//
//
//******************************************************************************

// システムやライブラリのヘッダーファイルは上の方へ
#include "../GameLib/game_lib.h"
#include <string>
#include <stdlib.h>
#include <time.h>

// 共通で使われるようなヘッダー
#include "common.h"
#include "math.h"
#include "Easing.h"
#include "obj2d.h"
#include "texture.h"

// 個々のヘッダーファイルは下の方へ
#include "audio.h"
#include "scene_game.h"
#include "scene_title.h"
#include "scene_score.h"

// namespace
using namespace GameLib;
using namespace input;

#endif//ALL_H
