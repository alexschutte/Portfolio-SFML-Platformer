//
// Created by alexa on 15/03/2023.
//

#include "TextObject.h"
#include <iostream>


TextObject::TextObject()
= default;

TextObject::~TextObject()
= default;

bool TextObject::initialiseText(std::string font, std::string text, int size, sf::Color colour)
{
  std::cout << "Initialising text" << std::endl;
  target_text.setString(text);
  target_text.setCharacterSize(size);
  target_text.setFillColor(colour);
  if (!target_font.loadFromFile(font))
  {
    std::cout << "Error loading font" << std::endl;
    return false;
  }
  target_text.setFont(target_font);
  std::cout << "Text initialised" << std::endl;
  return true;
}

void TextObject::setPos(float x, float y)
{
  target_text.setPosition(x, y);
  std::cout << "Text position set" << std::endl;
}

sf::Text TextObject::getText()
{
  return target_text;
}