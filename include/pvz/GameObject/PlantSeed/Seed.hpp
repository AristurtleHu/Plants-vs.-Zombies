#ifndef SEED_HPP__
#define SEED_HPP__

#include "pvz/GameObject/BaseObject/CooldownMask.hpp"
#include "pvz/GameObject/GameObject.hpp"

class Seed : public GameObject {
  int m_sunCost;
  int m_cooldown;

public:
  Seed(ImageID imageID, int pos, pGameWorld GameWorld, int SunCost,
       int Cooldown)
      : GameObject(imageID, 70 + pos * 60, WINDOW_HEIGHT - 44, LAYER_UI, 50, 70,
                   ANIMID_NO_ANIMATION, GameWorld),
        m_sunCost(SunCost), m_cooldown(Cooldown) {}

  virtual void Update() {}
  virtual void GiveHold() = 0;

  virtual void OnClick() {
    if (GetGameWorld()->GetHolding() == nullptr)
      if (GetGameWorld()->GetSun() >= m_sunCost) {
        GetGameWorld()->AddObject(std::make_shared<CooldownMask>(
            GetX(), GetY(), GetGameWorld(), m_cooldown));
        GiveHold();
        GetGameWorld()->SetSun(GetGameWorld()->GetSun() - m_sunCost);
      }
  }
};

#endif // !SEED_HPP__