/*
 * aedbasicas.c
 *
 *  Created on: 4 de nov de 2016
 *      Author: Rafael Lima de Carvalho <rafa@uft.edu.br>
 */


#include "aedbasicas.h"
#include <stdlib.h>
#include <string.h>
/**
 * Apenas aloca memória para um novo nó para uma lista duplamente encadeada. Um detalhe importante é
 * que além disso, ele instancia o ponteiro void* content. Alocando para ele uma quantidade size de bytes.
 * A cópia do pointeiro content para a área de memória recém criada é feita pela função memcpy (string.h).
 * Caso dê alguma coisa errada, NULL é retornado.
 * @param void* content um ponteiro para uma área válida de memória contendo o objeto a ser armazenado.
 * @param unsigned int size a quantidade em bytes do objeto a ser armazenado.
 */
dno* dno_create(void* content, unsigned int size){
	dno* novo = (dno*)malloc(sizeof(dno));
	if (novo){
		novo->ant = NULL; novo->prox = NULL;
		novo->content = malloc(size);
		if(novo->content){
			if(memcpy(novo->content, content,size) != novo->content){
				return NULL;
			}
		}
	}
	return novo;
}
/**
 * Destroi apropriadamente um determinado nó da lista.
 */
void dno_destroy(dno* no){
	free(no->content);
	free(no);
}
/**
 * Função apenas para criar e inicializar listas.
 */
dlist* dlist_create(){
	dlist* novo = (dlist*)malloc(sizeof(dlist));
	if (novo){
		novo->inicio = NULL; novo->iterator = NULL;
	}
	return novo;
}
/**
 * Função de ajuda apenas para reiniciar o iterador para voltar a apontar para o início da lista.
 */
void dlist_restart_iterator(dlist* L){
	L->iterator = L->inicio;
}

/**
 * Insere um elemento na lista. O último parâmetro é um ponteiro para uma função que retorna um inteiro
 * pegando-se dois ponteiros para conteúdos dos nós. Esta função serve para armazenar na lista segundo
 * algum critério de comparação. Caso seja NULL, os itens são inseridos à maneira que são apresentados.
 */
char dlist_insert(dlist* L, void* content, unsigned int size, int (*comp)(void*, void*)){
	dno* novo = dno_create(content, size);
	if(!novo  || !L)
		return 0;
	if(L->inicio==NULL){
		L->inicio = novo;
		L->iterator = novo;
	}else{
		dno* aux = L->inicio;
		if(comp==NULL)
		{
			//Se o ponteiro para a função de comparação é nulo, então devemos inserir apenas no final
			while(aux->prox) aux = aux->prox;
			aux->prox = novo;
		}else{
			//Codigo para inserir ordenado
			if(comp(novo->content, L->inicio->content) <=0){
				//se o novo for menor ou igual ao inicio
				L->inicio->ant = novo;
				novo->prox = L->inicio;
				L->inicio = novo;
				L->iterator = novo; //restart the iterator! This can generate confusion.
			}else{
				//Caso contrário, temos que achar o lugar apropriado para este nó.
				dno* aux2 = L->inicio->prox;;
				while(aux2!=NULL)
				{
					if(comp(aux2->content, novo->content) >0)
						break;//saio pq encontrei o lugar dele.
					aux = aux2;
					aux2=aux2->prox;
				}
				aux->prox = novo;
				novo->ant = aux;
				novo->prox = aux2;
				if(aux2)
					aux2->ant = novo;
			}
		}
		//Sempre que alterar a lista de alguma maneira, é preciso reiniciar o iterador.
		dlist_restart_iterator(L);
	}
	return 1;
}

/**
 * Procura linearmente um objeto cujo conteúdo seja igual a de algum nó na lista,
 * caso comp seja igual a zero no ato da comparação.
 */
char dlist_delete(dlist* L, void* content, int (*comp)(void*, void*)){
	if(!L || !L->inicio)
		return 0;
	dno* aux = L->inicio;
	while(aux){
		if(comp(aux->content, content)==0)
			break; //Conteúdo a ser deletado foi encontrado na lista.
		aux=aux->prox;
	}
	if(aux){
		if(aux->ant)
			aux->ant->prox = aux->prox;
		if(aux->prox)
			aux->prox->ant = aux->ant;
		dno_destroy(aux);
		//Após cada alteração na lista, o iterator deverá ser reiniciado.
		dlist_restart_iterator(L);
		return 1;
	}
	return 0;
}
/**
 * Apenas retorna o conteúdo do nó apontado por iterator e move-o para o próximo.
 */
void* dlist_next(dlist* L){
	dno* tmp = L->iterator;
	if(L->iterator)
		L->iterator = L->iterator->prox;
	else
		L->iterator = L->inicio;
	return (tmp!=NULL)?tmp->content:NULL;
}
/**
 * Apenas retorna o conteúdo guardado por início.
 */
void* dlist_head(dlist* L){
	dno* tmp = L->inicio;
	return (tmp!=NULL)?tmp->content:NULL;
}
/**
 * Retorna o valor corrente do iterator e move-o para o item anterior da lista.
 */
void* dlist_previous(dlist* L){
	dno* tmp = L->iterator;
	if(L->iterator)
		L->iterator = L->iterator->ant;
	else
		L->iterator = L->inicio;
	return (tmp!=NULL)?tmp->content:NULL;

}
