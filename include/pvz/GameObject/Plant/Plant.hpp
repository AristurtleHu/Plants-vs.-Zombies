#ifndef PLANT_HPP__
#define PLANT_HPP__

#include "pvz/GameObject/GameObject.hpp"

class Plant : public GameObject {
  int m_tick = 0;
  int m_hp = 0;

public:
  Plant(ImageID imageID, int x, int y, pGameWorld GameWorld, int HP = 300,
        int tick = 0)
      : GameObject(imageID, x, y, LAYER_PLANTS, 60, 80, ANIMID_NO_ANIMATION,
                   GameWorld, ObjectID::Plant),
        m_hp(HP), m_tick(tick) {}

  void OnClick() override {
    if (GetGameWorld()->GetHolding() &&
        GetGameWorld()->IsShovel(GetGameWorld()->GetHolding())) {
      SetState(ObjectState::Dead);
      GetGameWorld()->SetHolding(nullptr);
    }
  }

  virtual void PlantDo() = 0;

  int GetTick() const { return m_tick; }
  void DecTick() { m_tick--; }
  void SetTick(int tick) { m_tick = tick; }
  int GetHP() const { return m_hp; }
  void DecHP(int damage = 3) { m_hp -= damage; }

  void Update() override {
    if (GetHP() <= 0) {
      SetState(ObjectState::Dead);
      return;
    }
    PlantDo();
  }
};

#endif // !PLANT_HPP__