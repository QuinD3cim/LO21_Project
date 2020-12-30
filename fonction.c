#include "fonction.h"


/* Fonctions */

void Ajout_premisse(regle r, char* P){

    /* créé la prémisse l */
    premisse l;
    l.cc = P;
    l.ps = NULL;

    if (r->p == NULL) /* Si la règle ne contient pas de prémisses */
    {
        r->p = &l; /* On ajoute l comme prémisse de la règle r  */
    } 
    else 
    {
        premisse* indexP = r->p; /* On crée une variable pour parcourir les prémisses de r à laquelle on affecte la première prémisse de r*/
        while (indexP->ps !=  NULL) /* Tant que le prochain prémisse est défini */
        {
            indexP = indexP->ps; /* On défini la variable comme la prochaine prémisse */
        }
        indexP->ps = &l; /* On défini la prochaine prémisse comme étant l */
    }
    
}