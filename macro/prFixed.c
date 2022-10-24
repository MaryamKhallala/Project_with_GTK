#include"prFixed.h"
/********************************prFixed **********************/
/******************************************************************
*   Fonction   :   prFixed* pr_fixed_init(GtkWidget *pere)
*   --------------------------------------------------------------
*       Cette fonction sert a initialiser notre fixed
*   Entre   :   Le container nous allons mettre notre prFixed
*   Sortie  :   prFixed
******************************************************************/
prFixed* pr_fixed_init(GtkWidget *pere)
{
    prFixed *f=(prFixed*)malloc(sizeof(prFixed));
   // f->pere=pere;
    return((prFixed*)f);
}
/******************************************************************
*   Fonction   :  prFixed* pr_fixed_create(prFixed *f)
*   ---------------------------------------------------------------
*       Cette dernier nous permet de creer un nouveau fixed
*   Entre   :   La structure prFixed
*   Sortie  :   prFixed apres la creation du fixed
******************************************************************/
prFixed* pr_fixed_create(prFixed *f)
{
    f->fixed=gtk_fixed_new ();
    return((prFixed*)f);
}
/******************************************************************
*   Fonction   :   prFixed* pr_fixed_add(prFixed *,
                                               GtkWidget *,
                                               gint ,
                                               gint y)

*   ---------------------------------------------------------------
*       Cette fonction nous donne la possibilité d'ajouter
*    un element de type GtkWidget a notre container
*   Entre   :   - Le container nous allons mettre notre GtkWidget
*               - L'element a inserer
*                - x : l'abscisse du cordonnée
*                - y : ordonnée du cordonée
*   Sortie  :   notre fixed apres l'insertion de l'element
******************************************************************/

prFixed* pr_fixed_add(prFixed *f,GtkWidget *fils,gint x ,
                            gint y)
{
    gtk_fixed_put (GTK_FIXED(f->fixed),fils,x,y);
    return((prFixed*)f);
}
/******************************************************************
*   Fonction   :   prFixed* pr_fixed_move(prFixed *,
                                                GtkWidget *,
                                                gint,
                                                gint )
*   ---------------------------------------------------------------
*       Cette fonction permet de faire deplacer un GtkWidget
*    qui est deja apartien a notre container Fixed
*   Entre   :  - Le container ou nous allons mettre notre GtkWidget
*                 apres deplacement
*              - La GtkWidget concerner
*               - x c'est le nouveau abscisse de notre GtkWidget
*               - y c'est le nouveau ordonné de notre GtkWidget
*   Sortie  :   le nouveau Container fixed apres la modification
******************************************************************/

prFixed* pr_fixed_move(prFixed *f,GtkWidget *fils,
                             gint x ,gint y)
{
    gtk_fixed_move (GTK_FIXED(f->fixed),fils,x,y);
    return((prFixed*)f);
}
/*************************** prSeparator **********************/
/******************************************************************
*   Fonction   :  prSeparator* pr_separator_create(char type)
*   ---------------------------------------------------------------
*      Cette fonction permet de creer un separateur et le retourner
*    il faut just mentionner quel type de separateur hor/vert
*   Entre   :   - un caractére qui indique le type du separateur
*   Sortie  :   - Un separateur creer
******************************************************************/
prSeparator* pr_separator_create(char type)
{
    prSeparator *separateur =
            (prSeparator*)malloc(sizeof(prSeparator));
    switch(type)
    {
    case 'h':separateur->separator=
            gtk_separator_new (GTK_ORIENTATION_HORIZONTAL);break;
    case 'v':separateur->separator=
            gtk_separator_new (GTK_ORIENTATION_VERTICAL);break;
    }
    return((prSeparator*)separateur);
}

