#include"prTreeView.h"
/*************************************************************************
*   Fonction   : prComboBox *pr_combo_box_init (GtkWidget*, gchar*)
*   ------------------------------------------------------------------
*       Cette fonction fait l allocation et initialisation des champs
*   de la structure prComboBox
*   Entre   :   Le container nous allons mettre notre prComboBox
*               Le selectioneur du comboBox (pour le CSS)
*   Sortie  :
**************************************************************************/
prTreeView *pr_tree_view_init (GtkWidget *racine,
                                     gchar *nom,gint n_cols)
{
    prTreeView *tv = (prTreeView*) malloc (sizeof (prTreeView));
    tv->racine = racine;
    if (nom)
    {
        tv->nom = (gchar*) malloc (30*sizeof (gchar));
        strcpy (tv->nom, nom);
    }
    else tv->nom = NULL;
    tv->n_cols = n_cols;

    return ((prTreeView*) tv);
}
/*************************************************************************
*   Fonction   :   prComboBox *pr_combo_box_init (GtkWidget*,
                                                        gchar*)
*   ------------------------------------------------------------------
*       Cette fonction fait l allocation et initialisation des champs
*   de la structure prComboBox
*   Entre   :   Le container nous allons mettre notre prComboBox
*               Le selectioneur du comboBox (pour le CSS)
*   Sortie  :
*/
prTreeView *pr_tree_view_create (prTreeView *tv,
                                       prList *attributes,
                                       prStoreTypes *st)
{
    GtkCellRenderer       *renderer;
    GtkTreeViewColumn   *column;
    GtkListStore        *store;

    int i = 0;
    tv->treeView = gtk_tree_view_new ();
    renderer = gtk_cell_renderer_text_new();

    for (; i < tv->n_cols; i++)
    {
        column =
         gtk_tree_view_column_new_with_attributes (
                        (gchar*)(g_slist_nth (attributes->list, i)->data),
                            renderer, "text", i, NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW(tv->treeView), column);
    }
    store = gtk_list_store_newv (tv->n_cols, st->storeTypes);

    gtk_tree_view_set_model (GTK_TREE_VIEW(tv->treeView),
                             GTK_TREE_MODEL(store));

    g_object_unref(store);
    return ((prTreeView*) tv);
}
/*************************************************************************
*   Fonction   :  prComboBox *pr_combo_box_init (GtkWidget*, gchar*)
*   ------------------------------------------------------------------
*       Cette fonction fait l allocation et initialisation des champs
*   de la structure prComboBox
*   Entre   :   Le container nous allons mettre notre prComboBox
*               Le selectioneur du comboBox (pour le CSS)
*   Sortie  :
*/
void pr_tree_view_add (prTreeView *tv, prList *list,
                          prList *listTypes)
{
    GtkListStore *store;
    GtkTreeIter iter;

    store = GTK_LIST_STORE(gtk_tree_view_get_model(
                                            GTK_TREE_VIEW(tv->treeView)
                                                   )
                           );
    gtk_list_store_append (store, &iter);
    int temp = 0;
    int i = 0;
    int nombreCollones = g_slist_length (listTypes->list);
    for (; i < nombreCollones; i++)
    {
        if (! GPOINTER_TO_INT (g_slist_nth (listTypes->list, i)->data))
        {
            temp = atoi ((gchar*)g_slist_nth (list->list, i)->data);
            gtk_list_store_set (store, &iter, i, temp, -1);
        }
        else
            gtk_list_store_set (store, &iter, i,
                                (gchar*)(g_slist_nth (list->list, i)->data),
                                -1);
    }
}
/*************************************************************************
*   Fonction   :  prComboBox *pr_combo_box_init (GtkWidget*, gchar*)
*   ------------------------------------------------------------------
*       Cette fonction fait l allocation et initialisation des champs
*   de la structure prComboBox
*   Entre   :   Le container nous allons mettre notre prComboBox
*               Le selectioneur du comboBox (pour le CSS)
*   Sortie  :
*/
/*void pr_tree_view_remove (GtkWidget *widget, gpointer *treeView)
{
    GtkTreeSelection    *selection;
    GtkListStore            *store;
    GtkTreeModel        *model;
    GtkTreeIter         iter;

    selection = gtk_tree_view_get_selection (GTK_TREE_VIEW(treeView->treeView));
    store = GTK_LIST_STORE(gtk_tree_view_get_model(
                                    GTK_TREE_VIEW(treeView->treeView)));
    model = gtk_tree_view_get_model(GTK_TREE_VIEW(treeView->treeView));

    if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) {
        return;
    }

    if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(selection),
            &model, &iter)) {
        gtk_list_store_remove(store, &iter);
    }
}

void pr_tree_view_remove_all (prTreeView *treeView) {
  GtkListStore *store;
  GtkTreeModel *model;
  GtkTreeIter  iter;
  store = GTK_LIST_STORE(gtk_tree_view_get_model(
                                    GTK_TREE_VIEW(treeView->treeView)));
  model = gtk_tree_view_get_model(GTK_TREE_VIEW(treeView->treeView));
  if (gtk_tree_model_get_iter_first(model, &iter) == FALSE) return;
  gtk_list_store_clear(store);
}*/

