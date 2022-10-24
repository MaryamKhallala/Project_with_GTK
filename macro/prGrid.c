#include "prGrid.h"

/******************************************************************
*    Fonction : Grid  *initialiser_grid (GtkWidget*, gchar*)
*    --------------------------------------
*        Cette fonction fait l'initalisation et allocation
*    des champs d'une grid
*        Entree :    Le container de la grie
*                    Le nom du selecteur (pour Css)
*        Sortie : Le button apres creation
******************************************************************/
prGrid    *pr_grid_init (GtkWidget *racine, gchar *nom)
{
    prGrid    *grid = NULL;
    grid = (prGrid*) malloc (sizeof (prGrid));
    grid->racine = racine;
    if (nom)
    {
        grid->nom = (gchar*) malloc (30*sizeof (gchar));
        strcpy (grid->nom, nom);
    }
    else grid->nom = NULL;

    return ((prGrid*) grid);
}
/******************************************************************
*    Fonction : prGrid    *pr_grid_create (prGrid *grid)
*    --------------------------------------
*        Cette fonction permet de creer une grille avec certains
*    critére citer dans l'initialisation
*        Entree :   prGrid* deja initialiser
*        Sortie :   La grille apres la creation
*******************************************************************/
prGrid    *pr_grid_create (prGrid *grid)
{
    grid->grid = gtk_grid_new ();
    if (grid->nom)
        gtk_widget_set_name (grid->grid,grid->nom);

    return ((prGrid*) grid);
}
/******************************************************************
*    Fonction : pr_grid_add(prGrid *,
*                              GtkWidget *,
*                              gint ,
*                              gint ,
*                             gint ,
*                              gint )
*    --------------------------------------------------------------
*        Cette fonction ajout un element de type GtkWidget dans
*    la grie,les parametres de positionnement sont passes
*    en argument.
*        Entree :    Grid*       Le container/ la grie
*                    GtkWidget*  L element a ajouter
*                    left        indice de la collone
*                    top         indice de la ligne
*                    width       nombre de collones
*                    height      nombre de lignes
*        Sortie : Le button apres creation
******************************************************************/
void pr_grid_add (prGrid *grid, GtkWidget *element, gint left,
                     gint top, gint width, gint height)
{
    gtk_grid_attach (GTK_GRID(grid->grid),
                     element, left, top,
                     width, height);
}

