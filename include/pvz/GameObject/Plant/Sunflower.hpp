#ifndef SUNFLOWER_HPP
#define SUNFLOWER_HPP__

#include "pvz/GameObject/Plant/Plant.hpp"

class Sunflower : public Plant {

public:
  Sunflower(int x, int y, pGameWorld GameWorld)
      : Plant(IMGID_SUNFLOWER, x, y, GameWorld, 300, randInt(30, 600)) {}
  void PlantDo() override {
    if (!GetTick()) {
      GetGameWorld()->AddSun(false, GetX(), GetY());
      SetTick(600);
    } else
      DecTick();
  }
};

#endif // !SUNFLOWER_HPP__