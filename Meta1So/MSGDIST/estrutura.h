#ifndef ESTRUTURA_H_
#define ESTRUTURA_H_
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Mensagem mensagem, *pmensagem;
typedef struct Pid pid,*ppid;
typedef struct Topico topico, *ptopico;
struct Mensagem{
	ptopico topico; // Ponteiro da estrututa topico que guarda o topico da mensagem 
	char corpo[1000],titulo[101]; // Guarda o corpo e titulo da mensagem
	int duracao; //guarda a duraçao da mensagem
	pmensagem next_msg; //Ponteiro para a proxima mensagem
};

struct Pid{
	int pid;//Guarda o numero do PID do cleinte
	char *username;// Guarda o username do cliente
	ppid next_pid; //Ponteiro para o proximo cliente
}; 

struct Topico{
	char topico[40];//Nome do topico
	ptopico next_topic; //Ponteiro para o proximo topico
};




#endif