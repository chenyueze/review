/*************************************************************************
	> File Name: 2-list.c
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 日  9/13 20:58:12 2020
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define max_op 20

typedef struct ListNode{
    int data;
    struct ListNode *next;
} ListNode;

typedef struct List{
    ListNode head;
    int length;
} List;

ListNode *getNewNode(int val){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = val;
    p->next = NULL;
    return p;
}

List *getLinkList(){
    List *l = (List *)malloc(sizeof(List));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

int insert(List *l, int ind, int val){
    if(l == NULL) return 0;
    if(ind < 0 || ind > l->length) return 0;
    ListNode *p = &(l->head), *node = getNewNode(val);
    while(ind --) p = p->next;
    node->next = p->next;
    p->next = node;
    l->length += 1;
    return 1;
}

int erase(List *l, int ind){
    if(l == NULL) return 0;
    if(ind < 0 || ind >= l->length) return 0;
    ListNode *p = &(l->head), *q;
    while(ind --) p = p->next;
    q = p->next;
    p->next = q->next;
    free(q);
    l->length -= 1;
    return 1;
}

void output(List *l){
    printf("List(%d) = [", l->length);
    for(ListNode *p = l->head.next; p; p = p->next){
        printf("%d->", p->data);
    }
    printf("NULL]\n");
    return ;
}

void clear_ListNode(ListNode *node){
    if(node == NULL) return ;
    free(node);
    return ;
}

void clear_List(List *l){
    if(l == NULL) return;
    ListNode *p = l->head.next, *q;
    while(p){
        q = p->next;
        clear_ListNode(p);
        p = q;
    }
    free(l);
    return ;
}

int main(){
    srand(time(0));
    List *list = getLinkList();
    int op, val, ind;
    for(int i = 0; i < max_op; i++){
        op = rand() % 4;
        ind = rand() % (list->length + 3) - 1;
        val = rand() % 30;
        switch(op) {
            case 0:
            case 1:
            case 2:{
                printf("insert %d at %d to list = %d\n", val, ind, insert(list, ind, val));
            }break;
            case 3:{
                printf("erase iterm at %d from list = %d\n", ind, erase(list, ind));
            }break;
        }
        output(list);
    }
    return 0;
}
