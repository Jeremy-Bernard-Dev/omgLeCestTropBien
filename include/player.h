#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <unistd.h>

SDL_Surface *player1;
SDL_Texture *player1texture;
SDL_Rect P1Pos;

SDL_Surface *player2;
SDL_Texture *player2texture;
SDL_Rect P2Pos;

SDL_Surface *balle;
SDL_Texture *balletexture;
SDL_Rect BallPos;

#endif