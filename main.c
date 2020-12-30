#include "fonction.h"

int main(int argc, char* argv[]){

    regleElem testRegle;
    testRegle.c = NULL;
    testRegle.p = NULL;
    regle test = &testRegle;
    char* texte = "A";

    Ajout_premisse(test,texte);

    printf("%s\n",test->p->cc);

    return EXIT_SUCCESS;
}