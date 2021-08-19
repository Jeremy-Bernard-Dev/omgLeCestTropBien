#include "../../../../include/client.h"
#include "../../../../include/my.h"
 
int client(int Port, char *Ip)
{
    SOCKET sock;
    SOCKADDR_IN sin;
    char buffer[32] = "OK \n";
    // char rbuff[32];
    bool gametrue = false;

    // CREATE SOCK
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // CONF
    sin.sin_addr.s_addr = inet_addr(Ip);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(Port);

    // while(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
    if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
    {
        send(sock, buffer, 32, 0);

        if (gametrue == false) {
            printf("ok2");
            intBallDir(2); 
            game(1, sock);
            gametrue = true;
        }
        // while (1) {
        // if(recv(sock, rbuff, 32, 0) != SOCKET_ERROR)
        // {
        //     puts(rbuff);
        //     puts("ok");
        //     // game(atoi(rbuff));
        // }
        // }
    }

    getchar();
 
    return EXIT_SUCCESS;
}