#include"str_pr_window.h"

///******************** prWindow ********************/
/* initialisation de la fenetre */
prWindow * pr_window_init (gchar *titre,
                                 gchar type,
                                 gchar *nom,
                                 gint h,
                                 gint l,
                                 gint position,
                                 gint resizable,
                                 gchar * icon);
/* Creation de la fenetre */
prWindow * pr_window_create (prWindow * prWindow);

