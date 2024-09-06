#ifndef EXPLOSION_HPP__
#define EXPLOSION_HPP__

#include "pvz/GameObject/Bullet/Bullet.hpp"

class Explosion : public Bullet {
  int m_tick = 0;

public:
  Explosion(int x, int y)
      : Bullet(IMGID_EXPLOSION, x, y, 3 * LAWN_GRID_WIDTH, 3 * LAWN_GRID_HEIGHT,
               65536) {}

  void Update() override {
    m_tick++;
    if (m_tick >= 3)
      SetState(ObjectState::Dead);
  }
  void BulletHit() override {}
};

#endif // !EXPLOSION_HPP__