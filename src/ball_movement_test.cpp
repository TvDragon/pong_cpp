#include "../include/ball_movement_test.hpp"

#include <stdio.h>

bool TestMoveRight() {
  Rectangle ball = Rectangle(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 5, 1);

  Rectangle paddle_one = Rectangle(SCREEN_WIDTH - 35, SCREEN_HEIGHT/2 - 35, 5, 0);
  Rectangle paddle_two = Rectangle(20, SCREEN_HEIGHT/2 - 35, 5, 0);

  Rectangle top_bar = Rectangle(0, 0, 0, 2);  // Top bar
  Rectangle bottom_bar = Rectangle(0, SCREEN_HEIGHT - 10, 0, 2); // Bottom bar

  bool move_right = true;
  float b = 0;

  int paddle_one_score = 0;
  int paddle_two_score = 0;

  float expected_x_pos = SCREEN_WIDTH/2 + 5;
  float expected_y_pos = SCREEN_HEIGHT/2;
  bool expected_move_right_bool = true;
  int expected_paddle_scores = 0;

  // printf("%0.0f, %0.0f, %d, %d, %s\n", ball.GetX(), ball.GetY(), paddle_one_score, paddle_two_score, move_right ? "true" : "false");

  BallMovement(ball, paddle_one, paddle_two,
                move_right, b,
                top_bar, bottom_bar,
                paddle_one_score, paddle_two_score);

  // printf("%0.0f, %0.0f, %d, %d, %s\n", ball.GetX(), ball.GetY(), paddle_one_score, paddle_two_score, move_right ? "true" : "false");

  if (ball.GetX() == expected_x_pos && ball.GetY() == expected_y_pos &&
        move_right == expected_move_right_bool &&
        paddle_one_score == expected_paddle_scores &&
        paddle_two_score == expected_paddle_scores) {
    
    return true;
  }
  return false;
}

bool TestMoveLeft() {
  Rectangle ball = Rectangle(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, -5, 1);

  Rectangle paddle_one = Rectangle(SCREEN_WIDTH - 35, SCREEN_HEIGHT/2 - 35, 5, 0);
  Rectangle paddle_two = Rectangle(20, SCREEN_HEIGHT/2 - 35, 5, 0);

  Rectangle top_bar = Rectangle(0, 0, 0, 2);  // Top bar
  Rectangle bottom_bar = Rectangle(0, SCREEN_HEIGHT - 10, 0, 2); // Bottom bar

  bool move_right = false;
  float b = 0;

  int paddle_one_score = 0;
  int paddle_two_score = 0;

  float expected_x_pos = SCREEN_WIDTH/2 - 5;
  float expected_y_pos = SCREEN_HEIGHT/2;
  bool expected_move_right_bool = false;
  int expected_paddle_scores = 0;

  BallMovement(ball, paddle_one, paddle_two,
                move_right, b,
                top_bar, bottom_bar,
                paddle_one_score, paddle_two_score);

  if (ball.GetX() == expected_x_pos && ball.GetY() == expected_y_pos &&
        move_right == expected_move_right_bool &&
        paddle_one_score == expected_paddle_scores &&
        paddle_two_score == expected_paddle_scores) {
    
    return true;
  }
  return false;
}

