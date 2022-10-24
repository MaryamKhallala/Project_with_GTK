#include"str_scrolled_window.h"
/*Creaton */
    prScrolledWindow  *pr_scrolled_window_init (GtkWidget *,
                                                      gchar *,
                                                      gint ,
                                                      gint ,
                                                      gint );
/* Creation */
    prScrolledWindow  *pr_scrolled_window_create (prScrolledWindow *);
/* Ajout */
    void    pr_scrolled_window_add (prScrolledWindow *,
                                       GtkWidget *);

