//
// Created by yahya on 8/4/23.
//
#include "arraylist.h"

#include <stdio.h>
#include <stdlib.h>

const int initial_capacity = 10;

int _resize(ArrayList *l, int new_capacity) {
    if (new_capacity < initial_capacity) {
        return 0;
    }
    int *new_mem = (int *) realloc(l->arr, sizeof(int) * new_capacity);
    if (new_mem == NULL) {
        printf("Konnte keinen Speicher allokieren");
        return 0;
    }

    l->capacity = new_capacity;
    l->arr = new_mem;
    return 1;
}

void al_init(ArrayList *l) {
    l->size = 0;
    l->capacity = initial_capacity;
    l->arr = malloc(sizeof(int) * initial_capacity);
}

void al_destroy(ArrayList *l) {
    free(l->arr);
}

void al_append(ArrayList *l, int key) {
    if (l->size == l->capacity) {
        _resize(l, l->capacity * 2);
    }
    l->arr[l->size] = key;
    l->size++;
}

void al_insert(ArrayList *l, int pos, int key) {
    if (l->size == l->capacity) {
        _resize(l, l->capacity * 2);
    }
    if (pos == l->size) {
        al_append(l, key);
    }
    for (int i = l->size + 1; i > pos; --i) {
        l->arr[i] = l->arr[i - 1];
    }
    l->arr[pos] = key;
    l->size++;
}

void al_delete(ArrayList *l, int pos) {
    if (pos < l->size) {
        for (int i = pos; i < l->size - 1; ++i) {
            l->arr[i] = l->arr[i + 1];
        }
    }
    l->size--;
    if (l->size <= l->capacity / 3) {
        _resize(l, 0.5 * l->capacity);
    }
}

void al_print(FILE *f, const ArrayList *l) {
    fprintf(f, "[ ");
    for (int i = 0; i < l->size; ++i) {
        fprintf(f, "%3d ", l->arr[i]);
    }
    for (int i = l->size; i < l->capacity; ++i) {
        fprintf(f, "%3s ", "");
    }
    fprintf(f, " ][ size: %3d capacity: %3d ]\n", l->size, l->capacity);
}

