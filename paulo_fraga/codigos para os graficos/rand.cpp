#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char *argv[]){
	if(argc <= 1){
		printf("necessário parametro\n");
		return 0;
	}
	int tempoTotal = rand()&10000;;// T>0
	int numeroPlanetas = atoi(argv[1]);// 0 < P <= 1500000
	int tamanhoNome = rand()%int((log2 (tempoTotal)));
	srand(time(NULL));
	printf("%d %d %d\n",tempoTotal,numeroPlanetas,tamanhoNome);
	for(int i=0;i<numeroPlanetas;i++){
		int tempoPlaneta = 1+ rand()%tempoTotal;
		printf("%d ", tempoPlaneta);
		for(int x=0; x<tamanhoNome;x++){
			char letra = 97 + rand()%26;
			printf("%c", letra);
		}
		printf(" \n");
	}
	printf("\n");
	return 0;

}
