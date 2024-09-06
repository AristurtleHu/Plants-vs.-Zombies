#ifndef BULLET_HPP__
#define BULLET_HPP__

#include "pvz/GameObject/GameObject.hpp"

class Bullet : public GameObject {
  int m_damage = 0;

public:
  Bullet(ImageID imgid, int x, int y, int width, int height, int damage)
      : GameObject(imgid, x, y, LAYER_PROJECTILES, width, height,
                   ANIMID_NO_ANIMATION, nullptr, ObjectID::Bullet),
        m_damage(damage) {}
        
  virtual void BulletHit() = 0;
  int GetDamage() const { return m_damage; }
  void OnClick() override {}
};

#endif // !BULLET_HPP__