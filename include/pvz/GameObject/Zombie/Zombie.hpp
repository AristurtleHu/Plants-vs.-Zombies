#ifndef ZOMBIE_HPP__
#define ZOMBIE_HPP__

#include "pvz/GameObject/GameObject.hpp"

class Zombie : public GameObject {
public:
  enum class ZombieState { Walk, Eat, Run, Jump };

  Zombie(ImageID ImageID, int x, int y, pGameWorld GameWorld, int HP = 200,
         AnimID animid = ANIMID_WALK_ANIM,
         ZombieState state = ZombieState::Walk)
      : GameObject(ImageID, x, y, LAYER_ZOMBIES, 20, 80, animid, GameWorld,
                   ObjectID::Zombie),
        m_state(state), m_hp(HP) {}

  void OnClick() override {}
  virtual void ZombieDo() = 0;
  ZombieState GetZombieState() const { return m_state; }
  void SetZombieState(ZombieState state) { m_state = state; }
  int GetHP() const { return m_hp; }
  void DecHP(int damage = 20) { m_hp -= damage; }

  void Update() override {
    if (GetHP() <= 0) {
      SetState(ObjectState::Dead);
      return;
    }
    if (m_state == ZombieState::Walk)
      MoveTo(GetX() - 1, GetY());
    if (m_state == ZombieState::Run)
      MoveTo(GetX() - 2, GetY());

    ZombieDo();
  }

private:
  ZombieState m_state;
  int m_hp;
};

#endif // !ZOMBIE_HPP__