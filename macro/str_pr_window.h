#ifndef str_pr_window
#define str_pr_winodw
#include"bibliotheque.h"
/**************************************************************
*   Structure   :   prWindow
*   --------------------------
*       Le prWindow est la structure qui permet de creer
*    la fenetre de votre interface avec leur caractéristiques
***************************************************************/
typedef struct prWindow
{
    GtkWidget   *window;
    GtkWidget   *fixed;
	gchar       * titre;
	gchar       * nom;
	gchar       * icon;
	gchar       type;
	gint        longueur;
	gint        hauteur;
	gint        position;
	gint        resizable;
}prWindow;
#endif // str_pr_window


