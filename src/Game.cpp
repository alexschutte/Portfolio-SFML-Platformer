
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
  score_counter = 0;
  life_counter = 3;
  enemy[0].direction.y = -1;
  enemy[1].direction.y = -1;
  enemy[2].direction.y = -1;
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "FONT DID NOT LOAD!\n";
  }
  if (!background_texture.loadFromFile("Data/Images/lvl1.png")) {
    std::cout << "BACKGROUND DID NOT LOAD!\n";
  }
  background.setTexture(background_texture);
  background.setScale(
    window.getSize().x / background.getLocalBounds().width,
    window.getSize().y / background.getLocalBounds().height
  );
  main_menu_text.initialiseText("Data/Fonts/OpenSans-Bold.ttf",
                                "THE GOAT: ORIGINS", 80,
                                sf::Color(255, 255, 255, 255));
  main_menu_text.setPos(window.getSize().x/2 - main_menu_text.getText().getGlobalBounds().width/2,
                        window.getSize().y/3 - main_menu_text.getText().getGlobalBounds().height/2);
  game_over_text.initialiseText("Data/Fonts/OpenSans-Bold.ttf",
                                "GAME OVER!", 80,
                                sf::Color(255, 255, 255, 255));
  game_over_text.setPos(window.getSize().x/2 - game_over_text.getText().getGlobalBounds().width/2,
                        window.getSize().y/3 - game_over_text.getText().getGlobalBounds().height/2);
  game_over_text_2.initialiseText("Data/Fonts/OpenSans-Bold.ttf",
                                     "PRESS ENTER TO RESTART", 50,
                                     sf::Color(255, 255, 255, 255));
  game_over_text_2.setPos(window.getSize().x/2 - game_over_text_2.getText().getGlobalBounds().width/2,
                             window.getSize().y/2 - game_over_text_2.getText().getGlobalBounds().height/2);
  game_won_text.initialiseText("Data/Fonts/OpenSans-Bold.ttf",
                                "YOU WIN!", 80,
                                sf::Color(255, 255, 255, 255));
  game_won_text.setPos(window.getSize().x/2 - game_won_text.getText().getGlobalBounds().width/2,
                        window.getSize().y/3 - game_won_text.getText().getGlobalBounds().height/2);
  instructions_prompt.initialiseText("Data/Fonts/OpenSans-Bold.ttf",
                                     "PRESS SPACE FOR CONTROLS", 50,
                                     sf::Color(255, 255, 255, 255));
  instructions_prompt.setPos(window.getSize().x/2 - instructions_prompt.getText().getGlobalBounds().width/2,
                             window.getSize().y/2 - instructions_prompt.getText().getGlobalBounds().height/2);
  play_prompt.initialiseText("Data/Fonts/OpenSans-Bold.ttf",
                                     "PRESS ENTER TO START", 50,
                                     sf::Color(255, 255, 255, 255));
  play_prompt.setPos(window.getSize().x/2 - play_prompt.getText().getGlobalBounds().width/2,
                             window.getSize().y/1.6 - play_prompt.getText().getGlobalBounds().height/2);
  instructions_1.initialiseText("Data/Fonts/OpenSans-Bold.ttf",
                                "CONTROLS", 80,
                                sf::Color(255, 255, 255, 255));
  instructions_1.setPos(window.getSize().x/2 - instructions_1.getText().getGlobalBounds().width/2,
                        window.getSize().y/3 - instructions_1.getText().getGlobalBounds().height/2);
  instructions_2.initialiseText("Data/Fonts/OpenSans-Bold.ttf",
                                     "A & D KEYS TO MOVE", 50,
                                     sf::Color(255, 255, 255, 255));
  instructions_2.setPos(window.getSize().x/2 - instructions_2.getText().getGlobalBounds().width/2,
                             window.getSize().y/2 - instructions_2.getText().getGlobalBounds().height/2);
  instructions_3.initialiseText("Data/Fonts/OpenSans-Bold.ttf",
                             "SPACE TO JUMP, PRESS ENTER TO PLAY!", 50,
                             sf::Color(255, 255, 255, 255));
  instructions_3.setPos(window.getSize().x/2 - instructions_3.getText().getGlobalBounds().width/2,
                     window.getSize().y/1.6 - instructions_3.getText().getGlobalBounds().height/2);
  score_text.setString("Score: ");
  score_text.setFont(font);
  score_text.setFillColor(sf::Color(255, 255, 255, 255));
  score_text.setCharacterSize(40);
  score_text.setPosition(window.getSize().x/25 , window.getSize().y/20);
  life_text.setString("Lives: ");
  life_text.setFont(font);
  life_text.setFillColor(sf::Color(255, 255, 255, 255));
  life_text.setCharacterSize(40);
  life_text.setPosition(window.getSize().x/25 , window.getSize().y/9);

  player.initialiseSprite(player_texture , "Data/Images/kenney_animalpackredux/PNG/Square without details (outline)/goat.png");
  player.getSprite()->setPosition(window.getSize().x/10 - player.getSprite()->getGlobalBounds().width/2 , window.getSize().y/5 - player.getSprite()->getGlobalBounds().height/2);
  player.getSprite()->setScale(0.4 , 0.4);
  for (int i = 0; i < 6; i++)
  {
    collectible[i].visibility = true;
    collectible[i].initialiseSprite(
      collectible_texture,
      "Data/Images/kenney_pixelplatformer/Tiles/tile_0040.png");
  }
  collectible[0].getSprite()->setPosition(window.getSize().x/2.05 , window.getSize().y/1.5);
  collectible[1].getSprite()->setPosition(window.getSize().x/15 , window.getSize().y/2);
  collectible[2].getSprite()->setPosition(window.getSize().x/3.5 , window.getSize().y/5);
  collectible[3].getSprite()->setPosition(window.getSize().x/3.5 , window.getSize().y/1.8);
  collectible[4].getSprite()->setPosition(window.getSize().x/1.5 , window.getSize().y/2);
  collectible[5].getSprite()->setPosition(window.getSize().x/1.2 , window.getSize().y/2);
  for (int i = 0; i < 9; i++)
  {
    platform[i].initialiseSprite(platform_texture , "Data/Images/kenney_pixelplatformer/Tiles/tile_0020.png");
  }
  platform[0].getSprite()->setPosition(window.getSize().x/2.2 , window.getSize().y/1.2);
  platform[0].getSprite()->setScale(5 , 1);
  platform[1].getSprite()->setPosition(window.getSize().x/20 , window.getSize().y/1.1);
  platform[1].getSprite()->setScale(65 , 5);
  platform[2].getSprite()->setPosition(window.getSize().x/3 , window.getSize().y/1.3);
  platform[2].getSprite()->setScale(5 , 1);
  platform[3].getSprite()->setPosition(window.getSize().x/4 , window.getSize().y/1.5);
  platform[3].getSprite()->setScale(5 , 1);
  platform[4].getSprite()->setPosition(window.getSize().x/25 , window.getSize().y/1.6);
  platform[4].getSprite()->setScale(5 , 1);
  platform[5].getSprite()->setPosition(window.getSize().x/2.3 , window.getSize().y/1.8);
  platform[5].getSprite()->setScale(5 , 1);
  platform[6].getSprite()->setPosition(window.getSize().x/2.8 , window.getSize().y/2.3);
  platform[6].getSprite()->setScale(5 , 1);
  platform[7].getSprite()->setPosition(window.getSize().x/1.2 , window.getSize().y/1.5);
  platform[7].getSprite()->setScale(5 , 1);
  platform[8].getSprite()->setPosition(window.getSize().x/4 , window.getSize().y/2.8);
  platform[8].getSprite()->setScale(5 , 1);
  for (int i = 0; i < 3; i++)
  {
    enemy[i].initialiseSprite(enemy_texture , "Data/Images/kenney_animalpackredux/PNG/Square without details (outline)/snake.png");
    enemy[i].getSprite()->setScale(0.4 , 0.4);
  }
  enemy[0].getSprite()->setPosition(window.getSize().x/1.7 , window.getSize().y/2);
  enemy[1].getSprite()->setPosition(window.getSize().x/6 , window.getSize().y/1.6);
  enemy[2].getSprite()->setPosition(window.getSize().x/2.6 , window.getSize().y/6);
  start_location = enemy[0].getSprite()->getPosition().y;
  return true;
}

