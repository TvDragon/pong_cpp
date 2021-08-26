#include "../include/draw_objects.hpp"

void DrawObjects(RenderWindow window, int num_rects, Rectangle* middle_lines,
                  Rectangle paddle_one, Rectangle paddle_two, Rectangle ball,
                  int& paddle_one_score, int& paddle_two_score) {
  
  window.Clear();

  for (int i = 0; i < num_rects; i++) {
    window.RenderRectangles(middle_lines[i]);
  }

  window.RenderRectangles(paddle_one);

  window.RenderRectangles(paddle_two);

  window.RenderRectangles(ball);

  window.DisplayScores(paddle_one_score, paddle_two_score);

  window.SetBackgroundColour();

  window.Display();

}