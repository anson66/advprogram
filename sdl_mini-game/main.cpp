/*
 * A simple stupid game that is a good start to build any games in a clean and simple way.

 * Rule: a game is over when there is no SpongeBob left.
 * How to play: Use arrow keys to add more SpongeBob.
 */
#include <iostream>
#include <SDL.h>
#include <cstdlib>
#include <ctime>
#include "SDL_Utils.h"
#include "Game.h"

using namespace std;

Action getUserAction();

int main(int argc, char *argv[])
{
    srand(time(0));
    Game game;
    game.init();

    game.render();
    do {
        Action action = getUserAction();
        if (action == QUIT) break;

        game.move(action);
        game.render();
        SDL_Delay(10);
    } while (!game.over());
    game.renderGameOver();

    waitUntilKeyPressed();

    game.destroy();
    return 0;
}

Action getUserAction() {
    SDL_Event e;
    if (SDL_PollEvent(&e) == 0) return NONE;
    if (e.type == SDL_QUIT) return QUIT;
    if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
            case SDLK_ESCAPE: return QUIT;
            case SDLK_LEFT: return LEFT;
            case SDLK_RIGHT: return RIGHT;
            case SDLK_DOWN: return DOWN;
            case SDLK_UP: return UP;
            default: return NONE;
        }
    }
    return NONE;
}
