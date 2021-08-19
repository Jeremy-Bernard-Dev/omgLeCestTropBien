#include "../../../../include/serveur.h"

int readClient(int client, int playernbr)
{
    int n;
    char buff[128];
    int i = playernbr;
    char str[10];
    int gametrue = 1;
    sprintf(str, "%d", i) ;
    printf("%d", playernbr);

    if (client == -1) {
        return 1;
    }

    memset(buff, '\0', 128);
    n = recv(client, buff, 128, 0);
    if (n >= 0)
    {
        send(client,str, 10, 0);

        if (gametrue == 1) {
            game(1, client);
            gametrue = 0;
        }
        if (n == 0) {
            return -1;
        }

        if (buff[n - 1] == '\n') {
            memset(buff, '\0', 128);
        }
    }
    return 0;
}