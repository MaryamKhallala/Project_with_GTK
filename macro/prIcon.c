#include"prIcon.h"
/***************************** prIcone *********************************/
/***************************************************************************
*   Fonction   :   prIcon* pr_icon_init(GtkWidget *pere,
*                                              char url[30])
*   ------------------------------------------------------------------
*       Dans cette dernier on vas faire l'alocation et l'initialisation
*    de la structure prIcon
*   Entre   :  - Le container OU nous allons mettre notre prIcon
*               - Le chemin de l'icon a creer
*   Sortie  :  - une Variable de type prIcon apres allocation et
*                initialisation
***************************************************************************/

prIcon* pr_icon_init(GtkWidget *pere,char url[256])
{
    prIcon *ico=(prIcon*)malloc(sizeof(prIcon));
    ico->pere=pere;
    if(url)strcpy(ico->url,url);
    return((prIcon*)ico);
}
/***************************************************************************
*   Fonction   :   GtkWidget* pr_icon_create(prIcon *ico)
*   ------------------------------------------------------------------
*       Cette fonction nous permet de creer une icon c'est à dire collecter
*    l'icon a la fenetre qu'on a deja remplir dans l'initialisation
*   Entre   :   Notre prIcon qui contient les informations remplis dans
*            l'initialisation'
*   Sortie  :   on retourne la GtkWidget apres que nous allons collecter
*            l'icon
***************************************************************************/
GtkWidget* pr_icon_create(prIcon *ico)
{
    gtk_window_set_icon_from_file (GTK_WINDOW(ico->pere), ico->url, NULL);
    return((GtkWidget*)ico->pere);
}

