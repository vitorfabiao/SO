
#include <stdio.h>
#include <stdlib.h>


void help(){
    printf("Commands");
    printf("\tTurn on/off the menssage filter--> filter on / filter off");
    printf("\tUsers list--> users");
    printf("\tTopics list--> topics");
    printf("\tMenssages list--> msg");
    printf("\tMenssage list by topic--> topic topic-in-question");
    printf("\tErase menssage--> del menssage-in-question");
    printf("\tKick user--> kick username-in-question");
    printf("\tShutdown the system--> shutdown");
    printf("\tErase topics without messages--> prune");
}


int main(int argc, char** argv) {

    char *value_str = getenv("MAXMSG");
    
    unsigned int value_uint = 0U;
    if(value_str == NULL){
        printf("Variável ambiente <%s> desconhecida!\n",argv[1])
        return 2;
    }
    if(value_str){
        printf("Valor da variavel ambiente: %s",argv[1]);
        continue;
    }
    help();
    while(1){
        char
    }
    
    
    return (EXIT_SUCCESS);
}

