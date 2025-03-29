#include "../include/comp_and_player_movement.hpp"

void MoveUpPlayer(Rectangle& paddle, Rectangle top_bar) {
  float top_bar_height = top_bar.GetY() + top_bar.GetCurrentFrame().h;
  if (paddle.GetY() - paddle.GetSpeed() <= top_bar_height) {
    paddle.SetY(top_bar_height);
  } else {
    paddle.SetY(paddle.GetY() - paddle.GetSpeed());
  }
}

void MoveDownPlayer(Rectangle& paddle, Rectangle bottom_bar) {
  float bottom_bar_y = bottom_bar.GetY();
  if (paddle.GetY() + paddle.GetCurrentFrame().h + paddle.GetSpeed() >= bottom_bar_y) {
    paddle.SetY(bottom_bar_y - paddle.GetCurrentFrame().h);
  } else {
    paddle.SetY(paddle.GetY() + paddle.GetSpeed());
  }
}

void MoveUpComputer(Rectangle& paddle, Rectangle top_bar, bool& move_downwards) {
  float top_bar_height = top_bar.GetY() + top_bar.GetCurrentFrame().h;
  if (paddle.GetY() - paddle.GetSpeed() <= top_bar_height) {
    move_downwards = true;
  }
  if (!move_downwards)
    paddle.SetY(paddle.GetY() - paddle.GetSpeed());
}

void MoveDownComputer(Rectangle& paddle, Rectangle bottom_bar, bool& move_downwards) {
  float bottom_bar_y = bottom_bar.GetY();
  if (paddle.GetY() + paddle.GetCurrentFrame().h + paddle.GetSpeed() >= bottom_bar_y) {
    move_downwards = false;
  }
  if (move_downwards)
    paddle.SetY(paddle.GetY() + paddle.GetSpeed());
}

void MoveComputerUpHardMode(Rectangle& paddle) {
  paddle.SetY(paddle.GetY() - paddle.GetSpeed());
}

void MoveComputerDownHardMode(Rectangle& paddle) {
  paddle.SetY(paddle.GetY() + paddle.GetSpeed());
}