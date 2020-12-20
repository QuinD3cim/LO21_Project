#include "fonction.h"



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
