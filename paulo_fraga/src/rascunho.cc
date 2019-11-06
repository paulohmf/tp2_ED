
int tam = 4;

void junta(visitas *valores,int esq,int particao,int dir){
	//printf("ENTREI NO JUNTA ########\n");

	visitas *resposta = new visitas [dir-esq+1];

	//printf("dir-esq : %d\n",(dir-esq));
	//printf("esq : %d\n",esq);
	//printf("particao : %d\n",particao);
	//printf("dir : %d\n",dir);


	int i = esq;
	int j = particao+1;

	//printf("i : %d\n",i);
	//printf("j : %d\n",j);

	for(int k=0;k<=(dir-esq);k++){
		//printf("k : %d\n",k);

		if((i<=particao)&&(j<=dir)){
			int menor = i;
			//printf("valores[i] : %d\n",valores[i]);
			//printf("valores[j] : %d\n",valores[j]);
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
		//printf("i : %d\n",i);
		//printf("j : %d\n",j);
		//printf("resposta[k] : %d\n",resposta[k]);
	}
	
	for(int j=0,k=esq;j<=dir-esq;j++,k++){
		//printf("resposta[j] : %d\n",resposta[j]);
		//printf("valores[j] : %d\n",valores[j]);
		valores[k] = resposta[j];
	}
}

void myMergeSort(visitas *valores, int esq, int dir){
	//printf("myMergeSort ########\n");
	if(dir==esq){
		return;
	}else{
		int particao = (dir+esq)/2;
		myMergeSort(valores, esq, particao);
		myMergeSort(valores, particao+1, dir);
		junta(valores, esq, particao, dir);
	}
}

int main(){
	visitas v[tam];
	v[0].tempo = 4;
	v[1].tempo = 3;
	v[2].tempo = 1;
	v[3].tempo = 2; 

	for(int i=0;i<tam;i++){
		printf("%d\n",v[i].tempo);
	}
	printf("##########MERGE################\n");
	myMergeSort(v,0,3);

	for(int i=0;i<tam;i++){
		printf("%d\n",v[i].tempo);
	}

	return 0;
}



/*#######################################################*/


struct contadores{
	int contador = 0;
	visitas *visita = 0;
};

void countingSort(visitas *planetas, int maiorLetra, int tamanhoLista, int posicao){
	contadores *count = new contadores [maiorLetra-96];

	for(int k=0;k<tamanhoLista;k++){
		int letra = planetas[k].nome[posicao]-97;
		//printf("%c - letra : %i int\n", planetas[k].nome[posicao],letra);
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
		//printf("%c - %i\n",('a'+i),contador);
		//printf("VISITAS SALVAS\n");
		for(int x=0;x<contador;x++){
			//printf("%i - ",count[i].visita[x].tempo);
			//printf("%s\n",count[i].visita[x].nome);
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

