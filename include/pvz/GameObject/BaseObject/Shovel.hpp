#ifndef SHOVEL_HPP__
#define SHOVEL_HPP__

#include "pvz/GameObject/GameObject.hpp"

class Shovel : public GameObject {
public:
  Shovel(pGameWorld GameWorld)
      : GameObject(IMGID_SHOVEL, 600, WINDOW_HEIGHT - 40, LAYER_UI, 50, 50,
                   ANIMID_NO_ANIMATION, GameWorld, ObjectID::Shovel) {}
  void Update() override {}
  void OnClick() override {
    pGameObject holding = GetGameWorld()->GetHolding();
    if (holding == nullptr)
      GetGameWorld()->SetHolding(shared_from_this());
    else if (GetGameWorld()->IsShovel(holding))
      GetGameWorld()->SetHolding(nullptr);
  }
};

#endif // !SHOVEL_HPP__