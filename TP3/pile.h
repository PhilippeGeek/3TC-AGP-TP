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

/////////////////////// Function for TD

/************************************************
* \brief  affiche l'erreur et quitte le programme
* \param message une chaine de caractère à afficher avant de quitter
**************************************************/
int error1(char *message);

/************************************************
* \brief  initialise une pile
**************************************************/
PILE InitPile();

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

#endif //TP2_PILE_H
