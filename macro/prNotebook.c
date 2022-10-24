#include"prNotebook.h"
/**********************************************************************
*   Fonction   :   prNotebook  *pr_notebook_init (GtkWidget *,
*                                                        gchar *,
*                                                        gint )
*   ------------------------------------------------------------------
*
*   Entre   :
*
*   Sortie  :
**********************************************************************/
prNotebook    *pr_notebook_init (GtkWidget *racine, gchar *nom,
                                       gint type)
{
    prNotebook    *notebook = NULL;
    notebook    = (prNotebook*) malloc (sizeof (prNotebook));

    notebook->racine = racine;
    if (nom)
    {
        notebook->nom = (gchar*) malloc (35*sizeof (gchar));
        strcpy (notebook->nom, nom);
    }
    else notebook->nom = NULL;
    notebook->type = type;

    return ((prNotebook*) notebook);
}
/**********************************************************************
*   Fonction : prNotebook *pr_notebook_create (prNotebook *)
*   ------------------------------------------------------------------
*
*   Entre   :
*
*   Sortie  :
**********************************************************************/
prNotebook    *pr_notebook_create (prNotebook *notebook)
{
    notebook->notebook = gtk_notebook_new ();
    gtk_widget_set_name (notebook->notebook, notebook->nom);
    switch (notebook->type)
    {
        case 0:
        gtk_notebook_set_tab_pos (GTK_NOTEBOOK(notebook->notebook),
                                  GTK_POS_TOP);
         break;
        case 1:
         gtk_notebook_set_tab_pos (GTK_NOTEBOOK(notebook->notebook),
                                   GTK_POS_BOTTOM);
                break;
        case 2:
         gtk_notebook_set_tab_pos (GTK_NOTEBOOK(notebook->notebook),
                                   GTK_POS_RIGHT);
                break;
    }
    return ((prNotebook*) notebook);
}
/**********************************************************************
*   Fonction   :   GtkWidget   *pr_notebook_add (prNotebook *,
                                                    GtkWidget *,
                                                    prLabel *)
*   ------------------------------------------------------------------
*
*   Entre   :
*
*   Sortie  :
***********************************************************************/
GtkWidget   *pr_notebook_add (prNotebook *notebook,
                                 GtkWidget *contenu,
                                 prLabel *label)
{
    gtk_notebook_append_page (GTK_NOTEBOOK (notebook->notebook),
                              contenu, label->label);
    return ((GtkWidget*) contenu);
}

