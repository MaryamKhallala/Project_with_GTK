
#ifndef str_pr_fixed
#define str_pr_fixed
#include"bibliotheque.h"
/***********************************************************************
*   Structure   :   prFixed
*   --------------------------
*       Le prFixed est la structure qui represente l'objet fixed
*    qui sert à placer n'importe quel objet à la position que vous
*    voulez .
*       composante de la structure :
*            l'objet fixed
*            le conteneur de l'objet
*************************************************************************/
typedef struct prFixed
{
    GtkWidget *fixed;       // l'objet fixed
    GtkWidget *pere;        // le conteneur
} prFixed;
/**************************************************************************
*   Structure   :   prSeparator
*   --------------------------
*       Le prSeparator qui permet de creer un separatuer soit horizontal
*    soit verticale.
*        les champs de la structure :
*            l'objet separateur
*            le conteneur de l'objet
*            le type du separateur
*
***************************************************************************/
typedef struct prSeparator
{
    GtkWidget *separator;   // l'objet separateur
    GtkWidget *pere;        // le conteneur
    int type ;              // le type du separateur ( horizontal / vertical)
} prSeparator;
#endif // str_pr_fixed
