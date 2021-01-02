#ifndef FONCTION_HEADER
#define FONCTION_HEADER

#include "structures.h"


/* Constantes */

#define TAILLE_PHRASE_MAX 100


/* Fonctions */

void Ajout_premisse(regle r, char* s);

bool Si_premisse(liste* pp, char* s);

bool Pas_premisse(regle r);

char* Conclusion_regle(regle r);

BC Creer_base();

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
 * \return une regle - correspond à la règle à laquelle on a ajouté une conclusion
 */
regle inserer_conclusion(regle r);

/**
 * \fn regle supprimer_premisse(regle r, char* intitule_premisse)
 * \brief fonction permettant de supprimer une premisse donnée en argument dans une règle
 * \param r - regle que l'on veut modifier
 * \param intitule_premisse - chaîne de caractères, correspond à l'intitule de la premisse que l'on veut supprimer
 * \return une regle - la regle avec la premisse spécifiée en argument en moins
 */
regle supprimer_premisse(regle r,char* intitule_premisse);

/** \fn liste* premisse_tete(regle r)
 * \brief fonction permettant de donner de récupérer la prémisse de tête dans une regle
 * \param r - regle dont on veut connaitre la prémisse de tête
 * \return une premisse - la prémisse de tête
 */
liste* premisse_tete(regle r);

#endif