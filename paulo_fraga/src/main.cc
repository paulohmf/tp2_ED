#include <cstdio> // em C substituir por #include <stdio.h>
#include "foo.h"


struct visitas{
	int tempo;
	char *nome;
};

int main(){
	int tempoTotal,numeroVisitas,tamanhoNome;

	scanf("%d %d %d ",&tempoTotal,&numeroVisitas,&tamanhoNome);

	visitas planetas[numeroVisitas];

	char letra;
	int tempoVisita;
	for(int i=0;i<numeroVisitas;i++){

		char *nomePlaneta = new char[tamanhoNome];

		scanf("%d ",&tempoVisita);
		planetas[i].tempo = tempoVisita;

		for(int j=0;j<tamanhoNome;j++){
			scanf("%c",&letra);
			nomePlaneta[j] = letra;

		}
		nomePlaneta[tamanhoNome] = '\0';

		planetas[i].nome = nomePlaneta;
	}

	for(int k=0;k<numeroVisitas;k++){
		printf("%s - ",planetas[k].nome);
		printf("%i\n",planetas[k].tempo);
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
