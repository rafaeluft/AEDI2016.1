/*
 ============================================================================
 Name        : aedi.c
 Author      : Rafael Lima
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "aedbasicas.h"

/**
 * Esta função pega dois endereços void e converte-os e inteiros. Visto que estamos no momento
 * trabalhando com inteiros. Após transformar, compara o conteúdo destes inteiros. Caso o primeiro
 * seja menor que o segundo, retorna um valor negativo. Caso jj seja maior do que o primeiro, retorna
 * um valor positivo. Retorna 0 caso sejam iguais.
 */
int compara(void* ii, void *jj){
	int *i = (int*)ii, *j = (int*) jj;
	return ((*i)<(*j))? -1: ((*i)>(*j))? 1: 0;
}
/**
 * Retorna os valores invertidos da compara. Ou seja, quando usada, os valores ficam em ordem
 * descendente.
 */
int compara2(void* ii, void *jj){
	int *i = (int*)ii, *j = (int*) jj;
	return ((*i)>(*j))? -1: ((*i)<(*j))? 1: 0;
}
/**
 * Esta função apenas alloca memória para novos ints. Ele também copia o int passado por parâmetro
 * escrevendo-o na nova área alocada.
 */
int* criaInt(int i){
	int* t= (int*)malloc(sizeof(int)); //aloca a área
	*t = i; //preenche a nova área com o valor de i
	return t;
}
/**
 * Apenas uma função que navega na lista imprimindo os valores presentes na lista genérica.
 */
void printMyList(dlist* list){
	int* temp; // é um ponteiro para inteiros visto que estamos guardando inteiros
	do{
		temp = (int*)dlist_next(list);
		if(temp)
			printf("%d, ", *temp);
	}while(temp);
	puts("\n");
}
//Esta é a função principal :P
int main(void) {
	int v[] = {1, 2, 3, 4, 5, 6};
	int i, *temp;

	dlist* list = dlist_create();
	if(list){
		for(i=0; i<6; i++){

			temp = criaInt(v[i]); //cria um inteiro na memória e guarda o valor do endereço em temp
			//manda inserir o temp (inteiro recém criado), passa a quantidade de bytes e o endereço d
			//função compara.
			if(!dlist_insert(list, (void*)temp, sizeof(int), &compara2))
				puts("Erro ao inserir\n");
			free(temp);
		}

		printMyList(list); //imprimo para ver como ficou
		i = 4;
		if(dlist_delete(list, &i, compara)) // tento deletar o número 4
			puts("Removing 4\n");

		printMyList(list); //imprimo a lista novamente
	}

	return EXIT_SUCCESS;
}
