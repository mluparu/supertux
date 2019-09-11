#pragma once
#include <utility>
#include <vector>
#include <memory>
#include <object/gameplatform.hpp>

game::Platform find_longest_jump(Vector currentPosition, const std::vector<game::Platform>& platform);

game::Rock find_longest_jump(Vector currentPosition, const std::vector<game::Rock>& platform);
