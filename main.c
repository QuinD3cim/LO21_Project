#include "moteur.h"

int main(int argc, char* argv[]){
    /*char* fichier_choisi = NULL;
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

    char* titre = (char*) malloc (sizeof(char)*6);
    titre = "animal";

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
    
    bf_dauphin = Read_bf("./base_de_faits/bf_dauphin.txt");
    bf_dauphin = moteur_inference(bf_dauphin,br);
    afficher_base_de_faits(bf_dauphin,"Base de faits du dauphin");

    Write_bf(bf_dauphin, "dauphin");
    liste* test = Read_bf("./base_de_faits/bf_dauphin.txt");
    afficher_base_de_faits(test,"Dauphin");
    printf("\n\nend");*/

    /* Affichage menu principal */
    while (VRAI)
    {
        int choice = menu_principal();
        switch (choice)
        {
        case 0: /* Si on veut creer bc */
            BC base = Creer_base();
            int quit = 0;
            do
            {
                choice = menu_creer_bc();
                
                switch (choice)
                {
                case 0:
                    
                    /* conclusion de la regle */
                    regle r = creer_regle()
                    char ccl[TAILLE_PHRASE_MAX];
                    do{
                        printf("Entrez la conclusion de la regle :\n");
                        scanf("%s",ccl);
                    }while(lire(&ccl) == 1)
                    inserer_conclusion(r,ccl);

                    /* premisses de la regle */
                    int nb = 0;
                    char buffer[TAILLE_PHRASE_MAX];
                    do
                    {
                        printf("Combien de premisses voulez vous ajouter ?\n")
                        scanf("%s",buffer);
                    } while ((sscanf(buffer,"%d",&nb)==EOF)||(ccl < 0));
                    char premisse[TAILLE_PHRASE_MAX];
                    for (int i = 0; i < nb; i++)
                    {
                        do{
                            printf("Entrez le nom de la premisse %d :\n",i);
                            scanf("%s",premisse);
                        }while(lire(&ccl) == 1)
                        Ajout_premisse(r,premisse);
                        free(r);
                    }
                    
                    ajouter_regle(base,r);
                    printf("La regle a ete ajoute.\n");
                    quit = 0;
                    break;
                
                case 1:
                    if (base != NULL)
                    {
                        char ccl[TAILLE_PHRASE_MAX];
                        do{
                            printf("Entrez la nouvelle conclusion de la regle :\n");
                            scanf("%s",ccl);
                        }while(lire(&ccl) == 1)
                        inserer_conclusion(r,ccl);
                    }
                    else
                    {
                        printf("Il n'y a pas de regle à modifier !\n")
                    }
                    
                    quit = 0;
                    break;
                
                case 2:
                    if (base != NULL)
                    {
                        afficher_base_connaissances(base);
                        BC indexB = base;
                        bool found = FAUX;
                        char premisse[TAILLE_PHRASE_MAX];

                        do{
                            printf("Entrez la conclusion de la regle ou l'on ajoute la premisse :\n");
                            scanf("%s",premisse);
                        }while(lire(&premisse) == 1)

                        while(indexB->suivant != NULL && found == FAUX){
                            if (strcmp(Conclusion_regle(Regle_tete_base(indexB),premisse) != 1)
                            {
                                found = VRAI;
                                regle r = indexB->regle;
                            }
                            indexB = indexB->suivant;                            
                        }
                        if (found == FAUX)
                        {
                            printf("Cette premisse n'existe pas.\n")
                        }
                        else
                        {
                            do{
                                printf("Entrez le nom de la premisse %d :\n",i);
                                scanf("%s",premisse);
                            }while(lire(&premisse) == 1)
                            Ajout_premisse(r,premisse);
                            free(r);
                            
                        }
                        
                    }
                    else
                    {
                        printf("Il n'y a pas de regle à modifier !\n")
                    }
                    
                    quit = 0;
                    free(indexB);
                    break;

                case 3:
                    afficher_base_connaissances(base);
                    quit = 0;
                    break;
                
                case 4:
                    char nom[TAILLE_PHRASE_MAX];
                    do{
                        printf("Entrez le nom de la base de connaissance %d :\n",i);
                        scanf("%s",nom);
                    }while(lire(&nom) == 1)
                    Write_bc(base,&nom);
                    printf("fichier enregistre.\n");
                    quit = 1;
                    break;
                case 5:
                    quit = 1;
                    break; 
                }

            } while (quit == 0);
            break;

        case 1:
            int base_choisie = 1;
            printf("Choisissez le fichier à lire : \n");
            char *fichier_choisi = choix_base_de_connaissances();
            printf("Lecture du fichier...\n");
            BC bc = Read_bc(fichier_choisi);
            afficher_base_connaissances(bc);
            break;
        case 2:
            if(base_choisie == 1)
            {
                int quit = 0;
                do
                {
                    choice = menu_modifier_bc();
                    
                    switch (choice)
                    {
                    case 0:
                        
                        /* conclusion de la regle */
                        regle r = creer_regle()
                        char ccl[TAILLE_PHRASE_MAX];
                        do{
                            printf("Entrez la conclusion de la regle :\n");
                            scanf("%s",ccl);
                        }while(lire(&ccl) == 1)
                        inserer_conclusion(r,ccl);

                        /* premisses de la regle */
                        int nb = 0;
                        char buffer[TAILLE_PHRASE_MAX];
                        do
                        {
                            printf("Combien de premisses voulez vous ajouter ?\n")
                            scanf("%s",buffer);
                        } while ((sscanf(buffer,"%d",&nb)==EOF)||(ccl < 0));
                        char premisse[TAILLE_PHRASE_MAX];
                        for (int i = 0; i < nb; i++)
                        {
                            do{
                                printf("Entrez le nom de la premisse %d :\n",i);
                                scanf("%s",premisse);
                            }while(lire(&ccl) == 1)
                            Ajout_premisse(r,premisse);
                            free(r);
                        }
                        
                        ajouter_regle(br,r);
                        printf("La regle a ete ajoute.\n");
                        quit = 0;
                        break;
                    
                    case 1:
                        if (br != NULL)
                        {
                            char ccl[TAILLE_PHRASE_MAX];
                            do{
                                printf("Entrez la nouvelle conclusion de la regle :\n");
                                scanf("%s",ccl);
                            }while(lire(&ccl) == 1)
                            inserer_conclusion(r,ccl);
                        }
                        else
                        {
                            printf("Il n'y a pas de regle à modifier !\n")
                        }
                        
                        quit = 0;
                        break;
                    
                    case 2:
                        if (base != NULL)
                        {
                            afficher_base_connaissances(br);
                            BC indexB = br;
                            bool found = FAUX;
                            char premisse[TAILLE_PHRASE_MAX];

                            do{
                                printf("Entrez la conclusion de la regle ou l'on ajoute la premisse :\n");
                                scanf("%s",premisse);
                            }while(lire(&premisse) == 1)

                            while(indexB->suivant != NULL && found == FAUX){
                                if (strcmp(Conclusion_regle(Regle_tete_base(indexB),premisse) != 1)
                                {
                                    found = VRAI;
                                    regle r = indexB->regle;
                                }
                                indexB = indexB->suivant;                            
                            }
                            if (found == FAUX)
                            {
                                printf("Cette premisse n'existe pas.\n")
                            }
                            else
                            {
                                do{
                                    printf("Entrez le nom de la premisse %d :\n",i);
                                    scanf("%s",premisse);
                                }while(lire(&premisse) == 1)
                                Ajout_premisse(r,premisse);
                                free(r);
                                
                            }
                            
                        }
                        else
                        {
                            printf("Il n'y a pas de regle à modifier !\n")
                        }
                        
                        quit = 0;
                        free(indexB);
                    }
                    
                    break;

                    case 3:
                        afficher_base_connaissances(br);
                        quit = 0;
                        break;
                    
                    case 4:
                        Write_bc(br,fichier_choisi);
                        printf("fichier enregistre.\n");
                        quit = 1;
                        break;
                    case 5:
                        quit = 1;
                        break; 
                }
            else
            {
                quit = 1;
            }

            } while (quit == 0);
            break;
        case 3:
            if(base_choisie == 1)
            {
                liste* bf = (liste*)malloc(sizeof(liste));
                char nom[TAILLE_PHRASE_MAX];
                do{
                    printf("Entrez le nom de la premisse %d :\n",i);
                    scanf("%s",nom);
                }while(lire(&nom) == 1)

                int nb = 0;
                char buffer[TAILLE_PHRASE_MAX];
                do
                {
                    printf("Combien de premisses voulez vous ajouter ?\n")
                    scanf("%s",buffer);
                } while ((sscanf(buffer,"%d",&nb)==EOF)||(ccl < 0));
                char premisse[TAILLE_PHRASE_MAX];
                for (int i = 0; i < nb; i++)
                {
                    do{
                        printf("Entrez le nom de la premisse %d :\n",i);
                        scanf("%s",premisse);
                    }while(lire(&ccl) == 1);
                    Ajout_premisse_liste(bf,premisse);
                }
                bf = moteur_inference(bf,bc);
                Write_bf(bf,&nom);
                free(bf);
            else
            {
                printf("Vous devez selectionner une base de connaissance avant de créer une base de faits.\n");
            }
            
            break;
        case 4:
            int baseFaitChoisi = 1
            printf("Choisissez le fichier à lire : \n");
            char *fichier_choisi_faits = choix_base_de_faits();
            printf("Lecture du fichier...\n");
            liste* baseFaits = Read_bc(fichier_choisi_faits);
            afficher_base_de_faits(baseFaits,choix_base_de_faits);
            break;
        case 5:
        case 6:
            free(bc);
            return EXIT_SUCCESS;
            break;
        }
    }

}