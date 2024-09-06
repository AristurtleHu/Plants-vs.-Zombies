#ifndef CHEERYBOMBSEED_HPP__
#define CHEERYBOMBSEED_HPP__

#include "pvz/GameObject/PlantSeed/Seed.hpp"

class CherryBomb;

class CherryBombSeed : public Seed {
public:
  CherryBombSeed(pGameWorld GameWorld)
      : Seed(IMGID_SEED_CHERRY_BOMB, 4, GameWorld, 150, 1200) {}

  void GiveHold() override {
    GetGameWorld()->SetHolding(
        std::make_shared<CherryBomb>(0, 0, GetGameWorld()));
  }
};

#endif // !CHEERYBOMBSEED_HPP__