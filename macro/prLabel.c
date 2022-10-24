#include"prLabel.h"
/*********************************** Label *************************/
/*******************************************************************
*   Fonction   :   prLabel* pr_label_init(GtkWidget *,char *)
*   ----------------------------------------------------------------
*       Cette fonction permet d'initialiser notre Label pour
*    effectuer apres la creation
*   Entre   :   - Le container nous allons mettre notre prLabel
*               - une chaine de caratere qui vas etre le contenue
*                de notre label.
*   Sortie  : notre label apres initialisation
********************************************************************/
prLabel* pr_label_init(GtkWidget *pere,char text[200],int x ,int y)
{
    prLabel *Lab=(prLabel*)malloc(sizeof(prLabel));
    Lab->pox=(prPos*)malloc(sizeof(prPos));
    strcpy(Lab->text_lab,text);
    Lab->pere=pere;
    Lab->pox->x=x;
    Lab->pox->y=y;
    return ((prLabel*)Lab);
}
/********************************************************************
*   Fonction   :   prLabel* pr_label_create(prLabel *l)
*   ------------------------------------------------------------------
*       Cette fonction concerne just la creation de label avec
*    les critaire citer dans l'initialisation
*   Entre   :   La variable de type prLabel qui contient
*            les critaire
*   Sortie  :   prLabel apres la création avec les parametre citer
*********************************************************************/
prLabel* pr_label_create(prLabel *l)
{
    l->label=gtk_label_new(l->text_lab);
   return ((prLabel*)l);
}

