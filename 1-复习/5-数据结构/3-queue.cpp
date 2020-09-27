/*************************************************************************
	> File Name: 3-queue.cpp
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 一  9/14 15:27:32 2020
 ************************************************************************/
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Queue{
    int *data;
    int size, head, tail, cnt;
}Queue;

Queue *init(int n){
    Queue *p = (Queue *)malloc(sizeof(Queue));
    p->data = (int *)malloc(sizeof(int) * n);
    p->size = n;
    p->head = 0;
    p->tail = 0;
    p->cnt = 0;
    return p;
}

int empty(Queue *q){
    return q->cnt == 0;
}

int front(Queue *q){
    return q->data[q->head];
}

int push(Queue *q, int val){
    if(q == NULL) return 0;
    if(q->cnt == q->size) return 0;
    q->data[q->tail++] = val;
    if(q->tail == q->size) q->tail -= q->size;
    q->cnt += 1;
    return 1;
}

int pop(Queue *q){
    if(q == NULL) return 0;
    if(empty(q)) return 0;
    q->head += 1;
    if(q->head == q->size) q->head -= q->size;
    q->cnt -= 1;
    return 1;
}

void clear(Queue *q){
    if(q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

void output(Queue *q){
    printf("Queue(%d) = [", q->cnt);
    for(int i = q->head, j = 0; j < q->cnt; j++){
        j && printf(", ");
        printf("%d", q->data[(i + j) % (q->size)]);
    }
    printf("]\n");
    return ;
}

int main(){
    #define max_op 20
    srand(time(0));
    Queue *q = init(max_op); 
    int op, val;
    for(int i = 0; i < 2 * max_op; i++){
        op = rand() % 4;
        val = rand() % 30;
        switch(op){
            case 0:
            case 1:
            case 2:{
                printf("push %d to Queue = %d\n", val, push(q, val));
            }break;
            case 3:{
                printf("pop %d from Queue = %d\n", front(q), pop(q));
            }break;
        }
        output(q);
        printf("\n");
    }
    clear(q);
    return 0;
}
