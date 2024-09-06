#ifndef REGULARZOMBIE_HPP__
#define REGULARZOMBIE_HPP__

#include "pvz/GameObject/Zombie/Zombie.hpp"

class RegularZombie : public Zombie {
public:
  RegularZombie(int x, int y, pGameWorld GameWorld)
      : Zombie(IMGID_REGULAR_ZOMBIE, x, y, GameWorld){};

  void ZombieDo() override {}
};

#endif // !REGULARZOMBIE_HPP__