#ifndef str_pr_box
#define str_pr_box
#include"bibliotheque.h"

/***************************************************************
*   Structure   :   prBox
*   --------------------------
*       Le prBox est un conteneur global des widget, permet
*    d'inserer plusieurs widget dans le meme conteneur .
*        Avoir deux type soit horizontale ou vertical
*        Cette structure à comme champ:
*            le box notre objet
*            leur conteneur
*            nom de l'objet
*            le type de l'objet
*            s'il est homogene
*            espacement entre les widget
**************************************************************/
typedef struct prBox
{
    GtkWidget   *box;        //l'objet
    GtkWidget   *pere;       // le conteneur
    gchar       *nom;        // nom de l'objet
    gchar       type;        //type du box ( t v )
    gint        homogene;    // homogene ou non (1 0 )
    gint        espacement;  // espacement le contenue
} prBox;
#endif // str_pr_box

