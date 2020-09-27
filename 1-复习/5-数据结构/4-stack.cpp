/*************************************************************************
	> File Name: 4-stack.cpp
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 一  9/14 15:52:46 2020
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Stack{
    int *date;
    int top;
    int size;
}Stack;

Stack *init(int n){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->date = (int *)malloc(sizeof(int) * n);
    s->top = -1;
    s->size = n;
    return s;
}

int empty(Stack *s){
    return s->top == -1;
}

int push(Stack *s, int val){
    if(s == NULL) return 0;
    if(s->top + 1 == s->size) return 0;
    s->date[++s->top] = val;
    return 1;
}

int pop(Stack *s){
    if(s == NULL) return 0;
    if(s->top == -1) return 0;
    s->top -= 1;
    return 1;
}

int top(Stack *s){
    return s->date[s->top];
}

void clear(Stack *s){
    if(s == NULL) return ;
    free(s->date);
    free(s);
    return ;
}

void output(Stack *s){
    printf("Stack(%d) = [", s->top + 1);
    for(int i = 0; i <= s->top; i++){
        i && printf(", ");
        printf("%d", s->date[i]);
    }
    printf("]\n");
    return;
}


int main(){
    #define max_op 20
    Stack *s = init(max_op);
    srand(time(0));
    int op, val;
    for(int i = 0; i < max_op; i++){
        op = rand() % 4;
        val = rand() % 30;
        switch(op){
            case 0:
            case 1:
            case 2:{
                printf("push %d to stack = %d\n", val, push(s, val));
            }break;
            case 3:{
                printf("pop %d from stack = %d\n", top(s), pop(s));
            }break;
        }
        output(s);
        printf("\n");
    }
    clear(s);
    return 0;
}
