/*
 * stack.h
 *
 *  Created on: 7 de nov de 2016
 *      Author: rafael
 */

#ifndef STACK_H_
#define STACK_H_

typedef struct _no{
    void *info;
    struct _no *prox;
} no;

typedef struct{
    no* head;
    unsigned int qty;
} stack;

stack* create_stack();
int stack_push(stack* S, void* content);
int stack_pop(stack* S, void** content);
#endif /* STACK_H_ */