void Game::update(float dt)
{
  switch (current)
  {
    case gameplay:
      score_text.setString("Score: " + std::to_string(score_counter));
      life_text.setString("Lives: " + std::to_string(life_counter));
      for (int i = 0; i < 6; i++)
      {
        if (playerCollision(*player.getSprite(), *collectible[i].getSprite()))
        {
          if (collectible[i].visibility)
          {
            score_counter++;
            collectible[i].visibility = false;
          }
        }
      }
      if (playerCollision(*player.getSprite(), *enemy[0].getSprite()))
      {
        player.getSprite()->move(0, -30);
        if (!iframes)
        {
          iframes = true;
          life_counter--;
        }
      }
      if (playerCollision(*player.getSprite(), *enemy[1].getSprite()))
      {
        player.getSprite()->move(0, -30);
        if (!iframes)
        {
          iframes = true;
          life_counter--;
        }
      }
      if (playerCollision(*player.getSprite(), *enemy[2].getSprite()))
      {
        player.getSprite()->move(0, -30);
        if (!iframes)
        {
          iframes = true;
          life_counter--;
        }
      }
      for (int i = 0; i < 9; i++)
      {
        if (!playerCollision(*player.getSprite() , *platform[i].getSprite()))
        {
          player.direction.y = 1;
        }
        else
        {
          player.direction.y = 0;
          is_jumping = false;
          break;
        }
        if (sideCollision(*player.getSprite() , *platform[i].getSprite()) == 1)
        {
          player.direction.x = 0;
          player.getSprite()->move(-10 , 0);
          break;
        }
        if (sideCollision(*player.getSprite() , *platform[i].getSprite()) == 2)
        {
          player.direction.x = 0;
          player.getSprite()->move(10 , 0);
          break;
        }
      }
      if (player.getSprite()->getPosition().x + player.getSprite()->getGlobalBounds().width > window.getSize().x)
      {
        player.getSprite()->move(-10 , 0);
      }
      if (player.getSprite()->getPosition().x < 0)
      {
        player.getSprite()->move(10 , 0);
      }
      player.getSprite()->move(player.direction.x * velocity * dt , player.direction.y * gravity * dt);
      enemy[0].getSprite()->move(enemy[0].direction.x * velocity * dt , enemy[0].direction.y * velocity * dt);
      enemy[1].getSprite()->move(enemy[1].direction.x * velocity * dt , enemy[1].direction.y * velocity * dt);
      enemy[2].getSprite()->move(enemy[2].direction.x * velocity * dt , enemy[2].direction.y * velocity * dt);
      if (enemy[0].getSprite()->getPosition().y < start_location - 50)
      {
        enemy[0].direction.y = 1;
        enemy[1].direction.y = 1;
        enemy[2].direction.y = 1;
      }
      if (enemy[0].getSprite()->getPosition().y > start_location + 50)
      {
        enemy[0].direction.y = -1;
        enemy[1].direction.y = -1;
        enemy[2].direction.y = -1;
      }
      if (!is_jumping && current_y - 100 > player.getSprite()->getPosition().y)
      {
        is_jumping = true;
        gravity = 200;
      }
      if (score_counter == 6)
      {
        current = game_won;
      }
      if (life_counter == 0)
      {
        current = game_over;
      }
      break;
  }
}

