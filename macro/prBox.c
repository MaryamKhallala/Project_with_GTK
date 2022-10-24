#include"prBox.h"

/*********************************** BOX **********************************/

/***************************************************************************
*     Fonction  : prBox    *pr_box_init(GtkWidget *,
*                            gchar ,
*                            gchar *,
*                            gint ,
*                            gint )
*   ------------------------------------------------------------------------
*       Cette fonction fait l allocation et initialisation des champs
*   de la structure prBox.
*
*   Entre   :    - Le container ou nous allons mettre notre prBox.
*                - type du box vertical ou horizontal.
*                - le nom de notre box qui vas nous servire dans le Css.
*                - indicateur qui montre si le box est homogene ou non.
*                - espacement donner pour les element du box.
*
*   Sortie  : Une variable  de type prBox Bien initialiser et allouer
***************************************************************************/

prBox    *pr_box_init(GtkWidget *pere,gchar type,gchar *nom,
                            gint homogene,gint espacement)
{
    prBox *box=(prBox*)malloc(sizeof(prBox));

    if(!box) exit(1);
    box->nom=(gchar*)malloc(256*sizeof(gchar));
    strcpy(box->nom,nom);

    box->pere=pere;
    box->type=type;
    box->homogene=homogene;
    box->espacement=espacement;

    return ((prBox*)box);
}
/***************************************************************************
*   Fonction   :   prBox    *pr_box_create(prBox *)
*   ------------------------------------------------------------------------
*       Cette fonction sert a la creation d'un box a certaines
*    critére donner d'apres l'initialisation.
*
*   Entre   :   Notre variable de type prBox deja initialiser
*   Sortie  :   variable de type prBox apres la creation du box demenader
***************************************************************************/

prBox    *pr_box_create(prBox *box)
{
    if(!box)box=(prBox*)malloc(sizeof(prBox));
    if(box->type=='v' || box->type=='V')
    {
       if(box->homogene)
        {
           box->box= gtk_box_new (TRUE,box->espacement);
           gtk_orientable_set_orientation(GTK_ORIENTABLE(box->box),
                                          GTK_ORIENTATION_VERTICAL);
        }

       else
        {
           box->box= gtk_box_new(FALSE,box->espacement);
           gtk_orientable_set_orientation(GTK_ORIENTABLE(box->box),
                                          GTK_ORIENTATION_VERTICAL);
        }
    }
    else if(box->type=='h' || box->type=='H')
    {
       if(box->homogene)
        {
           box->box=gtk_box_new(TRUE,box->espacement);
           gtk_orientable_set_orientation(GTK_ORIENTABLE(box->box),
                                          GTK_ORIENTATION_HORIZONTAL);
        }

       else
        {
           box->box=gtk_box_new(FALSE,box->espacement);
           gtk_orientable_set_orientation(GTK_ORIENTABLE(box->box),
                                          GTK_ORIENTATION_HORIZONTAL);
        }
    }
    else printf("\n Le type citer n'esxiste pas ");

    if(box->nom) gtk_widget_set_name (box->box,box->nom);

  return ((prBox*)box);
}
/***************************************************************************
*   Fonction   :   void    pr_box_add(GtkWidget *,
*                                         GtkWidget *,
*                                         gboolean ,
*                                         gboolean ,
*                                         gint )
*   ------------------------------------------------------------------------
*       Cette fonction sert à ajouter un element de Type GtkWidget a notre
*    Box .
*   Entre   :    - le box qui vas contenir l'element
*                - element à a ajouter
*                - un gboolean qui nous donne la valeur de l'expand si true
*        alors tous element qui vas etre dans ce box occupe le meme espace
*                - le padding c'est l'espacement entre les elements cituer
*        dans le meme box.
*   Sortie  : void (avoir le box avec l'element ajouter)
***************************************************************************/
void    pr_box_add(GtkWidget *box,GtkWidget *elem,gboolean expand,
                      gboolean fill,gint padding)
{
    gtk_box_pack_start (GTK_BOX (box),elem,expand,fill,padding);
}
/***************************************************************************
*   Fonction   :  void  pr_box_add_end(GtkWidget *,
*                                         GtkWidget *,
*                                         gboolean ,
*                                         gboolean ,
*                                         gint )
*   ------------------------------------------------------------------------
*       Cette fonction sert à ajouter un element de Type GtkWidget a notre
*    Box .
*   Entre   :    - le box qui vas contenir l'element
*                - element à a ajouter
*                - un gboolean qui nous donne la valeur de l'expand si true
*        alors tous element qui vas etre dans ce box occupe le meme espace
*                - le padding c'est l'espacement entre les elements cituer
*        dans le meme box.
*   Sortie  : void (avoir le box avec l'element ajouter à la fin )
***************************************************************************/
void    pr_box_add_end(GtkWidget *box,GtkWidget *elem,gboolean expand,
                          gboolean fill,gint padding)
{
    gtk_box_pack_end(GTK_BOX (box),elem,expand,fill,padding);
}

