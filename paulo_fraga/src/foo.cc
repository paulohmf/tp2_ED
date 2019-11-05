struct visitas{
	int tempo;
	char *nome;
};

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