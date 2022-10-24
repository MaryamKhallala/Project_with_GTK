#include"prRadioButton.h"
/********************** prRadioButton *********************************/
/*************************************************************************
*   Fonction   :   prRadioButton *pr_radio_button_init (gchar *,
                                                              gchar,
                                                              gint,
                                                              GtkWidget *)
*   ------------------------------------------------------------------
*       Cette fonction fait l allocation et initialisation les champs
*   de la structure prRadioButton
*   Entre   : certaine caractéristique du button radio à creer
*               - Label du button
*               - nom du button qui vas nous aide a effectuer n'import
*                qu'il effet avec le CSS
*               - Un entier qui vas m'informer si le button avoir
*                une mnemonic ou non
*              - Le container ou nous allons mettre notre prRadioButton
*   Sortie  : Un objet prRadioButton apres allocation et initialisation
*************************************************************************/
prRadioButton *pr_radio_button_init (gchar *label, gchar *nom,
                                           gint mnemonic, GtkWidget *pere,int x,int y)
{
    prRadioButton *bout = NULL;
    bout = (prRadioButton*)malloc (sizeof (prRadioButton));
    bout->pox=(prPos*)malloc(sizeof(prPos));
    bout->racine = pere;
    bout->label = (gchar*)malloc (30*sizeof (gchar));
    bout->nom = (gchar*)malloc (30*sizeof (gchar));

    if (label)
        strcpy (bout->label, label);
    else bout->label = NULL;

    if (nom)
        strcpy (bout->nom, nom);
    else bout->nom = NULL;

    bout->mnemonic = mnemonic;
      bout->pox->x=x;
    bout->pox->y=y;
    return ((prRadioButton*) bout);
}

/*************************************************************************
*    Fonction : pr_radio_button_create(prRadioButton* ,
*                                         prRadioButton* )
*    --------------------------------------
*        Cette fonction prend une structure de type prRadioButton est
*    fait sa creation.
*        Entree : prRadioButton le radio a create
*        Sortie : Le button apres creation
*************************************************************************/
prRadioButton *pr_radio_button_create (prRadioButton *btn,
                                             prRadioButton *btn1)
{
    GtkWidget *group = NULL;
    if (btn1)
        group = btn1->radioButton;
    if ((btn->mnemonic) && (btn->label))
        btn->radioButton =
         gtk_radio_button_new_with_mnemonic_from_widget (
                                            GTK_RADIO_BUTTON (group),
                                            _(btn->label));
    else if ((btn->label))
      btn->radioButton =
        gtk_radio_button_new_with_label_from_widget (
                                        GTK_RADIO_BUTTON (group),
                                        btn->label);
    else
      btn->radioButton =
        gtk_radio_button_new_with_label_from_widget (
                                        GTK_RADIO_BUTTON (group),
                                        "prRadioButton");
    gtk_widget_set_name (btn->radioButton, btn->nom);
    if (btn->nom) gtk_widget_set_name(btn->radioButton,
                                      btn->nom);
    return ((prRadioButton*) btn);
}


