#ifndef util
#define util
#include "bibliotheque.h"

void pr_add_container(GtkContainer* container,GtkWidget* widget);

void pr_set_size(GtkWidget* widget,gint width,gint height);

void pr_set_bg(GtkWidget* widget,GtkStateType state,GdkColor* color);

void pr_show(GtkWidget* widget);

void pr_init(int argc,char *argv[]);

void pr_main();
#endif
