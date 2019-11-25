#include<stdio.h>
#include<stdlib.h>
#include "clientes.h"


int main(int argc,char **argv){
	int c;
	opterr = 0; //desativa as mensagens de erro da função getopt
	pid *cliente;

while((c = getopt(argc,argv,"u:"))!=-1){
	switch(c){
		case 'u':
		cliente->username = optarg;
		printf("Welcome, you're on %s\n", cliente->username);
		break;
		case'?':
		if (optopt == 'u')	// Esqueceu um argumento
			fprintf (stderr, "Opção '-%c' requer um username.\n", optopt);
		else if (isprint (optopt))
			fprintf(stderr, "Opção '-%c' desconhecida.\n", optopt);
		else
			fprintf(stderr, "Caractere '\\x%x' de opção desconhecido.\n", optopt );
		exit (1);
		default:
		printf("User not available");
		abort();
	}
}
return 0;
}