bool TestMoveRightAndDown() {
  Rectangle ball = Rectangle(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 5, 1);

  Rectangle paddle_one = Rectangle(SCREEN_WIDTH - 35, SCREEN_HEIGHT/2 - 35, 5, 0);
  Rectangle paddle_two = Rectangle(20, SCREEN_HEIGHT/2 - 35, 5, 0);

  Rectangle top_bar = Rectangle(0, 0, 0, 2);  // Top bar
  Rectangle bottom_bar = Rectangle(0, SCREEN_HEIGHT - 10, 0, 2); // Bottom bar

  bool move_right = true;
  float b = 3;

  int paddle_one_score = 0;
  int paddle_two_score = 0;

  float expected_x_pos = SCREEN_WIDTH/2 + 5;
  float expected_y_pos = SCREEN_HEIGHT/2 + 3;
  bool expected_move_right_bool = true;
  int expected_paddle_scores = 0;

  BallMovement(ball, paddle_one, paddle_two,
                move_right, b,
                top_bar, bottom_bar,
                paddle_one_score, paddle_two_score);

  if (ball.GetX() == expected_x_pos && ball.GetY() == expected_y_pos &&
        move_right == expected_move_right_bool &&
        paddle_one_score == expected_paddle_scores &&
        paddle_two_score == expected_paddle_scores) {
    
    return true;
  }
  return false;
}

bool TestMoveRightAndUp() {
  Rectangle ball = Rectangle(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 5, 1);

  Rectangle paddle_one = Rectangle(SCREEN_WIDTH - 35, SCREEN_HEIGHT/2 - 35, 5, 0);
  Rectangle paddle_two = Rectangle(20, SCREEN_HEIGHT/2 - 35, 5, 0);

  Rectangle top_bar = Rectangle(0, 0, 0, 2);  // Top bar
  Rectangle bottom_bar = Rectangle(0, SCREEN_HEIGHT - 10, 0, 2); // Bottom bar

  bool move_right = true;
  float b = -3;

  int paddle_one_score = 0;
  int paddle_two_score = 0;

  float expected_x_pos = SCREEN_WIDTH/2 + 5;
  float expected_y_pos = SCREEN_HEIGHT/2 - 3;
  bool expected_move_right_bool = true;
  int expected_paddle_scores = 0;

  BallMovement(ball, paddle_one, paddle_two,
                move_right, b,
                top_bar, bottom_bar,
                paddle_one_score, paddle_two_score);

  if (ball.GetX() == expected_x_pos && ball.GetY() == expected_y_pos &&
        move_right == expected_move_right_bool &&
        paddle_one_score == expected_paddle_scores &&
        paddle_two_score == expected_paddle_scores) {
    
    return true;
  }
  return false;
}

bool TestMoveLeftAndUp() {
  Rectangle ball = Rectangle(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, -5, 1);

  Rectangle paddle_one = Rectangle(SCREEN_WIDTH - 35, SCREEN_HEIGHT/2 - 35, 5, 0);
  Rectangle paddle_two = Rectangle(20, SCREEN_HEIGHT/2 - 35, 5, 0);

  Rectangle top_bar = Rectangle(0, 0, 0, 2);  // Top bar
  Rectangle bottom_bar = Rectangle(0, SCREEN_HEIGHT - 10, 0, 2); // Bottom bar

  bool move_right = false;
  float b = -3;

  int paddle_one_score = 0;
  int paddle_two_score = 0;

  float expected_x_pos = SCREEN_WIDTH/2 - 5;
  float expected_y_pos = SCREEN_HEIGHT/2 - 3;
  bool expected_move_right_bool = false;
  int expected_paddle_scores = 0;

  BallMovement(ball, paddle_one, paddle_two,
                move_right, b,
                top_bar, bottom_bar,
                paddle_one_score, paddle_two_score);

  if (ball.GetX() == expected_x_pos && ball.GetY() == expected_y_pos &&
        move_right == expected_move_right_bool &&
        paddle_one_score == expected_paddle_scores &&
        paddle_two_score == expected_paddle_scores) {
    
    return true;
  }
  return false;
}

