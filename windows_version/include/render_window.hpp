#ifndef RENDER_WINDOW
#define RENDER_WINDOW

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_hints.h>
#include "rectangle.hpp"
#include <stdio.h>

#define SCREEN_WIDTH (650)
#define SCREEN_HEIGHT (475)

#define MAX_SCORE (10)

class RenderWindow {
public:
  RenderWindow(const char* ptr_title, int width, int height); // Constructor

  int GetRefreshRate(); // Refresh rate for window

  void CleanUp(); // Destroy window

  void Clear(); // Clear window

  void RenderRectangles(Rectangle& rec);  // Render Rectangles

  void SetBackgroundColour();

  void PlayersOption(SDL_Rect& message_rect_one, SDL_Rect& message_rect_two,
                      SDL_Rect& outline_rect_one, SDL_Rect& outline_rect_two);

  void DifficultyPicker(SDL_Rect& message_rect_one, SDL_Rect& message_rect_two,
                        SDL_Rect& message_rect_three, SDL_Rect& outline_rect_one,
                        SDL_Rect& outline_rect_two, SDL_Rect& outline_rect_three);

  void DisplayScores(int paddle_one_score, int paddle_two_score);

  void Win(int paddle_one_score, int paddle_two_score);

  void Display(); // Display window

private:
  SDL_Window* window;
  SDL_Renderer* renderer;
};

#endif