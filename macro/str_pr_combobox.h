#ifndef str_pr_combobox
#define str_pr_combobox
#include"bibliotheque.h"

/**********************************************************
*   Structure   :   prComboBox
*   --------------------------
*       Le prComboBox est le widget qui permete de creer
*   des listes dirolantes (dropdown)
*       les composants de cette structure sont :
*     l'objet combobox
*     le conteneur
*     nom de l'objet
*     la position de l'objet
***********************************************************/
typedef struct prComboBox
{
    GtkWidget   *comboBox;  // notre objet
    GtkWidget   *racine;    // le conteneur
    gchar       *nom;       // le nom de l'objet
    prPos *pox;          // la position
} prComboBox;
#endif // str_pr_combobox

