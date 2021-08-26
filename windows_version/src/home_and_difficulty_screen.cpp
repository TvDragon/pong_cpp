#include "../include/home_and_difficulty_screen.hpp"

#include <iostream>

using namespace std;

void HomeScreen(RenderWindow window, bool& stay, bool& quit, SDL_Event event,
                SDL_Rect& message_rect_one, SDL_Rect& message_rect_two,
                SDL_Rect& outline_rect_one, SDL_Rect& outline_rect_two,
                int& num_players) {

  bool within_box = false;

  while (stay) {
    
    window.Clear();
    window.PlayersOption(message_rect_one, message_rect_two,
                          outline_rect_one, outline_rect_two);
    window.SetBackgroundColour();
    window.Display();

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        stay = false;
        quit = true;
      } else if (event.type == SDL_KEYDOWN) {
        // Keyboard API for key pressed
        switch (event.key.keysym.scancode) {
        
        case SDL_SCANCODE_Q:
          stay = false;
          quit = true;
          break;
        default:
          break;
        }
      }
      
      if (event.type == SDL_MOUSEMOTION) {
        // cout << event.motion.x << "," <<  event.motion.y << endl;
        // cout << message_rect_one.x << endl;
        if ((event.motion.x >= message_rect_one.x &&
            event.motion.x <= message_rect_one.x + message_rect_one.w) &&
            (event.motion.y >= message_rect_one.y &&
            event.motion.y <= message_rect_one.y + message_rect_one.h)) {
              within_box = true;
              num_players = 1;
        } else if((event.motion.x >= message_rect_two.x &&
                  event.motion.x <= message_rect_two.x + message_rect_two.w) &&
                  (event.motion.y >= message_rect_two.y &&
                  event.motion.y <= message_rect_two.y + message_rect_two.h)) {
            within_box = true;
            num_players = 2;
        } else {
          within_box = false;
          num_players = 0;
        }
      }

      if (event.type == SDL_MOUSEBUTTONDOWN) {
        if (event.button.button == SDL_BUTTON_LEFT) {
          // cout << "working mouse" << endl;
          if (within_box) {
            stay = false;
          }
        }
      } 
    }
  }

  stay = true;
  // cout << "No. Players: " << num_players << endl;
}

void DifficultyScreen(RenderWindow window, bool& stay, SDL_Event event,
                SDL_Rect& message_rect_one, SDL_Rect& message_rect_two,
                SDL_Rect& message_rect_three, SDL_Rect& outline_rect_one,
                SDL_Rect& outline_rect_two, SDL_Rect& outline_rect_three,
                int& num_difficulty) {

  bool within_box = false;

  while (stay) {

    window.Clear();
    window.DifficultyPicker(message_rect_one, message_rect_two,
                            message_rect_three, outline_rect_one,
                            outline_rect_two, outline_rect_three);
    window.SetBackgroundColour();
    window.Display();

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        stay = false;
      } else if (event.type == SDL_KEYDOWN) {
        // Keyboard API for key pressed
        switch (event.key.keysym.scancode) {
        
        case SDL_SCANCODE_Q:
          stay = false;
          break;
        default:
          break;
        }
      }

      if (event.type == SDL_MOUSEMOTION) {
        if ((event.motion.x >= message_rect_one.x &&
            event.motion.x <= message_rect_one.x + message_rect_one.w) &&
            (event.motion.y >= message_rect_one.y &&
            event.motion.y <= message_rect_one.y + message_rect_one.h)) {
              within_box = true;
              num_difficulty = 1;
        } else if((event.motion.x >= message_rect_two.x &&
                  event.motion.x <= message_rect_two.x + message_rect_two.w) &&
                  (event.motion.y >= message_rect_two.y &&
                  event.motion.y <= message_rect_two.y + message_rect_two.h)) {
            within_box = true;
            num_difficulty = 2;
        } else if((event.motion.x >= message_rect_three.x &&
                  event.motion.x <= message_rect_three.x + message_rect_three.w) &&
                  (event.motion.y >= message_rect_three.y &&
                  event.motion.y <= message_rect_three.y + message_rect_three.h)) {
            within_box = true;
            num_difficulty = 3;
        } else {
          within_box = false;
          num_difficulty = 0;
        }
      }

      if (event.type == SDL_MOUSEBUTTONDOWN) {
        if (event.button.button == SDL_BUTTON_LEFT) {
          if (within_box) {
            stay = false;
          }
        }
      } 
    }
  }

  // cout <<  "Difficulty Level: " << num_difficulty << endl;
}