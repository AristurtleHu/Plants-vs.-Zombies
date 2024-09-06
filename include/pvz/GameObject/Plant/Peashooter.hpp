#ifndef PEASHOOTER_HPP__
#define PEASHOOTER_HPP__

#include "pvz/GameObject/Plant/Plant.hpp"

class Pea;

class Peashooter : public Plant {
public:
  Peashooter(int x, int y, pGameWorld GameWorld)
      : Plant(IMGID_PEASHOOTER, x, y, GameWorld, 300, 30) {}

  void PlantDo() override {
    if (!GetTick()) {
      if (GetGameWorld()->ZombieExist(GetX(), GetY())) {
        GetGameWorld()->AddObject(
            std::make_shared<Pea>(GetX() + 30, GetY() + 20));
        SetTick(30);
      }
    } else
      DecTick();
  }
};

#endif // !PEASHOOTER_HPP__