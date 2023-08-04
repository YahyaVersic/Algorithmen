#ifndef ALGORITHMEN_ARRAYLIST_H
#define ALGORITHMEN_ARRAYLIST_H

#include <stdio.h>

typedef struct ArrayList{
    int* arr;
    int size;
    int capacity;
} ArrayList;

void al_init(ArrayList* l);

void al_destroy(ArrayList* l);

void al_append(ArrayList* l, int key);

void al_insert(ArrayList* l, int pos, int key);

void al_delete(ArrayList* l, int pos);

void al_print(FILE* f, const ArrayList* l);


#endif //ALGORITHMEN_ARRAYLIST_H
