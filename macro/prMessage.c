
#include"prMessage.h"

/************************** Boite Message **************************/

/*******************************************************************
*   Fonction   :  prMessage    *pr_message_init(int ,
*                                                      int ,
*                                                      int ,
*                                                      char *)
*   -----------------------------------------------------------------
*       Cette fonction peremet d'allouer et initialiser la structure
*    prMessage
*   Entre   :   -flag:
*                        1 = GTK_DIALOG_MODAL
*                        2 = GTK_DIALOG_DESTROY_WITH_PARENT
*                -type:
*                        1 = GTK_MESSAGE_INFO
*                        2 = GTK_MESSAGE_WARNING
*                        3 = GTK_MESSAGE_QUESTION
*                        4 = GTK_MESSAGE_ERROR
*                -type_boutton
*                        0 = GTK_BUTTONS_NONE
*                        1 = GTK_BUTTONS_OK
*                        2 = GTK_BUTTONS_CLOSE
*                        3 = GTK_BUTTONS_CANCEL
*                        4 = GTK_BUTTONS_YES_NO
*                        5 = GTK_BUTTONS_OK_CANCEL
*                - message a informer
*
*   Sortie  : Notre boite de Message bien initaliser
********************************************************************/
prMessage    *pr_message_init(int flag,int type,
                                    int type_boutton,
                                    char *message_afficher)
{
    prMessage *b=(prMessage*)malloc(sizeof(prMessage));
    b->message_a_afficher=(char*)malloc(300*sizeof(char));
    b->flag=flag;
    b->type_message=type;
    b->type_boutton=type_boutton;
if(message_afficher)
    strcpy(b->message_a_afficher,message_afficher);

    return ((prMessage*)b);
}
/********************************************************************
*   Fonction   :   prMessage *pr_message_create(prMessage *)
*   -----------------------------------------------------------------
*       Cette fonction permet de creer une boite de message
*    a certains critaire citer dans leur initialisation
*   Entre   :  Une variable de type prMessage deja initaliser
*   Sortie  :  retourner la variable prMessage apres la creation
*        que nous decide.
********************************************************************/
prMessage    *pr_message_create(prMessage *dialog)
{
   GtkDialogFlags flag;
   GtkMessageType type;
   GtkButtonsType btn;
   dialog->pere=gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_icon_from_file(GTK_WINDOW(dialog->pere),
                                 "favicon.ico",NULL);
  switch(dialog->flag)
   {
        case 1: flag=GTK_DIALOG_MODAL;break;
        case 2: flag=GTK_DIALOG_DESTROY_WITH_PARENT;break;
        default: flag=GTK_DIALOG_DESTROY_WITH_PARENT;break;
   }
   switch(dialog->type_message)
   {
   case 1:
        type=GTK_MESSAGE_INFO ;break;
   case 2:
       type=GTK_MESSAGE_WARNING;break;
   case 3:
       type=GTK_MESSAGE_QUESTION;break;
   case 4:
       type=GTK_MESSAGE_ERROR;break;
   default:type=GTK_MESSAGE_INFO;break;
   }
   switch(dialog->type_boutton)
   {
   case 0:btn=GTK_BUTTONS_NONE;break;
   case 1:btn=GTK_BUTTONS_OK;break;
   case 2:btn=GTK_BUTTONS_CLOSE;break;
   case 3:btn=GTK_BUTTONS_CANCEL;break;
   case 4:btn=GTK_BUTTONS_YES_NO;break;
   case 5:btn=GTK_BUTTONS_OK_CANCEL;break;
    default:btn=GTK_BUTTONS_NONE;break;
   }


    if(dialog->type_boutton==0)
    {
      if(dialog->pere)
        dialog->message= gtk_message_dialog_new(GTK_WINDOW(dialog->pere),
                                                flag,type,btn,
                                                dialog->message_a_afficher);
      else
        dialog->message= gtk_message_dialog_new(NULL,flag,type,btn,
                                                dialog->message_a_afficher);
    }


    if(0 < dialog->type_boutton && dialog->type_boutton < 4)
    {
        if(dialog->pere)
            dialog->message= gtk_message_dialog_new(GTK_WINDOW(dialog->pere),
                                                    flag,type,btn,
                                                    dialog->message_a_afficher);
        else
            dialog->message= gtk_message_dialog_new(NULL,flag,type,btn,
                                                    dialog->message_a_afficher);
    }

    if(3 < dialog->type_boutton)
    {
        if(dialog->pere)
            dialog->message=
               gtk_message_dialog_new(GTK_WINDOW(dialog->pere),
                                                 flag,type,btn,
                                                 dialog->message_a_afficher);
        else
            dialog->message=
                gtk_message_dialog_new(NULL,flag,type,btn,
                                       dialog->message_a_afficher);
    }
    return ((prMessage*)dialog);
}
