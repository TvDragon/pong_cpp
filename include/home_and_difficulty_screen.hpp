#ifndef HOME_SCREEN
#define HOME_SCREEN

#include "render_window.hpp"
#include "rectangle.hpp"

void HomeScreen(RenderWindow window, bool& stay, bool& quit, SDL_Event event,
                SDL_Rect& message_rect_one, SDL_Rect& message_rect_two,
                SDL_Rect& outline_rect_one, SDL_Rect& outline_rect_two,
                int& num_players);

void DifficultyScreen(RenderWindow window, bool& stay, SDL_Event event,
                SDL_Rect& message_rect_one, SDL_Rect& message_rect_two,
                SDL_Rect& message_rect_three, SDL_Rect& outline_rect_one,
                SDL_Rect& outline_rect_two, SDL_Rect& outline_rect_three,
                int& num_difficulty);

#endif