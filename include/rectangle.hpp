#ifndef RECTANGLE
#define RECTANGLE

#include <SDL2/SDL.h>

class Rectangle {
public:
  Rectangle();
  Rectangle(float x, float y, float speed, int num);

  void SetX(float x);

  void SetY(float y);

  void SetSpeed(float speed);

  float GetX();

  float GetY();

  float GetSpeed();

  SDL_Rect GetCurrentFrame();

private:
  float x, y, speed;
  int num;
  SDL_Rect current_frame;
};

#endif