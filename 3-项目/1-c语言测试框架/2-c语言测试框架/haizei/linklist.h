/*************************************************************************
	> File Name: linglist.h
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 一  9/ 7 20:40:28 2020
 ************************************************************************/

#ifndef _LINKLIST_H
#define _LINKLIST_H

#define offset(T, name) ((size_t)(&(((T *)(0))->name)))
#define Head(p, T, name) ((T *)((long long)(p) - offset(T, name)))

struct LinkNode {
    struct LinkNode *next;
    
};

#endif
