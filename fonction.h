#ifndef FONCTION_HEADER
#define FONCTION_HEADER


#include <stdio.h>
#include <stdlib.h> 
#include <string.h>


/* Types */

typedef struct elemP
{
    char* cc; /* nom de la prémisse */
    struct elemP* ps; /* prémisse suivant */
} premisse;

typedef struct
{
    premisse* p; /* prémisses */
    char* c; /* conclusion */
} regleElem;

typedef regleElem* regle;

typedef struct elemR 
{
    struct elemR* rp; /*règle précédente*/
    regle r; /* règle */
    struct elem* rs; /* règle suivante */
} bcElem;

typedef bcElem* bc;

typedef enum {
    TRUE = 1,
    FALSE = 0,
} bool;


/* Fonctions */

void Ajout_premisse(regle r, char* s);

bool Si_premisse(premisse* pp, char* s);

bool Pas_premisse(regle r);

char* Conclusion_regle(regle r);

bc Creer_base();

regle Regle_tete_base(bc b);


#endif