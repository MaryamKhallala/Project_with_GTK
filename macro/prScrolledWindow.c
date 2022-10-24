
#include"prScrolledWindow.h"
/**************************************************************************
*   Fonction : prScrolledWindow *pr_scrolled_window_init(GtkWidget *,
*                                                               gchar *,
*                                                               gint ,
*                                                               gint ,
*                                                               gint )
*   ------------------------------------------------------------------
*       Cette fonction fait l allocation et initialisation des champs
*   de la structure prScrolledWindow avec les parametre passer
*   Entre   :   - Le container ou nous allons mettre notre
*                    prScrolledWindow
*               - nom de notre objet (pour le CSS)
*               - hpolice qui vas nous indique l'existance d'assenseur
*                    horizontal
*               - vpolice qui vas nous indique l'existance d'assenseur
*                    vertical
*               - shadow c'est le type du cadre
*   Sortie  : Notre ScrolledWindow apres allocation et initialisation
**************************************************************************/
prScrolledWindow  *pr_scrolled_window_init (GtkWidget *racine,
                                                  gchar *nom,
                                                  gint hpolice,
                                                  gint vpolice,
                                                  gint shadow)
{
    prScrolledWindow  *sw =
            (prScrolledWindow*) malloc (sizeof (prScrolledWindow));
    sw->racine = racine;
    if (nom)
    {
        sw->nom = (gchar*) malloc (35*sizeof (gchar));
        strcpy (sw->nom, nom);
    }
    else sw->nom = NULL;
    sw->hpolice = hpolice;
    sw->vpolice = vpolice;
    sw->shadow  = shadow;

    return ((prScrolledWindow*) sw);
}
/**********************************************************************
*   Fonction :
*    prScrolledWindow *pr_scrolled_window_create(prScrolledWindow *)
*
*   ------------------------------------------------------------------
*       Cette fonction fait la creation du scrolledWindow avec
*   des caractéristique donner au deferent champ du structure
*   Entre   :   variable de type prScrolledWindow initialiser
*   Sortie  :   Une variable de type prScrolledWindow apres avoir
            creer l'objet avec leur critéres.
*/
prScrolledWindow  *pr_scrolled_window_create (prScrolledWindow *sw)
{
    sw->scrolledWindow = gtk_scrolled_window_new(NULL,NULL);
    gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW(sw->scrolledWindow),
            sw->hpolice, sw->vpolice);

    gtk_scrolled_window_set_shadow_type (
                                    GTK_SCROLLED_WINDOW(sw->scrolledWindow),
                                    sw->shadow);
    sw->fixed=gtk_fixed_new();

    return ((prScrolledWindow*) sw);
}
/*************************************************************************
*   Fonction : void pr_scrolled_window_add(prScrolledWindow *,
                                                      GtkWidget *)
*   ---------------------------------------------------------------------
*       Cette fonction permet d'ajouter n'import qu'elle GtkWidget a notre
*    ScrolledWindow.
*   Entre   :   - ScrolledWindow qui vas jouer le role du container
*               - element a ajouter
*   Sortie  :  void  avoir le scrolledWindow remplis par l'element
*************************************************************************/
void    pr_scrolled_window_add (prScrolledWindow *sw,
                                   GtkWidget *element)
{
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(sw->scrolledWindow),element);
}
