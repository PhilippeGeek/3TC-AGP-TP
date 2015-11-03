//
// Created by pvienne on 03/11/15.
//

#ifndef INC_3TC_AGP_TP_TREE_H
#define INC_3TC_AGP_TP_TREE_H

struct tree_model {
    int value;
    struct tree_model *right;
    struct tree_model *left;
};

typedef struct tree_model NODE;
typedef NODE *TREE;

int tree_depth_internal(TREE, int count);

int tree_depth(TREE t);

void tree_add(TREE tree, int value);

TREE tree_create(int value, TREE left, TREE right);

void tree_print(TREE tree);

#endif //INC_3TC_AGP_TP_TREE_H
