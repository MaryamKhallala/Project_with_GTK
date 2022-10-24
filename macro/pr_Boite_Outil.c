#include"pr_Boite_Outil.h"
/**********************************************************************
*   Fonction   :   static void pr_signal_destroy(GtkWidget *)
*   ------------------------------------------------------------------
*       Cette fonction permet à detruire n'import qu'elle widget
*   Entre   :   La widget qu'on veux detruire
*
*   Sortie  :   void
*/
void pr_signal_destroy(GtkWidget *dialog)
{
    gtk_widget_destroy(dialog);
}
/**********************************************************************
*   Fonction   :   Istatic gint pr_signal_start(GtkWidget *)
*   ------------------------------------------------------------------
*       Cette fonction nous offres la possibiliter de lancer une boite
    sois du dialog / du message ou about
*   Entre   :   notre Boite
*
*   Sortie  :   entier qui indique l'etat que l'etat et bien fait ou non
*/
gint pr_signal_start(GtkWidget *dialog)
{
    return(gtk_dialog_run(GTK_DIALOG(dialog)));
}
/**********************************************************************
*   Fonction   :  void pr_container_add (GtkWidget *,
                                            GtkWidget *)
*   ------------------------------------------------------------------
*       Cette fonction fait l allocation et initialisation des champs
*   de la structure prComboBox
*   Entre   :   Le container nous allons mettre notre prComboBox
*               Le selectioneur du comboBox (pour le CSS)
*   Sortie  :
*/
void pr_container_add (GtkWidget *pere,GtkWidget *fils)
{
    gtk_container_add (GTK_CONTAINER (pere), fils);
}
/**********************************************************************
*   Fonction   :   void pr_signal_connect(GtkWidget *,
                                             char *,
                                             gpointer ,
                                             gpointer )
*   ------------------------------------------------------------------
*       Cette fonction sert a connecter une widget a un signal definis
*   Entre   :   - widget
                - signal
                - la data
*   Sortie  :
*/
void pr_signal_connect(GtkWidget *widget,char *event,gpointer signal,
                          gpointer data)
{
     g_signal_connect(GTK_CONTAINER(widget),event,
                      G_CALLBACK(signal),data);
}

/**********************************************************************
*   Fonction   :   void pr_signal_on_destroy(GtkWidget  *,
                                                gpointer )
*   ------------------------------------------------------------------
*       Cette fonction sert a detruite l'application
*   Entre   :   -widget object
                - gpointer pour la data a passer
*               Le selectioneur du comboBox (pour le CSS)
*   Sortie  :
*/
void pr_signal_on_destroy(GtkWidget  *object,gpointer user_data)
{
    gtk_main_quit();
}

/*************************** Positionnement ***************************/
/**********************************************************************
*   Fonction   :   void pr_resize(GtkWidget *,
*                                     gint  ,
*                                     gint )
*   ------------------------------------------------------------------
*       Cette fonction sert a changer la dimension d'une widget
*    qu'il conque
*   Entre   :   - Widget
*                - hauteur
*                - largeur
*
*   Sortie  : void (la widget apres qu'on applique la nouvelle size
***********************************************************************/
void pr_resize(GtkWidget *element,gint h ,gint l)
{
        gtk_widget_set_size_request (element,h,l);
}

/*************************** Positionnement ***************************/
/**********************************************************************
*   Fonction   :   void pr_resize(GtkWidget *,
*                                     gint  ,
*                                     gint )
*   ------------------------------------------------------------------
*       Cette fonction sert a changer la dimension d'une widget
*    qu'il conque
*   Entre   :   - Widget
*                - hauteur
*                - largeur
*
*   Sortie  : void (la widget apres qu'on applique la nouvelle size
***********************************************************************/
void pr_start_application(int *argc,char ***argv)
{
        gtk_init(argc,argv);
}
