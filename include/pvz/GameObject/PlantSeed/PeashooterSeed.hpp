#ifndef PEASHOOTERSEED_HPP__
#define PEASHOOTERSEED_HPP__

#include "pvz/GameObject/PlantSeed/Seed.hpp"

class Peashooter;

class PeashooterSeed : public Seed {
public:
  PeashooterSeed(pGameWorld GameWorld)
      : Seed(IMGID_SEED_PEASHOOTER, 2, GameWorld, 100, 240) {}

  void GiveHold() override {
    GetGameWorld()->SetHolding(
        std::make_shared<Peashooter>(0, 0, GetGameWorld()));
  }
};

#endif // !PEASHOOTERSEED_HPP__