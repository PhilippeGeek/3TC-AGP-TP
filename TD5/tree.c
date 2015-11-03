//
// Created by pvienne on 03/11/15.
//

#include <stdlib.h>
#include <stdio.h>

#include "tree.h"


int tree_depth_internal(TREE, int count);

int tree_depth(TREE t) {
    if (t == NULL) {
        return 0;
    }
    return tree_depth_internal(t, 1);
}

int tree_depth_internal(TREE t, int count) {
    if (t->left == NULL && t->right == NULL) {
        return count;
    } else {
        if (t->left != NULL && t->right != NULL) {
            int depthLeft = tree_depth_internal(t->left, count + 1);
            int depthRight = tree_depth_internal(t->right, count + 1);

            return depthLeft > depthRight ? depthLeft : depthRight;
        }
        else if (t->left != NULL) {
            return tree_depth_internal(t->left, count + 1);
        }
        else {
            return tree_depth_internal(t->right, count + 1);
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

void tree_add(TREE tree, int value) {
    if (tree == NULL) {
        fprintf(stderr, "\nCan not add a value on a null TREE !\n");
        return;
    }
    TREE *good_side = value < tree->value ? &(tree->left) : &(tree->right);
    if ((*good_side) == NULL) {
        (*good_side) = tree_create(value, NULL, NULL);
    } else {
        tree_add((*good_side), value);
    }
}

void tree_print_travel(TREE tree, int level) {

    int i;
    for (i = 0; i < level; i++)
        printf("-");

    printf("%d\n", tree->value);

    if (tree->left != NULL) {
        tree_print_travel(tree->left, level + 1);
    }

    if (tree->right != NULL) {
        tree_print_travel(tree->right, level + 1);
    }

    printf("\n");
}

int tree_is_balanced(TREE tree) {
    int depthLeft = tree_depth(tree->left);
    int depthRight = tree_depth(tree->right);
    int difference = abs(depthLeft - depthRight);

    if (difference != 0 && difference != 1) {
        return 0;
    } else {
        if (tree->left != NULL && tree->right != NULL) {
            return tree_is_balanced(tree->left) && tree_is_balanced(tree->right);
        }
        else if (tree->left != NULL) {
            return tree_is_balanced(tree->left);
        }
        else if (tree->right != NULL) {
            return tree_is_balanced(tree->right);
        }
        else {
            return 1;
        }
    }
}

void tree_print(TREE tree) {
    tree_print_travel(tree, 0);
}