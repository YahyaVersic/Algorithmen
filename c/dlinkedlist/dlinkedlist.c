#include "dlinkedlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>


DListNode *_create_dlistnode(DListNode *prev, DListNode *next, int key) {
    DListNode *node = malloc(sizeof(DListNode));
    node->_next = next;
    node->_prev = prev;
    node->key = key;

    return node;
}

void dl_init(DLinkedList *l) {
    l->size = 0;
    DListNode *head;
    DListNode *tail;

    tail = _create_dlistnode(NULL, NULL, INT_MAX);
    head = _create_dlistnode(NULL, NULL, INT_MIN);

    head->_next = tail;
    tail->_prev = head;

    l->head = head;
    l->tail = tail;
}

void dl_destroy(DLinkedList *l) {
    DListNode *cur = l->head;
    DListNode *next = cur->_next;
    while (cur != l->tail) {
        free(cur);
        cur = next;
        next = cur->_next;
    }

    free(l->tail);
    free(l);
}

void dl_append(DLinkedList *l, int key) {
    DListNode *element = _create_dlistnode(l->tail->_prev, l->tail, key);
    element->_prev->_next = element;
    element->_next->_prev = element;
    l->size++;
}

void dl_insert_at(DLinkedList *l, int pos, int key) {

}

void dl_insert(DLinkedList *l, DListNode *p, int key) {
    assert(p != l->tail);
    DListNode *e = _create_dlistnode(p, p->_next, key);

    // Schritt 1
//    e->_prev = p;
//    e->_next = p->_next;

    // Schritt 2
    p->_next = e;
    e->_next->_prev = e;

    l->size++;
}

void dl_delete(DLinkedList *l, int pos) {

}

void dl_print(FILE *f, const DLinkedList *l) {
    DListNode *cur = l->head->_next;
    fprintf(f, "HEAD -> ");
    while (cur != l->tail) {
        fprintf(f, "%d -> ", cur->key);
        cur = cur->_next;
    }
    fprintf(f, "TAIL\n");
}





