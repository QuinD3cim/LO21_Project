#include "moteur.h"

int main(int argc, char* argv[]){
    char* fichier_choisi = NULL;
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

    Write_bc(b, titre);

    ajouter_regle(b,r); 
    printf("La conclusion de la premiere regle de b est : %s\n",b->regle->conclusion);

    fichier_choisi = choix_base_de_connaissances();
    BC br = Read_bc(fichier_choisi);


    

    afficher_base_connaissances(br,fichier_choisi);
    
    

    return EXIT_SUCCESS;
}