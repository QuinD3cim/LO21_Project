#include "fonction.h"


/* Fonctions */

    /* Fonctions regles */

void Ajout_premisse(regle r, char* s){

    if (r->premisses == NULL) /* Si la règle ne contient pas de prémisses */
    {
        /* Ajout de la prémisse en fin */
        r->premisses = (liste*) malloc (sizeof(liste));
        r->premisses->premisse = (char*) malloc (sizeof(char)*strlen(s));
        r->premisses->est_present = FAUX;
        r->premisses->premisse = s;
        r->premisses->suivant = NULL;
    } 
    else 
    {
        liste* indexP = r->premisses; /* On crée une variable pour parcourir les prémisses de r à laquelle on affecte la première prémisse de r*/
        while (indexP->suivant !=  NULL) /* Tant que le prochain prémisse est défini */
        {
            indexP = indexP->suivant; /* On défini la variable comme la prochaine prémisse */
        }
        /* Ajout de la prémisse en fin */
        indexP->suivant = (liste*) malloc (sizeof(liste));
        indexP->suivant->premisse = (char*) malloc (sizeof(char)*strlen(s));
        indexP->est_present = FAUX;
        indexP->suivant->premisse = s;
        indexP->suivant->suivant = NULL;
    }
    
}

liste* Ajout_premisse_liste(liste* l, char* s){
    if (l == NULL) /* Si la règle ne contient pas de prémisses */
    {
        /* Ajout de la prémisse en fin */
        l = (liste*) malloc (sizeof(liste));
        l->premisse = (char*) malloc (sizeof(char)*strlen(s));
        l->est_present = FAUX;
        l->premisse = s;
        l->suivant = NULL;
    } 
    else 
    {
        liste* indexP = l; /* On crée une variable pour parcourir les prémisses de r à laquelle on affecte la première prémisse de r*/
        while (indexP->suivant !=  NULL) /* Tant que le prochain prémisse est défini */
        {
            indexP = indexP->suivant; /* On définit la variable comme la prochaine prémisse */
        }
        /* Ajout de la prémisse en fin */
        indexP->suivant = (liste*) malloc (sizeof(liste));
        indexP->suivant->premisse = (char*) malloc (sizeof(char)*strlen(s));
        indexP->est_present = FAUX;
        indexP->suivant->premisse = s;
        indexP->suivant->suivant = NULL;
    }
    return l;
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
    regle r = (regle) malloc(sizeof(regleElem));
    r->premisses = NULL;
    r->conclusion = NULL;
    return r;
}

regle inserer_conclusion(regle r, char* c_conclusion){
    r->conclusion = (char*) malloc(sizeof(char)*strlen(c_conclusion));
    r->conclusion = strcpy(r->conclusion, c_conclusion);
    return r; 
}

regle supprimer_premisse(regle r,char* intitule_premisse){
    liste* copie_premisse;

    if(Pas_premisse(r)==VRAI){
        return r;
    } 
    else if (strcmp(r->premisses->premisse,intitule_premisse) == 0)
    {
        copie_premisse = r->premisses;
        r->premisses = r->premisses->suivant;
        free(copie_premisse);
    } 
    else 
    {
        liste* indexP = r->premisses;
        while((indexP->suivant != NULL) && (strcmp((indexP->suivant)->premisse, intitule_premisse) != 0)){
            indexP = indexP->suivant;
        }
        if(indexP->suivant != NULL){
            copie_premisse = indexP->suivant;
            indexP->suivant = (indexP->suivant)->suivant;
            free(copie_premisse);
        }
        else
        {
            free(indexP->suivant);
            indexP->suivant = NULL;
        }
        
    }
    return r;
}

liste* trouver_premisse(regle r,char* intitule_premisse){

    if(Pas_premisse(r)==VRAI){
        return NULL;
    }
    else if (strcmp(r->premisses->premisse,intitule_premisse) == 0)
    {
        return r->premisses;
    } 
    else 
    {
        liste* indexP = r->premisses;
        while((indexP->suivant != NULL) && (strcmp((indexP->suivant)->premisse, intitule_premisse) != 0)){
            indexP = indexP->suivant;
        }
        if(indexP->suivant != NULL){
            return (indexP->suivant);
        }
        else
        {
            return NULL;
        }
        
    }
}

