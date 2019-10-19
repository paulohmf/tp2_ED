#include "listaEncadeada.h"

//Construtor da lista vazia 
listaEncadeada::listaEncadeada(){
	this->cabeca = new nodulo;//Aloca dinamicamenteo nodulo Cabeca da lista

	this->cabeca->valor = 42; //O valor da lista não é utilizaod, por isso receve um valor arbitrario para que o identificasse
	this->cabeca->contador = -1; //Na cabeça o contador é o tamanho da lista
	this->cabeca->proximoNodulo = 0; //Lista criada é vazia
	this->cabeca->nome = 0;

}
//O destrutor libera a memoria alocada para a cabeca da lista
listaEncadeada::~listaEncadeada(){
	this->esvaziaLista();//Desaloca toda a memoria que tinha sido alocada pela lista
	delete this->cabeca;
}

//Checa se a lista está vazia
bool listaEncadeada::ehVazia(){
	if(this->cabeca->proximoNodulo == 0){
		return true;
	}else{
		return false;
	}
}

//Aloca dinamicamente um novo modulo e adiciona no inicio da lista, a função aceita valores repetidos
void listaEncadeada::push_front(int valor,char *nome){
	//Aloca o novo modulo dinamicamente, recebendo dois valores
	nodulo *novo = new nodulo();
	novo->valor = valor;
	novo->nome = nome; // Nos nodulos o contador é o numero de operações

	//Caso a lista seja vazia, a cabeca passa a apontar para o nodulo
	if(this->ehVazia()){
		this->cabeca->proximoNodulo = novo;
		novo->proximoNodulo = 0;
	//Caso exista algum elemento na lista
	}else{
		//O nodulo novo comeca a apontar pro antigo primeiro elemente (que se torna o segundo elemento)
		novo->proximoNodulo = this->cabeca->proximoNodulo;
		//E a cabeca começa a apontar para o novo nodulo
		this->cabeca->proximoNodulo = novo;
	}

	//O aumento do tamanho da lista é computado na cabeça
	this->cabeca->contador++;
}
//Percorre a lista inteira e imprime seu resultado
void listaEncadeada::imprimeLista(){
	nodulo *aux = this->cabeca->proximoNodulo;

	//Caso a lista esteja vazia, imprime lista vazia
	if(this->ehVazia()){
		printf("(Lista Vazia)\n");
	}else{
		//Caso não seja vazia imprime os elementos no estipo "(posicao na lista) -> valor : valor"
		int i=0;
		while(aux->proximoNodulo != 0){
			printf("%i -> %s : %i\n",i,aux->nome,aux->valor);
			aux = aux->proximoNodulo;
			i++;
		}
		printf("%i -> %s : %i\n",i,aux->nome,aux->valor);
	}

}
//Retorna o primeiro nodulo do lista removendo o da lista
nodulo listaEncadeada::pop(){
	nodulo *primeiro = this->cabeca->proximoNodulo;

	//A cabeca passa a apontar para o segundo elemento da lista que se tornara o novo primeiro elemento
	this->cabeca->proximoNodulo = primeiro->proximoNodulo;
	//O tamanho da lista é reduzido
	this->cabeca->contador--;

	//O nodulo retirado é salvo numa auxiliar e tem seu apontador zerado
	nodulo retorno;
	retorno.valor = primeiro->valor;
	retorno.contador = primeiro->contador;
	retorno.proximoNodulo = 0;

	//A memoria ocupada pelo nodulo é desocupada
	delete primeiro->nome;
	delete primeiro;

	//O nodulo auxiliar é retornado
	return retorno;
}
//Adiciona um par de valores no final da lista, a função não aceita valores repetidos
void listaEncadeada::push_back(int valor, int contador){
	//Aloca memoria para o novo nodulo
	nodulo *novo = new nodulo;
	novo->valor = valor;
	novo->contador = contador;
	novo->proximoNodulo = 0;

	//Percorre a lista, com um nodulo auxiliar, ate que chegue ao final da lista
	nodulo *aux = this->cabeca;
	for(int i=0;i<=this->size();i++){
		aux = aux->proximoNodulo;
		//A FUNÇÃO NÃO ACEITA VALORES REPETIDOS
		if(aux->valor == valor){
			delete novo->nome;
			delete novo;
			return;
		}
	}

	//Salva no novo nodulo no final da lista
	aux->proximoNodulo = novo;
	//Incrementa o tamanho da lista
	this->cabeca->contador++;
}
//Retorna o valor do contador da cabeça que representa o tamanho da lista
int listaEncadeada::size(){
	return this->cabeca->contador;
}

//Remove o modulo e desaloca o espaço da memoria
void listaEncadeada::remover(int valor){
	//Mantem controle do nodulo atual e do nodulo anterior
	nodulo *NoduloAnterior = this->cabeca;
	nodulo *NoduloAtual = this->cabeca->proximoNodulo;

	//Checa se a lista não eh vazia
	if(this->ehVazia()){
		printf("A lista está vazia\n");
	}else{
		//Percorre a lista ate que o valor seja encontrado em alguma posição (caso existam elementos repetidos apenas o primeiro deles e apagado)
		for(int i=0; i<=this->cabeca->contador;i++){
			//Caso encontre o valor
			if(NoduloAtual->valor == valor){
				//Faz com que o nodulo anterior a ele aponte para o proximo 
				NoduloAnterior->proximoNodulo = NoduloAtual->proximoNodulo;
				//Diminui o tamanho da lista
				this->cabeca->contador--;
				//Desaloca a memoria que era utilizada pelo nodulo
				delete NoduloAtual->nome;
				delete NoduloAtual;
				//Sai da funcao
				return;
			}
			NoduloAnterior = NoduloAtual;
			NoduloAtual = NoduloAnterior->proximoNodulo;
		}
	}
	//Se o valor não existir na lista nada acontece
	//printf("Valor não encontrado\n");
}

//Esvazia a lista, desalocando cada espaço de memoria e depois imprime a lista
void listaEncadeada::esvaziaLista(){
	nodulo *NoduloAtual = this->cabeca->proximoNodulo;

	if(this->ehVazia()){
		
	}else{
		//Percorre a lista desalocando todos os nodulos da memoria
		for(int i=0; i<=this->cabeca->contador;i++){

			this->cabeca->proximoNodulo = NoduloAtual->proximoNodulo;
			delete NoduloAtual->nome;
			delete NoduloAtual;

			NoduloAtual = this->cabeca->proximoNodulo;
		}
		this->cabeca->contador = -1;
	}
	//Imprime a lista, como está vazia, imprimira "(Lista vazia)"
	//this->imprimeLista();
}
