#include "../include/render_window.hpp"
#include "../include/rectangle.hpp"
#include <string>
#include <iostream>

using namespace std;

RenderWindow::RenderWindow(const char* ptr_title, int width, int height)
  :window(NULL), renderer(NULL) // Set NULL pointer to window and renderer initially
{
  window = SDL_CreateWindow(ptr_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
              width, height, SDL_WINDOW_SHOWN);

/*   window = SDL_CreateWindow(ptr_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERE>
              width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
*/
  if (window == NULL)
    printf("Window failed to init. Error %s\n", SDL_GetError());

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  // the window, index graphics, use graphics faster if exist

  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");  // Specify scaling quality
  // SDL_ShowCursor(0);  // Don't show cursor when on window
}

int RenderWindow::GetRefreshRate() {
  int display_index = SDL_GetWindowDisplayIndex(window);  // Figures out which screen our window is on

  SDL_DisplayMode mode;

  SDL_GetDisplayMode(display_index, 0, &mode);

  return mode.refresh_rate;
}

void RenderWindow::CleanUp() {
  SDL_DestroyWindow(window);  // Destroy game window
  SDL_DestroyRenderer(renderer);
}

void RenderWindow::Clear() {
  SDL_RenderClear(renderer);
}

void RenderWindow::PlayersOption(SDL_Rect& message_rect_one, SDL_Rect& message_rect_two,
                                  SDL_Rect& outline_rect_one, SDL_Rect& outline_rect_two) {

  char one_player[15] = "(1) ONE PLAYER";
  char two_players[16] = "(1) TWO PLAYERS";

  // Type Text On Screen
  // TTF_Font* font = TTF_OpenFont("fonts/bit5x3.ttf", 50);  // Font type ttf in folder on linux
  TTF_Font* font = TTF_OpenFont("fonts/bit5x3.ttf", 50);  // Font type ttf in folder on windows

  SDL_Color text_colour = {255, 255, 255};

  // as TTF_RenderText_Solid could only be used on
  // SDL_Surface then you have to create the surface first
  SDL_Surface* surface_message_one_player = TTF_RenderText_Solid(font, one_player, text_colour);
  SDL_Surface* surface_message_two_players = TTF_RenderText_Solid(font, two_players, text_colour);
  // now you can convert it into a texture
  SDL_Texture* message_one = SDL_CreateTextureFromSurface(renderer, surface_message_one_player);
  SDL_Texture* message_two = SDL_CreateTextureFromSurface(renderer, surface_message_two_players);

  message_rect_one.x = SCREEN_WIDTH / 2 - 125;  //controls the rect's x coordinate 
  message_rect_one.y = SCREEN_HEIGHT / 2 - 90; // controls the rect's y coordinte
  message_rect_one.w = 250; // controls the width of the rect
  message_rect_one.h = 70; // controls the height of the rect

  message_rect_two.x = SCREEN_WIDTH / 2 - 125;  //controls the rect's x coordinate 
  message_rect_two.y = SCREEN_HEIGHT / 2 + 20; // controls the rect's y coordinte
  message_rect_two.w = 250; // controls the width of the rect
  message_rect_two.h = 70; // controls the height of the rect

  outline_rect_one = {message_rect_one.x - 10, message_rect_one.y - 10,
                      message_rect_one.w + 20,
                      message_rect_one.h + 20};
  outline_rect_two = {message_rect_two.x - 10, message_rect_two.y - 10,
                      message_rect_two.w + 20,
                      message_rect_two.h + 20};

  SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0x00);
  SDL_RenderDrawRect(renderer, &outline_rect_one);
  SDL_RenderDrawRect(renderer, &outline_rect_two);

  // renderer, message, crop size (ignore), rect with coordinate
  SDL_RenderCopy(renderer, message_one, NULL, &message_rect_one);
  SDL_RenderCopy(renderer, message_two, NULL, &message_rect_two);

  SDL_FreeSurface(surface_message_one_player);
  SDL_FreeSurface(surface_message_two_players);

  SDL_DestroyTexture(message_one);
  SDL_DestroyTexture(message_two);

  TTF_CloseFont(font);
}

