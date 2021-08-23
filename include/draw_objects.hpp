#ifndef DRAW_OBJECTS
#define DRAW_OBJECTS

#include <SDL2/SDL.h>

#include "render_window.hpp"
#include "rectangle.hpp"

void DrawObjects(RenderWindow window, int num_rects, Rectangle* middle_lines,
                  Rectangle paddle_one, Rectangle paddle_two, Rectangle ball,
                  int& paddle_one_score, int& paddle_two_score);

#endif