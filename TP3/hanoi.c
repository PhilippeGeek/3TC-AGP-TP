//
// Created by pvienne on 16/10/15.
//
#include "pile.h"
#include <stdlib.h>
#include <stdio.h>

void create_hanoi_stack(PILE *pile) {
    int i = 4;
    do {
        pile_push(pile, i);
        i--;
    } while (i > 0);
}

int main() {
    PILE **pPILE = malloc(3 * sizeof(PILE **));
    int i = 0;
    printf("%p\n", pPILE);
    for (; i < 3; i++) {
        *(pPILE + i * sizeof(PILE *)) = malloc(sizeof(PILE *));
        printf("%p\n", *(pPILE + i * sizeof(PILE *)));
        //free(*(pPILE+i*sizeof(PILE*)));
    }
    create_hanoi_stack(*(pPILE));
    debug_pile(*pPILE);
    free(pPILE);
    return 0;
}
