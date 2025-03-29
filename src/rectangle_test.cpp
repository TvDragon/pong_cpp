#include "../include/rectangle_test.hpp"

bool TestGetX() {
  float exepected_value = 0;
  Rectangle rect = Rectangle(0, 0, 5, 0);

  if (rect.GetX() == exepected_value)
    return true;

  return false;
}

bool TestGetY() {
  float exepected_value = 1;
  Rectangle rect = Rectangle(0, 1, 5, 0);

  if (rect.GetY() == exepected_value)
    return true;

  return false;
}

bool TestGetSpeed() {

  float expected_value = 5;
  Rectangle rect = Rectangle(0, 0, 5, 0);

  if (rect.GetSpeed() == expected_value)
    return true;

  return false;
}

bool TestSetX() {
  float expected_value = 5;
  Rectangle rect = Rectangle(0, 0, 5, 0);

  rect.SetX(5);

  if (rect.GetX() == expected_value)
    return true;

  return false;
}

bool TestSetY() {
  float expected_value = 5;
  Rectangle rect = Rectangle(0, 0, 5, 0);

  rect.SetY(5);

  if (rect.GetY() == expected_value)
    return true;

  return false;
}

bool TestSetSpeed() {
  float expected_value = 5;
  Rectangle rect = Rectangle(0, 0, 5, 0);

  rect.SetSpeed(10);

  if (rect.GetSpeed() == expected_value)
    return true;

  return false;
}

bool TestGetCurrentFramePaddle() {
  float expected_value_w = 15;
  float expected_value_h = 70;
  Rectangle rect = Rectangle(0, 0, 5, 0);

  if (rect.GetCurrentFrame().w == expected_value_w &&
      rect.GetCurrentFrame().h == expected_value_h)
    return true;

  return false;
}

bool TestGetCurrentFrameCenterBlock() {
  float expected_value_w = 15;
  float expected_value_h = 70;
  Rectangle rect = Rectangle(0, 0, 5, 0);

  if (rect.GetCurrentFrame().w == expected_value_w &&
      rect.GetCurrentFrame().h == expected_value_h)
    return true;

  return false;
}

bool TestGetCurrentFrameTopAndBottomBars() {
  float expected_value_w = SCREEN_WIDTH;
  float expected_value_h = 10;
  Rectangle rect = Rectangle(0, 0, 5, 2);

  if (rect.GetCurrentFrame().w == expected_value_w &&
      rect.GetCurrentFrame().h == expected_value_h)
    return true;

  return false;
}