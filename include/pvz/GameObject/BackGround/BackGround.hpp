#ifndef BACKGROUND_HPP__
#define BACKGROUND_HPP__

#include "pvz/GameObject/GameObject.hpp"

class BackGround : public GameObject {
public:
  BackGround(int width, int height)
      : GameObject(IMGID_BACKGROUND, width / 2, height / 2, LAYER_BACKGROUND,
                   width, height, ANIMID_NO_ANIMATION){};
  void Update() override {}
  void OnClick() override {}
};

#endif // !BACKGROUND_HPP__