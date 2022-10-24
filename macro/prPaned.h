#include"str_pr_paned.h"
/* inialisation */
prPaned* pr_paned_init(gchar type);
/*creation*/
prPaned* pr_paned_creat(prPaned *paned);
/*ajout*/
prPaned* pr_paned_add(prPaned *paned,
                            GtkWidget *element,
                            gchar emplacement);
