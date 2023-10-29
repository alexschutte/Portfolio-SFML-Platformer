
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>
#include "TextObject.h"
#include "GameObject.h"

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  static bool playerCollision(const sf::Sprite& player_collider , sf::Sprite other_collider);
  static int sideCollision(const sf::Sprite& player_collider , const sf::Sprite& wall_collider);
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  void keyReleased(sf::Event event);

 private:
  sf::RenderWindow& window;
  sf::Font font;
  enum game_state {menu, instructions, gameplay, game_over, game_won};
  game_state current = menu;
  TextObject main_menu_text;
  TextObject instructions_prompt;
  TextObject play_prompt;
  TextObject instructions_1;
  TextObject instructions_2;
  TextObject instructions_3;
  TextObject game_over_text;
  TextObject game_over_text_2;
  TextObject game_won_text;
  sf::Text score_text;
  sf::Text life_text;
  sf::Sprite background;
  sf::Texture background_texture;
  GameObject player;
  sf::Texture player_texture;
  GameObject platform[8];
  sf::Texture platform_texture;
  GameObject collectible[5];
  sf::Texture collectible_texture;
  GameObject enemy[2];
  sf::Texture enemy_texture;
  int velocity = 250;
  int gravity = 300;
  bool is_jumping = false;
  float current_y = 0;
  float start_location = 0;
  bool a_down = false;
  bool d_down = false;
  bool right_collided = false;
  bool left_collided = false;
  bool iframes = false;
  int score_counter = 0;
  int life_counter = 3;
};

#endif // PLATFORMER_GAME_H
