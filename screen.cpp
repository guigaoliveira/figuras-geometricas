#include "screen.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Screen::Screen
 * @param nl
 * @param nc
 */
Screen::Screen(int nl, int nc)
{
    nlin = nl;
    ncol = nc;
    mat = vector<vector<char>>(nlin, vector<char>(ncol, ' '));
}

/**
 * @brief Screen::setPixel
 * @param x
 * @param y
 * @details Cria um novo pixel, usando a brush "setada".
 */
void Screen::setPixel(int x, int y)
{
    if ((x < nlin) & (y < ncol) && (x >= 0) & (y >= 0))
    {
        mat[x][y] = brush;
    }
}

/**
 * @brief Screen::clear
 * @details Método para limpar da tela uma figura.
 */
void Screen::clear()
{
    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t j = 0; j < mat[i].size(); j++)
        {
            mat[i][j] = ' ';
        }
    }
}

/**
 * @brief Screen::setBrush
 * @param _brush
 * @details Seta uma brush
 */
void Screen::setBrush(char _brush)
{
    brush = _brush;
}

/**
 * @brief operator <<
 * @param os
 * @param t
 * @return
 * @details Sobrecarga no operador << para exibição na tela.
 */
ostream &operator<<(ostream &os, Screen &t)
{
    for (int i = 0; i < t.nlin; i++)
    {
        for (int j = 0; j < t.ncol; j++)
        {
            os << t.mat[i][j];
        }
        os << endl;
    }
    return os;
}
