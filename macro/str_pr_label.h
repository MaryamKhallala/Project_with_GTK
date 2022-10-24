#ifndef str_pr_label
#define str_pr_label
#include"bibliotheque.h"

/************************************************************************
*   Structure   :   prLabel
*   --------------------------
*       Le prLabel est la structure qui peremet de creer une etiquette
*    composants de la structure :
*        - l'objet etiquette
*        - le conteneur
*        - le text à afficher
*        - la position de l'objet
*
*************************************************************************/
typedef struct prLabel
{
  GtkWidget *label;     // l'objet etiquette
  GtkWidget *pere;      // le conteneur
  char text_lab[200];   // text à afficher
  prPos *pox;        // la position de l'objet
} prLabel;
#endif // str_pr_label

