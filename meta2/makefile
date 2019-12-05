all: gestor clientes verificador

gestor: gestor.o 
	gcc gestor.o -o gestor

clientes: clientes.o
	gcc clientes.o -o clientes

verificador: verificador.c
	gcc verificador.c -o verificador

gestor.o: gestor.c gestor.h estrutura.h
	gcc gestor.c -c

clientes.o: clientes.c clientes.h estrutura.h
	gcc clientes.c -c

clear:
	rm -f clientes.o gestor.o gestor clientes verificador


