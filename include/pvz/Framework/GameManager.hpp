#ifndef GAMEMANAGER_H__
#define GAMEMANAGER_H__

#include <memory>

#include "pvz/Framework/ObjectBase.hpp"
#include "pvz/Framework/WorldBase.hpp"

#include <vector>
#include <map>

class GameManager {
public:
  // Meyers' singleton pattern
  virtual ~GameManager() {}
  GameManager(const GameManager& other) = delete;
  GameManager& operator=(const GameManager& other) = delete;
  static GameManager& Instance() { static GameManager instance; return instance; }

  void Play(int argc, char** argv, std::shared_ptr<WorldBase> world);

  bool GetKey(KeyCode key) const;
  bool GetKeyDown(KeyCode key);

  void Update();
  void Display();

  void KeyDownEvent(unsigned char key, int x, int y);
  void KeyUpEvent(unsigned char key, int x, int y);
  void SpecialKeyDownEvent(int key, int x, int y);
  void SpecialKeyUpEvent(int key, int x, int y);
  void MouseDownEvent(int x, int y);

  std::size_t DrawOneObject(ImageID imageID, AnimID animID, double x, double y, std::size_t frame) const;
private:
  enum class GameState{TITLE, ANIMATING, PROMPTING, GAMEOVER};
  GameManager();
  inline double NormalizeCoord(double pixels, double totalPixels) const;
  inline int DenormalizeCoord(double normalizedCoord, double totalPixels) const;
  inline void Rotate(double x, double y, double degrees, double& xout, double& yout) const;
  void Prompt(const char* title, const char* subtitle) const;
  void ShowZombiesWon() const;

  inline KeyCode ToKeyCode(unsigned char key) const;
  inline KeyCode SpecialToKeyCode(int key) const;

  GameState m_gameState;
  std::shared_ptr<WorldBase> m_world;

  std::map<KeyCode, bool> m_pressedKeys;

  bool m_pause;

};
#endif // !GAMEMANAGER_H__
