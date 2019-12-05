#ifndef ESTRUTURAG_H_
#define ESTRUTURAG_H_
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <fcntl.h>


#define MAXUSER 20

typedef struct Menssagem Menssage;
typedef struct Client Client;
typedef struct Topico Topic;
struct Menssage{
	char corpo[10][100],titulo[101]; // Guarda o corpo e titulo da mensagem
	int duracao; //guarda a duraçao da mensagem
	Client *creator;
	Topic *tooopic;
};

struct Client{
	int pid;//Guarda o numero do PID do cleinte
	char username[20];// Guarda o username do cliente
	Topic *vetor_ponteiros_topico[20];
}; 

struct Topic{
	char topico[40] ;//Nome do topico
};

typedef struct Pipe_cliente PPcliente;
struct PPcliente{
	char corpo[10][100];
	char titulo[100];
	int duracao; 
	char topic[30];
	char username[20];
	int pid;
};



struct thread1{
	Mensage *menssagens;
	Client *clientes;
	Topic *topicos;	
}


#endif