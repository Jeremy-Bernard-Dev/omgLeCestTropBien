#include "../include/my.h"

SDL_Window *window = NULL;
SDL_Renderer *screen = NULL;
SDL_Surface *tileset = NULL;
SDL_Texture *texture = NULL;
SDL_Surface *menu = NULL;
SDL_Texture *menutexture = NULL;
SDL_Surface *win = NULL;
SDL_Texture *wintexture = NULL;
SDL_Surface *lose = NULL;
SDL_Texture *losetexture = NULL;
SDL_Color color = {105, 105, 105, 128};

void Createwindow()
{
	window = SDL_CreateWindow("Pong !", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, LARGEUR_TILE*NOMBRE_BLOCS_LARGEUR, HAUTEUR_TILE*NOMBRE_BLOCS_HAUTEUR, SDL_WINDOW_SHOWN);
    screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	tileset = IMG_Load("img/Textures_v02.bmp");
    texture = SDL_CreateTextureFromSurface(screen, tileset);
	
	setWindowColor();
}

void ScreenMenu()
{
	menu = IMG_Load("img/Menu.png");
    menutexture = SDL_CreateTextureFromSurface(screen, menu);

	SDL_RenderCopy(screen, menutexture, NULL, NULL);
}

void ScreenEnd(int status)
{
    if (status == 1) {
        win = IMG_Load("img/win.jpg");
        wintexture = SDL_CreateTextureFromSurface(screen, win);

        SDL_RenderCopy(screen, wintexture, NULL, NULL);
    } else if (status == 2) {
        lose = IMG_Load("img/lose.jpg");
        losetexture = SDL_CreateTextureFromSurface(screen, lose);

        SDL_RenderCopy(screen, losetexture, NULL, NULL);
    }
}

SDL_Renderer *getscreen()
{
	return screen;
}

int setWindowColor()
{
    if (SDL_SetRenderDrawColor(screen, color.r, color.g, color.b, color.a) < 0)
        return -1;
    if (SDL_RenderClear(screen) < 0)
        return -1;
    return 0;
}

void clearScreen()
{
	SDL_DestroyTexture(texture);
    SDL_FreeSurface(tileset);
    SDL_DestroyRenderer(screen);
    SDL_DestroyWindow(window);
}
