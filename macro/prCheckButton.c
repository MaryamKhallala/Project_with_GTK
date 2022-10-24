#include"prCheckButton.h"
/*********************** prCheckButton *********************************/
/***************************************************************************
*   Fonction : prCheckButton * pr_check_button_init (gchar*,
*                                                          gchar*,
*                                                          gint,
*                                                          GtkWidget*)
*   ------------------------------------------------------------------------
*       Cette fonction fait l allocation et initialisation des champs
*   de la structure prCheckButton.
*
*   Entre   :   - Le text de la label du checkButton
*               - Le selectioneur du comboBox (pour le CSS)
*               - Un boolean pour dire si cretion avec mnemonic ou sans
*               - Le container ou nous allons mettre notre prCheckButton
*
*   Sortie  :   Un objet prCheckButton apres allocation et initialisation
***************************************************************************/
prCheckButton * pr_check_button_init (gchar *label, gchar *nom,
                                            gint mnemonic, GtkWidget *pere,int x ,int y)
{
    prCheckButton *bout = NULL;
    bout = (prCheckButton*)malloc (sizeof (prCheckButton));
    bout->pox=(prPos*)malloc(sizeof(prPos));
    bout->label = (gchar*)malloc (30*sizeof (gchar));
    bout->nom = (gchar*)malloc (30*sizeof (gchar));

    bout->racine = pere;
    bout->mnemonic = mnemonic;

    if (label) strcpy (bout->label, label);
    else bout->label = NULL;

    if (nom) strcpy (bout->nom, nom);
    else bout->nom = NULL;
    bout->pox->x=x;
    bout->pox->y=y;
    return ((prCheckButton*) bout);
}
/***************************************************************************
* Fonction : prCheckButton *pr_check_button_create (prCheckButton*)
*   ------------------------------------------------------------------------
*       Cette fonction fait la creation d un objet prCheckButton
*   Entre   :   Les donnees de l objet a creer
*   Sortie  :   L objet creer
*/

prCheckButton *pr_check_button_create(prCheckButton *btn)
{
    if (!btn) btn = (prCheckButton*)malloc(sizeof (prCheckButton));
    if ((btn->mnemonic) && (btn->label))
     btn->checkButton = gtk_check_button_new_with_mnemonic((btn->label));
    else if (btn->label)
     btn->checkButton = gtk_check_button_new_with_label(btn->label);
    else
     btn->checkButton = gtk_check_button_new_with_label("prCheckButton");
    if (btn->nom) gtk_widget_set_name(btn->checkButton, btn->nom);

    return ((prCheckButton*) btn);
}

