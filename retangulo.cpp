#include "retangulo.h"
#include "screen.h"
#include <iostream>
using namespace std;

/**
 * @brief Retangulo::Retangulo
 * @param _x
 * @param _y
 * @param _width
 * @param _height
 * @param _brush
 * @param _isFilled
 */
Retangulo::Retangulo(int _x, int _y, int _width, int _height, char _brush, int _isFilled)
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    brush = _brush;
    isFilled = _isFilled;
}

/**
 * @brief Retangulo::draw
 * @param t
 * @details Cria um retângulo, podendo ser preenchido ou não.
 */
void Retangulo::draw(Screen &t)
{
    t.setBrush(brush);

    if (isFilled > 0)
    {
        for (int i = x; i < (x + width); i++)
        {
            for (int j = y; j < (y + height); j++)
            {
                t.setPixel(i, j);
            }
        }
    }
    else
    {
        int width_aux = width - 1;
        int height_aux = height - 1;

        for (int i = x; i < x + width_aux; i++)
        {
            t.setPixel(i, y);
            t.setPixel(i + 1, y + height_aux);
        }

        for (int i = y; i < y + height_aux; i++)
        {
            t.setPixel(x, i + 1);
            t.setPixel(x + width_aux, i);
        }
    }
}
