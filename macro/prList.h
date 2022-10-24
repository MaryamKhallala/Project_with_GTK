#include"str_pr_list.h"
/********************* prList *********************/
/* initalisation */
prList *pr_list_init ();
/* creation */
prList *pr_list_create (prList *list);

/* ajouter un entier */
prList    *pr_list_add_int (prList *list,
                                  gint element);
/* ajouter une chaine de caractere*/
prList    *pr_list_add_string (prList *list,
                                     gchar *element);

