//
// Created by alexa on 15/03/2023.
//

#ifndef PLATFORMERSFML_GAMEOBJECT_H
#define PLATFORMERSFML_GAMEOBJECT_H
#include "SFML/Graphics.hpp"
#include "Vector2.h"

class GameObject
{
 public:
  GameObject();
  ~GameObject();
  bool initialiseSprite(sf::Texture &texture , std::string filename);
  sf::Sprite* getSprite();
  bool visibility = false;
  Vector2 direction;
  float speed;
 private:
  sf::Sprite* sprite = nullptr;
};

#endif // PLATFORMERSFML_GAMEOBJECT_H
