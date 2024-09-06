#ifndef WALLNUTSEED_HPP__
#define WALLNUTSEED_HPP__

#include "pvz/GameObject/PlantSeed/Seed.hpp"

class Wallnut;

class WallnutSeed : public Seed {
public:
  WallnutSeed(pGameWorld gameWorld)
      : Seed(IMGID_SEED_WALLNUT, 3, gameWorld, 50, 900) {}

  void GiveHold() override {
    GetGameWorld()->SetHolding(std::make_shared<Wallnut>(0, 0, GetGameWorld()));
  }
};

#endif // !WALLNUTSEED_HPP__