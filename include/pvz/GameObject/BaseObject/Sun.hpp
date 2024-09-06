#ifndef SUN_HPP__
#define SUN_HPP__

#include "pvz/GameObject/GameObject.hpp"

class Sun : public GameObject {
  int m_drop_time = 12;
  int m_tick_floor = 0;
  int m_tick = 0;
  bool m_skySun;

public:
  Sun(int x, int y, pGameWorld GameWorld, bool SkySun = true)
      : GameObject(IMGID_SUN, x, y, LAYER_SUN, 80, 80, ANIMID_IDLE_ANIM,
                   GameWorld),
        m_skySun(SkySun) {
    if (m_skySun)
      m_drop_time = randInt(63, 263);
  }

  void Update() override {
    if (m_tick < m_drop_time) {
      if (m_skySun)
        MoveTo(GetX(), GetY() - 2);
      else
        MoveTo(GetX() - 1, GetY() + (4 - m_tick));
      m_tick++;
    } else {
      m_tick_floor++;
      if (m_tick_floor >= 300)
        SetState(ObjectState::Dead);
    }
  }

  void OnClick() override {
    GetGameWorld()->SetSun(GetGameWorld()->GetSun() + 25);
    SetState(ObjectState::Dead);
  }
};

#endif // !SUN_HPP__