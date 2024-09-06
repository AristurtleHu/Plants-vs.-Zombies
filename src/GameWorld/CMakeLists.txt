cmake_minimum_required(VERSION 3.16)

add_library(
  GameWorld
  STATIC
  GameWorld.cpp
)

target_link_libraries(
  GameWorld
  GameObject
)