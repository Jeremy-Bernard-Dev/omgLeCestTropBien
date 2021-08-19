#include "../include/my.h"
#include "../include/var.h"
#include "../include/serveur.h"
#include <sys/socket.h>

int main() {
    // Déclaration des Variables
    int port = 4444;
    char *clients = "127.0.0.1";
    bool Menu = true;
    SDL_Event event;
    // Initilisation des ressources
    init();
 
    while (Menu == true) {
        drawMenu();
        SDL_WaitEvent(&event);

        switch (event.type) {
        case SDL_KEYDOWN:

            switch(event.key.keysym.sym) {
                case SDLK_KP_1 :
                printf("Trying to host\n");
                serveur(port);
                printf("Host ok");
                // Client(port, clients);

                // Game(1,1);
                Menu = false;
                // Game(1);
                break;

                case SDLK_KP_2 :
                printf("Trying to join the game\n");
                client(port, clients);
                Menu = false;
                // Game(1);
                break;

                case SDLK_KP_3 :
                Menu = false;
                break;
            }
        break;
        }
    }
    
    return 0;
}
// Fonction de jeu principale
int game(int idpPlayer, SOCKET socket) {
    bool quit = false;
    bool first = true;
    int timer = 0;
    // char buffer[32] = "OK \n";
    char rbuff[32];

    while (!quit)
    {
        if (first == true)
        {
            send(socket, "N", 32, 0);
            // first = false;
        }
        while (SDL_PollEvent(&event)) {
            switch (event.type)
            {
                case SDL_QUIT:
                    quit = true;
                break;

                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym) {
                        
                        case SDLK_UP :
                        move(idpPlayer, HAUT);
                        send(socket, "H", 32, 0);
                        break;

                        case SDLK_DOWN :
                        move(idpPlayer, BAS);
                        send(socket, "B", 32, 0);
                        break;

                        // case SDLK_LEFT :
                        // move(2, HAUT);
                        // break;

                        // case SDLK_RIGHT :
                        // move(2, BAS);
                        // break;
                    }
                break;
            }
        }
        if (timer < 100) {
            timer ++;
        } else {
            timer = 0;
            moveBalle();
        }
        if(recv(socket, rbuff, 32, 0) != SOCKET_ERROR)
        {
            // puts(rbuff);
            if (strcmp(rbuff , "H") == 0) {
                move(2, HAUT);
            } else if (strcmp(rbuff , "B") == 0) {
                move(2, BAS);
            }
        }
        draw(2);
        int point1 = getPoint(1);
        int point2 = getPoint(2);
        if (point1 == 3 || point2 == 3) {
            endGame();
        }
    }
    endGame();

    return 0;
}