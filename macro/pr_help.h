#ifndef _help_
#define _help_

#include"pr_assistant.h"
    // la page d'aide d'une window
void pr_window_help(GtkWidget *win,gpointer *data);

    // la bon fermeture de la page d'aide
void fermeture (GtkWidget *widget,GdkEvent *event, gpointer *data);

    // la page initiale qui definis les devellopeurs de l'application
void pr_application_writer(GtkWidget *win,gpointer *data);

    // la page d'aide d'une boite de dialog
void pr_dialog_help(GtkWidget *win,gpointer *data);

    //la page d'aide d'une boite de message
void pr_message_help(GtkWidget *win,gpointer *data);

    // la page d'aide d'une boite about
void pr_about_help(GtkWidget *win,gpointer *data);

    // la page d'aide des fonctions arithmetique
void pr_arithmetique_help(GtkWidget *win,gpointer *data);


#endif
