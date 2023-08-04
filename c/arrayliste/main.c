#include "arraylist.h"

#include <stdio.h>
#include <stdlib.h>


int main(void){

    ArrayList al;

    al_init(&al);

    int counter = 0;

    for (int i = 0; i < 40; ++i) {
        al_append(&al, counter++);
        al_print(stdout, &al);
    }

    for (int i = 10; i < 30; ++i) {
        al_delete(&al, 10);
        al_print(stdout, &al);
    }

    for (int i = 4; i < 10; ++i) {
        al_insert(&al, i, counter++);
        al_print(stdout, &al);
    }

    al_destroy(&al);
}