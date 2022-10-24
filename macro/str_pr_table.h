#ifndef str_pr_table
#define str_pr_table
#include"bibliotheque.h"
/********************************************************************
*   Structure   :   prTable
*   --------------------------
*       Le prTable Est la structure qui peremet de creer un tableau
*    rassemble a grille dans gtk3
**********************************************************************/
typedef struct prTable
{
  GtkWidget *table;             // l'objet table
  GtkWidget *pere;              // le contenaire
  int nbr_lignes;               // nombre de ligne
  int nbr_colonnes;             // nombre de collone
  int homogene;                 /*  TRUE , 0: pour FALSE */
} prTable;
#endif // str_pr_table

