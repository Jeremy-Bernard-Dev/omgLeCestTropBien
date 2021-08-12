#ifndef MY_H
#define MY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#define LARGEUR_TILE 24  // hauteur et largeur des tiles.
#define HAUTEUR_TILE 24 

#define NOMBRE_BLOCS_LARGEUR 15  // nombre a afficher en x et y
#define NOMBRE_BLOCS_HAUTEUR 13

enum{HAUT,BAS,GAUCHE,DROITE};

void init();
void draw(int playernbr);
void drawMenu();
int game(int idpPlayer);
void clear();
void Createwindow();
SDL_Renderer *getscreen();
void move(int player, int direction);
void moveBalle();
void ScreenMenu();
int setWindowColor();
void initPlayerSprites(SDL_Renderer *screen);
void drawPlayer(SDL_Renderer *screen, int playernbr);
// SDL_Rect getPos(int player);
void clearPlayer();
void clearScreen();
int client(int Port, char *Ip);
int serveur(int Port);
void endGame();
int getPoint(int player);

#endif