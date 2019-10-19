#include <cstdio> // em C substituir por #include <stdio.h>
#include "foo.h"
#include "listaEncadeada.h"

int main(){
	int tempoTotal,numeroDePlanetas,tamanhoNomePlaneta;

	scanf("%d %d %d ",&tempoTotal,&numeroDePlanetas,&tamanhoNomePlaneta);
	
	listaEncadeada *planetas = new listaEncadeada();

	char letra;
	int tempoVisita;
	for(int i=0;i<numeroDePlanetas;i++){

		char *nomePlaneta = new char[tamanhoNomePlaneta];

		scanf("%d ",&tempoVisita);

		for(int j=0;j<tamanhoNomePlaneta;j++){
			scanf("%c",&letra);
			nomePlaneta[j] = letra;

		}
		nomePlaneta[tamanhoNomePlaneta] = '\0';

		planetas->push_front(tempoVisita,nomePlaneta);
	}
	planetas->imprimeLista();


	delete planetas;
	return 0;
}


/*
  int t;
  int p;
  int c;

  while(scanf("%d %d %d", &t, &p, &c) != EOF) {
      return 1;
  }
*/