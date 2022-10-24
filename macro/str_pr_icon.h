#ifndef str_pr_icon
#define str_pr_icon
#include"bibliotheque.h"
/********************************************************************
*   Structure   :   prIcon
*   --------------------------
*       Le prIcon est la structure qui peremet de creer une icone
*    qu'on va relier apres avec des fenetre ou des boites.
*********************************************************************/
typedef struct prIcon
{
    GtkWidget *pere;    // le porteur de l'icone
    char url[256];       // le chemin relatif a la structure
}prIcon;
#endif // str_pr_icon

