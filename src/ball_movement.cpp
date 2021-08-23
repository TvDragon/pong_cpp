#include "../include/ball_movement.hpp"

#include <stdio.h>

void BallMovement(Rectangle& ball, Rectangle paddle_one, Rectangle paddle_two,
                    bool& move_right, float& b,
                    Rectangle top_bar, Rectangle bottom_bar,
                    int& paddle_one_score, int& paddle_two_score)
{
  bool start_over = false;

  float paddle_one_x = paddle_one.GetX();
  float paddle_one_width = paddle_one_x + paddle_one.GetCurrentFrame().w;
  float paddle_one_y = paddle_one.GetY();
  float paddle_one_height = paddle_one_y + paddle_one.GetCurrentFrame().h;

  float paddle_two_x = paddle_two.GetX();
  float paddle_two_width = paddle_two_x + paddle_two.GetCurrentFrame().w;
  float paddle_two_y = paddle_two.GetY();
  float paddle_two_height = paddle_two_y + paddle_two.GetCurrentFrame().h;

  float ball_x = ball.GetX();
  float ball_width = ball_x + ball.GetCurrentFrame().w;
  float ball_y = ball.GetY();
  float ball_height = ball_y + ball.GetCurrentFrame().h;

  float top_bar_height = top_bar.GetY() + top_bar.GetCurrentFrame().h;
  float bottom_bar_y = bottom_bar.GetY();

  if ((ball_width + ball.GetSpeed() >= paddle_one_x) &&
      ((ball_y >= paddle_one_y && ball_y <= paddle_one_height) || (ball_height <= paddle_one_height && ball_height >= paddle_one_y)) &&
      move_right == true) {

    ball.SetSpeed(ball.GetSpeed() * -1);
    move_right = false;

  } else if ((ball_x >= paddle_two_width + ball.GetSpeed() && ball_x <= paddle_two_width - ball.GetSpeed()) &&
              ((ball_y >= paddle_two_y && ball_y <= paddle_two_height) || (ball_height <= paddle_two_height && ball_height >= paddle_two_y)) &&
              move_right == false) {
    
    ball.SetSpeed(ball.GetSpeed() * -1);
    move_right = true;

  } else if (ball_width >= SCREEN_WIDTH) {
    ball.SetSpeed(ball.GetSpeed() * -1);
    b = rand() % 3 + 1; // number between 1 & 3
    b *= -1;
    move_right = false;
    start_over = true;
    paddle_two_score += 1;

  } else if (ball_x <= 0) {
    ball.SetSpeed(ball.GetSpeed() * -1);
    b = rand() % 3 + 1; // number between 1 & 3
    b *= -1;
    start_over = true;
    move_right = true;
    paddle_one_score += 1;
    
  } else if (ball_y + b <= top_bar_height || ball_height + b >= bottom_bar_y) {
    // printf("Ball: %0.0f, %0.0f, %0.0f, %0.0f, %0f\n", ball_x, ball_width, ball_y, ball_height, bottom_bar_y);
    b *= -1;
  }

  if (start_over) {
    ball.SetX(SCREEN_WIDTH/2);
    ball.SetY(SCREEN_HEIGHT/2);
  } else {
    ball.SetX(ball_x + ball.GetSpeed());
    ball.SetY(ball_y + b);
  }
}