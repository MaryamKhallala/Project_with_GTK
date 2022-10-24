#ifndef str_pr_PANED
#define str_pr_PANED
#include"bibliotheque.h"

/**********************************************************************
*   Structure   :   prPaned
*   --------------------------
*       Le prPaned qui permet de creer un separateur pour la fenetre
*   en divison la fenetre en deux part avec un separateur non fix.
*        avec le choix du type de votre separateur soit horizontale soit
*    Verticale.
***********************************************************************/


typedef struct prpaned
{
  GtkWidget *paned;         // l'objet paned
  gchar type;               // le type
}prPaned;

#endif
