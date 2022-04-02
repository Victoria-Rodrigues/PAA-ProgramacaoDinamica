all:
	gcc main.c -o run sources/geradorArquivo.c sources/caverna.c sources/modoAnalise.c
	./run