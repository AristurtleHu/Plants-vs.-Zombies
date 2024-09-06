#ifndef CHERRYBOMB_HPP__
#define CHERRYBOMB_HPP__

#include "pvz/GameObject/Plant/Plant.hpp"

class Explosion;

class CherryBomb : public Plant {
public:
  CherryBomb(int x, int y, pGameWorld GameWorld)
      : Plant(IMGID_CHERRY_BOMB, x, y, GameWorld, 4000, 15) {}

  void PlantDo() override {
    if (!GetTick()) {
      SetState(ObjectState::Dead);
      GetGameWorld()->AddObject(std::make_shared<Explosion>(GetX(), GetY()));
    }
    DecTick();
  }
};

#endif // !CHERRYBOMB_HPP__