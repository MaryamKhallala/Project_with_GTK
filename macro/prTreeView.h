#include"str_pr_treeview.h"
#include"prList.h"
#include"prStoreTypes.h"

/* inialisation */
prTreeView *pr_tree_view_init (GtkWidget *racine,
                                     gchar *nom,
                                     gint n_cols);
/* Creation */
prTreeView *pr_tree_view_create (prTreeView *tv,
                                       prList *attributes,
                                       prStoreTypes *st);
/* ajout */
void pr_tree_view_add (prTreeView *tv,
                          prList *list,
                          prList *listTypes);
/* Supprimer element de liste */
void pr_tree_view_remove (GtkWidget *widget,
                             gpointer *treeView);
/* Supprimer tout la liste */
void pr_tree_view_remove_all (prTreeView *treeView);

