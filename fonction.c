#include "fonction.h"


/* Fonctions */

/* Fonctions regles */

void Ajout_premisse(regle r, char* s){

    /* créé la prémisse l */
    liste l;
    l.premisse = (char*) malloc (sizeof(char)*strlen(s)); 
    l.premisse = s;
    l.suivant = NULL;

    if (r->premisses == NULL) /* Si la règle ne contient pas de prémisses */
    {
        r->premisses = &l; /* On ajoute l comme prémisse de la règle r  */
    } 
    else 
    {
        liste* indexP = r->premisses; /* On crée une variable pour parcourir les prémisses de r à laquelle on affecte la première prémisse de r*/
        while (indexP->suivant !=  NULL) /* Tant que le prochain prémisse est défini */
        {
            indexP = indexP->suivant; /* On défini la variable comme la prochaine prémisse */
        }
        indexP->suivant = &l; /* On défini la prochaine prémisse comme étant l */
    }
    
}

bool Si_premisse(liste* pp, char* s){

    if (strcmp(pp->premisse,s)==0) /* Sinon si le texte de la prémisse correspond à la prémisse recherchée*/
    {
        return VRAI; 
    }
    else if (pp->suivant == NULL) /* Sinon s'il n'y a pas de prémisse suivante */
    {
        return FAUX;
    }
    else /* S'il y a une prémisse suivante */
    {
        printf("D\n");
        return FAUX + Si_premisse(pp->suivant,s);
    } 

}

bool Pas_premisse(regle r){

    if (r->premisses == NULL) /* S'il n'y a pas de premisse */
    {
        return VRAI;
    }
    else
    {
        return FAUX;
    }

}

char* Conclusion_regle(regle r){

    if (r->conclusion == NULL)
    {
        printf("Erreur : Cette règle n'a pas de conclusion.\n");
        return "error c not found";
    }
    else
    {
        return r->conclusion;
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
    regleElem r;
    r.premisses = NULL;
    r.conclusion = NULL;
    regle nr = &r;
    return nr;
}

regle inserer_conclusion(regle r){
    r->conclusion = (char*) malloc(sizeof(char)*TAILLE_PHRASE_MAX);
    if(lire(r->conclusion)!=EXIT_SUCCESS){
        return r;
    } else{
        free(r->conclusion);
        return r;
    }
}




regle supprimer_premisse(regle r,char* intitule_premisse){
    liste* copie_premisse;
    if(est_premisse_vide(r->premisses)==VRAI){
        return r;
    } else if(est_premisse_vide((r->premisses)->suivant)==VRAI){
        if(strcmp((r->premisses)->premisse,intitule_premisse) == 1){
            free((r->premisses)->premisse);
            (r->premisses)->premisse = NULL;
            return r;
        } else {
            return r;
        }
    } else {
        while((est_premisse_vide((r->premisses)->suivant)==FAUX) &&(strcmp(((r->premisses)->suivant)->premisse, intitule_premisse))){
            r->premisses = (r->premisses)->suivant;
        }
        if(est_premisse_vide((r->premisses)->suivant)==FAUX){
            copie_premisse = (r->premisses)->suivant;
            (r->premisses)->suivant = ((r->premisses)->suivant)->suivant;
            free(copie_premisse);

        }
    }
    return r;
}
 

liste* premisse_tete(regle r){
    return r->premisses;
}

/* Fonctions base de connaissance */

BC Creer_base(){
    connaissance b;
    b.precedent = NULL;
    b.suivant = NULL;
    b.regle = NULL;
    BC base = &b;
    return base;
}

regle Regle_tete_base(BC b){

    if (b == NULL)
    {
        return NULL;
    }
    else if (b->precedent == NULL)
    {
        return b->regle;
    }
    else
    {
        BC indexB = b;
        while (indexB->precedent != NULL)
        {
            indexB = indexB->precedent;
        }
        return indexB->regle;
    }

}