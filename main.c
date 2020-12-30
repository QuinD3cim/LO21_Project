#include "fonction.h"

int main(int argc, char* argv[]){

    regleElem testRegle;
    testRegle.c = (char*)malloc(sizeof(char)*3);
    testRegle.c = "Lol";
    testRegle.p = NULL;
    regle test = &testRegle;

    char* texte = "A";
    
    bc b = Creer_base();
    b->r = test;

    regle essai = Regle_tete_base(b);

    printf("%s\n",essai->c);

    Ajout_premisse(test,texte);
    
    printf("%d\n", Si_premisse(essai->p,texte));
    printf("%s\n",Conclusion_regle(essai));

    
    //printf("%s\n",Conclusion_regle(Regle_tete_base(b)));

    return EXIT_SUCCESS;
}