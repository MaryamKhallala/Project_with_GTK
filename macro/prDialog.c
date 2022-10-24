#include"prDialog.h"
#include"bibliotheque.h"

/***************************************************************************
*   Fonction   :   prDialog *pr_dialog_init(int ,
*                                                  int ,
*                                                  char *,
*                                                  gint ,
*                                                  gint
*                                                  )
*   ------------------------------------------------------------------------
*       Cette fonction fait l allocation et initialisation des champs
*   de la structure prDialog
*   Entre   :   - le flag du button
*                        1 = GTK_DIALOG_MODAL
*                        2 = GTK_DIALOG_DESTROY_WITH_PARENT
*                - le type du button
*                        1 = GTK_STOCK_OK
*                        2 = GTK_STOCK_CLOSE
*                        3 = GTK_STOCK_CANCEL
*                        4 = GTK_STOCK_YES && GTK_STOCK_NO
*                        5 = GTK_STOCK_OK && GTK_STOCK_CANCEL
*                        6 = GTK_STOCK_OK && GTK_STOCK_CLOSE
*                - Titre de la boite a creer
*                - Taille hauteur de la boite
*                - Taille largeur de la boite
*   Sortie  :   Notre boite du dialog apres l'allocation et l'initialiser
***************************************************************************/
prDialog *pr_dialog_init(int flag,int type_boutton,
                                char *titre,gint h,gint l)
{
    prDialog *b=(prDialog*)malloc(sizeof(prDialog));
    b->titre=(char*)malloc(80*sizeof(char));
    if(titre)
    strcpy(b->titre,titre);

    b->flag=flag;
    b->type_boutton=type_boutton;
    b->hauteur=h;
    b->largeur=l;

    return ((prDialog*)b);
}
/***************************************************************************
*   Fonction   :   prDialog* pr_dialog_create(prDialog *dialog)
*   ------------------------------------------------------------------
*
*       Cette fonction vas nous permet de faciliter la creation d'une boite
*    du dialogue avec des critére deja citer au niveau du initialisation
*   Entre   :  Une variable de type prDialog qui contient leur
*             caractérisque
*   Sortie  :  La meme variable apres q'on assure la creation de la boite
*             que nous voullons.
***************************************************************************/
prDialog* pr_dialog_create(prDialog *dialog)
{

   GtkDialogFlags flag;
   GtkStockItem *btn;
   GtkStockItem *btn1;
   GtkResponseType reponse1;
   GtkResponseType reponse2;

      dialog->pere=gtk_window_new (GTK_WINDOW_TOPLEVEL);
      gtk_window_set_icon_from_file(GTK_WINDOW(dialog->pere),
                                    "favicon.ico",NULL);
      gtk_window_set_default_size(GTK_WINDOW(dialog->pere),
                                dialog->hauteur,dialog->largeur);
      gtk_window_set_position(GTK_WINDOW(dialog->pere),
                              GTK_WIN_POS_CENTER);
  switch(dialog->flag)
   {
        case 1: flag=GTK_DIALOG_MODAL;break;
        case 2: flag=GTK_DIALOG_DESTROY_WITH_PARENT;break;
        default: flag=GTK_DIALOG_DESTROY_WITH_PARENT;break;
   }

   switch(dialog->type_boutton)
   {
   case 1:btn=GTK_STOCK_OK;
          reponse1=GTK_RESPONSE_OK;
          break;
   case 2:btn=GTK_STOCK_CLOSE;
          reponse1=GTK_RESPONSE_CLOSE;
          break;
   case 3:btn=GTK_STOCK_CANCEL;
          reponse1=GTK_RESPONSE_CANCEL;
          break;
   case 4:btn=GTK_STOCK_YES;
          btn1=GTK_STOCK_NO;
          reponse1=GTK_RESPONSE_YES;
          reponse2=GTK_RESPONSE_NO;
          break;
   case 5:btn=GTK_STOCK_OK;
          btn1=GTK_STOCK_CANCEL;
          reponse1=GTK_RESPONSE_OK;
          reponse2=GTK_RESPONSE_CANCEL;
          break;
   case 6:btn=GTK_STOCK_OK;
          btn1=GTK_STOCK_CLOSE;
          reponse1=GTK_RESPONSE_OK;
          reponse2=GTK_RESPONSE_CLOSE;
    default:break;
   }



    if(0 < dialog->type_boutton && dialog->type_boutton < 4)
    {
        if(dialog->pere)
            dialog->dialog=
                    gtk_dialog_new_with_buttons(
                    dialog->titre,GTK_WINDOW(dialog->pere),
                    flag,btn,reponse1,NULL);
         else
            dialog->dialog= gtk_dialog_new_with_buttons(
                    dialog->titre,NULL,flag,btn,reponse1,NULL);
    }

    if(4 <= dialog->type_boutton)
    {
        if(dialog->pere)
            dialog->dialog= gtk_dialog_new_with_buttons(dialog->titre,
                            GTK_WINDOW(dialog->pere),flag,
                            btn,reponse1,btn1,
                            reponse2,NULL);
        else
            dialog->dialog= gtk_dialog_new_with_buttons(dialog->titre,NULL,
                            flag,btn,reponse1,btn1,
                            reponse2,NULL);
    }
/*
    GtkWidget *button_name_label =
            gtk_label_new("Press escape at any time to "
                          "cancel.\ntype in the button name");
    GtkWidget *entry=gtk_entry_new();

    pr_dialog_add(dialog,button_name_label);
    pr_dialog_add(dialog,entry);*/
           //gtk_widget_show_all((GtkWidget *)dialog->dialog);
return ((prDialog*)dialog);
}

/***************************************************************************
*   Fonction   :   static void pr_dialog_add(prDialog *,GtkWidget *)
*   ------------------------------------------------------------------
*       Cette fonction sert a ajouter n'import quelle element de type
*    GtkWidget à notre boite du dialog
*   Entre   :   - Le container ou nous allons ajouter notre Objet
*               - L'element à ajouter
*   Sortie  :
***************************************************************************/
void pr_dialog_add(prDialog *dialog,GtkWidget *elem)
{
    GtkWidget *container=
            gtk_dialog_get_content_area(GTK_DIALOG(dialog->dialog));
    gtk_container_add(GTK_CONTAINER(container), elem);

}

