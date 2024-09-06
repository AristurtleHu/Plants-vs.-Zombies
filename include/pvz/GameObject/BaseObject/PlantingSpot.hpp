#ifndef PLANTINGSPOT_HPP__
#define PLANTINGSPOT_HPP__

#include "pvz/GameObject/GameObject.hpp"

class PlantingSpot : public GameObject {
public:
  PlantingSpot(int x, int y, pGameWorld GameWorld)
      : GameObject(IMGID_NONE, x, y, LAYER_UI, 60, 80, ANIMID_NO_ANIMATION,
                   GameWorld) {}
  void Update() override {}
  void OnClick() override {
    if (GetGameWorld()->GetHolding() &&
        GetGameWorld()->IsPlant(GetGameWorld()->GetHolding()))
      GetGameWorld()->AddPlant(shared_from_this());
  }
};

#endif // !PLANTINGSPOT_HPP__