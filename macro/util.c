#include "util.h"

void pr_add_container(GtkContainer* container,GtkWidget* widget)
{
    gtk_container_add(container,widget);
}

void pr_set_size(GtkWidget* widget,gint width,gint height)
{
    gtk_widget_set_size_request(widget,width,height);
}

void pr_set_bg(GtkWidget* widget,GtkStateType state,GdkColor* color)
{
    gtk_widget_modify_bg(widget,state,color);
}

void pr_show(GtkWidget* widget)
{
    gtk_widget_show_all(widget);
}

void pr_init(int argc,char *argv[])
{
    gtk_init(&argc,&argv);
}

void pr_main()
{
    gtk_main();
}
