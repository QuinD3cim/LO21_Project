#ifndef MOTEUR_HEADER
#define MOTEUR_HEADER

#include <dirent.h>
#include "fonction.h"

/** 
 * \fn int menu_principal()
 * \brief Fonction permettant d'afficher le menu principal
 * \return un entier - l'index de la proposition que l'utilisateur a choisi. S'il est égal à -1 c'est qu'il n'y avait pas de propositions.
 */
int menu_principal();

/** 
 * \fn int menu_creer_bc()
 * \brief Fonction permettant d'afficher le menu creer base de connaissance
 * \return un entier - l'index de la proposition que l'utilisateur a choisi. S'il est égal à -1 c'est qu'il n'y avait pas de propositions.
 */
int menu_creer_bc();

/** 
 * \fn int menu(char* titre_menu, char** tableau_proposition)
 * \brief Fonction permettant d'afficher un menu
 * \param titre_menu - une chaîne de caractères correspondant au titre du menu
 * \param tableau_proposition - un tableau de chaîne de caractère correspondant aux différentes propostions possibles d'effectuer
 * \return un entier - l'index de la proposition que l'utilisateur a choisi. S'il est égal à -1 c'est qu'il n'y avait pas de propositions.
 */
int menu(char* titre_menu, char** tableau_proposition);

/** 
 * \fn char* choix_base_de_faits()
 * \brief Cette fonction permet de scanner le répertoire base_de_faits pour trouver la base de faits que l'on désire
 * \return une chaîne de caractères - C'est le nom du fichier qu'il faut ouvrir
 */
char* choix_base_de_faits();

/** 
 * \fn char* choix_base_de_connaissances()
 * \brief Cette fonction permet de scanner le répertoire base_de_connaissances pour trouver la base de connaissances que l'on désire
 * \return une chaîne de caractères - C'est le nom du fichier qu'il faut ouvrir
 */
char* choix_base_de_connaissances();

/**
 * \fn liste* moteur_inference(liste* base_de_faits,BC base_de_connaissances )
 * \brief Il s'agit du moteur d'inférence. Il va utiliser la base de connaissances et la base de faits pour déduire de nouveaux faits et les ajouter à la base de faits.
 * \param base_de_faits - une liste de premisses. Elle regroupe tous les faits donnés par l'utilisateur
 * \param base_de_connaissances - une base de connaissance que nous aurons chois au préalable et à partir de laquelle nous allons raisonner.
 * \return une liste de premisses - la base_de_faits agrémentée de nouveaux faits grâce au moteur d'inférence.
 */
liste* moteur_inference(liste* base_de_faits,BC base_de_connaissances );

#endif