#ifndef __RADIX___
#define __RADIX__

struct visitas{
	int tempo;
	char *nome;
};

void radix(visitas *planetas, int maiorLetra, int tamanhoLista, int tamanhoNome);

#endif
