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

// Dessiner le menu
void drawMenu()
{
    SDL_RenderClear(screenRender);
    
    ScreenMenu();

    SDL_RenderPresent(screenRender);
}

void drawEnd(int status)
{
    SDL_RenderClear(screenRender);
    
    ScreenEnd(status);

    SDL_RenderPresent(screenRender);
}

// Fonction de fin de jeu
void endGame() {
    clear();
    SDL_Quit();
}


// Fonction pour quitter le jeu
void clear()
{
    clearPlayer();
    clearScreen();
}