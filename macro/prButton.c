#include"prButton.h"
/****************************** Button ***********************************/
/*************************************************************************
*   Fonction : prButton * pr_button_init (gchar *,
*                                                gchar *,
*                                                gchar *,
*                                                gint ,
*                                                GtkWidget *)
*   ----------------------------------------------------------------------
*       Cette fonction nous permet de faire l'allocation de la structure
*    du button et initialiser leur champs.
*
*   Entre   :  - Le text de la label du Button
*              - L'id d'icon du Stock
*              - Le nom du button si on veut appliquer un theme en css
*              - Un boolean pour dire si cretion avec mnemonic ou sans
*              - Le container ou nous allons mettre notre Button
*
*   Sortie  :   Un objet prButton apres allocation et initialisation
***************************************************************************/

prButton * pr_button_init (gchar *label, gchar *stock_icon,gchar *nom,
                                 gint mnemonic,GtkWidget *pere,int x ,int y,int type)
{
    prButton *bout = NULL;
    bout=(prButton*)malloc(sizeof(prButton));
    bout->pox=(prPos*)malloc(sizeof(prPos));
    bout->racine=pere;
    bout->label=(gchar*)malloc(256 *sizeof(gchar));
    bout->stock_icon=(gchar*)malloc(256*sizeof(gchar));
    bout->nom=(gchar*)malloc(256*sizeof(gchar));
    if(label)
        strcpy(bout->label,label);
    else bout->label = NULL;

    if(stock_icon)
             strcpy(bout->stock_icon,stock_icon);
    else     bout->stock_icon = NULL;

    if(nom)  strcpy(bout->nom,nom);
    else     bout->nom=NULL;

    bout->mnemonic=mnemonic;
    bout->pox->x=x;
    bout->pox->y=y;
    bout->type_special=type;

    return((prButton*)bout);
}
/***************************************************************************
*   Fonction   :  prButton *pr_button_create(prButton *btn)
*   ------------------------------------------------------------------------
*
*        Cette fonction fait la creation d un objet prButton avec
*   les meme caractéristiques citer dans l'initialisation.
*
*   Entre   :   Les donnees de l objet a creer
*                (Stocker dans la meme structure)
*   Sortie  :   L'objet creer
***************************************************************************/
prButton *pr_button_create(prButton *btn)
{
    if(!btn) btn=(prButton*)malloc(sizeof(prButton));

    if(btn->mnemonic && btn->label)
        btn->button=gtk_button_new_with_mnemonic(_(btn->label));
    else
    if(btn->stock_icon)
        btn->button=gtk_button_new_from_stock (btn->stock_icon);
    else
    if(btn->label)
       btn->button=gtk_button_new_with_label(btn->label);
    else
      btn->button=gtk_button_new_with_label("");
    if(btn->nom) gtk_widget_set_name(btn->button,btn->nom);
    switch(btn->type_special)
    {
        case 0 :break;
        case 1:
            btn->button = gtk_file_chooser_button_new(btn->label,GTK_FILE_CHOOSER_ACTION_OPEN);
            break;
        case 2:
            btn->button = gtk_color_button_new();
            break;
        case 3:
            btn->button = gtk_font_button_new();
            break;
        default: break;
    }
    return ((prButton*)btn);
}