bool TestMoveLeftAndDown() {
  Rectangle ball = Rectangle(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 5, 1);

  Rectangle paddle_one = Rectangle(SCREEN_WIDTH - 35, SCREEN_HEIGHT/2 - 35, 5, 0);
  Rectangle paddle_two = Rectangle(20, SCREEN_HEIGHT/2 - 35, 5, 0);

  Rectangle top_bar = Rectangle(0, 0, 0, 2);  // Top bar
  Rectangle bottom_bar = Rectangle(0, SCREEN_HEIGHT - 10, 0, 2); // Bottom bar

  bool move_right = true;
  float b = 3;

  int paddle_one_score = 0;
  int paddle_two_score = 0;

  float expected_x_pos = SCREEN_WIDTH/2 + 5;
  float expected_y_pos = SCREEN_HEIGHT/2 + 3;
  bool expected_move_right_bool = true;
  int expected_paddle_scores = 0;

  BallMovement(ball, paddle_one, paddle_two,
                move_right, b,
                top_bar, bottom_bar,
                paddle_one_score, paddle_two_score);

  if (ball.GetX() == expected_x_pos && ball.GetY() == expected_y_pos &&
        move_right == expected_move_right_bool &&
        paddle_one_score == expected_paddle_scores &&
        paddle_two_score == expected_paddle_scores) {
    
    return true;
  }
  return false;
}

bool TestBounceOffTopBarGoingLeft() {
  Rectangle ball = Rectangle(SCREEN_WIDTH/2, 13, -5, 1);

  Rectangle paddle_one = Rectangle(SCREEN_WIDTH - 35, SCREEN_HEIGHT/2 - 35, 5, 0);
  Rectangle paddle_two = Rectangle(20, SCREEN_HEIGHT/2 - 35, 5, 0);

  Rectangle top_bar = Rectangle(0, 0, 0, 2);  // Top bar
  Rectangle bottom_bar = Rectangle(0, SCREEN_HEIGHT - 10, 0, 2); // Bottom bar

  bool move_right = false;
  float b = -3;

  int paddle_one_score = 0;
  int paddle_two_score = 0;

  float expected_x_pos = SCREEN_WIDTH/2 - 5;
  float expected_y_pos = 16;  // Ball just moves to new position by ball.GetY() + (b * -1)
  bool expected_move_right_bool = false;
  int expected_paddle_scores = 0;

  BallMovement(ball, paddle_one, paddle_two,
                move_right, b,
                top_bar, bottom_bar,
                paddle_one_score, paddle_two_score);

  if (ball.GetX() == expected_x_pos && ball.GetY() == expected_y_pos &&
        move_right == expected_move_right_bool &&
        paddle_one_score == expected_paddle_scores &&
        paddle_two_score == expected_paddle_scores) {
    
    return true;
  }
  return false;
}

bool TestBounceOffTopBarGoingRight() {
  Rectangle ball = Rectangle(SCREEN_WIDTH/2, 13, 5, 1);

  Rectangle paddle_one = Rectangle(SCREEN_WIDTH - 35, SCREEN_HEIGHT/2 - 35, 5, 0);
  Rectangle paddle_two = Rectangle(20, SCREEN_HEIGHT/2 - 35, 5, 0);

  Rectangle top_bar = Rectangle(0, 0, 0, 2);  // Top bar
  Rectangle bottom_bar = Rectangle(0, SCREEN_HEIGHT - 10, 0, 2); // Bottom bar

  bool move_right = true;
  float b = -3;

  int paddle_one_score = 0;
  int paddle_two_score = 0;

  float expected_x_pos = SCREEN_WIDTH/2 + 5;
  float expected_y_pos = 16;
  bool expected_move_right_bool = true;
  int expected_paddle_scores = 0;

  BallMovement(ball, paddle_one, paddle_two,
                move_right, b,
                top_bar, bottom_bar,
                paddle_one_score, paddle_two_score);

  if (ball.GetX() == expected_x_pos && ball.GetY() == expected_y_pos &&
        move_right == expected_move_right_bool &&
        paddle_one_score == expected_paddle_scores &&
        paddle_two_score == expected_paddle_scores) {
    
    return true;
  }
  return false;
}

