#ifndef RETANGULO_H
#define RETANGULO_H
#include "figurageometrica.h"
#include "screen.h"

/**
 * @brief The Retangulo class
 */
class Retangulo : public FiguraGeometrica
{
private:
  int x, y, width, height, isFilled;
  char brush;

public:
  Retangulo(int _x = 0, int _y = 0, int _width = 0, int _height = 0, char _brush = ' ', int _isFilled = 0);
  void draw(Screen &t);
};

#endif // RETANGULO_H
