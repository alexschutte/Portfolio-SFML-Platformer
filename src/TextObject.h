//
// Created by alexa on 15/03/2023.
//
#include <SFML/Graphics.hpp>
#ifndef PLATFORMERSFML_TEXTOBJECT_H
#define PLATFORMERSFML_TEXTOBJECT_H

class TextObject
{
 public:
  TextObject();
  ~TextObject();
  bool initialiseText(std::string font, std::string text, int size, sf::Color colour);
  void setPos(float x, float y);
  sf::Text getText();
 private:
  sf::Text target_text;
  sf::Font target_font;
};

#endif // PLATFORMERSFML_TEXTOBJECT_H
