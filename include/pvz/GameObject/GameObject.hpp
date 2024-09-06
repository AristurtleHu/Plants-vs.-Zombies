#ifndef GAMEOBJECT_HPP__
#define GAMEOBJECT_HPP__

#include "pvz/Framework/ObjectBase.hpp"
#include <memory>

// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class GameObject : public ObjectBase,
                   public std::enable_shared_from_this<GameObject> {
public:
  using std::enable_shared_from_this<GameObject>::shared_from_this;
  enum class ObjectState { Dead, Alive };
  enum class ObjectID { Other, Plant, Zombie, Bullet, Shovel };

  GameObject(ImageID imageID, int x, int y, LayerID layer, int width,
             int height, AnimID animID, pGameWorld GameWorld = nullptr,
             ObjectID objectID = ObjectID::Other,
             ObjectState state = ObjectState::Alive)
      : ObjectBase(imageID, x, y, layer, width, height, animID),
        m_gameWorld(GameWorld), m_objectID(objectID), m_state(state) {}

  ObjectState GetState() const { return m_state; }
  void SetState(ObjectState state) { m_state = state; }
  pGameWorld GetGameWorld() const { return m_gameWorld; }
  ObjectID GetObjectID() const { return m_objectID; }

private:
  pGameWorld m_gameWorld;
  ObjectID m_objectID;
  ObjectState m_state;
};

#endif // !GAMEOBJECT_HPP__