liste* premisse_tete(regle r){
    return r->premisses;
}

    /* Fonctions base*/

BC Creer_base(){
    BC b = (BC) malloc(sizeof(connaissance));
    b->precedent = NULL;
    b->suivant = NULL;
    b->regle = NULL;
    return b;
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

BC ajouter_regle(BC base, regle r){
    if(base->regle == NULL){
        base->precedent = NULL;
        base->regle = r;
        base->suivant = NULL;
        return base;
    } 
    else
    {
        BC nouvelle_connaissance = Creer_base();
        nouvelle_connaissance->regle = r;
        nouvelle_connaissance->suivant = NULL;

        BC indexB = base;

        while(indexB->suivant != NULL){
            indexB = indexB->suivant;
        }
        nouvelle_connaissance->precedent = indexB;
        indexB->suivant = nouvelle_connaissance;
        return base;
    }
}


    /* Fonctions menu */

void afficher_premisses(liste* l){
    if(l != NULL){
        printf("\n\t%s",l->premisse);
        afficher_premisses(l->suivant);
    }
}

void afficher_base_de_faits(liste* l, char* nom_base_de_faits){
    printf("\nLa base de faits : %s\n", nom_base_de_faits);
    afficher_premisses(l);    
}

void afficher_regle(regle r){
    afficher_premisses(r->premisses);
    printf("\n\n\t\tConclusion : %s", r->conclusion);
}

void afficher_base_connaissances(BC base, char* nom_base_connaissances){
    int i = 1;
    BC copie_base = base;
    if(nom_base_connaissances !=NULL){
        printf("\n%s",nom_base_connaissances);
        while((copie_base != NULL)&&(copie_base->regle != NULL)&&(copie_base->regle->premisses != NULL)){
            printf("\n\n\tRegle no %d\n",i);
            afficher_regle(copie_base->regle);
            copie_base = copie_base->suivant;
            i++;
        }
    }
}

    /* Fonctions pour les fichiers */

void Write_bc(BC b, char* bcName){

    FILE* f;
    
    /*creating the file name*/
    char* fileName = (char*) malloc (sizeof(char)*(7+strlen(bcName)));
    strcpy(fileName,"BC_");
    strcat(fileName,bcName);
    strcat(fileName,".txt"); 
    
    /*opening the file*/
    f = fopen(fileName,"w");
    
    /*writing the rules in the file*/
    char line[100] = "";
    regle r;
    liste* p;
    BC indexB = b;
    bool end;
    if(b != NULL || b->regle != NULL) /* if base is not null or b has a rule */
    {
        do
        {
            end = VRAI;
            r = indexB->regle; /* r is the rule of the base */
            p = r->premisses; /* p is a premisse of the rule r */
            if (Pas_premisse(r) == FAUX) /* if there is at least one premisse */
            {   
                /* creating the line to add */       
                while (p->suivant != NULL)
                {
                    strcat(line,p->premisse);
                    strcat(line,"+");
                    p = p->suivant;
                }
                strcat(line,p->premisse);
                strcat(line,"=");
                strcat(line,Conclusion_regle(r));
                strcat(line,"\n");
                fputs(line,f); /* adding the line in the file */
            }
            if (indexB->suivant != NULL) /* selecting the next rule if the actual isn't the last and say to continue */
            {
                indexB = indexB->suivant;
                end = FAUX;
                strcpy(line,"");
            }
        } while(end == FAUX); /* while we don't say to end it */
    }
    fclose(f);
    printf("Le fichier %s est cree.\n",fileName);

}

BC Read_bc(char* fileName){

    /* open the file */
    FILE* f;
    f = fopen(fileName,"r");

    BC b = Creer_base(); /* Base we return */
    regle r = creer_regle(); /* rule to add in the base */
    BC indexB = b;

    int ch; /* read character */
    char line[TAILLE_PHRASE_MAX] = ""; /* get characters put together */
    char* element = NULL; /* the element to put in the rule */
    int i = 0; /* place to put ch in line */
    while ((ch = fgetc(f)) != EOF) /* Do until we get to the end of the file */
    {
        if (ch == '+' || ch == '=')
        {
            /* writing the final phrase in element */
            element = (char*) malloc (sizeof(char)*strlen(line));
            strcpy(element,line);
            /* Adding the premisse */
            Ajout_premisse(r,element);
            /* reset line to make new phrase */
            memset(line,0,TAILLE_PHRASE_MAX);
            i=0;
        }
        else if (ch == '\n') /* if we get the end of a line */
        {
            /* writing the final phrase in element */
            element = (char*) malloc (sizeof(char)*strlen(line));
            strcpy(element,line);
            /* Adding the premisse */
            inserer_conclusion(r,element);
            /* reset line to make new phrase */
            memset(line,0,TAILLE_PHRASE_MAX);
            i=0;
            /* Adding the rule to the base */
            ajouter_regle(indexB,r);
            /* create the next rule */
            indexB->suivant = Creer_base();
            indexB = indexB->suivant;
            /* creating a new rule */
            r = creer_regle();
        }
        else
        {
            line[i] = ch;
            i++;
        }
    }
    fclose(f);
    free(indexB->suivant);
    indexB->suivant = NULL;
    return b;

}

void Write_bf(liste* b, char* bcName){

    FILE* f;
    
    /*creating the file name*/
    char* fileName = (char*) malloc (sizeof(char)*(7+strlen(bcName)));
    strcpy(fileName,"BF_");
    strcat(fileName,bcName);
    strcat(fileName,".txt"); 
    
    /*opening the file*/
    f = fopen(fileName,"w");
    
    /*writing the premisses in the file*/
    char line[100] = "";
    char* p;
    liste* indexB = b;
    bool end;
    if(b != NULL || b->premisse != NULL) /* if base is not null or b has a premisse */
    {
        do
        {
            end = VRAI;
            p = (char*)malloc(sizeof(char)*strlen(indexB->premisse));
            strcpy(p,indexB->premisse); /* p is a premisse of the base */
            
            strcat(line,p);
            strcat(line,"\n");
            fputs(line,f); /* adding the line in the file */
            
            if (indexB->suivant != NULL) /* selecting the next rule if the actual isn't the last and say to continue */
            {
                indexB = indexB->suivant;
                end = FAUX;
                strcpy(line,"");
            }
        } while(end == FAUX); /* while we don't say to end it */
    }
    fclose(f);
    printf("Le fichier %s est cree.\n",fileName);

}

liste* Read_bf(char* fileName){

    /* open the file */
    FILE* f;
    f = fopen(fileName,"r");

    liste* b = (liste*) malloc(sizeof(liste)); /* Base we return */
    b->premisse = NULL;
    b->suivant = NULL;

    int ch; /* read character */
    char line[TAILLE_PHRASE_MAX] = ""; /* get characters put together */
    char* element = NULL; /* the element to put in the rule */
    int i = 0; /* place to put ch in line */

    while ((ch = fgetc(f)) != EOF) /* Do until we get to the end of the file */
    {
        if (ch == '\n') /* if we get the end of a line */
        {
            /* writing the final phrase in element */
            element = (char*) malloc (sizeof(char)*strlen(line));
            strcpy(element,line);
            if(b->premisse == NULL){
                strcpy(b->premisse,element);
            }
            else
            {
            /* Adding the premisse */
            Ajout_premisse_liste(b,element);
            }
            /* reset line to make new phrase */
            memset(line,0,TAILLE_PHRASE_MAX);
            i=0;
        }
        else
        {
            line[i] = ch;
            i++;
        }
    }
    fclose(f);
    return b;

}