void RenderWindow::DifficultyPicker(SDL_Rect& message_rect_one, SDL_Rect& message_rect_two,
                                    SDL_Rect& message_rect_three, SDL_Rect& outline_rect_one,
                                    SDL_Rect& outline_rect_two, SDL_Rect& outline_rect_three) {
  char easy[9] = "(1) EASY";
  char medium[11] = "(2) MEDIUM";
  char hard[9] = "(3) HARD";

  // Type Text On Screen
  // TTF_Font* font = TTF_OpenFont("fonts/bit5x3.ttf", 50);  // Font type ttf in folder on linux
  TTF_Font* font = TTF_OpenFont("fonts/bit5x3.ttf", 50);  // Font type ttf in folder on windows
  SDL_Color text_colour = {255, 255, 255};

  // as TTF_RenderText_Solid could only be used on
  // SDL_Surface then you have to create the surface first
  SDL_Surface* surface_message_easy = TTF_RenderText_Solid(font, easy, text_colour);
  SDL_Surface* surface_message_medium = TTF_RenderText_Solid(font, medium, text_colour);
  SDL_Surface* surface_message_hard = TTF_RenderText_Solid(font, hard, text_colour);
  // now you can convert it into a texture
  SDL_Texture* message_easy = SDL_CreateTextureFromSurface(renderer, surface_message_easy);
  SDL_Texture* message_medium = SDL_CreateTextureFromSurface(renderer, surface_message_medium);
  SDL_Texture* message_hard = SDL_CreateTextureFromSurface(renderer, surface_message_hard);

  message_rect_one.x = SCREEN_WIDTH / 2 - 125;  //controls the rect's x coordinate 
  message_rect_one.y = SCREEN_HEIGHT / 2 - 140; // controls the rect's y coordinte
  message_rect_one.w = 250; // controls the width of the rect
  message_rect_one.h = 70; // controls the height of the rect

  message_rect_two.x = SCREEN_WIDTH / 2 - 125;
  message_rect_two.y = SCREEN_HEIGHT / 2 - 35;
  message_rect_two.w = 250;
  message_rect_two.h = 70;

  message_rect_three.x = SCREEN_WIDTH / 2 - 125;
  message_rect_three.y = SCREEN_HEIGHT / 2 + 70;
  message_rect_three.w = 250;
  message_rect_three.h = 70;

  outline_rect_one = {message_rect_one.x - 10, message_rect_one.y - 10,
                      message_rect_one.w + 20,
                      message_rect_one.h + 20};
  outline_rect_two = {message_rect_two.x - 10, message_rect_two.y - 10,
                      message_rect_two.w + 20,
                      message_rect_two.h + 20};
  outline_rect_three = {message_rect_three.x - 10, message_rect_three.y - 10,
                      message_rect_three.w + 20,
                      message_rect_three.h + 20};

  SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0x00);
  SDL_RenderDrawRect(renderer, &outline_rect_one);
  SDL_RenderDrawRect(renderer, &outline_rect_two);
  SDL_RenderDrawRect(renderer, &outline_rect_three);

  // renderer, message, crop size (ignore), rect with coordinate
  SDL_RenderCopy(renderer, message_easy, NULL, &message_rect_one);
  SDL_RenderCopy(renderer, message_medium, NULL, &message_rect_two);
  SDL_RenderCopy(renderer, message_hard, NULL, &message_rect_three);

  SDL_FreeSurface(surface_message_easy);
  SDL_FreeSurface(surface_message_medium);
  SDL_FreeSurface(surface_message_hard);

  SDL_DestroyTexture(message_easy);
  SDL_DestroyTexture(message_medium);
  SDL_DestroyTexture(message_hard);

  TTF_CloseFont(font);
}

