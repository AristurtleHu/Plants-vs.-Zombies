#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>

#include "pvz/Framework/WorldBase.hpp"

#include "pvz/GameObject/GameObject.hpp"

#include "pvz/Framework/TextBase.hpp"
#include "pvz/utils.hpp"

using pGameObject = std::shared_ptr<GameObject>;

class GameWorld : public WorldBase,
                  public std::enable_shared_from_this<GameWorld> {
public:
  // Use shared_from_this() instead of "this" to create a pointer to oneself.
  GameWorld();
  virtual ~GameWorld();

  void InitGameWorldObjects();

  void Init() override;

  void AddSeed();

  void AddPlant(pGameObject Plant);
  int GetSun() const;
  void SetSun(int sun);
  pGameObject GetHolding() const;
  void SetHolding(pGameObject holding);
  void AddSun(bool SkySun, int x, int y);

  void AddObject(pGameObject object);

  void GenerateSun();
  void GenerateZombie();

  bool IsShovel(pGameObject object) const;
  bool IsOther(pGameObject object) const;
  bool IsBullet(pGameObject object) const;
  bool IsPlant(pGameObject object) const;
  bool IsZombie(pGameObject object) const;
  bool ZombieWin(pGameObject zombie);
  bool ZombieExist(int x, int y) const;
  bool IsHit(pGameObject object1, pGameObject object2) const;
  void ZombieFinish();
  void HitCheck();
  bool HitPlant(pGameObject zombie);

  LevelStatus Update() override;

  void CleanUp() override;

private:
  std::list<pGameObject> m_object;
  TextBase m_sunText = TextBase(SUN_TEXT_X, SUN_TEXT_Y);
  TextBase m_waveText = TextBase(WAVE_TEXT_X, WAVE_TEXT_Y, "Wave: 0",
                                 215.0 / 255, 99.0 / 255, 100.0 / 255);
  int m_wave = 0;
  int m_sun = 50;
  pGameObject m_holding = nullptr;
  int m_sun_tick = 180;
  int m_wave_tick = 1200;
};

#endif // !GAMEWORLD_HPP__
