#include "moteur.h"

int main(int argc, char* argv[]){
    char* fichier_choisi = NULL;
    liste* bf_dauphin = NULL;   
    
    regle r = creer_regle();
    char* c = (char*) malloc (sizeof(char)*10);
    c = "sauterelle";
    char* ex = (char*) malloc (sizeof(char)*12);
    ex = "exosquelette";
    char* ec = (char*) malloc (sizeof(char)*7);
    ec = "ecaille";
    char* i = (char*) malloc (sizeof(char)*7);
    i = "insecte";

    regle re = creer_regle();

    BC b = Creer_base();

    inserer_conclusion(r,c);
    inserer_conclusion(re,i);

    printf("Ajout de %s\n",ec);
    Ajout_premisse(re,ex);
    Ajout_premisse(r,ec);
    Ajout_premisse(re,ec);
    printf("Ajout de %s\n",ex);
    Ajout_premisse(r,ex);
    printf("Ajout de %s\n",i);
    Ajout_premisse(r,i);


    ajouter_regle(b,r);
    ajouter_regle(b,re);

    printf("La conclusion de la premiere regle de b est : %s\n",Regle_tete_base(b)->conclusion);
    printf("La conclusion de la deuxieme regle de b est : %s\n",b->suivant->regle->conclusion);

    char* titre = (char*) malloc (sizeof(char)*7);
    titre = "animaux";

    printf("excriture du fichier\n");
    Write_bc(b, titre);
    free(b);
 
    printf("La conclusion de la premiere regle de b est : %s\n",b->regle->conclusion);

    printf("choix fichier\n");
    fichier_choisi = choix_base_de_connaissances();
    printf("%s\n",fichier_choisi);
    printf("Lecture du fichier...\n");
    BC br = Read_bc(fichier_choisi);
    printf("Fichier lu !\n");

    printf("Afficher BC :\n");
    afficher_base_connaissances(br,fichier_choisi);
    printf("\n\n\nFonctionnement moteur d'inférence");
    afficher_base_de_faits(bf_dauphin,"Base de faits du dauphin");
    
    bf_dauphin = moteur_inference(bf_dauphin,br);
    afficher_base_de_faits(bf_dauphin,"Base de faits du dauphin");

    Write_bf(bf_dauphin, "dauphin");
    liste* test = Read_bf("BF_dauphin.txt");
    afficher_base_de_faits(test,"Dauphin");
    printf("\n\nend");

    return EXIT_SUCCESS;
}