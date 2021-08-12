#include "../include/my.h"

SDL_Renderer *screenRender = NULL;

void init()
{
    //init video
    SDL_Init(SDL_INIT_VIDEO);
    //créer la fenetre
    Createwindow();
    screenRender = getscreen();
    //créer le player
    initPlayerSprites(screenRender);
}

void draw(int playernbr)
{
    SDL_RenderClear(screenRender);
    //player
    drawPlayer(screenRender, playernbr);

    SDL_RenderPresent(screenRender);
}

void drawMenu()
{
    SDL_RenderClear(screenRender);
    
    ScreenMenu();

    SDL_RenderPresent(screenRender);
}

void endGame() {
    clear();
    SDL_Quit();
}

void clear()
{
    clearPlayer();
    clearScreen();
}