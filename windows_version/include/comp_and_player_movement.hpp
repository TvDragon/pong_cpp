#ifndef COMP_AND_PLAYER_MOVEMENT
#define COMP_AND_PLAYER_MOVEMENT

#include "render_window.hpp"
#include "rectangle.hpp"

void MoveUpPlayer(Rectangle& paddle, Rectangle top_bar);

void MoveDownPlayer(Rectangle& paddle, Rectangle bottom_bar);

void MoveUpComputer(Rectangle& paddle, Rectangle top_bar, bool& move_downwards);

void MoveDownComputer(Rectangle& paddle, Rectangle bottom_bar, bool& move_downwards);

#endif