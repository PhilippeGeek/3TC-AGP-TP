//
// Created by Gabriel Augendre on 03/11/2015.
//

#include <stdlib.h>

#include "tree.h"

int main() {
    TREE t1, t2, tree;
    t1 = tree_create(1337, NULL, NULL);
    t2 = tree_create(42, NULL, NULL);
    tree = tree_create(0, t1, t2);
    tree_print(tree);
}