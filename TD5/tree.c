//
// Created by pvienne on 03/11/15.
//

#include "tree.h"

TREE tree_create(int value, TREE left, TREE right) {
    TREE new_tree = (TREE) malloc(sizeof(LEAF));
    new_tree->value = value;
    new_tree->left = left;
    new_tree->right = right;
    return new_tree;
}