#include "../../../../include/client.h"
#include "../../../../include/my.h"
 
int client(int Port, char *Ip)
{
    SOCKET sock;
    SOCKADDR_IN sin;
    char buffer[32] = "Connect \n";
    bool gametrue = false;

    // CREATE SOCK
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // CONF
    sin.sin_addr.s_addr = inet_addr(Ip);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(Port);

    // SI CONNECTION AU SERVEUR
    if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
    {
        send(sock, buffer, 32, 0);

        if (gametrue == false) {
            intBallDir(2); 
            game(1, sock);
            gametrue = true;
        }
    }
 
    return EXIT_SUCCESS;
}