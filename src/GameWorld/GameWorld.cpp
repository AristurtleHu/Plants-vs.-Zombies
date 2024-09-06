#include "pvz/GameWorld/GameWorld.hpp"
#include "pvz/GameObject/AllBaseObject.hpp"
#include "pvz/GameObject/AllBullet.hpp"
#include "pvz/GameObject/AllPlant.hpp"
#include "pvz/GameObject/AllZombie.hpp"
#include "pvz/GameObject/BackGround/BackGround.hpp"

GameWorld::GameWorld() {}

GameWorld::~GameWorld() {}

void GameWorld::InitGameWorldObjects() {
  m_waveText.MoveTo(WAVE_TEXT_X, WAVE_TEXT_Y);
  m_waveText.SetText("Wave: 0");
  m_sunText.SetText("50");
  m_sun = 50;
  m_wave = 0;
  m_holding = nullptr;
  m_sun_tick = 180;
  m_wave_tick = 1200;
}

void GameWorld::AddSeed() {
  m_object.push_back(std::make_shared<SunflowerSeed>(shared_from_this()));
  m_object.push_back(std::make_shared<PeashooterSeed>(shared_from_this()));
  m_object.push_back(std::make_shared<WallnutSeed>(shared_from_this()));
  m_object.push_back(std::make_shared<CherryBombSeed>(shared_from_this()));
}

void GameWorld::Init() {
  InitGameWorldObjects();
  m_object.push_back(std::make_shared<BackGround>(WINDOW_WIDTH, WINDOW_HEIGHT));
  m_object.push_back(std::make_shared<Shovel>(shared_from_this()));
  AddSeed();
  for (int i = 0; i < GAME_COLS; i++) {
    for (int j = 0; j < GAME_ROWS; j++) {
      m_object.push_back(std::make_shared<PlantingSpot>(
          FIRST_COL_CENTER + i * LAWN_GRID_WIDTH,
          FIRST_ROW_CENTER + j * LAWN_GRID_HEIGHT, shared_from_this()));
    }
  }
}

void GameWorld::AddPlant(pGameObject Plant) {
  if (m_holding) {
    m_holding->MoveTo(Plant->GetX(), Plant->GetY());
    m_holding->PlayAnimation(ANIMID_IDLE_ANIM);
    m_object.push_back(m_holding);
  }
  m_holding = nullptr;
}

void GameWorld::AddSun(bool SkySun = true, int x = 0, int y = 0) {
  if (SkySun)
    m_object.push_back(std::make_shared<Sun>(
        randInt(75, WINDOW_WIDTH - 75), WINDOW_HEIGHT - 1, shared_from_this()));
  else
    m_object.push_back(std::make_shared<Sun>(x, y, shared_from_this(), false));
}

int GameWorld::GetSun() const { return m_sun; }
void GameWorld::SetSun(int sun) { m_sun = sun; }
pGameObject GameWorld::GetHolding() const { return m_holding; }
void GameWorld::SetHolding(pGameObject holding) { m_holding = holding; }

bool GameWorld::IsShovel(pGameObject object) const {
  return object->GetObjectID() == GameObject::ObjectID::Shovel;
}

void GameWorld::AddObject(pGameObject object) { m_object.push_back(object); }

void GameWorld::GenerateSun() {
  if (m_sun_tick == 0) {
    AddSun();
    m_sun_tick = 300;
  }
  m_sun_tick--;
}
void GameWorld::GenerateZombie() {
  m_wave_tick--;
  if (!m_wave_tick) {
    m_wave++;
    m_wave_tick = std::max(150, 600 - 20 * m_wave);

    int p1 = 20, p2 = 2 * std::max(m_wave - 8, 0),
        p3 = 3 * std::max(m_wave - 15, 0);
    for (int i = 0; i < (15 + m_wave) / 10; i++) {
      int ZombieType = randInt(1, p1 + p2 + p3);
      if (ZombieType <= p1)
        AddObject(std::make_shared<RegularZombie>(
            WINDOW_WIDTH - 40,
            FIRST_ROW_CENTER + LAWN_GRID_HEIGHT * randInt(0, 4),
            shared_from_this()));
      else if (ZombieType <= p1 + p2)
        AddObject(std::make_shared<PoleVaultingZombie>(
            WINDOW_WIDTH - 40,
            FIRST_ROW_CENTER + LAWN_GRID_HEIGHT * randInt(0, 4),
            shared_from_this()));
      else
        AddObject(std::make_shared<BucketHeadZombie>(
            WINDOW_WIDTH - 40,
            FIRST_ROW_CENTER + LAWN_GRID_HEIGHT * randInt(0, 4),
            shared_from_this()));
    }
  }
}

