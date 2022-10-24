#include"prCombobox.h"
/******************************* prComboBox*****************************/

/***************************************************************************
*   Fonction   :   prComboBox *pr_combo_box_init (GtkWidget*, gchar*)
*   ------------------------------------------------------------------
*
*       Cette fonction fait l allocation et initialisation des champs
*   de la structure prComboBox
*   Entre   :   - Le container nous allons mettre notre prComboBox
*               - Le selectioneur du comboBox (pour le CSS)
*
*   Sortie  :   Un objet prComboBox apres allocation et initialisation
***************************************************************************/

prComboBox    *pr_combo_box_init (GtkWidget *racine, gchar *nom,int x,int y)
{
    prComboBox    *cb = NULL;
    cb = (prComboBox*) malloc (sizeof (prComboBox));
    cb->pox=(prPos*)malloc(sizeof(prPos));
    cb->comboBox = NULL;
    cb->racine = racine;

    if (nom)
    {
        cb->nom = (gchar*) malloc (35*sizeof (gchar));
        strcpy (cb->nom, nom);
    }
    else cb->nom = NULL;
    cb->pox->x=x;
    cb->pox->y=y;
    return ((prComboBox*) cb);
}
/***************************************************************************
*   Fonction : prComboBox *pr_combo_box_create (prComboBox *cb)
*   ------------------------------------------------------------------
*
*       Cette fonction fait l allocation et initialisation des champs
*   de la structure prComboBox.
*
*   Entre   :   - Les donnees de l objet a creer
*   Sortie  :   - L'objet creer
***************************************************************************/
prComboBox    *pr_combo_box_create (prComboBox *cb)
{
    cb->comboBox = gtk_combo_box_text_new();
    gtk_widget_set_name (cb->comboBox, cb->nom);

    return ((prComboBox*) cb);
}
/***************************************************************************
*   Fonction   : void pr_combo_box_add (prComboBox*, gchar*)
*   ---------------------------------------------------------------
*       Cette fonction fait l ajout d un nouveau champs a au comboBox
*   passe en atguments.
*
*   Entre   :   - L'objet comboBox des items
*               - Le text de l item a ajouter
*   Sortie  :   void
***************************************************************************/
void    pr_combo_box_add (prComboBox *cb, gchar *text)
{
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(cb->comboBox), NULL, text);
    gtk_combo_box_set_active(GTK_COMBO_BOX(cb->comboBox), 0);
}
/***************************************************************************
*   Fonction   : void pr_combo_box_get (prComboBox*)
*   ---------------------------------------------------------------
*       Cette fonction retourne le text de l item selectionner dans
*   un comboBox donne.
*
*   Entre   :   L objet comboBox des items
*   Sortie  :   Le text de l item selectionnee
***************************************************************************/
gchar   *pr_combo_box_get (prComboBox *cb)
{
    return ((gchar*) gtk_combo_box_text_get_active_text(
                                        GTK_COMBO_BOX_TEXT(cb->comboBox)));
}

gchar * pr_combo_box_value(prComboBox *combo)
{

    gboolean b_ret = FALSE;
    GtkTreeIter iter;
    gchar *conteneur;
    g_return_val_if_fail (combo->comboBox != NULL, conteneur);
    b_ret = gtk_combo_box_get_active_iter (combo->comboBox, &iter);
    if (b_ret)
        {
          GtkTreeModel *p_model = NULL;
          p_model = gtk_combo_box_get_model (combo->comboBox);
            if (p_model != NULL)
                  gtk_tree_model_get (p_model, &iter, 0, &conteneur, -1);
        }
    ((gchar*)conteneur);
}
