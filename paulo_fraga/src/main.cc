#include <cstdio> // em C substituir por #include <stdio.h>
#include "foo.h"

int main(){
	int tempoTotal,numeroVisitas,tamanhoNome;

	scanf("%d %d %d ",&tempoTotal,&numeroVisitas,&tamanhoNome);

	visitas planetas[numeroVisitas];

	char letra;
	int tempoVisita;
	char maiorLetra = 'a';
	for(int i=0;i<numeroVisitas;i++){

		char *nomePlaneta = new char[tamanhoNome];

		scanf("%d ",&tempoVisita);
		planetas[i].tempo = tempoVisita;

		for(int j=0;j<tamanhoNome;j++){
			scanf("%c",&letra);
			nomePlaneta[j] = letra;

			if(letra > maiorLetra){
				maiorLetra = letra;
			}

		}
		nomePlaneta[tamanhoNome] = '\0';

		planetas[i].nome = nomePlaneta;
	}
	printf("VETOR INICIAL\n");
	for(int k=0;k<numeroVisitas;k++){
		printf("%s - ",planetas[k].nome);
		printf("%i\n",planetas[k].tempo);
	}

	/*
	printf("MERGESORT\n");
	myMergeSort(planetas,0,numeroVisitas-1);
	*/
	/*
	printf("RADIX\n");
	radix(planetas,maiorLetra,numeroVisitas,tamanhoNome);
	*/

	for(int k=0;k<numeroVisitas;k++){
		printf("%s - ",planetas[k].nome);
		printf("%i\n",planetas[k].tempo);
	}

	for(int k=0;k<numeroVisitas;k++){
		delete planetas[k].nome;
	}
	return 0;
}

/*
int main() {
  int t;
  int p;
  int c;
  while(scanf("%d %d %d", &t, &p, &c) != EOF) {
      return 1;
  }
  return 0;
}
*/
