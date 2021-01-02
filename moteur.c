#include "moteur.h"

int menu(char* titre_menu, char** tableau_proposition){
    if(tableau_proposition[0] != NULL){
        int i = 0;
        char buffer[100];
        int reponse = -1;
        do{
            i=0;
            printf("\n%s\n", titre_menu);
            while(tableau_proposition[i] != NULL){
                printf("\n%s", tableau_proposition[i]);
                i++;
            }
            printf("\n\n Votre reponse :\t");
            scanf("%s", buffer);
        } while((sscanf(buffer,"%d",&reponse)==EOF)||(reponse > i)||(reponse <0));
        return reponse;
    }
    return -1;
}

char* choix_base_de_faits(){
    int index_base_de_faits = -1;
    struct dirent *dir;
    int iteration = 0;
    char** tableau_fichiers = NULL;
    tableau_fichiers;
    char* buffer_fichier;
    // opendir() renvoie un pointeur de type DIR. 
    DIR *d = opendir("base_de_faits");

    if (d != NULL){
        while ((dir = readdir(d)) != NULL){
            if(sscanf(dir->d_name,"bf_%s")!= EOF){
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
            printf("%s\n", dir->d_name);
        }
        closedir(d);
        index_base_de_faits = menu("Quelle base de faits voulez-vous choisir ?", tableau_fichiers);
        buffer_fichier = (char*) malloc(sizeof(char)*(strelen(tableau_fichiers[index_base_de_faits]+ 15)));
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
    tableau_fichiers;
    char* buffer_fichier;
    // opendir() renvoie un pointeur de type DIR. 
    DIR *d = opendir("base_de_connaissances"); 
    if (d != NULL){
        while ((dir = readdir(d)) != NULL){
            if(sscanf(dir->d_name,"bf_%s")!= EOF){
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
            printf("%s\n", dir->d_name);
        }
        closedir(d);
        index_base_de_connaissances = menu("Quelle base de connaissances voulez-vous choisir ?", tableau_fichiers);
        buffer_fichier = (char*) malloc(sizeof(char)*(strelen(tableau_fichiers[index_base_de_connaissances]+ 22)));
        buffer_fichier = strcpy(buffer_fichier,"base_de_connaissances\\");
        
        return strcat(buffer_fichier, tableau_fichiers[index_base_de_connaissances]);
    }
    return NULL;
}

