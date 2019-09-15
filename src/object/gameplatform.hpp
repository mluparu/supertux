#pragma once
#include <math/vector.hpp>

#define SPRITE_WIDTH (1.0f)

namespace game
{
  namespace io {
    class ReaderMapping {};
  }

  class MovingSprite
  {
  protected:
    /*Rectf bbox;*/
    Vector pos;

  public:
    //const Rectf& get_bbox() const { return bbox; std::find_if(); }
    const Vector& get_pos() const noexcept { return pos; }
    float get_width() const noexcept { return SPRITE_WIDTH; }
    void set_pos(const Vector& _pos) { pos = _pos; /*bbox.set_pos(_pos);*/ }

    MovingSprite() noexcept {}
    MovingSprite(const io::ReaderMapping&) {}

    bool operator<= (const MovingSprite& other) noexcept { return pos.y <= other.get_pos().y; }
    bool operator> (const MovingSprite& other) noexcept { return pos.y > other.get_pos().y; }
    bool operator<= (int other) noexcept { return pos.y <= other; }
    MovingSprite& operator+= (const MovingSprite& other) noexcept { pos.y += other.get_pos().y; return *this; }
    MovingSprite& operator+= (int other) noexcept { pos.y += other; return *this; }
    MovingSprite& operator= (int other) noexcept { pos.y = other; return *this; }
  };

  class Platform : public MovingSprite
  {
  public:
    Platform(const io::ReaderMapping& mapping) : MovingSprite(mapping) {}
    Platform() noexcept {}

    Platform& operator= (int other) noexcept { pos.y = other; return *this; }
  };

  class Rock : public MovingSprite
  {
  public:
    Rock(const io::ReaderMapping& mapping) : MovingSprite(mapping) {}
    Rock() noexcept {}

    Rock& operator= (int other) noexcept { pos.y = other; return *this; }
  };
}
