/*
 * aedbasicas.h
 *
 *  Created on: 4 de nov de 2016
 *      Author: Rafael Lima de Carvalho <rafa@uft.edu.br>
 */

#ifndef AEDBASICAS_H_
#define AEDBASICAS_H_

typedef struct _dno_{
	void *content;
	struct _dno_ *prox, *ant;
} dno;

typedef struct{dno* inicio; dno* iterator;} dlist;

dlist* dlist_create();
/**
 * Insere um novo no na lista, cujo conteudo eh um ponteiro para um conteudo.
 * @param dlist*L -> ponteiro para uma dlist valida (não nula).
 * @param void* content o ponteiro para o objeto que se deseja armazenar
 * @param int size o tamanho em bytes do conteúdo. A lista será capaz de copiar
 * 	      os dados para a memória contida por ela mesma.
 * @return char 0 indicando erro e 1 indicando sucesso.
 */
char dlist_insert(dlist* L, void* content, unsigned int size, int (*comp)(void*, void*));
/**
 * Deleta um nó na lista se o conteúdo estiver presente lá de acordo com a função de comparação comp.
 * @return 0 em caso de erro e 1 em caso de sucesso.
 */
char dlist_delete(dlist* L, void* content, int (*comp)(void*, void*));
/**
 * Função de auxílio que apenas retorna quem é o conteúdo que está no início. Retorna NULL, caso o
 * início seja nulo.
 */
void* dlist_head(dlist* L);
/**
 * Função que retorna o ponteiro atual de navegação da lista. Além disso ele anda com o ponteiro interno.
 * Retona NULL ao chegar no final da lista (e após isso reinicia o ponteiro para o início). Lembre-se
 * retorna o conteúdo.
 */
void* dlist_next(dlist* L);
/**
 * Faz o contrário de next andando com o ponteiro iterator para o nó anterior.
 */
void* dlist_previous(dlist* L);

#endif /* AEDBASICAS_H_ */
