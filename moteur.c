#include "moteur.h"


int menu(char* titre_menu, char** tableau_proposition){
    if(tableau_proposition[0] != NULL){
        int i;
        char buffer[100];
        int reponse = -1;
        do{
            i=0;
            printf("\n%s\n", titre_menu);
            while(tableau_proposition[i] != NULL){
                printf("\n%d : %s", i,  tableau_proposition[i]);
                i++;
            }
            printf("\n\n Votre reponse :\t");
            scanf("%s", buffer);
        } while((sscanf(buffer,"%d",&reponse)==EOF)||(reponse > i-1)||(reponse <0));
        return reponse;
    }
    return -1;
}

char* choix_base_de_faits(){
    int index_base_de_faits = -1;
    struct dirent *dir;
    int iteration = 0;
    char** tableau_fichiers = NULL;
    char* buffer_fichier;
    // opendir() renvoie un pointeur de type DIR. 
    DIR *d = opendir("base_de_faits");

    if (d != NULL){
        while ((dir = readdir(d)) != NULL){
            if(strstr(dir->d_name,"bf_")!= NULL){
                buffer_fichier =(char*) malloc(sizeof(char)*strlen(dir->d_name));
                buffer_fichier = strcpy(buffer_fichier, dir->d_name);

                if(tableau_fichiers == NULL){
                    tableau_fichiers = (char**) malloc(sizeof(char*));
                } else{
                    tableau_fichiers = realloc(tableau_fichiers, sizeof(char*)*(iteration+1));
                }

                tableau_fichiers[iteration] = (char*) malloc(sizeof(char)*strlen(buffer_fichier));
                tableau_fichiers[iteration] = strcpy(tableau_fichiers[iteration],buffer_fichier);
                tableau_fichiers[iteration + 1] = NULL;

                iteration++;
                free(buffer_fichier);
            }
        }
        closedir(d);
        index_base_de_faits = menu("Quelle base de faits voulez-vous choisir ?", tableau_fichiers);
        buffer_fichier = (char*) malloc(sizeof(char)*(strlen(tableau_fichiers[index_base_de_faits]+ 15)));
        buffer_fichier = strcpy(buffer_fichier,"base_de_faits\\");
        
        return strcat(buffer_fichier, tableau_fichiers[index_base_de_faits]);
    }
    return NULL;
}


char* choix_base_de_connaissances(){
    int index_base_de_connaissances = -1;
    struct dirent *dir;
    int iteration = 0;
    char** tableau_fichiers = NULL;
    char* buffer_fichier;
    // opendir() renvoie un pointeur de type DIR. 
    DIR *d = opendir("base_de_connaissances"); 
    if (d != NULL){
        while ((dir = readdir(d)) != NULL){
            if(strstr(dir->d_name,"bc_")!= NULL){
                buffer_fichier =(char*) malloc(sizeof(char)*strlen(dir->d_name));
                buffer_fichier = strcpy(buffer_fichier, dir->d_name);

                if(tableau_fichiers == NULL){
                    tableau_fichiers = (char**) malloc(sizeof(char*));
                } else{
                    tableau_fichiers = realloc(tableau_fichiers, sizeof(char*)*(iteration+1));
                }

                tableau_fichiers[iteration] = (char*) malloc(sizeof(char)*strlen(buffer_fichier));
                tableau_fichiers[iteration] = strcpy(tableau_fichiers[iteration],buffer_fichier);
                tableau_fichiers[iteration + 1] = NULL;

                iteration++;
                free(buffer_fichier);
            }
        }
        closedir(d);
        index_base_de_connaissances = menu("Quelle base de connaissances voulez-vous choisir ?", tableau_fichiers);
        buffer_fichier = (char*) malloc(sizeof(char)*(strlen(tableau_fichiers[index_base_de_connaissances]+ 22)));
        buffer_fichier = strcpy(buffer_fichier,"base_de_connaissances\\");
        
        return strcat(buffer_fichier, tableau_fichiers[index_base_de_connaissances]);
    }
    return NULL;
}

liste* moteur_inference(liste* base_de_faits,BC base_de_connaissances ){
    liste* copie_bf;
    BC copie_bc;
    liste* copie_liste_premisses;
    bool premisse_en_plus;
    do{
        premisse_en_plus = FAUX;
        copie_bf = base_de_faits;
        /* Première phase : on scanne la base de connaissances pour savoir quelles propositions de la base de faits lui appartiennent */
        while ((copie_bf != NULL)&&(copie_bf->premisse != NULL)){
            copie_bc = base_de_connaissances;

            while((copie_bc != NULL)&&(copie_bc->regle)&&(copie_bc->regle->premisses != NULL)){
                copie_liste_premisses = copie_bc->regle->premisses;
                
                if(Si_premisse(copie_liste_premisses,copie_bf->premisse) == VRAI){
                    trouver_premisse(copie_bc->regle,copie_bf->premisse)->est_present = VRAI;
                }

                copie_liste_premisses = copie_liste_premisses->suivant;
                copie_bc = copie_bc->suivant;
            }

            copie_bf = copie_bf->suivant;
        }

        /* Deuxième phase : on ajoute les conclusions à la base de faits en fonction des regles qui n'ont que des prémisses vraies */
        copie_bf = base_de_faits;
        copie_bc = base_de_connaissances;

        while((copie_bc->suivant != NULL)&&(copie_bc->suivant->regle != NULL)&&(copie_bc->suivant->regle->conclusion != NULL)){
            copie_liste_premisses = copie_bc->regle->premisses;
            
            while((copie_liste_premisses != NULL)&&(copie_liste_premisses->est_present==VRAI)){
                
                copie_liste_premisses = copie_liste_premisses->suivant;
            }

            if((copie_liste_premisses == NULL)&&(Si_premisse(base_de_faits,copie_bc->regle->conclusion)==FAUX)){
                base_de_faits = Ajout_premisse_liste(base_de_faits,copie_bc->regle->conclusion);
                premisse_en_plus = VRAI;
            }
            copie_bc = copie_bc->suivant;
        }
    } while(premisse_en_plus);

    return base_de_faits;
}