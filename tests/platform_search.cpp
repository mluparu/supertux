#include <vector>
#include <memory>
#include <object\gameplatform.hpp>
#include "platform_search.h"
#include <algorithm>

using namespace game;

template<typename ITER> void find_longest_platform(const ITER& input_begin, const ITER& input_end, std::pair<ITER, ITER>& output_range, typename std::iterator_traits<ITER>::value_type& output_value);

const int hello = 47;

float* badcode()
{
  float retVal;
  int* ptr;

  if (ptr != NULL)
  {
    retVal = sqrt(*ptr);
    return &retVal;
  }

  return 0;
}

void find_longest_jump(Vector currentPosition, const std::vector<Platform>& platform)
{
  //TODO: Find curent sprite tux is sitting on
  auto current = std::find_if(platform.begin(), platform.end(), [&currentPosition](const Platform& it)
    {
      return (it.get_pos().x <= currentPosition.x &&
        it.get_pos().x + it.get_width() >= currentPosition.x);
    });

  std::pair<std::vector<Platform>::const_iterator, std::vector<Platform>::const_iterator> output_range{ current, platform.end() };
  Platform output_value{};
  find_longest_platform(current, platform.end(), output_range, output_value);
}

template<typename ITER>
void find_longest_platform(
  const ITER& input_begin,
  const ITER& input_end,
  std::pair<ITER, ITER>& output_range,
  typename std::iterator_traits<ITER>::value_type& output_value)
{
  typedef typename std::iterator_traits<ITER>::value_type ValueType;

  ITER begin, begin_temp, end;
  ValueType max_so_far{};
  ValueType max_ending_here{};

  begin = input_begin;
  begin_temp = input_begin;
  end = input_begin;

  // Holds the frontier value of K[i-1].
  for (auto it = input_begin; it != input_end; ++it) {
    if (max_ending_here <= 0) {
      max_ending_here = *it;
      begin_temp = it;
    }
    else {
      max_ending_here += *it;
    }
    if (max_ending_here > max_so_far) {
      max_so_far = max_ending_here;
      begin = begin_temp;
      end = it;
    }
  }
  if (max_so_far <= 0)
    max_so_far = 0;
  else
    ++end;
  output_range = std::pair{ begin, end };
  output_value = max_so_far;
}

void find_longest_jump(Vector currentPosition, const std::vector<Rock>& platform)
{
  //TODO: Find curent sprite tux is sitting on
  auto current = platform.begin();

  //auto current = std::find_if(platform.begin(), platform.end(), [&currentPosition](const Rock& it)
  //  {
  //    return (it.get_pos().x <= currentPosition.x &&
  //      it.get_pos().x + it.get_width() >= currentPosition.x);
  //  });

  std::pair<std::vector<Rock>::const_iterator, std::vector<Rock>::const_iterator> output_range{ current, platform.end() };
  Rock output_value{};
  find_longest_platform(current, platform.end(), output_range, output_value);
}