void RenderWindow::DisplayScores(int paddle_one_score, int paddle_two_score) {
  char score_one[3];
  char score_two[3];
  sprintf(score_one, "%d", paddle_one_score);
  sprintf(score_two, "%d", paddle_two_score);

  // Type text on screen
  // TTF_Font* font = TTF_OpenFont("fonts/bit5x3.ttf", 50);  // Font type ttf in folder on linux
  TTF_Font* font = TTF_OpenFont("fonts/bit5x3.ttf", 50);  // Font type ttf in folder on windows
  SDL_Color text_colour = {255, 255, 255};

  // as TTF_RenderText_Solid could only be used on
  // SDL_Surface then you have to create the surface first
  SDL_Surface* surface_message_score_one = TTF_RenderText_Solid(font, score_one, text_colour);
  SDL_Surface* surface_message_score_two = TTF_RenderText_Solid(font, score_two, text_colour);

  // now conver it into a texture
  SDL_Texture* message_one = SDL_CreateTextureFromSurface(renderer, surface_message_score_one);
  SDL_Texture* message_two = SDL_CreateTextureFromSurface(renderer, surface_message_score_two);

  SDL_Rect message_rect_one; // Create a rect for paddle_one_score
  message_rect_one.x = SCREEN_WIDTH / 2 + 50;  //controls the rect's x coordinate 
  message_rect_one.y = 30; // controls the rect's y coordinte
  message_rect_one.w = 50; // controls the width of the rect
  message_rect_one.h = 50; // controls the height of the rect
  
  SDL_Rect message_rect_two;
  message_rect_two.x = SCREEN_WIDTH / 2 - 70;
  message_rect_two.y = 30;
  message_rect_two.w = 50;
  message_rect_two.h = 50;

  // renderer, message, crop size (ignore), rect with coordinate
  SDL_RenderCopy(renderer, message_one, NULL, &message_rect_one);
  SDL_RenderCopy(renderer, message_two, NULL, &message_rect_two);
  SDL_FreeSurface(surface_message_score_one);
  SDL_FreeSurface(surface_message_score_two);
  SDL_DestroyTexture(message_one);
  SDL_DestroyTexture(message_two);
  TTF_CloseFont(font);
}

void RenderWindow::Win(int paddle_one_score, int paddle_two_score) {
  
  char gameover[4] = "WIN";

  // Type Text On Screen
  TTF_Font* font = TTF_OpenFont("fonts/bit5x3.ttf", 30);  // Font type ttf in folder
  SDL_Color text_colour = {255, 255, 255};

  // as TTF_RenderText_Solid could only be used on
  // SDL_Surface then you have to create the surface first
  SDL_Surface* surface_message_gameover = TTF_RenderText_Solid(font, gameover, text_colour);
  // now you can convert it into a texture
  SDL_Texture* message_one = SDL_CreateTextureFromSurface(renderer, surface_message_gameover);

  SDL_Rect message_rect_one; //create a rect
  if (paddle_two_score == MAX_SCORE) {
    message_rect_one.x = SCREEN_WIDTH / 5 - 75;  //controls the rect's x coordinate 
    message_rect_one.y = SCREEN_HEIGHT / 5 - 25; // controls the rect's y coordinte
    message_rect_one.w = 150; // controls the width of the rect
    message_rect_one.h = 50; // controls the height of the rect
  } else if (paddle_one_score == MAX_SCORE) {
    message_rect_one.x = 4 * SCREEN_WIDTH / 5 - 75;
    message_rect_one.y = SCREEN_HEIGHT / 5 - 25;
    message_rect_one.w = 150;
    message_rect_one.h = 50;
  }

  // renderer, message, crop size (ignore), rect with coordinate
  SDL_RenderCopy(renderer, message_one, NULL, &message_rect_one);

  SDL_FreeSurface(surface_message_gameover);

  SDL_DestroyTexture(message_one);

  TTF_CloseFont(font);
}

void RenderWindow::RenderRectangles(Rectangle& rec) {

  SDL_Rect box = {int(rec.GetX()), int(rec.GetY()), int(rec.GetCurrentFrame().w), int(rec.GetCurrentFrame().h)};
  SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
  SDL_RenderFillRect(renderer, &box);
}

void RenderWindow::SetBackgroundColour() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set renderer colour back to black
}

void RenderWindow::Display() {
  SDL_RenderPresent(renderer);
}
