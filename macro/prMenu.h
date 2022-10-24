#ifndef pr_menu
    #define pr_menu
    #include"bibliotheque.h"
    #include"prAbout.h"
    #include"prMessage.h"
    #include"prDialog.h"
    #include"prNotebook.h"

    /* ajout au menu */
        void pr_menu_add (GtkUIManager * p_uiManager,
                             GtkWidget * p_widget,
                             GtkContainer * p_box);
    /* creation menu */
        GtkWidget* pr_menu_create(GtkWidget *p_vprBox,
                                     prNotebook *note);
     void pr_signal_menu_about (void);
    void pr_signal_menu_help(void);
    void pr_signal_menu_quit (void);
   void text_edit_register_filename(gchar *fname, gint tab_num);

#endif // pr_menu


