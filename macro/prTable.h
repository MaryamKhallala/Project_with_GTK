#include"str_pr_table.h"
/****************** table **********************/
/* Inialisation */
    prTable* initialiser_table(GtkWidget *pere,
                                  int nb_ligne,
                                  int nb_collone,
                                  int homogene);
/* Creation */
    prTable* pr_table_create(prTable *tab);
/* ajout */
    void pr_table_add(prTable *tab,
                         GtkWidget *fils,
                         int gauche,
                         int droite,
                         int haut,
                         int bas);


