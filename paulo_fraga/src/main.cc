#include <cstdio> // em C substituir por #include <stdio.h>
#include "radix.h"
#include "merge.h"

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
	myMergeSort(planetas,0,numeroVisitas-1);

	int ultimoVisitado = 0;
	int visitasMes = -1;
	int mez = 1;
	int soma = 0;
	bool flag = false;

	for(int x=0;x<numeroVisitas;x++){

		while(soma<tempoTotal && x<numeroVisitas){
			visitasMes++;
			soma+=planetas[x].tempo;
			x++;
			flag = true;
		}
		if(soma>tempoTotal){
			x--;
			visitasMes--;
		}
		soma = 0;

		visitas *mes = new visitas[visitasMes+2];

		for(int i=ultimoVisitado,k=0;i<=ultimoVisitado+visitasMes;i++,k++){
			mes[k] = planetas[i];
		}
		ultimoVisitado = x;

		radix(mes,maiorLetra,visitasMes+1,tamanhoNome);

		for(int j=0;j<=visitasMes;j++){
			printf("%i %s %i\n",mez,mes[j].nome,mes[j].tempo);
		}
		visitasMes = -1;
		mez++;

		delete mes;

		if(flag){
			x--;
			flag = false;
		}
	}
	for(int k=0;k<numeroVisitas;k++){
		delete planetas[k].nome;
	}
	return 0;
}