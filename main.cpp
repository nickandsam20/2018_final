#include <iostream>
#include "game_window.h"
using namespace std;

int main()
{
    GameWindow *game=new GameWindow();
    game->game_play();
    delete game;
    return 0;
}
