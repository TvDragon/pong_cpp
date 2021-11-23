#include "../include/game.hpp"

void CheckGameOver(int paddle_one_score, int paddle_two_score, bool& game_over) {
  if (paddle_one_score == MAX_SCORE || paddle_two_score == MAX_SCORE) {
    game_over = true;
  }
}

void VersusComputerEasy(bool& move_right, bool& within_range, bool& move_downwards,
                    Rectangle top_bar, Rectangle bottom_bar,
                    Rectangle& paddle_two, Rectangle ball, double& distance) {
  if (!move_right) {
    if (distance <= 100) {
      if (ball.GetX() >= paddle_two.GetX()) {
        within_range = true;
      } else {
        within_range = false;
      }
    } else {
      within_range = false;
    }
  } else {
    within_range = false;
  }

  if (within_range) {
    if (paddle_two.GetY() >= ball.GetY() + ball.GetCurrentFrame().h) {
      MoveUpComputer(paddle_two, top_bar, move_downwards);
    } else if (paddle_two.GetY() + paddle_two.GetCurrentFrame().h <= ball.GetY()) {
      MoveDownComputer(paddle_two, bottom_bar, move_downwards);
    }
  } else {
    if (move_downwards) {
      MoveDownComputer(paddle_two, bottom_bar, move_downwards);
    } else if (!move_downwards) {
      MoveUpComputer(paddle_two, top_bar, move_downwards);
    }
  }
}

void VersusComputerHard(Rectangle& paddle_two, Rectangle ball) {
  
  if (paddle_two.GetY() >= ball.GetY() + ball.GetCurrentFrame().h) {
    MoveComputerUpHardMode(paddle_two);
  } else if (paddle_two.GetY() + paddle_two.GetCurrentFrame().h <= ball.GetY()) {
    MoveComputerDownHardMode(paddle_two);
  }
}

void Input(bool& game_running, Rectangle& paddle_one, Rectangle& paddle_two,
            Rectangle top_bar, Rectangle bottom_bar, int num_players) {

  const Uint8* keystates = SDL_GetKeyboardState(NULL);
  if (keystates[SDL_SCANCODE_ESCAPE])
    game_running = false;
  if (keystates[SDL_SCANCODE_UP])
    MoveUpPlayer(paddle_one, top_bar);
  if (keystates[SDL_SCANCODE_DOWN])
    MoveDownPlayer(paddle_one, bottom_bar);
  
  if (num_players == 2) {
    if (keystates[SDL_SCANCODE_W])
      MoveUpPlayer(paddle_two, top_bar);
    if (keystates[SDL_SCANCODE_S])
      MoveDownPlayer(paddle_two, bottom_bar);
  }
}

void GameLoop(RenderWindow window, SDL_Event event, Rectangle paddle_one,
                Rectangle paddle_two, Rectangle top_bar, Rectangle bottom_bar,
                Rectangle ball, Rectangle* middle_lines,
                bool& game_running, bool& within_range, bool& game_over,
                bool& move_downwards, bool& move_right,
                float& b, double& distance, int num_rects,
                int& paddle_one_score, int& paddle_two_score,
                int num_players, int num_difficulty) {

  int ticks = 0;

  // Draw objects onto window
  DrawObjects(window, num_rects, middle_lines,
                paddle_one, paddle_two, ball, paddle_one_score, paddle_two_score);

  SDL_Delay(1000);

  while (game_running) {

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        game_running = false;
    }

    Input(game_running, paddle_one, paddle_two, top_bar, bottom_bar, num_players); // Take input from player

    BallMovement(ball, paddle_one, paddle_two, move_right, b,
                  top_bar, bottom_bar,
                  paddle_one_score, paddle_two_score,
                  num_difficulty);

    distance = sqrt(pow((ball.GetX() - paddle_two.GetX()), 2) + pow((ball.GetY() - paddle_two.GetY()), 2));

    if (num_players == 1 && num_difficulty == 1) {
      VersusComputerEasy(move_right, within_range, move_downwards,
                      top_bar, bottom_bar,
                      paddle_two, ball, distance);
    } else if (num_players == 1 && num_difficulty == 3) {
      VersusComputerHard(paddle_two, ball);
    }

    // Draw objects onto window
    DrawObjects(window, num_rects, middle_lines,
                  paddle_one, paddle_two, ball, paddle_one_score, paddle_two_score);

    // Check if game is over
    CheckGameOver(paddle_one_score, paddle_two_score, game_over);

    if (game_over) {
      game_running = false;
    }

    SDL_Delay(10);
  }
}