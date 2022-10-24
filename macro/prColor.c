#include"prColor.h"
/********************************** Couleur *******************************/

/***************************************************************************
*   Fonction   :  prColor pr_color_init(prColor ,
*                                              guint16 ,
*                                              guint16 ,
*                                              guint16 ,
*                                              int )
*   ------------------------------------------------------------------------
*       Cette fonction fait l'initialisation du coleur par un pourcentage
*   du coleur principale Rouge/Vert/Bleu.
*
*   Entre   :  - Une variable de type prColor pour la remplir
*              - valeur du rouge
*              - valeur du vert
*              - valeur du bleu
*              - choix de methode a poser la coleur
*
*   Sortie  : La variable coleur apres le remplissage
***************************************************************************/
prColor* pr_color_init(double R,double V,
                            double B,int C)
{
    prColor *Coul=(prColor*)malloc(sizeof(prColor));
    Coul->bleu = B;
    Coul->rouge = R;
    Coul->vert = V;
    Coul->choix = C;

    return ((prColor*)Coul);
}
/***************************************************************************
*   Fonction   :   void pr_color_create(prColor ,
*                                           GtkWidget *)
*   ------------------------------------------------------------------
*
*       Cette fonction permet d'appliquer la coleur demander a la widget
*  citer en parametre ,tous ca en utilise le type GdkColor.
*
*   Entre   :   - La coleur demander
*               - Widget d'application
*
*   Sortie  : void, application direct de la commande donner
***************************************************************************/

void pr_color_create(prColor *C,GtkWidget *widget)
{
    GdkRGBA color;
    color.alpha = 32;
    color.red = C->rouge;
    color.green = C->vert;
    color.blue = C->bleu;
    switch(C->choix)
    {
        case 1 :
            gtk_widget_modify_bg (widget, GTK_STATE_NORMAL, &color);
            break;
        case 2 :
            gtk_widget_modify_bg (widget, GTK_STATE_ACTIVE, &color);
            break;
        case 3 :
            gtk_widget_modify_bg (widget, GTK_STATE_PRELIGHT, &color);
            break;
        case 4 :
            gtk_widget_modify_bg (widget, GTK_STATE_SELECTED, &color);
            break;
        case 5 :
            gtk_widget_modify_bg (widget, GTK_STATE_INSENSITIVE, &color);
            break;
        default :
            gtk_widget_modify_bg (widget, GTK_STATE_NORMAL, &color);
            break;
    }
}


