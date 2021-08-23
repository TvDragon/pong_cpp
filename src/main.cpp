#include "../include/render_window.hpp"
#include "../include/rectangle.hpp"
#include "../include/home_and_difficulty_screen.hpp"
#include "../include/game.hpp"

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {

  if (TTF_Init() < 0)
    printf("TTF could not initialise! TTF_Error :%s\n", TTF_GetError());

  // Returns 0 on success else non-zero
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    printf("SDL could not initialise! SDL_Error: %s\n", SDL_GetError());
  
  if (!(IMG_Init(IMG_INIT_PNG)))
    printf("IMG_init has failed. ERROR: %s\n", SDL_GetError());

  RenderWindow window("Pong", SCREEN_WIDTH, SCREEN_HEIGHT);

  Rectangle paddle_one = Rectangle(SCREEN_WIDTH - 35, SCREEN_HEIGHT/2 - 35, 5, 0);

  Rectangle paddle_two = Rectangle(20, SCREEN_HEIGHT/2 - 35, 5, 0);

  Rectangle ball = Rectangle(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 5, 1);

  int num_rects = 18;
  Rectangle middle_lines[num_rects];

  int i = 0;
  for (; i < num_rects-2; i++) {
    middle_lines[i] = Rectangle(SCREEN_WIDTH/2, (i+1)*27, 0, 1);
  }

  middle_lines[i] = Rectangle(0, 0, 0, 2);  // Top bar
  middle_lines[i+1] = Rectangle(0, SCREEN_HEIGHT - 10, 0, 2); // Bottom bar

  // Speed ball travels in y-direction
  float b = 3;

  bool game_running = true;
  bool game_over = false;
  bool within_range = false;
  bool stay = true;
  bool quit = false;

  bool move_downwards = true;
  bool move_right = true;

  double distance = 0;

  int paddle_one_score = 0;
  int paddle_two_score = 0;

  int num_players = 0;
  int num_difficulty = 0;

  SDL_Event event;  // Take events from keyboard

  SDL_Rect message_rect_one;
  SDL_Rect message_rect_two;
  SDL_Rect message_rect_three;

  SDL_Rect outline_rect_one;
  SDL_Rect outline_rect_two;
  SDL_Rect outline_rect_three;

  HomeScreen(window, stay, quit, event,
              message_rect_one, message_rect_two,
              outline_rect_one, outline_rect_two,
              num_players);
  
  if (!quit) {
    DifficultyScreen(window, stay, event,
                  message_rect_one, message_rect_two, message_rect_three,
                  outline_rect_one, outline_rect_two, outline_rect_three,
                  num_difficulty);

    if (num_difficulty == 1 && num_players == 1) {
      EasyMode(window, event, paddle_one,
                paddle_two, middle_lines[num_rects-2], middle_lines[num_rects-1],
                ball, middle_lines,
                game_running, within_range, game_over, move_downwards, move_right,
                b, distance, num_rects, paddle_one_score, paddle_two_score,
                num_players);
    } else if (num_difficulty == 1 && num_players == 2) {
        EasyMode(window, event, paddle_one,
                paddle_two, middle_lines[num_rects-2], middle_lines[num_rects-1],
                ball, middle_lines,
                game_running, within_range, game_over, move_downwards, move_right,
                b, distance, num_rects, paddle_one_score, paddle_two_score,
                num_players);
    }

    window.Win(paddle_one_score, paddle_two_score);
    window.SetBackgroundColour();
    window.Display();

    if (paddle_one_score == MAX_SCORE || paddle_two_score == MAX_SCORE) {
      SDL_Delay(1500);
    }
  }

  window.CleanUp();

  TTF_Quit();
  SDL_Quit();

  return 0;
}