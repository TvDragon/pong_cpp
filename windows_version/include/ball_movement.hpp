#ifndef BALL_MOVEMENT
#define BALL_MOVEMENT

#include <stdlib.h>
#include <time.h>

#include "render_window.hpp"
#include "rectangle.hpp"

void BallMovement(Rectangle& ball, Rectangle paddle_one, Rectangle paddle_two,
                    bool& move_right, float& b,
                    Rectangle top_bar, Rectangle bottom_bar,
                    int& paddle_one_score, int& paddle_two_score);

#endif