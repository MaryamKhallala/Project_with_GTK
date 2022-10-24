#ifndef str_pr_dialog
#define str_pr_dialog
#include"bibliotheque.h"

/*****************************************************************
*   Structure   :   prDialog
*   --------------------------
*       Le prDialog est la structure qui represente la fenetre
*    dialog avec ses caractéristique
*       Les composantes:
*     l'objet dialog
*     le conteneur
*     titre de la fenetre dialog
*     le flag ( une fenetre separer ou en relation avec le pere )
*     les differents button du boite dialog
*     la dimension de notre boite
******************************************************************/
typedef struct prDialog
{
  GtkWidget *dialog;                /* notre dialog de dialogue */
  GtkWidget *pere;                  /* Conteneur */
  char *titre;                      /* titre de la dialog de dialog */
                    /* valeurs possible  s:
                         1: GTK_DIALOG_MODAL;
                         2: GTK_DIALOG_DESTROY_WITH_PARENT;*/
  int flag;
  int type_boutton;
  gint hauteur;                     // la hauteur de la boite
  gint largeur;                     // largeur
} prDialog;
#endif // str_pr_dialog

