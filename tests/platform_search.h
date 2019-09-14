#pragma once
#include <utility>
#include <vector>
#include <memory>

namespace game
{
  class Platform;
  class Rock;
}
class Vector;

game::Platform find_longest_jump(Vector currentPosition, const std::vector<game::Platform>& platform);

game::Rock find_longest_jump(Vector currentPosition, const std::vector<game::Rock>& platform);
