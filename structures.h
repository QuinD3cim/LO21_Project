#ifndef STRUCTURES_HEADER
#define STRUCTURES_HEADER

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * \struct liste
 * \brief Liste chaînée de prémices : élément d'une règle
 */
typedef struct l{
  char* premice; /** \brief chaîne de caractères contenant l'intitulé d'une prémice */
  struct l* suivant; /** \brief pointeur sur l'élément suivant de la liste */
} liste;

/**
 * \struct regle
 * \brief Produit cartésien d'une liste de prémices et d'une conclusion
 */
typedef struct{
  liste* premices; /** \brief liste de premices */
  char* conclusion; /** \brief chaîne de caractère contenant l'intitulé d'une conclusion */
} regle;

/**
 * \struct connaissance
 * \brief élément d'une base de connaissance : liste de regle
 */
typedef struct bc_elem{
  regle* regle; /** \brief liste de regles */
  struct bc_elem* suivant; /** \brief pointeur sur l'élément suivant de la base de connaissances */
} connaissance;

/**
 * \struct BC
 * \brief liste de connaissances
 */
typedef connaissance* BC;





#endif