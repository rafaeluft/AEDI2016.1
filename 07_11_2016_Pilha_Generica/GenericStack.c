/*
 ============================================================================
 Name        : GenericStack.c
 Author      : Rafael
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int* create_int(int value){
    int* i = (int*)malloc(sizeof(int));
    *i = value;
    return i;
}

float* create_float(float value){
    float* i = (float*)malloc(sizeof(float));
    *i = value;
    return i;
}

typedef struct{int id; float value;} X;

X* create_x(int i, float v){
    X* t = (X*) malloc(sizeof(X));
    if(t){
        t->id = i; t->value = v;
    }
    return t;
}

char* x_to_string(X* temp, char* tmp){
    if(temp!=NULL)
        sprintf(tmp, "X{id:%d, value:%f}", temp->id, temp->value);
    else
        sprintf(tmp, "NULL");
    return tmp;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int v1[] = {1, 2, 3, 4, 5, 6};
    float v2[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    char tmp[64];
    X* value;
    //int *value;
    stack* st = create_stack();
    for(int i=0; i< 6; i++)
        stack_push(st, create_x(v1[i], v2[i]));
        //stack_push(st, create_int(v1[i]));
    while(stack_pop(st, (void**) &value)){
        //printf("stack value: %2.2f \n", *value);
        //printf("stack value: %d \n", *value);
        printf("stack value: %s \n", x_to_string(value, tmp));
        free(value);
    }
    return 0;
}
