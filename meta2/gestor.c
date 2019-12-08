
#include "gestor.h"

int main(int argc, char **argv)
{
    Menssage menssages[20];

    system("clear");
    /*_________________________________________________________________

			Verifica se as variaveis existem e qual o valor
___________________________________________________________________*/

    int value_maxnot = atoi(getenv("MAXNOT")); //Vai à procura da variável de ambiente com o nome MAXNOT, o atoi converte a string para numero e esse numero é guardado na variavel

    printf("Value of the environment variable <MAXNOT>: %d\n", value_maxnot);

    char *value_wordsnot = getenv("WORDSNOT");
    if (value_wordsnot == NULL)
    { //Vai à procura da variável de ambiente com o nome WORDSNOT, verifica se tem alguma string com o nome do ficheiro texto e se tiver guarda para dentro do array
        printf("Environment variable <WORDSNOT> does not exist! So it will start with a default file\n");
    }
    if (value_wordsnot)
    {
        printf("Value of the environment variable <WORDSNOT>: %s\n", value_wordsnot);
    }

    int value_maxmsg = atoi(getenv("MAXMSG")); //Vai à procura da variável de ambiente com o nome MAXMSG, o atoi converte a string para numero e esse numero é guardado na variavel
    printf("Value of the environment variable <MAXMSG>: %d\n", value_maxmsg);
    /*_________________________________________________________________

			Cria ligação entre o gestor e o verificador
___________________________________________________________________*/

    int pstdin[2], pstdout[2]; //cria dois vetores de inteiros
    pipe(pstdin);              //cria o pipe responsavel por levar a info do pai para o filho
    pipe(pstdout);             //cria o pipe responsavel por levar a info do filho para o pai
    int pid = fork();          //criação do filho e coloca o pid a 0
    if (pid == 0)
    { //cria um novo processo duplicando o processo atual que o chama
        //input
        close(0);         //Fecha stdin
        dup(pstdin[0]);   //duplica o stdin do pipe que vai do pai para o filho e assume a posiçao que foi fechada anteriormente
        close(pstdin[0]); //depois da duplicaçao fechasse a posiçao original deixando uma "slot" livre
        close(pstdin[1]); // fechar igualmente o stdout do pipe que vai do pai  para o filho porque nao é necessario o stdout

        //output do filho
        close(1);          //Fecha o output
        dup(pstdout[1]);   //duplica o stdout do pipe que vai do filho para o pai e vai assumir a posiçao que foi fechada anteriormente
        close(pstdout[1]); // depois da duplicaçao fechasse a posiçao original deixando esta slot tambem livre
        close(pstdout[0]); // fechar igualmente o stdout do pipe que vai do filho para o pai porque nao vai ser necessario o stdin
        // IR BUSCAR A VARIAVEL DE AMBIENTE NOME DO FICHEIRO

        execl("verificador", "verificador", value_wordsnot, NULL); //substitui o processo atual (filho (copia do gestor)) pelo verificador
        printf("ERROR in execl");                                  //caso nao seja possivel a substituição entao o administrador é avisado
    }
    //pai
    //ao inicio ele vai fechar aquilo que nao necessita para nao usar recursos ao sistema
    close(pstdin[0]);                                         //fecha o stdin do pipe pai para filho
    close(pstdout[1]);                                        // fecha o stdout do pipe filho para pai
    char mensagem[] = "gosto de cona cadeira ##MSGEND## \n";  //declara a mensagem a enviar
    char result[8];                                           // cria um vetor para o resultado que vier
    write(pstdin[1], mensagem, sizeof(mensagem));             //envia a mensagem para o filho
    close(pstdin[1]);                                         //fecha a porta que utilizou ou seja o stdout do pipe do pai para filho
    int n = read(pstdout[0], result, sizeof(result));         //aguarda resposta e quando a recebe envia para uma variavel do tipo inteiro
    close(pstdout[0]);                                        //fecha a porta que utilizou ou seja o stdin do pipe do filho para pai
    result[n - 1] = '\0';                                     //adiciona um /0 ao final da string
    printf("O numero de palavras proibidas e: %s\n", result); // apresenta o resultado recebido

    ////////////////////////////////////////////////////////////////////
    /* int fd1;
  //  char *myfifo = "fifogestor";
   // PPcliente client;

    mkfifo(myfifo, 0666);
  //  fd1 = open("fifogestor", O_RDONLY);
  //  read(fd1, &client, sizeof(PPcliente) + 1);
   // printf("User1: %s\n", client.username);
    close(fd1); 

  //  fd1 = open("fifocliente", O_WRONLY);
   // write(fd1, &client, sizeof(PPcliente) + 1);
    close(fd1);*/

    ///////////////////////////////////////////////////////////////////

    /*_________________________________________________________________

		//	Quando o programa estiver pronto apresenta o MENU
___________________________________________________________________*/

    help(); //Chama a funçao que contem o painel de ajuda para o administrador
    char *command;
    size_t command_size = 20;
    command = (char *)malloc(command_size * sizeof(char));
    size_t characters;
    int arguments = 2;
    char *token[arguments];
    if (command == NULL)
    {
        perror("Unable to allocate command");
        exit(1);
    }
    while (1)
    {
        printf("---->"); //Espera o utilizador colocar o comando pretendido
        getline(&command, &command_size, stdin);
        arguments = 0;
        token[arguments] = strtok(command, " ");
        while ((token[++arguments] = strtok(NULL, " ")) != NULL)
            ;

        if (strcmp("filter", token[0]) == 0)
        { //compara o comando com a palavra que o utilizador colocou
            if (strcmp("on\n", token[1]) == 0)
                printf("Filter is on\n");
            else if (strcmp("off\n", token[1]) == 0)
                printf("Filter is off\n");
            else
                printf("Command filter invalid\n");
            //Se for igual ao comando entao o comando é aceite
        }
        else if (strcmp(token[0], "users\n") == 0)
        {
            mostra_users(menssages);
        }
        else if (strcmp(token[0], "topics\n") == 0)
        {
            mostra_topics(menssages);
        }
        else if (strcmp(token[0], "msg\n") == 0)
        {
            printf("Accepted command\n");
        }
        else if (strcmp(token[0], "topic") == 0)
        {
            printf("This is the topic you choose <%s>\n", token[1]);
        }
        else if (strcmp(token[0], "del") == 0)
        {
            printf("This is the message you choose to delete <%s>\n", token[1]);
        }
        else if (strcmp(token[0], "kick") == 0)
        {
            printf("This is the user you choose to kick <%s>\n", token[1]);
        }
        else if (strcmp(token[0], "shutdown\n") == 0)
        {
            shutdown(); // se o comando for shutdown entao chama a funcao shutdown
        }
        else if (strcmp(token[0], "prune\n") == 0)
        {
            printf("Accepted command");
        }
        else
            printf("Command <%s> not recognized\n", token[0]); //Se o comando for diferente entao volta a pedir um comando ao administrador
    }

    return (EXIT_SUCCESS);
}

void help()
{
    printf("Commands:\n");
    printf("\tTurn on/off the menssage filter-->%8s \n", "filter on / filter off");
    printf("\tUsers list-->%8s \n", "users");
    printf("\tTopics list-->%8s\n", "topic");
    printf("\tMenssages list-->%8s\n", "msg");
    printf("\tMenssage list by topic-->%8s\n", " topic topic-in-question");
    printf("\tErase menssage-->%8s\n", " del menssage-in-question");
    printf("\tKick user-->%8s\n", " kick username-in-question");
    printf("\tShutdown the system-->%8s\n", "shutdown");
    printf("\tErase topics without messages-->%8s\n\n", "prune");
}

void shutdown()
{
    exit(0); // faz com que o programa termine naquele momento
}

void mostra_users(Menssage *menssages)
{
    int i = 0;
    char *maria = "maria";

    for (i = 0; i < 20; i++)
    {
        strcpy(menssages[i].creator->username, maria);
        menssages[i].creator->pid = i + 1;
    }
    i = 0;
     while (i != 20)
    {
        printf("User %d: %s PID: %d\n", i + 1, menssages[i].creator->username, menssages[i].creator->pid);
        i++;
    }
}

void mostra_topics (Menssage *menssages){


}