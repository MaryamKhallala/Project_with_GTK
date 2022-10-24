#include "str_pr_grid.h"
/*initialisation*/
prGrid    *pr_grid_init (GtkWidget *racine, gchar *nom);
/* creation*/
prGrid    *pr_grid_create(prGrid *grid);
/* ajout */
void pr_grid_add (prGrid*, GtkWidget*, gint, gint, gint, gint);

