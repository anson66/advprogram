#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "SDL_utils.h"
#include <SDL.h>

using namespace std;

const int SIZE = 3;
vector<int> column[SIZE];
SDL_Window* window;
SDL_Renderer* renderer;

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 400;
const char WINDOW_TITLE[] = "Hanoi Tower";

#define STEP 5
#define CELL 20
#define GAP 10
#define STICK_WIDTH 6
const int COLUMN_WIDTH = SCREEN_WIDTH / 3;
const int COLUMN_OFFSET = SCREEN_WIDTH / 6;

const int TOP_Y = 100;
const int BASE_Y = SCREEN_HEIGHT - 100;
const int COLUMN_HEIGHT = BASE_Y - TOP_Y;

void drawDisk(int size, int x, int y)
{
    SDL_Rect filled_rect;
    filled_rect.x = x - size*CELL/2;
    filled_rect.y = y - CELL;
    filled_rect.w = size * CELL;
    filled_rect.h = CELL;
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // green
    SDL_RenderFillRect(renderer, &filled_rect);
}

int getColumnY(int level)
{
    return BASE_Y - level *(CELL + GAP);
}

void drawColumn(vector<int> column, int x)
{
    SDL_Rect filled_rect;
    filled_rect.x = x - STICK_WIDTH/2;
    filled_rect.y = TOP_Y;
    filled_rect.w = STICK_WIDTH;
    filled_rect.h = COLUMN_HEIGHT;
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    SDL_RenderFillRect(renderer, &filled_rect);

    for (int i = 0; i < column.size(); i++) {
        drawDisk(column[i], x, getColumnY(i));
    }
}

void draw_screen(int disk, int x, int y)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (int col = 0; col < 3; col ++) {
        drawColumn(column[col], COLUMN_OFFSET + COLUMN_WIDTH*col);
    }
    drawDisk(disk, x, y);

#ifndef LAB
    SDL_RenderPresent(renderer);
#else
    //SDL_UpdateWindowSurface(window);
#endif // LAB
    this_thread::sleep_for(chrono::milliseconds(100));
}

int getColumnX(int column)
{
    return COLUMN_OFFSET + COLUMN_WIDTH*column;
}

void move(int disk, int source, int dest)
{
    int x = getColumnX(source);
    int y = getColumnY(column[source].size());
    int end_x = getColumnX(dest);
    int end_y = getColumnY(column[dest].size());

    int ceiling_y = TOP_Y;
    //moveup
    while (y > ceiling_y) {
        draw_screen(disk, x, y);
        y-=STEP;
    }
    //move left
    while (x > end_x) {
        draw_screen(disk, x, y);
        x-=STEP;
    }
    //move right
    while (x < end_x) {
        draw_screen(disk, x, y);
        x+=STEP;
    }
    x = end_x;
    //move down
    while (y < end_y) {
        draw_screen(disk, x, y);
        y+=STEP;
    }
    draw_screen(disk, x, end_y);
}

void move(int source, int dest)
{
    int disk = column[source].back();
    column[source].pop_back();
    move(disk, source, dest);
    column[dest].push_back(disk);
}

void solve(int n, int source, int dest, int intermediate)
{
    if (n <= 1) move(source, dest);
    else {
        solve(n-1, source, intermediate, dest);
        solve(1, source, dest, intermediate);
        solve(n-1, intermediate, dest, source);
    }
}

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    for (int i = n; i > 0; i--) column[0].push_back(i);

    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    solve(n, 0, 1, 2);

    waitUntilKeyPressed();
    quitSDL(window, renderer);
    return 0;
}
