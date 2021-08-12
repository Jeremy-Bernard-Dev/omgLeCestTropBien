#include "../../../../include/serveur.h"

int readClient(int client, int playernbr)
{
    int n;
    char buff[128];
    int i = playernbr;
    char str[10];
    sprintf(str, "%d", i) ;
    printf("%d", playernbr);

    if (client == -1)
    {
        return 1;
    }

    n = 0;
    memset(buff, '\0', 128);
    while ((n = recv(client, buff, 128, 0)) >= 0)
    {
        if (n == 0)
        {
            return -1;
        }

        send(client,str, 10, 0);

        if (buff[n - 1] == '\n')
        {
            memset(buff, '\0', 128);
            break;
        }
    }
    return 0;
}