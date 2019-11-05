
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
