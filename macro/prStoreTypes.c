#include"prStoreTypes.h"
/*************************************************************************
*   Fonction : prComboBox *pr_combo_box_init (GtkWidget*, gchar*)
*   ------------------------------------------------------------------
*       Cette fonction fait l allocation et initialisation des champs
*   de la structure prComboBox
*   Entre   :   Le container nous allons mettre notre prComboBox
*               Le selectioneur du comboBox (pour le CSS)
*   Sortie  :
*************************************************************************/
prStoreTypes  *pr_store_type_init (int n_cols)
{
    prStoreTypes  *st =
      (prStoreTypes*) malloc (sizeof (prStoreTypes));
    st->storeTypes = NULL;
    st->n_cols = n_cols;

    return ((prStoreTypes*) st);
}
/*************************************************************************
*   Fonction  :  prComboBox *pr_combo_box_init (GtkWidget*, gchar*)
*   ------------------------------------------------------------------
*       Cette fonction fait l allocation et initialisation des champs
*   de la structure prComboBox
*   Entre   :   Le container nous allons mettre notre prComboBox
*               Le selectioneur du comboBox (pour le CSS)
*   Sortie  :
*************************************************************************/
prStoreTypes  *pr_store_type_create (prStoreTypes *st,
                                           prList *list)
{
    int i = 0;
    st->storeTypes = g_new0 (GType, st->n_cols);

    for (; i < st->n_cols; i++)
    {
        if (! GPOINTER_TO_INT (g_slist_nth (list->list, i)->data))
            st->storeTypes[i] = G_TYPE_UINT;
        else
            st->storeTypes[i] = G_TYPE_STRING;
    }
    return ((prStoreTypes*) st);
}

