#ifndef HIT_
#define HIT_
#include "Puzzle.h"


bool HitNextArea(float left_x, float right_x, float up_y, float down_y);

bool HitPlayerObject(float obj_x, float obj_y, float obj_width, float obj_height);

bool HitPlayerEyeObject(float obj_x, float obj_y, float obj_width, float obj_height);

bool HitCabe(int d, int d2, int idx_, PuzzleCabe* puzzle1, float width, float height, float Compare_width, float Compare_height);

#endif