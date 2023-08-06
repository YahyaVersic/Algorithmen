#ifndef ALGORITHMEN_DLINKEDLIST_H
#define ALGORITHMEN_DLINKEDLIST_H

#include <stdio.h>

typedef struct DLinkedList DLinkedList;
typedef struct DListNode DListNode;

typedef struct DLinkedList {
    int size;
    DListNode *head;
    DListNode *tail;
} DLinkedList;

typedef struct DListNode {
    int key;
    DListNode *_next;
    DListNode *_prev;
} DListNode;

void dl_init(DLinkedList *l);

void dl_destroy(DLinkedList *l);

void dl_append(DLinkedList *l, int key);

void dl_insert_at(DLinkedList *l, int pos, int key);

void dl_insert(DLinkedList *l, DListNode* p, int key);

void dl_delete(DLinkedList *l, int pos);

void dl_print(FILE *f, const DLinkedList *l);

#endif //ALGORITHMEN_DLINKEDLIST_H
