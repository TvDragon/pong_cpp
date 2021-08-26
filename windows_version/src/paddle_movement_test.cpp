#include "../include/paddle_movement_test.hpp"

bool TestMoveUpPlayer() {

  float expected_value = 20;
  Rectangle player_rect = Rectangle(10, 25, 5, 0);
  Rectangle top_bar = Rectangle(0, 0, 0, 2);

  MoveUpPlayer(player_rect, top_bar);

  if (player_rect.GetY() == expected_value)
    return true;
  return false;
}

bool TestMoveDownPlayer() {

  float expected_value = 30;
  Rectangle player_rect = Rectangle(10, 25, 5, 0);
  Rectangle bottom_bar = Rectangle(0, SCREEN_HEIGHT - 10, 0, 2);

  MoveDownPlayer(player_rect, bottom_bar);

  if (player_rect.GetY() == expected_value)
    return true;
  return false;
}

bool PlayerTouchTopBar() {

  float expected_value = 10;
  Rectangle player_rect = Rectangle(10, 5, 5, 0);
  Rectangle top_bar = Rectangle(0, 0, 0, 2);

  MoveUpPlayer(player_rect, top_bar); // Player will touch top bar so stays below top bar

  if (player_rect.GetY() == expected_value)
    return true;
  return false;
}

bool PlayerTouchBottomBar() {

  float expected_value = SCREEN_HEIGHT - 80;  // paddle height is 70 pixels
  Rectangle player_rect = Rectangle(10, SCREEN_HEIGHT - 10, 5, 0);
  Rectangle bottom_bar = Rectangle(0, SCREEN_HEIGHT - 10, 0, 2);

  MoveDownPlayer(player_rect, bottom_bar);

  if (player_rect.GetY() == expected_value)
    return true;
  return false;
}

bool TestMoveUpComputer() {

  bool move_downards = false;
  float expected_value = 20;
  Rectangle comp_rect = Rectangle(10, 25, 5, 0);
  Rectangle top_bar = Rectangle(0, 0, 0, 2);

  MoveUpComputer(comp_rect, top_bar, move_downards);

  if (comp_rect.GetY() == expected_value && move_downards == false)
    return true;
  return false;
}

bool TestMoveDownComputer() {

  bool move_downards = true;
  float expected_value = 30;
  Rectangle comp_rect = Rectangle(10, 25, 5, 0);
  Rectangle top_bar = Rectangle(0, SCREEN_HEIGHT - 10, 0, 2);

  MoveDownComputer(comp_rect, top_bar, move_downards);

  if (comp_rect.GetY() == expected_value && move_downards == true)
    return true;
  return false;
}

bool BotTouchTopBar() {

  bool move_downards = false;
  float expected_value = 10;
  Rectangle comp_rect = Rectangle(10, 10, 5, 0);
  Rectangle top_bar = Rectangle(0, 0, 0, 2);

  MoveUpComputer(comp_rect, top_bar, move_downards);

  if (comp_rect.GetY() == expected_value && move_downards == true)
    return true;

  return false;
}

bool BotTouchBottomBar() {

  bool move_downards = true;
  float expected_value = SCREEN_HEIGHT - 10;
  Rectangle comp_rect = Rectangle(10, SCREEN_HEIGHT - 10, 5, 0);
  Rectangle top_bar = Rectangle(0, SCREEN_HEIGHT - 10, 0, 2);

  MoveDownComputer(comp_rect, top_bar, move_downards);

  if (comp_rect.GetY() == expected_value && move_downards == false)
    return true;
  
  return false;
}