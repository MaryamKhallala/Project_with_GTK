#ifndef str_pr_color
#define str_pr_color
#include"bibliotheque.h"
/****************************************************************************
*   Structure   :   prColor
*   --------------------------
*       Le prColor pemermet de choisir le porcentage
*    des coleur principale
*        Et aussi choisir la methode d'application du
*    coleur pour l'objet donner
*   1 = GTK_STATE_NORMAL : Etat de base
*   2 = GTK_STATE_ACTIVE : lorsque le widget est actif (qu'il a le focus)
*   3 = GTK_STATE_PRELIGHT : lorsque le curseur de la souris est sur le widget
*   4 = GTK_STATE_SELECTED : lorsque le widget est sélectionné
*   5 = GTK_STATE_INSENSITIVE : lorsque le widget est inactif
*****************************************************************************/
typedef struct prColor
{
    double rouge;   // la valeur du rouge
    double vert;    // du vert
    double bleu;    // du bleu
    int choix;      // le methode de coloration
}prColor;
#endif // str_pr_color

