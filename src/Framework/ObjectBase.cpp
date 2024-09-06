#include "pvz/Framework/ObjectBase.hpp"
#include "pvz/Framework/GameManager.hpp"

ObjectBase::ObjectBase(int imageID, int x, int y, LayerID layer, int width, int height, AnimID animID)
  : m_imageID(imageID), m_x(x), m_y(y), m_layer(layer), m_width(width), m_height(height), m_animID(animID), m_currentFrame(0) {
  GetObjects(m_layer).insert(this);
}

ObjectBase::~ObjectBase() {
  GetObjects(m_layer).erase(this);
}

bool ObjectBase::operator==(const ObjectBase& other) {
  return this == &other;
}

int ObjectBase::GetX() const {
  return m_x;
}

int ObjectBase::GetY() const {
  return m_y;
}

int ObjectBase::GetWidth() const {
  return m_width;
}

int ObjectBase::GetHeight() const {
  return m_height;
}

AnimID ObjectBase::GetCurrentAnimation() const {
  return m_animID;
}

void ObjectBase::MoveTo(int x, int y) {
  m_x = x;
  m_y = y;
}

void ObjectBase::ChangeImage(ImageID imageID) {
  m_imageID = imageID;
}

void ObjectBase::PlayAnimation(AnimID animID) {
  m_animID = animID;
  m_currentFrame = 0;
}


std::set<ObjectBase*>& ObjectBase::GetObjects(int layer) {
  static std::set<ObjectBase*> gameObjects[MAX_LAYERS];
  if (layer < MAX_LAYERS) {
    return gameObjects[layer];
  }
  else {
    return gameObjects[0];
  }
}
