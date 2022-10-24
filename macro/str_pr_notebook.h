
#ifndef str_pr_notebook
#define str_pr_notebook
#include"bibliotheque.h"
/*********************************************************************
*   Structure   :   prNotebook
*   --------------------------
*       Le prNotebook est la structure qui nous donne la possiblité
*    de creer un notebook c'est a dire plusieurs page dans la meme
*    inerface , qui donne plus de utilite a votre interface.
**********************************************************************/
typedef struct prNotebook
{
    GtkWidget   *notebook;      // l'objet notebook
    GtkWidget   *racine;        // le conteneur
    gchar       *nom;           // le nom de l'objet
    gint        type;         /* le type du notebook */
                                //  0 pour GTK_POS_TOP,
                                //  1 pour GTK_POS_BOTTOM,
                                //  2 pour GTK_POS_RIGHT
} prNotebook;
#endif //str_pr_notebook
