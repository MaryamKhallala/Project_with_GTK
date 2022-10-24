#include"prAlignement.h"
/************************* alignenment *************************************/

/***************************************************************************
*
*   Fonction   :  prAlignement *pr_alignement_init(GtkWidget *,
*                                                         gchar *,
*                                                         gfloat ,
*                                                         gfloat ,
*                                                         gfloat ,
*                                                         gfloat)
*   ------------------------------------------------------------------------
*       Cette fonction fait l allocation et initialisation des champs
*   de la structure prAlignement.
*
*   Entre   :   - le container  ou nous allons mettre notre prAlignement
*                - nom de l'alignement qui vas nous servire dans CSS
*                - xl float qui est entre 0 et 1 qui conserne l'alignement
*        horizontal de widget
*                - yl float qui est entre 0 et 1 qui conserne l'alignement
*        vertical de widget
*                - xs float qui est meme entre 0 et 1 qui indique
*        la taille horizontal qui vas prendre la widget par rapport a note
*        prAlignement
*                - ys float qui est meme entre 0 et 1 qui indique la taille
*        vertical qui vas prendre la widget par rapport a note
*        prAlignement
*
*   Sortie  :   - notre Alignement apres initialiser
***************************************************************************/

prAlignement *pr_alignement_init(GtkWidget *pere,gchar *nom,gfloat xl,
                                        gfloat yl,gfloat xs,gfloat ys)
{
    prAlignement *alignement=
                        (prAlignement*)malloc(sizeof(prAlignement));
    if(!alignement) exit(1);
    alignement->nom=(gchar*)malloc(30*sizeof(gchar));

    alignement->pere=pere;
    alignement->xligne=xl;
    alignement->yligne=yl;
    alignement->xscal=xs;
    alignement->yscal=ys;
    strcpy(alignement->nom,nom);

    return ((prAlignement*)alignement);
}

/***************************************************************************
*   Fonction  : prAlignement *pr_alignement_create (prAlignement* )
*
*   ------------------------------------------------------------------------
*     Cette fonction permet la creation de l'alignement a certains critaires
*   deja initialiser.
*
*   Entre   :   La variable prAlignement qui comporte les critaires
*             de l'alignement
*
*   Sortie  :   Notre Alignement apres la creation
***************************************************************************/

prAlignement *pr_alignement_create (prAlignement *a)
{
    if(!a)a=(prAlignement*)malloc(sizeof(prAlignement));

    a->alignement= gtk_alignment_new (a->xligne,a->yligne,a->xscal,a->yscal);
    gtk_widget_set_name (a->alignement,a->nom);

    return ((prAlignement*)a);
}