bool TestBounceOffBottomBarGoingLeft() {
  Rectangle ball = Rectangle(SCREEN_WIDTH/2, SCREEN_HEIGHT - 13, -5, 1);

  Rectangle paddle_one = Rectangle(SCREEN_WIDTH - 35, SCREEN_HEIGHT/2 - 35, 5, 0);
  Rectangle paddle_two = Rectangle(20, SCREEN_HEIGHT/2 - 35, 5, 0);

  Rectangle top_bar = Rectangle(0, 0, 0, 2);  // Top bar
  Rectangle bottom_bar = Rectangle(0, SCREEN_HEIGHT - 10, 0, 2); // Bottom bar

  bool move_right = false;
  float b = 3;

  int paddle_one_score = 0;
  int paddle_two_score = 0;

  float expected_x_pos = SCREEN_WIDTH/2 - 5;
  float expected_y_pos = SCREEN_HEIGHT - 16;
  bool expected_move_right_bool = false;
  int expected_paddle_scores = 0;

  // printf("%0.0f, %0.0f, %d, %d, %s\n", ball.GetX(), ball.GetY(), paddle_one_score, paddle_two_score, move_right ? "true" : "false");

  BallMovement(ball, paddle_one, paddle_two,
                move_right, b,
                top_bar, bottom_bar,
                paddle_one_score, paddle_two_score);

  // printf("%0.0f, %0.0f, %d, %d, %s\n", ball.GetX(), ball.GetY(), paddle_one_score, paddle_two_score, move_right ? "true" : "false");

  if (ball.GetX() == expected_x_pos && ball.GetY() == expected_y_pos &&
        move_right == expected_move_right_bool &&
        paddle_one_score == expected_paddle_scores &&
        paddle_two_score == expected_paddle_scores) {
    
    return true;
  }
  return false;
}

bool TestBounceOffBottomBarGoingRight() {
  Rectangle ball = Rectangle(SCREEN_WIDTH/2, SCREEN_HEIGHT - 13, 5, 1);

  Rectangle paddle_one = Rectangle(SCREEN_WIDTH - 35, SCREEN_HEIGHT/2 - 35, 5, 0);
  Rectangle paddle_two = Rectangle(20, SCREEN_HEIGHT/2 - 35, 5, 0);

  Rectangle top_bar = Rectangle(0, 0, 0, 2);  // Top bar
  Rectangle bottom_bar = Rectangle(0, SCREEN_HEIGHT - 10, 0, 2); // Bottom bar

  bool move_right = true;
  float b = 3;

  int paddle_one_score = 0;
  int paddle_two_score = 0;

  float expected_x_pos = SCREEN_WIDTH/2 + 5;
  float expected_y_pos = SCREEN_HEIGHT - 16;
  bool expected_move_right_bool = true;
  int expected_paddle_scores = 0;

  // printf("%0.0f, %0.0f, %d, %d, %s\n", ball.GetX(), ball.GetY(), paddle_one_score, paddle_two_score, move_right ? "true" : "false");

  BallMovement(ball, paddle_one, paddle_two,
                move_right, b,
                top_bar, bottom_bar,
                paddle_one_score, paddle_two_score);

  // printf("%0.0f, %0.0f, %d, %d, %s\n", ball.GetX(), ball.GetY(), paddle_one_score, paddle_two_score, move_right ? "true" : "false");

  if (ball.GetX() == expected_x_pos && ball.GetY() == expected_y_pos &&
        move_right == expected_move_right_bool &&
        paddle_one_score == expected_paddle_scores &&
        paddle_two_score == expected_paddle_scores) {
    
    return true;
  }
  return false;
}

bool TestBounceOffLeftPaddleUp() {

  return false;
}

bool TestBounceOffLeftPaddleDown() {

  return false;
}

bool TestBounceOffRightPaddleUp() {

  return false;
}

bool TestBounceOffRightPaddleDown() {

  return false;
}

bool TestHitEndScreenLeft() {

  return false;
}

bool TestHitEndScreenRight() {

  return false;
}