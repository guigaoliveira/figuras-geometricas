#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "screen.h"

/**
 * @brief The FiguraGeometrica class
 */
class FiguraGeometrica
{
public:
  FiguraGeometrica();
  /**
     * @brief draw
     * @param s
     */
  virtual void draw(Screen &s) = 0;
};

#endif // FIGURAGEOMETRICA_H
