#ifndef str_pr_alignement
#define str_pr_alignement
#include"bibliotheque.h"
/****************************************************************
*   Structure   :   prAlignement
*   --------------------------
*       Le prAlignement est la structure qui represente l'objet
*    alignement qui nous peremet de construire une simple ligne
*    qui peut contenir un menu bar ou bien une label soit en haut
*    ou en bas de la fenetre
*        Les champs de cette stucture:
*            l'objet alignement
*            le conteneur de l'objet
*            la position x de l'objet
*            la position y de l'objet
*            la longeur de l'objet
*            la hauteur de l'objet
*
*****************************************************************/
 typedef struct prAlignement
 {
     GtkWidget *alignement; // note objet
     GtkWidget *pere;       // le conteneur
     gchar *nom;            // nom de l'objet
     gfloat xligne;         // position x
     gfloat yligne;         // position y
     gfloat xscal;          // longeur
     gfloat yscal;          //hauteur
 } prAlignement;
#endif // str_pr_alignement

