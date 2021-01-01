#ifndef STRUCTURES_HEADER
#define STRUCTURES_HEADER

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/* Types */

typedef enum {
    VRAI = 1,
    FAUX = 0,
} bool;

/**
 * \struct liste
 * \brief Liste chaînée de prémisses : élément d'une règle
 */
typedef struct l{
  char* premisse; /** \brief chaîne de caractères contenant l'intitulé d'une prémisse */
  struct l* suivant; /** \brief pointeur sur l'élément suivant de la liste */
} liste;

/**
 * \struct regle
 * \brief Produit cartésien d'une liste de prémisses et d'une conclusion
 */
typedef struct{
  liste* premisses; /** \brief liste de prémisses */
  char* conclusion; /** \brief chaîne de caractère contenant l'intitulé d'une conclusion */
} regleElem;

typedef regleElem* regle;

/**
 * \struct connaissance
 * \brief élément d'une base de connaissance : liste de regle
 */
typedef struct bc_elem{
  struct bc_elem* precedent; /** \brief pointeur sur l'élément precedent de la base de connaissances */
  regle* regle; /** \brief liste de regles */
  struct bc_elem* suivant; /** \brief pointeur sur l'élément suivant de la base de connaissances */
} connaissance;

/**
 * \struct BC
 * \brief liste de connaissances
 */
typedef connaissance* BC;


#endif