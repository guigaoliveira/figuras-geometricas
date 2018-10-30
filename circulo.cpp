#include "circulo.h"
#include "screen.h"
#include <iostream>
#include <cmath>

using namespace std;

/**
 * @brief Circulo::Circulo
 * @param _x
 * @param _y
 * @param _r
 * @param _brush
 * @param _isFilled
 */
Circulo::Circulo(int _x, int _y, int _r, char _brush, int _isFilled)
{
    radius = _r;
    x = _x;
    y = _y;
    brush = _brush;
    isFilled = _isFilled;
}

/**
 * @brief Circulo::draw
 * @param t
 * @details Método para o desenho do círculo, usa o algoritmo de bresenham para tentar criar o círculo.
 * Baseado em: https://www.geeksforgeeks.org/bresenhams-circle-drawing-algorithm/.
 */
void Circulo::draw(Screen &t)
{
    t.setBrush(brush);

    if (isFilled > 0)
    {
        for (int i = (x - radius); i <= (x + radius); i++)
        {
            for (int j = (y - radius); j <= (y + radius); j++)
            {
                if ((i - x) * (i - x) + (j - y) * (j - y) <= (radius * radius))
                {
                    t.setPixel(i, j);
                }
            }
        }
    }
    else
    {
           int x1 = 0, y1 = radius;
           int d = 3 - 2 * radius;
           while (y1 >= x1)
           {
               createCircumference(t, x1, y1);
               x1++;
               if (d > 0)
               {
                   y1--;
                   d = d + 4 * (x1 - y1) + 10;
               }
               else {
                   d = d + 4 * x1 + 6;
               }
               createCircumference(t, x1, y1);

           }
    }
}

/**
 * @brief Circulo::createCircumference
 * @param t
 * @param x1
 * @param y1
 * @details Cria os pontos de uma circunferência.
 */
void Circulo::createCircumference(Screen &t, int x1, int y1)
{
    t.setPixel(x + x1, y + y1);
    t.setPixel(x + y1, y + x1);
    t.setPixel(x - y1, y + x1);
    t.setPixel(x - x1, y + y1);
    t.setPixel(x - x1, y - y1);
    t.setPixel(x - y1, y - x1);
    t.setPixel(x + y1, y - x1);
    t.setPixel(x + x1, y - y1);
}
