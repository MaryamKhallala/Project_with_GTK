#include"str_pr_notebook.h"
#include"prLabel.h"
/*initialisation*/
    prNotebook    *pr_notebook_init (GtkWidget *racine,
                                           gchar *nom,
                                           gint type);
/* creation */
    prNotebook    *pr_notebook_create (prNotebook *notebook);
/* ajout d'une page */
    GtkWidget   *pr_notebook_add (prNotebook *notebook,
                                     GtkWidget *contenu,
                                     prLabel *label);

