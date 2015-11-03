//
// Created by Gabriel Augendre on 03/11/2015.
//

#include <stdlib.h>
#include <time.h>

#include "tree.h"

int main() {
    TREE t1, t2, tree;
    t1 = tree_create(1337, NULL, NULL);
    int i = 0;
    srand((unsigned int) time(NULL));
    for (i = 0; i < 1337; i++) {
        tree_add(t1, rand());
    }
    t2 = tree_create(42, NULL, NULL);
    tree = tree_create(0, t1, t2);
    tree_print(tree);
    printf("\n");
    printf("Tree depth : %d\n", tree_depth(tree));
    return 0;
}