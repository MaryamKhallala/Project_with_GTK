#include"str_pr_box.h"
///*************************** BOX *******************/
prBox    *pr_box_init(GtkWidget *pere,
                            gchar type,
                            gchar *nom,
                            gint homogene,
                            gint espacement);
prBox* pr_box_create(prBox *box);
void pr_box_add(GtkWidget *box,
                   GtkWidget *elem,
                   gboolean expand,
                   gboolean fill,
                   gint padding);
void    pr_box_add_end(GtkWidget *box,
                          GtkWidget *elem,
                          gboolean expand,
                          gboolean fill,
                          gint padding);