void Game::render()
{
  switch (current)
  {
    case menu:
      window.draw(main_menu_text.getText());
      window.draw(instructions_prompt.getText());
      window.draw(play_prompt.getText());
      break;
    case instructions:
      window.draw(instructions_1.getText());
      window.draw(instructions_2.getText());
      window.draw(instructions_3.getText());
      break;
    case gameplay:
      window.draw(background);
      window.draw(*player.getSprite());
      for (int i = 0; i < 9; i++)
      {
        window.draw(*platform[i].getSprite());
      }
      for (int i = 0; i < 6; i++)
      {
        if (collectible[i].visibility)
        {
          window.draw(*collectible[i].getSprite());
        }
      }
      for (int i = 0; i < 3; i++)
      {
        window.draw(*enemy[i].getSprite());
      }
      window.draw(score_text);
      window.draw(life_text);
      break;
    case game_over:
      window.draw(game_over_text.getText());
      window.draw(game_over_text_2.getText());
      break;
    case game_won:
      window.draw(game_won_text.getText());
      window.draw(game_over_text_2.getText());
      break;
  }
}

bool Game::playerCollision(const sf::Sprite& player_collider , sf::Sprite other_collider)
{
  if (player_collider.getPosition().x <= other_collider.getPosition().x + other_collider.getGlobalBounds().width
      && other_collider.getPosition().x <= player_collider.getPosition().x + player_collider.getGlobalBounds().width
      && player_collider.getPosition().y <= other_collider.getPosition().y + other_collider.getGlobalBounds().height
      && other_collider.getPosition().y <= player_collider.getPosition().y + player_collider.getGlobalBounds().height)
  {
    return true;
  }
  return false;
}


