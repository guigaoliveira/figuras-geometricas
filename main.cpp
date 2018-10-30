#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <sstream>

#include "screen.h"
#include "reta.h"
#include "retangulo.h"
#include "circulo.h"

using namespace std;

/**
 * @brief main
 * @return
 */
int main()
{

    vector<FiguraGeometrica *> figures;
    vector<FiguraGeometrica *>::iterator it;

    ifstream input;
    ofstream output;

    string basePath = "/home/gm/figuras-geometricas/";
    string inputPath = basePath + "input.txt";
    string outputPath = basePath + "output.txt";

    string command;
    int x, y, x0, y0, width, height, radius;
    char brush;
    bool fillmode;
    Screen screen;

    input.open(inputPath);

    if (input.is_open())
    {
        cout << inputPath << " is open \n";
    }
    else
    {
        cout << inputPath << " is not open \n";
    }

    while (input.good())
    {

        getline(input, command);
        stringstream ss(command);
        ss >> command;

        if (command == "dim")
        {
            ss >> width >> height;
            screen = Screen(width, height);
        }
        else if (command == "line")
        {
            ss >> x0 >> y0 >> x >> y >> brush;
            figures.push_back(new Reta(x0, y0, x, y, brush));
        }
        else if (command == "rectangle")
        {
            ss >> x >> y >> width >> height >> fillmode >> brush;
            figures.push_back(new Retangulo(x, y, width, height, brush, fillmode));
        }
        else if (command == "circle")
        {
            ss >> x0 >> y0 >> radius >> fillmode >> brush;
            figures.push_back(new Circulo(x0, y0, radius, brush, fillmode));
        }
    }

    for (it = figures.begin(); it != figures.end(); it++)
    {
        (*it)->draw(screen);
    }

    cout << screen;
    input.close();

    output.open(outputPath);

    output << screen;
    output.close();
    return 0;
}
