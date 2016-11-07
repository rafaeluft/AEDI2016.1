/*
 * stack.c
 *
 *  Created on: 7 de nov de 2016
 *      Author: rafael
 */
#include "stack.h"

//
//  main.c
//  Palindrome
//
//  Created by Rafael Lima de Carvalho on 31/10/16.
//  Copyright © 2016 Rafael Lima de Carvalho. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

no* create_no(void *content){
    no* novo = (no*)malloc(sizeof(no));
    if(novo){
        novo->info = content;
        novo->prox = NULL;
    }
    return novo;
}
typedef char bool_t;

stack* create_stack(){
    stack* novo = (stack*)malloc(sizeof(stack));
    if(novo){
        novo->head = NULL;
        novo->qty = 0;
    }
    return novo;
}

unsigned int stack_size(stack* S){
    if(S)
        return S->qty;
    return 0;
}

int stack_push(stack* S, void* content){
    no* novo = create_no(content);
    if(!novo || !S)
        return 0;
    novo->prox = S->head;
    S->head = novo;
    S->qty++;
    return 1;
}

int stack_pop(stack* S, void** content){
    if(S && S->qty>0 && S->head){
        no* temp = S->head;
        *content = S->head->info;
        S->head = S->head->prox;
        free(temp);
        S->qty--;
        return 1;
    }return 0;
}
