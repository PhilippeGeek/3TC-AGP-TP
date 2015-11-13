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

PILE **InitPile() {
    PILE **pile = malloc(3 * sizeof(PILE **));
    int i = 4;
    do {
        pile_push(pile, i);
        i--;
    } while (i > 0);
    return pile;
}

/************************************************
* \brief     ajoute l'élément elem au sommet de la pile pointée par ppile
* \param ppile un pointeur vers la pile
* \param elem L'élément à rajouter au sommet de pile
* \pre Precondition: ppile pointe sur une pile valide
* \post Postcondition: La pile pointée par ppile a été modifiée:
          un élément de valeur elem a été rajouté au sommet de pile.
* \result La fonction renvoie 0 si aucune erreur n'est intervenue
**************************************************/
int Empiler(PILE *, int);


/************************************************
* \brief    Retire l'element du sommet de la pile pointée par ppile et renvoie
   sa valeur.
* \param ppile un pointeur vers la pile
* \pre Precondition: ppile pointe sur une pile valide
* \post Postcondition: La pile pointée par ppile a été modifiée: son premier
          élément a été supprimé (le deuxième élément est donc devenu
	  le sommet de pile).
* \result Le résultat de la fonction est la
	  valeur de l'élément supprimé si aucune erreur n'est intervenue
* \remark    Si la pile pointé par ppile est vide, la fonction affiche une erreur et interrompt le programme.
**************************************************/
int Depiler(PILE *);

/************************************************
* \brief affiche une pile d'entier
* \param liste une liste d'entier
**************************************************/
void afficherPile(PILE pile);