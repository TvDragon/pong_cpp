#ifndef GAME
#define GAME

#include "render_window.hpp"
#include "rectangle.hpp"
#include "ball_movement.hpp"
#include "comp_and_player_movement.hpp"
#include "draw_objects.hpp"

void CheckGameOver(int paddle_one_score, int paddle_two_score, bool& game_over);

void VersusComputer(bool& move_right, bool& within_range, bool& move_downwards,
                    Rectangle top_bar, Rectangle bottom_bar,
                    Rectangle& paddle_two, Rectangle ball, double& distance);

void Input(bool& game_running, Rectangle& paddle_one, Rectangle top_bar, Rectangle bottom_bar);

void EasyMode(RenderWindow window, SDL_Event event, Rectangle paddle_one,
                Rectangle paddle_two, Rectangle top_bar, Rectangle bottom_bar,
                Rectangle ball, Rectangle* middle_lines,
                bool& game_running, bool& within_range, bool& game_over,
                bool& move_downwards, bool& move_right,
                float& b, double& distance, int num_rects,
                int& paddle_one_score, int& paddle_two_score,
                int num_players);


#endif