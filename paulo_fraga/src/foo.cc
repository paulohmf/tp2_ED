/*#################################################### UTEIS ###################################*/
struct visitas{
	int tempo;
	char *nome;
};
/*#################################################### MERGE ###################################*/

void junta(visitas *valores,int esq,int particao,int dir){

	visitas *resposta = new visitas [dir-esq+1];

	int i = esq;
	int j = particao+1;

	for(int k=0;k<=(dir-esq);k++){

		if((i<=particao)&&(j<=dir)){
			int menor = i;
			if(valores[i].tempo > valores[j].tempo){
				menor = j;
				j++;
			}else{
				i++;
			}
			resposta[k] = valores[menor];

		}else if(i>particao){
			resposta[k] = valores[j];
			j++;

		}else{
			resposta[k] = valores[i];
			i++;
		}
	}
	
	for(int j=0,k=esq;j<=dir-esq;j++,k++){
		valores[k] = resposta[j];
	}

	delete resposta;
}

void myMergeSort(visitas *valores, int esq, int dir){
	if(dir==esq){
		return;
	}else{
		int particao = (dir+esq)/2;
		myMergeSort(valores, esq, particao);
		myMergeSort(valores, particao+1, dir);
		junta(valores, esq, particao, dir);
	}
}


/*#################################################### RADIX ###################################*/
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

