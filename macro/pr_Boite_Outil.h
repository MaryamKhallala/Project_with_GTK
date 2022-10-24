#ifndef pr_boite_outil
#define pr_boite_outil
#include"bibliotheque.h"

    // detruire une boite de dialog / widget
void pr_signal_destroy(GtkWidget *dialog);
    // lancer une boite
gint pr_signal_start(GtkWidget *dialog);
    // lier Widget avec une fonction creer
void pr_signal_connect(GtkWidget *widget,char *event,gpointer signal,
                          gpointer data);
    // Ajouter une widget a un container
void pr_container_add (GtkWidget *pere,GtkWidget *fils);

    // feremer l'application
void pr_signal_on_destroy(GtkWidget  *object,gpointer data);

    // changer size d'une Widget
void pr_resize(GtkWidget *element,gint h ,gint l);

#endif // pr_boite_outil


