#ifndef __TP1_ED___
#define __TP1_ED__

struct visitas{
	int tempo;
	char *nome;
};

void myMergeSort(visitas *valores, int esq, int dir);
void junta(visitas *valores,int esq,int particao,int dir);

#endif
