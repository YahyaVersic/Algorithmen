#include <stdio.h>

#include "dlinkedlist.h"

int main() {

    int counter = 0;

    DLinkedList dl;

    dl_init(&dl);

    for (int i = 0; i < 10; ++i) {
//        printf("A%d\n", i);
        dl_append(&dl, counter++);
//        printf("B%d\n", -i);
        dl_print(stdout, &dl);
//        printf("C%d\n", -i);
    }

    for (int i = 0; i < 10; ++i) {
        dl_insert(&dl, dl.tail->_prev->_prev->_prev->_prev, counter++);
        dl_print(stdout, &dl);
    }

    dl_destroy(&dl);

}