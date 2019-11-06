struct visitas{
	int tempo;
	char *nome;
};

struct contadores{
	int contador = 0;
	visitas *visita = 0;
};

void countingSort(visitas *planetas, int maiorLetra, int tamanhoLista, int posicao){
	contadores *count = new contadores [maiorLetra-96];

	for(int k=0;k<tamanhoLista;k++){
		int letra = planetas[k].nome[posicao]-97;
		count[letra].contador++;
		
		int contador = count[letra].contador;
		visitas *atualizarPlanetas = new visitas[contador];

		for(int x=0; x<contador-1;x++){
			atualizarPlanetas[x] = count[letra].visita[x];
		}
		atualizarPlanetas[contador-1] = planetas[k];

		delete count[letra].visita;
		count[letra].visita = atualizarPlanetas;
	}

	int aux=0;
	for(int i=0;i<maiorLetra-96;i++){
		int contador = count[i].contador;
		for(int x=0;x<contador;x++){
			planetas[aux] = count[i].visita[x];
			aux++;
		}
	}

	delete count;
}

void radix(visitas *planetas, int maiorLetra, int tamanhoLista, int tamanhoNome){
	for(int i=tamanhoNome-1;i>=0;i--){
		countingSort(planetas,maiorLetra,tamanhoLista,i);
	}
}