bool GameWorld::IsOther(pGameObject object) const {
  return object->GetObjectID() == GameObject::ObjectID::Other ||
         object->GetObjectID() == GameObject::ObjectID::Shovel;
}
bool GameWorld::IsBullet(pGameObject object) const {
  return object->GetObjectID() == GameObject::ObjectID::Bullet;
}
bool GameWorld::IsPlant(pGameObject object) const {
  return object->GetObjectID() == GameObject::ObjectID::Plant;
}
bool GameWorld::IsZombie(pGameObject object) const {
  return object->GetObjectID() == GameObject::ObjectID::Zombie;
}
bool GameWorld::ZombieWin(pGameObject zombie) {
  if (zombie->GetObjectID() == GameObject::ObjectID::Zombie) {
    if (zombie->GetX() < 0) {
      m_waveText.SetText(std::to_string(m_wave));
      m_waveText.MoveTo(WINDOW_WIDTH / 2 - 66, 49);
      return true;
    }
  }
  return false;
}
bool GameWorld::ZombieExist(int x, int y) const {
  for (auto &i : m_object) {
    if (i->GetObjectID() == GameObject::ObjectID::Zombie && i->GetY() == y &&
        i->GetX() >= x)
      return true;
  }
  return false;
}

bool GameWorld::IsHit(pGameObject object1, pGameObject object2) const {
  return abs(object1->GetX() - object2->GetX()) <=
             object1->GetWidth() / 2 + object2->GetWidth() / 2 &&
         abs(object1->GetY() - object2->GetY()) <=
             object1->GetHeight() / 2 + object2->GetHeight() / 2;
}
void GameWorld::HitCheck() {
  for (auto &i : m_object) {
    if (!IsOther(i) && IsZombie(i))
      for (auto &j : m_object) {
        if (i != j && !IsOther(j) && !IsZombie(j) && IsHit(i, j)) {
          auto zombie = std::dynamic_pointer_cast<Zombie>(i);
          if (IsBullet(j)) {
            auto bullet = std::dynamic_pointer_cast<Bullet>(j);
            zombie->DecHP(bullet->GetDamage());
            bullet->BulletHit();
          } else if (IsPlant(j)) {
            auto plant = std::dynamic_pointer_cast<Plant>(j);
            if (zombie->GetZombieState() == Zombie::ZombieState::Walk) {
              zombie->SetZombieState(Zombie::ZombieState::Eat);
              zombie->PlayAnimation(ANIMID_EAT_ANIM);
            }
            plant->DecHP();
          }
        }
      }
  }
}
void GameWorld::ZombieFinish() {
  for (auto &i : m_object) {
    if (IsZombie(i)) {
      bool HitPlant = false;
      for (auto &j : m_object) {
        if (IsPlant(j) && IsHit(i, j)) {
          HitPlant = true;
          break;
        }
      }
      if (!HitPlant) {
        auto zombie = std::dynamic_pointer_cast<Zombie>(i);
        if (zombie->GetZombieState() == Zombie::ZombieState::Eat) {
          zombie->SetZombieState(Zombie::ZombieState::Walk);
          zombie->PlayAnimation(ANIMID_WALK_ANIM);
        }
      }
    }
  }
}

bool GameWorld::HitPlant(pGameObject zombie) {
  for (auto &i : m_object) {
    if (IsPlant(i)) {
      if (IsHit(zombie, i))
        return true;
    }
  }
  return false;
}

LevelStatus GameWorld::Update() {
  GenerateSun();
  GenerateZombie();
  for (auto &object : m_object)
    object->Update();

  HitCheck();

  for (auto it = m_object.begin(); it != m_object.end();) {
    if (ZombieWin(*it))
      return LevelStatus::LOSING;
    if ((*it)->GetState() == GameObject::ObjectState::Dead) {
      it = m_object.erase(it);
    } else {
      it++;
    }
  }

  ZombieFinish();

  m_sunText.SetText(std::to_string(m_sun));
  m_waveText.SetText("Wave: " + std::to_string(m_wave));
  return LevelStatus::ONGOING;
}

void GameWorld::CleanUp() { m_object.clear(); }