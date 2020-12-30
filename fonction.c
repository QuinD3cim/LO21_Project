#include "fonction.h"


/* Fonctions */

void Ajout_premisse(regle r, char* s){

    /* créé la prémisse l */
    premisse l;
    l.cc = (char*) malloc (sizeof(char)*strlen(s)); 
    l.cc = s;
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

bool Si_premisse(premisse* pp, char* s){

    if (strcmp(pp->cc,s)==0) /* Sinon si le texte de la prémisse correspond à la prémisse recherchée*/
    {
        return TRUE; 
    }
    else if (pp->ps == NULL) /* Sinon s'il n'y a pas de prémisse suivante */
    {
        return FALSE;
    }
    else /* S'il y a une prémisse suivante */
    {
        printf("D\n");
        return FALSE + Si_premisse(pp->ps,s);
    } 

}

bool Pas_premisse(regle r){

    if (r->p == NULL) /* S'il n'y a pas de premisse */
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}

char* Conclusion_regle(regle r){

    if (r->c == NULL)
    {
        printf("Erreur : Cette règle n'a pas de conclusion.\n");
        return "error c not found";
    }
    else
    {
        return r->c;
    }

}

bc Creer_base(){
    bcElem b;
    b.r = NULL;
    b.rp = NULL;
    b.rp = NULL;
    bc base = &b;
    return base;
}

regle Regle_tete_base(bc b){

    if (b == NULL)
    {
        return NULL;
    }
    else if (b->rp == NULL)
    {
        return b->r;
    }
    else
    {
        bc indexB = b;
        while (indexB->rp != NULL)
        {
            indexB = indexB->rp;
        }
        return indexB->r;
    }

}