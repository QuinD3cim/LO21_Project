#include "fonction.h"


/* Fonctions */

/* Fonctions regles */

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

void viderBuffer(){
    int c=0;
    while((c!='\n')&&(c!=EOF)){
        c=getchar();
    }
}

int lire(char* Buffer){
    char* positionEntree = NULL;
    viderBuffer();
    /* On lit le texte saisi au clavier */

    if(fgets(Buffer,TAILLE_PHRASE_MAX,stdin)!=NULL){ /* Pas d'erreur de saisie ? (Buffer de 100 caractères) */
        positionEntree = strchr(Buffer,'\n'); /* On recherche "l'Entrée" */
        if(positionEntree != NULL){ /* si on a trouvé le retour à la ligne */
            *positionEntree='\0'; /* On remplace ce caractère par \0 */
        } else {
            viderBuffer();
        }
        return EXIT_SUCCESS; /* On renvoie 1 si la fonction s'est déroulé sans erreur */
    } else{
        viderBuffer();
        return EXIT_FAILURE;
    }
}

regle creer_regle(){
    regle r;
    r.premisses = NULL;
    r.conclusion = NULL;
    return r;
}

regle inserer_conclusion(regle r){
    r.conclusion = (char*) malloc(sizeof(char)*TAILLE_PHRASE_MAX);
    if(lire(r.conclusion)!=EXIT_SUCCESS){
        return r;
    } else{
        free(r.conclusion);
        return r;
    }
}




regle supprimer_premisse(regle r,char* intitule_premisse){
    liste* copie_premisse;
    if(est_premisse_vide(r.premisses)==VRAI){
        return r;
    } else if(est_premisse_vide((r.premisses)->suivant)==VRAI){
        if(strcmp((r.premisses)->premisse,intitule_premisse) == 1){
            free((r.premisses)->premisse);
            (r.premisses)->premisse = NULL;
            return r;
        } else {
            return r;
        }
    } else {
        while((est_premisse_vide((r.premisses)->suivant)==FAUX) &&(strcmp(((r.premisses)->suivant)->premisse, intitule_premisse))){
            r.premisses = (r.premisses)->suivant;
        }
        if(est_premisse_vide((r.premisses)->suivant)==FAUX){
            copie_premisse = (r.premisses)->suivant;
            (r.premisses)->suivant = ((r.premisses)->suivant)->suivant;
            free(copie_premisse);

        }
    }
    return r;
}
 

liste* premisse_tete(regle r){
    return r.premisses;
}

/* Fonctions base de connaissance */

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