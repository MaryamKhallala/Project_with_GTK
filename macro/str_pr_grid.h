#ifndef str_pr_gride
#define str_pr_gride
#include"bibliotheque.h"

/**********************************************************
*   Structure   :   prGrid
*   --------------------------
*       Le prGrid est le widget qui rassemble au tableau
*    qui nous donne la possibliter de mettre des objets
*    a des case .
*        les composants de la structure :
*     l'objet grille
*     le conteneur
*    le nom de l'objet
*
**********************************************************/


typedef struct prGrid
{
    GtkWidget     *grid;    // l'objet grille
    GtkWidget   *racine;    // le conteneur
    gchar       *nom;       // nom de l'objet
} prGrid;
#endif // str_pr_gride

