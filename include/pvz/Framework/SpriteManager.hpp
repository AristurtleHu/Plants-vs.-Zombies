#ifndef SPRITEMANAGER_HPP__
#define SPRITEMANAGER_HPP__

#include <string>
#include <unordered_map>
#include <filesystem>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "pvz/utils.hpp"


struct SpriteInfo {
public:
  SpriteInfo(std::string filename_, int totalWidth_, int totalHeight_, int spriteWidth_, int spriteHeight_, int cols_ = 1, int frames_ = 1)
    : filename((std::filesystem::path(ASSET_DIR) / filename_).string()), totalWidth(totalWidth_), totalHeight(totalHeight_), spriteWidth(spriteWidth_), spriteHeight(spriteHeight_), cols(cols_), frames(frames_) {}
  std::string filename;
  int totalWidth;
  int totalHeight;
  int spriteWidth;
  int spriteHeight;
  int cols;
  int frames;
  GLuint texture = 0;
};

using SpriteInfoID = int;

class SpriteManager {
public:
  // Meyers' singleton pattern
  virtual ~SpriteManager() {}
  SpriteManager(const SpriteManager& other) = delete;
  SpriteManager& operator=(const SpriteManager& other) = delete;
  static SpriteManager& Instance() { static SpriteManager instance; return instance; }

  GLuint GetTexture(ImageID imageID) const;
  SpriteInfo GetSpriteInfo(ImageID imageID, AnimID animID) const;
  //GLuint GetTexture(ImageID imageID, std::size_t frame) const;


private:
  SpriteManager();

  bool LoadSprites();
  constexpr SpriteInfoID EncodeAnim(ImageID imgID, AnimID animID) const { return imgID * 1000 + animID; }

  std::unordered_map<SpriteInfoID, SpriteInfo> m_spriteInfos;
};
#endif // !SPRITEMANAGER_HPP__
