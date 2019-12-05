#ifndef ESTRUTURAC_H_
#define ESTRUTURAC_H_
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


typedef struct Menssagem Menssage;
struct Menssage{
	char corpo[10][100];
	char titulo[100];
	int duracao; 
	char topic[30];
	char username[20];
	int pid;
};


#endif