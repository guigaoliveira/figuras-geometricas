#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief The Screen class
 */
class Screen
{
private:
  int nlin, ncol;
  char brush = ' ';
  vector<vector<char>> mat;

public:
  Screen(int nl = 0, int nc = 0);
  void setPixel(int x, int y);
  void clear();
  void setBrush(char _brush);
  friend ostream &operator<<(ostream &os, Screen &t);
};

#endif // SCREEN_H
