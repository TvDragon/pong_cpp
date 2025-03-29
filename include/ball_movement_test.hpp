#ifndef BALL_MOVEMENT_TEST
#define BALL_MOVEMENT_TEST

#include "render_window.hpp"
#include "rectangle.hpp"
#include "ball_movement.hpp"

bool TestMoveRight();

bool TestMoveLeft();

bool TestMoveRightAndUp();

bool TestMoveRightAndDown();

bool TestMoveLeftAndUp();

bool TestMoveLeftAndDown();

bool TestBounceOffTopBarGoingLeft();

bool TestBounceOffTopBarGoingRight();

bool TestBounceOffBottomBarGoingLeft();

bool TestBounceOffBottomBarGoingRight();

bool TestBounceOffLeftPaddleUp();

bool TestBounceOffLeftPaddleDown();

bool TestBounceOffRightPaddleUp();

bool TestBounceOffRightPaddleDown();

bool TestHitEndScreenLeft();

bool TestHitEndScreenRight();

#endif