
#include <iostream>
#include "engine.h"

#define WIDTH 800
#define HEIGHT 600
#define TITLE "OpenGLEngine"

using namespace ogle;

int main(int argcp, char **argv)
{
    Engine game(WIDTH, HEIGHT, TITLE);

    game.start(&argcp, argv);

    std::cout << "All Done" << std::endl;


}
