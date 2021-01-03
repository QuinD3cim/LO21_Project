#include "fonction.h"

int main(int argc, char* argv[]){

    regle r = creer_regle();
    char* c = (char*) malloc (sizeof(char)*10);
    c = "sauterelle";
    char* ex = (char*) malloc (sizeof(char)*12);
    ex = "exosquelette";
    char* ec = (char*) malloc (sizeof(char)*7);
    ec = "ecaille";
    char* i = (char*) malloc (sizeof(char)*7);
    i = "insecte";

    BC b = Creer_base();

    inserer_conclusion(r,c);

    printf("La premisse est vide : %d\n",Pas_premisse(r));

    printf("Ajout de %s\n",ec);
    Ajout_premisse(r,ec);
    printf("Ajout de %s\n",ex);
    Ajout_premisse(r,ex);
    printf("Ajout de %s\n",i);
    Ajout_premisse(r,i);

    printf("La premisse est vide : %d\n",Pas_premisse(r));

    printf("La premiere premisse est : %s\n",premisse_tete(r)->premisse);
    printf("La premisse %s est dedans : %d\n",i,Si_premisse(r->premisses,i));

    printf("Supprimer %s\n",ec);
    supprimer_premisse(r,ec);
    printf("La premisse %s est dedans : %d\n",ec,Si_premisse(r->premisses,ec));
    printf("La premiere premisse est : %s\n",premisse_tete(r)->premisse);
    printf("La premisse %s est dedans : %d\n",ex,Si_premisse(r->premisses,ex));

    printf("Ajout de %s\n",ec);
    Ajout_premisse(r,ec);
    printf("La premisse %s est dedans : %d\n",ec,Si_premisse(r->premisses,ec));

    printf("Supprimer %s\n",ec);
    supprimer_premisse(r,ec);
    printf("La premisse %s est dedans : %d\n",ec,Si_premisse(r->premisses,ec));

    printf("La conclusion est : %s\n",Conclusion_regle(r));

    ajouter_regle(b,r); 
    printf("La conclusion de la premiere regle de b est : %s\n",b->regle->conclusion);
    
    return EXIT_SUCCESS;
}