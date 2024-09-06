#ifndef WORLDBASE_H__
#define WORLDBASE_H__

#include <iostream>
#include <set>
#include <memory>

#include "pvz/utils.hpp"


class WorldBase {
public:
  WorldBase();
  virtual ~WorldBase();

  virtual void Init() = 0;

  virtual LevelStatus Update() = 0;

  virtual void CleanUp() = 0;

private:

};


#endif // !WORLDBASE_H__
