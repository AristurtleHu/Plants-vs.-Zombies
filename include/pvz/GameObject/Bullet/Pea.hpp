#ifndef PEA_HPP__
#define PEA_HPP__

#include "pvz/GameObject/Bullet/Bullet.hpp"

class Pea : public Bullet {

public:
  Pea(int x, int y) : Bullet(IMGID_PEA, x, y, 28, 28, 20) {}

  void Update() override {
    if (GetX() >= WINDOW_WIDTH) {
      SetState(ObjectState::Dead);
      return;
    }
    MoveTo(GetX() + 8, GetY());
  }

  void BulletHit() override { SetState(ObjectState::Dead); }
};

#endif // !PEA_HPP__