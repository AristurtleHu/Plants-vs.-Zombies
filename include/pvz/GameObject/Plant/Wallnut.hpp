#ifndef WALLNUT_HPP__
#define WALLNUT_HPP__

#include "pvz/GameObject/Plant/Plant.hpp"

class Wallnut : public Plant {
public:
  Wallnut(int x, int y, pGameWorld gameWorld)
      : Plant(IMGID_WALLNUT, x, y, gameWorld, 4000) {}

  void PlantDo() override {
    if (GetHP() <= 4000 / 3) {
      ChangeImage(IMGID_WALLNUT_CRACKED);
    }
  }
};

#endif // !WALLNUT_HPP__