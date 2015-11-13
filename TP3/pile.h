//
// Created by pvienne on 16/10/15.
//

#ifndef TP2_PILE_H
#define TP2_PILE_H

struct STACK_ELEM {
    int val;
    struct STACK_ELEM *previous;
    struct STACK_ELEM *next;
};

typedef struct STACK_ELEM Element;
typedef Element *PILE;
typedef char boolean;

void insert_after(int value, PILE *pile, Element *after);

void insert_previous(int value, PILE *pile, Element *previous);

int first_value(PILE pile);

int last_value(PILE pile);

boolean is_pile_empty(PILE *pile);

Element *first_element(PILE pile);

Element *last_element(PILE pile);

/**
 * Add an element in the pile.
 */
void pile_push(PILE *pile, int val);

/**
 * Remove the last added element
 */
int pile_pop(PILE *pile);

void debug_pile(PILE *pile);

#endif //TP2_PILE_H
