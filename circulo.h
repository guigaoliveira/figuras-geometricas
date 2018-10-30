#ifndef CIRCULO_H
#define CIRCULO_H
#include "figurageometrica.h"
#include "screen.h"

/**
 * @brief The Circulo class
 */
class Circulo : public FiguraGeometrica
{
private:
  int radius, x, y, isFilled;
  char brush;
  void createCircumference(Screen &t, int x1, int y1);

public:
  Circulo(int _x = 0, int _y = 0, int _r = 0, char _brush = ' ', int _isFilled = 0);
  void draw(Screen &t);
};

#endif // CIRCULO_H
