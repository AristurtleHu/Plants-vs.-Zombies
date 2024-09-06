#ifndef COOLDOWNMASK_HPP__
#define COOLDOWNMASK_HPP__

#include "pvz/GameObject/GameObject.hpp"

class CooldownMask : public GameObject {
  int m_cooldown;

public:
  CooldownMask(int x, int y, pGameWorld GameWorld, int Cooldown)
      : GameObject(IMGID_COOLDOWN_MASK, x, y, LAYER_COOLDOWN_MASK, 50, 70,
                   ANIMID_NO_ANIMATION, GameWorld),
        m_cooldown(Cooldown) {}
  void OnClick() override {}
  void Update() override {
    m_cooldown--;
    if (m_cooldown == 0)
      SetState(ObjectState::Dead);
  }
};

#endif // !COOLDOWNMASK_HPP__