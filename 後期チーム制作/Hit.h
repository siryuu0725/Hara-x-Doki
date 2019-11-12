#ifndef HIT_
#define HIT_
#include "Puzzle.h"



bool HitCabe1_1(int idx_, Puzzle_1* puzzle1);
bool HitCabe1_2(int idx_, Puzzle_1* puzzle1, Puzzle_2* puzzle2);
bool HitCabe1_3(int idx_, Puzzle_1* puzzle1, Puzzle_3* puzzle3);


bool HitCabe2_2(int idx_, Puzzle_2* puzzle2);
bool HitCabe2_1(int idx_, Puzzle_2* puzzle2, Puzzle_1* puzzle1);
bool HitCabe2_3(int idx_, Puzzle_2* puzzle2, Puzzle_3* puzzle3);


bool HitCabe3_3(int idx_, Puzzle_3* puzzle3);
bool HitCabe3_1(int idx_, Puzzle_3* puzzle3, Puzzle_1* puzzle1);
bool HitCabe3_2(int idx_, Puzzle_3* puzzle3, Puzzle_2* puzzle2);

#endif