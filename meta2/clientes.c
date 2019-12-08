#include "clientes.h"

int main(int argc, char **argv)
{
    int c;
    Menssage send_client;
    Menssage rcv_client;
    char user[20];
    opterr = 0; //desativa as mensagens de erro da função getopt
    int fd;
    char *myfifo = "fifocliente";
    mkfifo(myfifo, 0666);
    while ((c = getopt(argc, argv, "u:")) != -1)
    {
        switch (c)
        {
        case 'u':
            strcpy(user,optarg);
            fd = open("fifogestor", O_WRONLY);
            strcpy(send_client.username,optarg);
            write(fd, &send_client, sizeof(Menssage) + 1);
            close(fd);

            fd = open("fifocliente", O_RDONLY);
            read(fd, &rcv_client, sizeof(Menssage) + 1);
            close(fd);
            printf("Welcome, you're on, %s \n",rcv_client.username);
            break;
        case '?':
            if (optopt == 'u') // Esqueceu um argumento
                fprintf(stderr, "Opção '-%c' requer um username.\n", optopt);
            else if (isprint(optopt))
                fprintf(stderr, "Opção '-%c' desconhecida.\n", optopt);
            else
                fprintf(stderr, "Caractere '\\x%x' de opção desconhecido.\n", optopt);
            exit(1);
        default:
            printf("User not available");
            abort();
        }
    }

    return 0;
}