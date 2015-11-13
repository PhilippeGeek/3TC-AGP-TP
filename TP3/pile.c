//
// Created by pvienne on 16/10/15.
//

#include <stdlib.h>
#include <stdio.h>
#include "pile.h"

boolean is_pile_empty(PILE *pile) {
    return *pile == NULL;
}

/**
 * Add an element in the pile.
 */
void pile_push(PILE *pile, int val) {
    if (is_pile_empty(pile)) {
        Element *element = (Element *) malloc(sizeof(Element));
        element->val = val;
        *pile = element;
        return;
    }
    Element *firstElement = first_element(*pile);
    if (firstElement->val < val) {
        perror("Stack error, can not be grather than the top element !");
        exit(1);
    }
    Element *element = (Element *) malloc(sizeof(Element));
    element->val = val;
    element->next = firstElement->next;
    firstElement->previous = element;
}

/**
 * Remove the last added element
 */
int pile_pop(PILE *pile) {
    if (is_pile_empty(pile)) {
        perror("Pile is empty !");
        return -1;
    }
    Element *element = first_element(*pile);
    int value = element->val;
    if (element->next != NULL)
        element->next->previous = NULL;
    else
        *pile = NULL;
    free(element);
    return value;
}

void debug_pile(PILE *pile) {
    printf("\n== DEBUG PILE %p ==\nValues: ", pile);
    if (*pile == NULL) {
        printf("empty\n");
        return;
    }
    Element *current = first_element(*pile);
    do {
        printf("%d", current->val);
        if (current->next != NULL) {
            printf(", ");
        }
    } while (current->next != NULL);
    printf("\n");
}

int first_value(PILE pile) {
    return first_element(pile)->val;
}

int last_value(PILE pile) {
    return last_element(pile)->val;
}

Element *first_element(PILE pile) {
    Element *element = pile;
    if (element == NULL) {
        perror("Can not get element from a null pile");
        exit(1);
    }
    while (element->previous != NULL) {
        element = element->previous;
    }
    return element;
}

Element *last_element(PILE pile) {
    Element *element = pile;
    if (element == NULL) {
        perror("Can not get element from a null pile");
        exit(1);
    }
    while (element->next != NULL) {
        element = element->next;
    }
    return element;
}

int error1(char *message) {
    perror(message);
    exit(1);
}