//
// Created by Gabriel Augendre on 03/11/2015.
//

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "tree.h"

int main() {
    TREE t1, t2, tree;
    srand((unsigned int) time(NULL));
    int i;
    t1 = tree_create(1337, NULL, NULL);
    t2 = tree_create(42, NULL, NULL);
    tree = tree_create(0, t1, t2);
    printf("Tree is balanced : %d\n", tree_is_balanced(tree));
    t1 = tree_create(1337, NULL, NULL);
    t2 = tree_create(42, NULL, NULL);
    tree = tree_create(0, t1, t2);
    printf("Tree is balanced : %d\n", tree_is_balanced(tree));
    for (i = 0; i < 25000; i++) {
        tree_add(t1, rand());
    }
    t2 = tree_create(42, NULL, NULL);
    tree = tree_create(0, t1, t2);
    tree_print(tree);
    printf("\n");
    printf("Tree depth : %d\n", tree_depth(tree));
    printf("Tree is balanced : %d", tree_is_balanced(tree));
    return 0;
}