/*************************************************************************
	> File Name: 1-vector.cpp
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 日  9/13 19:47:38 2020
 ************************************************************************/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define max_op 20

typedef struct Vector{
    int *data;
    int size, length;
} Vector;

Vector *init(int n){
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    vec->data = (int *)malloc(sizeof(int) * n);
    vec->size = n;
    vec->length = 0;
    return vec;
}

int expand(Vector *vec){
    int extr_size = vec->size;
    int *p;
    while (extr_size){
        p = (int *)realloc(vec->data, sizeof(int) * (vec->size) + extr_size);
        if(p) break;
        extr_size /= 2;
    }
    if(p == NULL) return 0;
    vec->data = p;
    vec->size += extr_size;
    return 1;
}

int insert(Vector *vec, int ind, int val){
    if(vec == NULL) return 0;
    if (ind > vec->length || ind < 0) return 0;
    if(vec->length == vec->size){
        if(!expand(vec)) return 0;
        printf("expand successful ! size = %d\n", vec->size);
    } 
    for(int i  = vec->length; i > ind; i--){
        vec->data[i] = vec->data[i - 1];
    }
    vec->data[ind] = val;
    vec->length += 1;
    return 1;
}

int erase(Vector *vec, int ind){
    if(vec == NULL) return 0;
    if(ind < 0 || ind >= vec->length) return 0;
    for(int i = ind + 1; i < vec->length; i++){
        vec->data[i - 1] = vec->data[i];
    }
    vec->length -= 1;
    return 1;
}

void output(Vector *vec){
    printf("Vector(%d) = [", vec->length);
    for(int i = 0; i < vec->length; i++){
        i && printf(", ");
        printf("%d", vec->data[i]);
    }
    printf("]\n");
}

void clear(Vector *vec){
    if(vec == NULL) return;
    free(vec->data);
    free(vec);
    return;
}

int main(){
    int op, ind, val;
    srand(time(0));
    Vector *vec = init(1);
    for(int i = 0; i < max_op; i++){
        op = rand() % 4;
        ind = rand() % (vec->length + 1);
        val = rand() % 50;
        switch (op) {
            case 0 :
            case 1 :
            case 2 : {
                printf("insert %d at %d to vector = %d\n", val, ind, insert(vec, ind, val));
            } break;
            case 3 : {
                printf("erase iterm  at %d from vector = %d\n", ind, erase(vec, ind));
            }break;
        }
        output(vec);
        printf("\n");
    }
    return 0;
}
