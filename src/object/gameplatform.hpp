#pragma once
#include <math/vector.hpp>

#define SPRITE_WIDTH (16.0f)

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
    const Vector& get_pos() const { return pos; }
    float get_width() const { return SPRITE_WIDTH; }
    void set_pos(const Vector& _pos) { pos = _pos; /*bbox.set_pos(_pos);*/ }

    MovingSprite() {}
    MovingSprite(const io::ReaderMapping&) {}

    bool operator<= (const MovingSprite& other) { return pos.x <= other.get_pos().x; }
    bool operator> (const MovingSprite& other) { return pos.x > other.get_pos().x; }
    bool operator<= (int other) { return pos.x <= other; }
    MovingSprite& operator+= (const MovingSprite& other) { pos.x += other.get_pos().x; return *this; }
    MovingSprite& operator+= (int other) { pos.x += other; return *this; }
    MovingSprite& operator= (const MovingSprite& other) { pos.x = other.get_pos().x; return *this; }
    MovingSprite& operator= (int other) { pos.x = (float)other; return *this; }
  };

  class Platform : public MovingSprite
  {
  public:
    Platform(const io::ReaderMapping& mapping) : MovingSprite(mapping) {}
    Platform() {}

    bool operator<= (const Platform& other) { return pos.x <= other.get_pos().x; }
    bool operator> (const Platform& other) { return pos.x > other.get_pos().x; }
    bool operator<= (int other) { return pos.x <= other; }
    Platform& operator+= (const Platform& other) { pos.x += other.get_pos().x; return *this; }
    Platform& operator+= (int other) { pos.x += other; return *this; }
    Platform& operator= (const Platform& other) { pos.x = other.get_pos().x; return *this; }
    Platform& operator= (int other) { pos.x = (float)other; return *this; }
  };

  class Rock : public MovingSprite
  {
  public:
    Rock(const io::ReaderMapping& mapping) : MovingSprite(mapping) {}
    Rock() {}

    bool operator<= (const Rock& other) { return pos.x <= other.get_pos().x; }
    bool operator> (const Rock& other) { return pos.x > other.get_pos().x; }
    bool operator<= (int other) { return pos.x <= other; }
    Rock& operator+= (const Rock& other) { pos.x += other.get_pos().x; return *this; }
    Rock& operator+= (int other) { pos.x += other; return *this; }
    Rock& operator= (const Rock& other) { pos.x = other.get_pos().x; return *this; }
    Rock& operator= (int other) { pos.x = (float)other; return *this; }
  };
}
