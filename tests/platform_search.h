#pragma once
#include <utility>
#include <vector>
#include <memory>
#include <object\gameplatform.hpp>

typedef std::vector<game::Platform> MovingSpriteVec;
typedef std::vector<game::Platform>::iterator MovingSpriteVecIter;

void find_longest_jump(Vector currentPosition, const MovingSpriteVec& platform);

typedef std::vector<game::Rock> RockVec;
typedef std::vector<game::Rock>::const_iterator RockVecIter;
void find_longest_jump(Vector currentPosition, const RockVec& platform);
