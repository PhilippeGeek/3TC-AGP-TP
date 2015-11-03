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
    tree = tree_create(0, NULL, NULL);
    tree_print_list(tree);
    printf("\nTree depth : %d\n", tree_depth(tree));
    printf("Tree is balanced : %d\n", tree_is_balanced(tree));

    tree_add(tree, 1);
    tree_print_list(tree);
    printf("\nTree depth : %d\n", tree_depth(tree));
    printf("Tree is balanced : %d\n", tree_is_balanced(tree));

    tree_add(tree, 2);
    tree_print_list(tree);
    printf("\nTree depth : %d\n", tree_depth(tree));
    printf("Tree is balanced : %d\n", tree_is_balanced(tree));

    tree_add(tree, -2);
    tree_print_list(tree);
    printf("\nTree depth : %d\n", tree_depth(tree));
    printf("Tree is balanced : %d\n", tree_is_balanced(tree));

    tree_add(tree, -1);
    tree_print_list(tree);
    printf("\nTree depth : %d\n", tree_depth(tree));
    printf("Tree is balanced : %d\n", tree_is_balanced(tree));
    return 0;
}