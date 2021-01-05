#ifndef FONCTION_HEADER
#define FONCTION_HEADER

#include "structures.h"


/* Constantes */

#define TAILLE_PHRASE_MAX 100


/* Fonctions */

    /* Fonctions regles */

/**
 * \fn void Ajout_premisse(regle r, char*s)
 * \param r - regle ou l'on veut ajouter la premisse
 * \param s - chaine de caractere representant la premisse a ajouter
 * \brief Permet d'ajouter la premisse s a la regle r
 */
void Ajout_premisse(regle r, char* s);

/**
 * \fn void Ajout_premisse(regle r, char* s)
 * \brief fonction permettant d'ajouter une prémisse dans une premisse
 * \param l - liste de prémisses que l'on souhaite altérer
 * \param s - chaîne de caractère / intitulé de la prémisse que l'on veut ajouter
 */
liste* Ajout_premisse_liste(liste* l, char* s);

/**
 * \fn bool Si_premisse(liste* pp, char* s)
 * \param pp - liste de premisse dans laquelle on verifie l'existence
 * \param s - chaine de caractere représentant la premisse a verifier
 * \return bool - presence de l'element
 * \brief Permet de verifier si la premisse s appartient e la liste pp
 */
bool Si_premisse(liste* pp, char* s);

/**
 * \fn bool Pas_premisse(regle r)
 * \param r - regle ou l'on verifie la presence
 * \return bool - présence de premisse(s)
 * \brief Permet de verifier si r possede au moins une premisse
 */
bool Pas_premisse(regle r);

/**
 * \fn char* Conclusion_regle(regle r)
 * \brief fonction permettant d'obtenir la conclusion d'une règle
 * \param r - regle dont on veut connaitre la conclusion
 * \return une chaîne de caractères correspondant à l'intitulé de la conclusion de la règle
 */
char* Conclusion_regle(regle r);

/**
 * \param r - regle ou l'on veut recuperer la conclusion
 * \return char* - chaine de caractere representant la conclusion de r
 * \brief permet de recuperer lq conclusion de r
 */
char* Conclusion_regle(regle r);

/**
 * \fn void vider Buffer()
 * \brief fonction permettant de vider le buffer utilisé en argument de la fonction lire
 */
void viderBuffer();

/**
 * \fn int lire(char* Buffer)
 * \brief fonction permettant de lire une phrase d'une taille maximale (définie au début de ce fichier header)
 * \param Buffer - chaîne de caractère où va être stocké la phrase entrée par l'utilisateur (il faut avoir alloué sa place en mémoire)
 * \return un entier - 1 ou 0 en fonction de si la fonction s'est déroulée sans problème ou non
 */
int lire(char* Buffer);

/**
 * \fn regle creer_regle()
 * \brief fonction permettant de créer une règle vide : avec une conclusion vide et une liste de prémises vide
 * \return une regle - correpond à la règle créée
 */
regle creer_regle();

/**
 * \fn regle inserer_conclusion(regle r)
 * \brief fonction permettant de donner une conclusion à une regle
 * \param r - regle dans laquelle on veut insérer une conclusion
 * \param c_conclusion - chaîne de caractères corespondant à la conclusion que l'on veut ajouter
 * \return une regle - correspond à la règle à laquelle on a ajouté une conclusion
 */
regle inserer_conclusion(regle r, char* c_conclusion);

/**
 * \fn regle supprimer_premisse(regle r, char* intitule_premisse)
 * \brief fonction permettant de supprimer une premisse donnée en argument dans une règle
 * \param r - regle que l'on veut modifier
 * \param intitule_premisse - chaîne de caractères, correspond à l'intitule de la premisse que l'on veut supprimer
 * \return une regle - la regle avec la premisse spécifiée en argument en moins
 */
regle supprimer_premisse(regle r,char* intitule_premisse);

liste* trouver_premisse(regle r,char* intitule_premisse);

/** 
 * \fn liste* premisse_tete(regle r)
 * \brief fonction permettant de récupérer la prémisse de tête dans une regle
 * \param r - regle dont on veut connaitre la prémisse de tête
 * \return une premisse - la prémisse de tête
 */
liste* premisse_tete(regle r);


    /* Fonctions base */

/**
 * \fn BC Creer_base()
 * \brief Fonction permettant de créer une base vide
 * \return une base e connaissances vide
 */
BC Creer_base();

/**
 * \fn regle Regle_tete_base(BC b)
 * \brief Fonction permettant de connaitre la règle de tête d'une base
 * \param b - une base de connaissances
 * \return une regle, la regle de tête de b
 */
regle Regle_tete_base(BC b);

/** \fn BC ajouter_regle(BC base, regle r)
 * \brief fonction permettant de rajouter une regle r dans une base de connaissances
 * \param base - Base de connaissance que l'on va altérer
 * \param r - regle que l'on veut ajouter à notre base de connaissances
 * \return la base de connaissance altérée
 */
BC ajouter_regle(BC base, regle r);


    /* Fonctions menu */

/**
 * \fn void afficher_premisses(liste* l)
 * \brief fonction affichant une liste de prémisse
 * \param l - liste de prémisses que l'on souhaite afficher
 */
void afficher_premisses(liste* l);

/**
 * \fn void afficher_base_de_faits(liste* l, char* nom_base_de_faits)
 * \brief fonction permettant d'afficher une base de faits
 * \param l - liste de prémisse composant la base de connaissance
 * \param nom_base_base_de_faits - nom de la base de faits
 */
void afficher_base_de_faits(liste* l, char* nom_base_de_faits);

/**
 * \fn void afficher_regle(regle r)
 * \brief fonction permettant d'afficher une règle
 * \param r - règle que l'on souhaite afficher
 */
void afficher_regle(regle r);

/**
 * \fn void afficher_base_connaissances(BC base, char* nom_base_connaissances)
 * \brief fonction permettant d'afficher une base de connaissances
 * \param base - la base que l'on souhaite afficher
 * \param nom_base_connaissances - nom de la base de connaissances
 */
void afficher_base_connaissances(BC base, char* nom_base_connaissances);

/**
 * \fn BC Creer_base()
 * \return BC - base de connaissance initialisée et vide
 * \brief initialise une Base de connaissance vide
 */
BC Creer_base();

/**
 * \fn regle Regle_tete_base(BC b)
 * \param b - base de connaissance où l'on veut récupérer
 * \return regle - regle en tete de la base 
 * \brief permet de recupere la regle en tete de la base b
 */
regle Regle_tete_base(BC b);


    /* Fonctions pour les fichiers */

/**
 * \fn void Write_bc(BC b, char* bcName)
 * \param b - base de connaissance que l'on veut enregistrer
 * \param bcName - chaine de caractere representant le nom a donner a la base 
 * \brief permet d'enregister une base dans un fichier .txt
 */
void Write_bc(BC b, char* bcName);

/**
 * \fn BC Read_bc(char* fileName)
 * \param fileName - chaine de caractere represantant le nom du fichier
 * \return BC - base initialisé et contenant les regles du fichier .txt 
 * \brief permet de recupere la base du fichier .txt
 */
BC Read_bc(char* fileName);

#endif