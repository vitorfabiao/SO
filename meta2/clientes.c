#include "clientes.h"


int main(int argc,char **argv){
	int c;
	opterr = 0; //desativa as mensagens de erro da função getopt

while((c = getopt(argc,argv,"u:"))!=-1){
	switch(c){
		case 'u':
		printf("Welcome, you're on \n");
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

int fd; 
  
    // FIFO file path 
    char * myfifo = "fifocliente"; 
  
    // Creating the named file(FIFO) 
    // mkfifo(<pathname>, <permission>) 
    mkfifo(myfifo, 0666); 
  
    char arr1[80], arr2[80]; 
    while (1) 
    { 
        // Open FIFO for write only 
        fd = open("fifogestor", O_WRONLY); 
  
        // Take an input arr2ing from user. 
        // 80 is maximum length 
        fgets(arr2, 80, stdin); 
  
        // Write the input arr2ing on FIFO 
        // and close it 
        write(fd, arr2, strlen(arr2)+1); 
        close(fd); 
  
        // Open FIFO for Read only 
        fd = open("fifocliente", O_RDONLY); 
  
        // Read from FIFO 
        read(fd, arr1, sizeof(arr1)); 
  
        // Print the read message 
        printf("User2: %s\n", arr1); 
        close(fd); 
    } 

return 0;
}