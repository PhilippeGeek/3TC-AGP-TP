//
// Created by pvienne on 03/11/15.
//

#include <stdlib.h>

#include "tree.h"

int tree_depth(TREE t, int count) {
    if (t->left == NULL && t->right == NULL) {
        return count;
    } else {
        if (t->left != NULL && t->right != NULL) {
            int depthLeft = tree_depth(t->left, count + 1);
            int depthRight = tree_depth(t->right, count + 1);

            return depthLeft > depthRight ? depthLeft : depthRight;
        }
        else if (t->left != NULL) {
            return tree_depth(t->left, count + 1);
        }
        else {
            return tree_depth(t->right, count + 1);
        }
    }
}

TREE tree_create(int value, TREE left, TREE right) {
    TREE new_tree = (TREE) malloc(sizeof(NODE));
    new_tree->value = value;
    new_tree->left = left;
    new_tree->right = right;
    return new_tree;
}