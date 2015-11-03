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

typedef struct tree_model LEAF;
typedef LEAF *TREE;

TREE tree_create(int value, TREE left, TREE right);

#endif //INC_3TC_AGP_TP_TREE_H
