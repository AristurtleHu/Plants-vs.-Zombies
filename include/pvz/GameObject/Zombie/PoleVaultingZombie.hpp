#ifndef POLEVAULTINGZOMBIE_HPP__
#define POLEVAULTINGZOMBIE_HPP__

#include "pvz/GameObject/Zombie/Zombie.hpp"

class PoleVaultingZombie : public Zombie {
  int m_tick = 42;
  bool m_jump = false;

public:
  PoleVaultingZombie(int x, int y, pGameWorld GameWorld)
      : Zombie(IMGID_POLE_VAULTING_ZOMBIE, x, y, GameWorld, 340,
               ANIMID_RUN_ANIM, ZombieState::Run) {}

  void ZombieDo() override {
    if (m_jump) {
      m_tick--;
      if (m_tick == 0) {
        SetZombieState(ZombieState::Walk);
        PlayAnimation(ANIMID_WALK_ANIM);
        m_jump = false;
        MoveTo(GetX() - 150, GetY());
      }
    }
    if (GetZombieState() == ZombieState::Run) {
      MoveTo(GetX() - 40, GetY());
      if (GetGameWorld()->HitPlant(shared_from_this())) {
        SetZombieState(ZombieState::Jump);
        PlayAnimation(ANIMID_JUMP_ANIM);
        m_jump = true;
      }
      MoveTo(GetX() + 40, GetY());
    }
  }
};

#endif // !POLEVAULTINGZOMBIE_HPP__