int Game::sideCollision(const sf::Sprite& player_collider , const sf::Sprite& other_collider)
{
  if (
    player_collider.getPosition().x + player_collider.getGlobalBounds().width >=
      other_collider.getPosition().x &&
    player_collider.getPosition().x + player_collider.getGlobalBounds().width <=
      other_collider.getPosition().x + other_collider.getGlobalBounds().width &&
    player_collider.getPosition().y +
        player_collider.getGlobalBounds().height >=
      other_collider.getPosition().y &&
    player_collider.getPosition().y <=
      other_collider.getPosition().y + other_collider.getGlobalBounds().height)
  {
    return 1;
  }
  else if (
    player_collider.getPosition().x <=
      other_collider.getPosition().x + other_collider.getGlobalBounds().width &&
    player_collider.getPosition().x >=
      other_collider.getPosition().x + other_collider.getGlobalBounds().width -
        other_collider.getGlobalBounds().width &&
    player_collider.getPosition().y +
        player_collider.getGlobalBounds().height >=
      other_collider.getPosition().y &&
    player_collider.getPosition().y <=
      other_collider.getPosition().y + other_collider.getGlobalBounds().height)
  {
    return 2;
  }
  else
  {
    return 0;
  }
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);


}

void Game::keyPressed(sf::Event event)
{
  switch (current)
  {
    case menu:
      if (event.key.code == sf::Keyboard::Enter)
      {
        current = gameplay;
      }
      if (event.key.code == sf::Keyboard::Space)
      {
        current = instructions;
      }
    case instructions:
      if (event.key.code == sf::Keyboard::Enter)
      {
        current = gameplay;
      }
    case gameplay:
      if (event.key.code == sf::Keyboard::D && !right_collided)
      {
        left_collided = false;
        d_down = true;
        player.direction.x = 1;
      }
      if (event.key.code == sf::Keyboard::A && !left_collided)
      {
        right_collided = false;
        a_down = true;
        player.direction.x = -1;
      }
      if (event.key.code == sf::Keyboard::Space && !is_jumping)
      {
        iframes = false;
        current_y = player.getSprite()->getPosition().y;
        player.getSprite()->move(0 , -5);
        gravity = -200;
        player.direction.y = -1;
      }
    case game_over:
      if (event.key.code == sf::Keyboard::Enter)
      {
        init();
        current = gameplay;
      }
    case game_won:
      if (event.key.code == sf::Keyboard::Enter)
      {
        init();
        current = gameplay;
      }
  }
}

void Game::keyReleased(sf::Event event)
{
  switch (current)
  {
    case gameplay:
      if (event.key.code == sf::Keyboard::D)
      {
        d_down = false;
        if (a_down)
        {
          player.direction.x = -1;
        }
        else
        {
          player.direction.x = 0;
        }
      }
      if (event.key.code == sf::Keyboard::A)
      {
        a_down = false;
        if (d_down)
        {
          player.direction.x = 1;
        }
        else
        {
          player.direction.x = 0;
        }
      }
      if (event.key.code == sf::Keyboard::Space)
      {
        is_jumping = true;
        gravity = 200;
      }
  }
}


