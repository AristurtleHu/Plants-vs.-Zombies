#include <memory>

#include "pvz/Framework/GameManager.hpp"
#include "pvz/GameWorld/GameWorld.hpp"

int main(int argc, char** argv) {
  std::shared_ptr<WorldBase> world = std::make_shared<GameWorld>();

  GameManager::Instance().Play(argc, argv, world);
}