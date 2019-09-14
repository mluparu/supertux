#include <gtest/gtest.h>
#include <util/reader_document.hpp>
#include <util/reader_mapping.hpp>
#include <physfs.h>
#include <codecvt>
#include <object/gameplatform.hpp>

using namespace game;
#include "platform_search.h"

TEST(PlatformTest, create_platform)
{
  PHYSFS_init("");
  std::istringstream in(
    "(platform\n"
    "   (x 1.0001)\n\r"
    "   (y 1.0001)\n\r"
    "   (sprite \"test\")\n"
    "   (name \"Platform\")\n"
    ")\n");

  auto doc = ReaderDocument::from_stream(in);
  auto root = doc.get_root();
  ASSERT_EQ("platform", root.get_name());
  ReaderMapping mapping = root.get_mapping();

  Platform plat{};
  plat.set_pos(Vector(1.0001, 1.0001));

  ASSERT_FLOAT_EQ(plat.get_pos().x, 1.0001);
}

#define LONG_PLATFORM_SIZE 32
TEST(PlatformTest, create_long_platform)
{
  PHYSFS_init("");
  std::istringstream in(
    "(platform\n"
    "   (sprite \"test\")\n"
    "   (name \"Platform\")\n"
    ")\n");

  auto doc = ReaderDocument::from_stream(in);
  auto root = doc.get_root();
  ASSERT_EQ("platform", root.get_name());
  ReaderMapping mapping = root.get_mapping();

  std::vector<Platform> long_platform;
  for (int i = 0; i < LONG_PLATFORM_SIZE; ++i)
  {
    Platform plat{};
    plat.set_pos({ (float)i, 1.0f });
    long_platform.push_back(plat);
  }

  const auto ret = find_longest_jump(Vector(14, 2.0f), long_platform);

  ASSERT_EQ(ret.get_pos().x, 0);
  ASSERT_EQ(long_platform.size(), LONG_PLATFORM_SIZE);
}

TEST(PlatformTest, create_rock_platform)
{
  PHYSFS_init("");
  std::istringstream in(
    "(platform\n"
    "   (sprite \"test\")\n"
    "   (name \"Platform\")\n"
    ")\n");

  const auto doc = ReaderDocument::from_stream(in);
  const auto root = doc.get_root();
  ASSERT_EQ("platform", root.get_name());
  ReaderMapping mapping = root.get_mapping();

  std::vector<Rock> long_platform;
  for (int i = 0; i < LONG_PLATFORM_SIZE; ++i)
  {
    Rock plat{};
    plat.set_pos({ (float)i, 1.0f });
    long_platform.push_back(plat);
  }

  auto ret = find_longest_jump(Vector(14, 2.0f), long_platform);
  ASSERT_EQ(ret.get_pos().x, 0);

  ASSERT_EQ(long_platform.size(), LONG_PLATFORM_SIZE);
}
