#ifndef MY_H
#define MY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SOCKET_ERROR -1

#define LARGEUR_TILE 24  // hauteur et largeur des tiles.
#define HAUTEUR_TILE 24 

#define NOMBRE_BLOCS_LARGEUR 15  // nombre a afficher en x et y
#define NOMBRE_BLOCS_HAUTEUR 13

enum{HAUT,BAS,GAUCHE,DROITE};
typedef int SOCKET;

void init();
void draw(int playernbr);
void intBallDir(int player);
void drawMenu();
void drawEnd(int status);
void ScreenEnd(int status);
int game(int idpPlayer, SOCKET socket);
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