#ifndef BUCKETHEADZOMBIE_HPP__
#define BUCKETHEADZOMBIE_HPP__

#include "pvz/GameObject/Zombie/Zombie.hpp"

class BucketHeadZombie : public Zombie {
public:
  BucketHeadZombie(int x, int y, pGameWorld GameWorld)
      : Zombie(IMGID_BUCKET_HEAD_ZOMBIE, x, y, GameWorld, 1300) {}

  void ZombieDo() override {
    if (GetHP() <= 200)
      ChangeImage(IMGID_REGULAR_ZOMBIE);
  }
};

#endif // !BUCKETHEADZOMBIE_HPP__