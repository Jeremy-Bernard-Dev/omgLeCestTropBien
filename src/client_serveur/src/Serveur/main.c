#include "../../../../include/serveur.h"
#include "../../../../include/my.h"

int serveur(int Port)
{
    int playernbr = 1;
    // ADRESSAGE SERVEUR
    SOCKADDR_IN sin;
    SOCKET sock;
    // socklen_t recsize = sizeof(sin);
    
    // ADRESSAGE CLIENT
    SOCKADDR_IN csin;
    SOCKET csock1;
    SOCKET csock2;
    // socklen_t crecsize = sizeof(csin);
    socklen_t client_addr_len;

    //
    fd_set readfs;

    // char Buffer[32] = "OK";
    // char buffer[32] = "";

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
            puts("Wait cl \n");

                csock1 = accept(sock, (SOCKADDR*)&csin, &client_addr_len);
                csock2 = accept(sock, (SOCKADDR*)&csin, &client_addr_len);

                if (csock1 < 0 || csock2 < 0)
                {
                    return  1;
                }
                puts("connect \n");
                playernbr++;

                while (1)
                {
                    FD_ZERO(&readfs);

                    FD_SET(csock1, &readfs);
                    FD_SET(csock2, &readfs);

                    select(csock2 + 1, &readfs, NULL, NULL, NULL);

                    if (FD_ISSET(csock1, &readfs))
                    {
                        if (readClient(csock1, playernbr) == -1)
                        {
                            puts("c1 dis \n");
                            close(csock1);
                            csock1 = -1;
                        }
                    } else if (FD_ISSET(csock2, &readfs))
                    {
                        if (readClient(csock2 ,playernbr) == -1)
                        {
                            puts("c2 dis \n");
                            close(csock2);
                            csock2 = -1;
                        }
                    }

                    if (csock1 == -1 && csock2 == -1)
                    {
                        break;
                    }
                    puts("search \n");
                }
        
        // CLOSE
        // closesocket(csock);
        // closesocket(sock);
    }
    
    getchar();
    
    return EXIT_SUCCESS;
}