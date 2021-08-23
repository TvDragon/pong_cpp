#include "../include/render_window.hpp"
#include "../include/rectangle.hpp"

Rectangle::Rectangle() {

}

Rectangle::Rectangle(float x, float y, float speed, int num)
  :x(x), y(y), speed(speed) // Set to values given in parameter
{
  current_frame.x = 0;
  current_frame.y = 0;
  if (num == 0) {         // paddles
    current_frame.w = 15;
    current_frame.h = 70;
  } else if (num == 1) {  // center blocks
    current_frame.w = 15;
    current_frame.h = 15;
  } else if (num == 2) {
    current_frame.w = SCREEN_WIDTH; // top and bottom bars
    current_frame.h = 10;
  }
}

void Rectangle::SetX(float x) {
  this->x = x;
}

void Rectangle::SetY(float y) {
  this->y = y;
}

void Rectangle::SetSpeed(float speed) {
  this->speed = speed;
}

float Rectangle::GetX() {
  return x;
}

float Rectangle::GetY() {
  return y;
}

float Rectangle::GetSpeed() {
  return speed;
}

SDL_Rect Rectangle::GetCurrentFrame() {
  return current_frame;
}