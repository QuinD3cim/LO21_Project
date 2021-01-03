#ifndef FONCTION_HEADER
#define FONCTION_HEADER

#include "structures.h"


/* Constantes */

#define TAILLE_PHRASE_MAX 100


/* Fonctions */

/**
 * \fn void Ajout_premisse(regle r, char* s)
 * \brief fonction permettant d'ajouter une prémisse dans une règle
 * \param r - regle que l'on souhaite altérer
 * \param s - chaîne de caractère / intitulé de la prémisse que l'on veut ajouter
 */
void Ajout_premisse(regle r, char* s);

/**
 * \fn bool Si_premisse(liste* pp, char* s)
 * \brief Fonction permettant de savoir si une prémisse appartient à une règle
 * \param pp - une liste de prémisse que l'on va scanner
 * \param s - une chaîne de caractères correspondant à la prémisse que l'on recherche dans pp
 * \return un booléen : FAUX : s n'appartient pas à pp, VRAI : s appartient à pp
 */
bool Si_premisse(liste* pp, char* s);

/**
 * \fn bool Pas_premisse(regle r)
 * \brief fonction permettant de savoir si une regle possède une prémisse
 * \param r - regle dont on cherche à savoir si elle possède au moins une prémisse
 * \return un booléen : VRAI : r n'a pas de prémisses, FAUX : r a au moins une prémisse
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

/** 
 * \fn liste* premisse_tete(regle r)
 * \brief fonction permettant de récupérer la prémisse de tête dans une regle
 * \param r - regle dont on veut connaitre la prémisse de tête
 * \return une premisse - la prémisse de tête
 */
liste* premisse_tete(regle r);


/** 
 * \fn BC ajouter_regle(BC base, regle r)
 * \brief fonction permettant de rajouter une regle r dans une base de connaissances
 * \param base - Base de connaissance que l'on va altérer
 * \param r - regle que l'on veut ajouter à notre base de connaissances
 * \return la base de connaissance altérée
 */
BC ajouter_regle(BC base, regle r);

#endif