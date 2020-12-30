#ifndef FONCTION_HEADER
#define FONCTION_HEADER


#include <stdio.h>
#include <stdlib.h> 


/* Types */

typedef struct elem
{
    char* cc; /* nom de la prémisse */
    struct elem* ps; /* prémisse suivant */
} premisse;

typedef struct
{
    premisse* p; /* prémisses */
    char* c; /* conclusion */
} regleElem;

typedef regleElem* regle;


/* Fonctions */

void Ajout_premisse(regle r, char* P);



#endif