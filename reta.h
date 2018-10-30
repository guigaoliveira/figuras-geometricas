#ifndef RETA_H
#define RETA_H
#include "figurageometrica.h"
#include "screen.h"

/**
 * @brief The Reta class
 */
class Reta : public FiguraGeometrica
{
private:
  int x1, y1, x2, y2;
  char brush;

public:
  Reta(int _x1 = 0, int _y1 = 0, int _x2 = 0, int _y2 = 0, char _brush = ' ');
  void draw(Screen &t);
};

#endif // RETA_H
