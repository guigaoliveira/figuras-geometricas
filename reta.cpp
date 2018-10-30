#include "reta.h"
#include "screen.h"
#include <iostream>
#include <cmath>

using namespace std;

/**
 * @brief Reta::Reta
 * @param _x1
 * @param _y1
 * @param _x2
 * @param _y2
 * @param _brush
 */
Reta::Reta(int _x1, int _y1, int _x2, int _y2, char _brush)
{
    x1 = _x1;
    y1 = _y1;
    x2 = _x2;
    y2 = _y2;
    brush = _brush;
}

/**
 * @brief Reta::draw
 * @param t
 * @details Método para o desenho da, usa o algoritmo de bresenham para tentar criar a reta.
 * Baseado em: https://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm#C.2B.2B.
 */
void Reta::draw(Screen &t)
{
    t.setBrush(brush);

    const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));

    if(steep)
    {
      swap(x1, y1);
      swap(x2, y2);
    }

    if(x1 > x2)
    {
      swap(x1, x2);
      swap(y1, y2);
    }

    const float dx = x2 - x1;
    const float dy = fabs(y2 - y1);

    float error = dx / 2.0f;
    const int ystep = (y1 < y2) ? 1 : -1;
    int y = (int)y1;

    const int maxX = (int)x2;

    for(int x=(int)x1; x<maxX; x++)
    {

      (steep) ?  t.setPixel(y,x) : t.setPixel(x,y);
      error -= dy;
      if(error < 0)
      {
          y += ystep;
          error += dx;
      }
    }
}
