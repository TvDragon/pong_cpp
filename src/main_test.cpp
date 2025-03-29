#include "../include/rectangle_test.hpp"
#include "../include/paddle_movement_test.hpp"
#include "../include/ball_movement_test.hpp"

#include <stdio.h>

int main() {

  printf("Test Rectangle Class\n-----------\n");
  printf("Test GetX(): %s\n", TestGetX() ? "true" : "false");  // ternary if
  printf("Test GetY(): %s\n", TestGetY() ? "true" : "false");
  printf("Test GetSpeed(): %s\n", TestGetSpeed() ? "true" : "false");
  printf("Test SetX(): %s\n", TestSetX() ? "true" : "false");
  printf("Test SetY(): %s\n", TestSetY() ? "true" : "false");
  printf("Test GetCurrentFrame() For Paddle: %s\n", TestGetCurrentFramePaddle() ? "true" : "false");
  printf("Test GetCurrentFrame() For Center Block: %s\n", TestGetCurrentFrameCenterBlock() ? "true" : "false");
  printf("Test GetGetCurrentFrame() For Top & Bottom Bars: %s\n\n", TestGetCurrentFrameTopAndBottomBars() ? "true" : "false");

  printf("Test Player And Computer Movement\n-----------\n");
  printf("Test MoveUpPlayer(): %s\n", TestMoveUpPlayer() ? "true" : "false");
  printf("Test MoveDownPlayer(): %s\n", TestMoveDownPlayer() ? "true" : "false");
  printf("Test PlayerTouchTopBar() : %s\n", PlayerTouchTopBar() ? "true" : "false");
  printf("Test PlayerTouchBottomBar() : %s\n", PlayerTouchBottomBar() ? "true" : "false");
  printf("Test TestMoveUpComputer(): %s\n", TestMoveUpComputer() ? "true" : "false");
  printf("Test TestMoveDownComputer(): %s\n", TestMoveDownComputer() ? "true" : "false");
  printf("Test BotTouchTopBar(): %s\n", BotTouchTopBar() ? "true" : "false");
  printf("Test BotTouchBottomBar(): %s\n\n", BotTouchBottomBar() ? "true" : "false");

  printf("Test Ball Movement\n-----------\n");
  printf("Test MoveRight(): %s\n", TestMoveRight() ? "true" : "false");
  printf("Test MoveLeft(): %s\n", TestMoveLeft() ? "true" : "false");
  printf("Test MoveRightAndUp(): %s\n", TestMoveRightAndUp() ? "true" : "false");
  printf("Test MoveRightAndDown(): %s\n", TestMoveRightAndDown() ? "true" : "false");
  printf("Test MoveLeftAndUp(): %s\n", TestMoveLeftAndUp() ? "true" : "false");
  printf("Test MoveLeftAndDown(): %s\n", TestMoveLeftAndDown() ? "true" : "false");
  printf("Test BounceOffTopBarGoingLeft(): %s\n", TestBounceOffTopBarGoingLeft() ? "true" : "false");
  printf("Test BounceOffTopBarGoingRight(): %s\n", TestBounceOffTopBarGoingRight() ? "true" : "false");
  printf("Test BounceOffBottomBarGoingLeft(): %s\n", TestBounceOffBottomBarGoingLeft() ? "true" : "false");
  printf("Test BounceOffBottomBarGoingRight(): %s\n", TestBounceOffBottomBarGoingRight() ? "true" : "false");
  // printf("Test BounceOffLeftPaddleUp(): %s\n", TestBounceOffLeftPaddleUp() ? "true" : "false");
  // printf("Test BounceOffLeftPaddleDown(): %s\n", TestBounceOffLeftPaddleDown() ? "true" : "false");
  // printf("Test BounceOffRightPaddleUp(): %s\n", TestBounceOffRightPaddleUp() ? "true" : "false");
  // printf("Test BounceOffRightPaddleDown(): %s\n", TestBounceOffRightPaddleDown() ? "true" : "false");
  // printf("Test HitEndScreenLeft(): %s\n", TestHitEndScreenLeft() ? "true" : "false");
  // printf("Test HitEndScreenRight(): %s\n", TestHitEndScreenRight() ? "true" : "false");

  return 0;
}