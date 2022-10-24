#ifndef str_pr_treeview
#define str_pr_treeview
#include"bibliotheque.h"
/************************************************************
*   Structure   :   prTreeView
*   -----------------------------
*       Le prTreeView permet de creer une list d'affichage
**************************************************************/
typedef struct prTreeView
{
    GtkWidget   *treeView;      // l'objet treeview
    GtkWidget   *racine;        // le conteneur
    gchar       *nom;           // nom de l'objet
    gint        n_cols;         // nombre de collone
} prTreeView;
#endif // str_pr_treeview

