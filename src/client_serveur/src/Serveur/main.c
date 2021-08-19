#include "../../../../include/serveur.h"
#include "../../../../include/my.h"

int serveur(int Port)
{
    int playernbr = 1;
    // ADRESSAGE SERVEUR
    SOCKADDR_IN sin;
    SOCKET sock;
    
    // ADRESSAGE CLIENT
    SOCKADDR_IN csin;
    SOCKET csock1;

    // SOCKET csock2;
    socklen_t client_addr_len;

    //
    fd_set readfs;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock != INVALID_SOCKET)
    {
        //CONF-
        sin.sin_addr.s_addr = INADDR_ANY;
        sin.sin_family = AF_INET;
        sin.sin_port = htons(Port);

        if (bind(sock, (SOCKADDR *)&sin, sizeof(sin)) < 0)
        {
            return -1;
        }

            listen(sock, 5);
            puts("Attente client \n");

                csock1 = accept(sock, (SOCKADDR*)&csin, &client_addr_len);

                if (csock1 < 0)
                {
                    return  1;
                }
                puts("Connecté \n");
                playernbr++;

                while (1)
                {
                    FD_ZERO(&readfs);

                    FD_SET(csock1, &readfs);

                    if (FD_ISSET(csock1, &readfs))
                    {
                        puts("C1 connecté \n");
                        if (readClient(csock1, playernbr) == -1)
                        {
                            puts("c1 déconnecté \n");
                            close(csock1);
                            csock1 = -1;
                        }
                    }

                    if (csock1 == -1)
                    {
                        break;
                    }
                    puts("Recherche du client \n");
                }
        
        // CLOSE
        closesocket(csock1);
        closesocket(sock);
    }
        
    return EXIT_SUCCESS;
}