#ifndef SUNFLOWERSEED_HPP__
#define SUNFLOWERSEED_HPP__

#include "pvz/GameObject/PlantSeed/Seed.hpp"

class Sunflower;

class SunflowerSeed : public Seed {
public:
  SunflowerSeed(pGameWorld GameWorld)
      : Seed(IMGID_SEED_SUNFLOWER, 1, GameWorld, 50, 240) {}

  void GiveHold() override {
    GetGameWorld()->SetHolding(
        std::make_shared<Sunflower>(0, 0, GetGameWorld()));
  }
};

#endif // !SUNFLOWERSEED_HPP__