#include "../include/my.h"
#include "../include/var.h"

int main() {
    //déclaration var
    // int port = 4444;
    // char *clients = "127.0.0.1";
    // bool Menu = true;
    // SDL_Event event;
    //initilisation des ressources
    init();
 
    // while (Menu == true) {
    //     drawMenu();
    //     SDL_WaitEvent(&event);

    //     switch (event.type) {
    //     case SDL_KEYDOWN:

    //         switch(event.key.keysym.sym) {
    //             case SDLK_KP_1 :
    //             printf("ok");
    //             serveur(port);
    //             // client(port, clients);

    //             printf("ok3");
    //             game(1, 1);
    //             printf("ok4");
    //             Menu = false;
    //             break;

    //             case SDLK_KP_2 :
    //             printf("ok");
    //             client(port, clients);
    //             Menu = false;
    //             break;

    //             case SDLK_KP_3 :
    //             Menu = false;
    //             break;
    //         }
    //     break;
    //     }
    // }
    game(1);
    return 0;
}

int game(int idpPlayer) {
    bool quit = false;
    int timer = 0;

    while (!quit)
    {
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
                        break;

                        case SDLK_DOWN :
                        move(idpPlayer, BAS);
                        break;

                        case SDLK_LEFT :
                        move(2, HAUT);
                        break;

                        case SDLK_RIGHT :
                        move(2, BAS);
                        break;
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
        draw(2);
    }
    clear();
    SDL_Quit();

    return 0;
}