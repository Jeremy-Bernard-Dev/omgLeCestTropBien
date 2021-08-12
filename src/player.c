#include "../include/player.h"

enum{HAUT,BAS,GAUCHE,DROITE};
int directionH = DROITE;
int directionV = BAS;

void initPlayerSprites(SDL_Renderer *screen)
{
    player1 = IMG_Load("img/Player1.png");
    player1texture = SDL_CreateTextureFromSurface(screen, player1);
    P1Pos.x = 40;
    P1Pos.y = 100;
    P1Pos.w = 10;
    P1Pos.h = 100;

    player2 = IMG_Load("img/Player2.png");
    player2texture = SDL_CreateTextureFromSurface(screen, player2);
    P2Pos.x = 300;
    P2Pos.y = 100;
    P2Pos.w = 10;
    P2Pos.h = 100;

    balle = IMG_Load("img/Balle.png");
    balletexture = SDL_CreateTextureFromSurface(screen, balle);
    BallPos.x = 150;
    BallPos.y = 150;
    BallPos.w = 20;
    BallPos.h = 20;
}

void drawPlayer(SDL_Renderer *screen, int playernbr)
{
    switch (playernbr)
    {
        case 1:
        SDL_RenderCopy(screen, player1texture, NULL, &P1Pos);
        break;

        case 2:
        SDL_RenderCopy(screen, player1texture, NULL, &P1Pos);
        SDL_RenderCopy(screen, player2texture, NULL, &P2Pos);
        break;
    }

    SDL_RenderCopy(screen, balletexture, NULL, &BallPos);

}

void move(int player, int direction) {
    SDL_Rect *position = NULL;
    if (player == 1) 
    {
        position = &P1Pos;
    } else if (player == 2) {
        position = &P2Pos;
    }
    switch (direction)
    {
        case HAUT:
        if (position->y > 0) {
            position->y-=7;
        }
        break;

        case BAS:
        if (position->y < 210) {
            position->y+=7;
        }
        break;
    }
}

void resetBall() {
    SDL_Rect *position = &BallPos;
    position->x = 200;
    position->y = 150;
    if (directionH == DROITE) {
        directionH = GAUCHE;
    } else {
        directionH = DROITE;
    }
}

void moveBalle() {
    SDL_Rect *position = &BallPos;
    SDL_Rect *p1pos = &P1Pos;
    SDL_Rect *p2pos = &P2Pos;
    switch (directionH)
    {
        case DROITE:
        if (position->x < 345) {
            position->x +=3;
        } else {
            resetBall();
        }
        if (position->x >= p2pos->x - 10) {
            if (position->y >= p2pos->y - 20 && position->y <= p2pos->y + 99) {
                directionH = GAUCHE;
            }
        }
        break;

        case GAUCHE:
            if (position->x > 0) {
                position->x -=3;
            } else {
                resetBall();
            }
            if (position->x <= p1pos->x + 10) {
                if (position->y >= p1pos->y - 20 && position->y <= p1pos->y + 99) {
                    directionH = DROITE;
                }
            }
        break;
    }

    switch (directionV)
    {
        case HAUT:
            if (position->y > 0) {
                position->y -=2;
            } else {
                directionV = BAS;
            }
        break;

        case BAS:
            if (position->y < 290) {
                position->y +=2;
            } else {
                directionV = HAUT;
            }
        break;
    }
}

void clearPlayer()
{
    SDL_DestroyTexture(player1texture);
    SDL_FreeSurface(player1);
    SDL_DestroyTexture(player2texture);
    SDL_FreeSurface(player2);
    SDL_DestroyTexture(balletexture);
    SDL_FreeSurface(balle);
}