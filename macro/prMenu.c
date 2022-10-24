#include"prMenu.h"
#include"prScrolledWindow.h"
#include"prLabel.h"
#include"prWindow.h"
#include"prToolPallet.h"
#include"pr_help.h"
#include"prForm.h"
#include"prPaned.h"

typedef struct {
   prScrolledWindow *scrolled_window;
   GtkWidget *textview;
   prLabel *tab_label;
} prFileObject;
typedef struct {
   gchar *filename;
   gint tab_number;
} prFileData;
static int files_open = 0;

static GList *filename_data = NULL;   /* Linked list of open file names */
static PangoFontDescription *desc = NULL;   /* Global font for all tabs */

/*************************************************************************
*   Fonction   :   static void pr_signal_menu_about (void)
*   ----------------------------------------------------------------------
*
*   Entre   :
*   Sortie  :
*************************************************************************/
void pr_signal_menu_about (void)
{
     prAbout *ab=pr_about_init("Il-Inter Application ","1.0",
                                     " © copy right \nEDDAOUDI & BAAZIZ",
                                     "Demo Application ",
                                     "www.pr-inter.com",
                                     "il-inter_icon.png");
    pr_about_create(ab);
   return;
}

/*************************************************************************
*   Fonction   :   static void pr_signal_menu_quit (void)
*   ------------------------------------------------------------------
*
*   Entre   :
*   Sortie  :
*************************************************************************/
void pr_signal_menu_quit (void)
{
   prMessage *bt=pr_message_init(1,3,4,
                        "Voulez vous vraiment\nquitter ce programme?");
   bt=pr_message_create(bt);
switch(pr_signal_start(bt->message))
 {
        case GTK_RESPONSE_YES:
        // OUI −> on quitte l application
         gtk_main_quit();
        break;
        case GTK_RESPONSE_NO:
        // NON −> on detruit la dialog de message
           pr_signal_destroy(bt->message);
        break;
 }
   return;
}

/*************************************************************************
*   Fonction   :   static void pr_signal_menu_new (void)
*   ------------------------------------------------------------------
*
*   Entre   :
*
*   Sortie  :
*************************************************************************/
void text_edit_register_filename(gchar *fname, gint tab_num)
{
   /**
    * Manage the full path to the open file names
    * with a linked list.  Keeping the full path around
    * is important so that saving functionality puts the
    * file in its proper place (rather than using only the
    * name in the tab label, which would put it in the current
    * working directory)
    */
   gint found = FALSE;

   prFileData *f = g_new(prFileData, 1);

   GList *node = g_list_alloc();

   f->filename = fname;
   f->tab_number = tab_num;

   node->data = f;

   if (filename_data == NULL)
        filename_data = node;
   else
    {
      GList *list = filename_data;
      while (list != NULL)
       {
         if (((prFileData *) list->data)->tab_number == tab_num)
          {
            found = TRUE;

            ((prFileData *) list->data)->filename = fname;

            break;
          }
         else list = g_list_next(list);
       }

      if (!found) g_list_append(filename_data, node);
    }
}

static gchar *text_edit_get_filename(gint tab_num)
{
   GList *list = filename_data;

   while (list != NULL)
    {
      if (((prFileData *) list->data)->tab_number == tab_num)
         return ((prFileData *) list->data)->filename;
      else
         list = g_list_next(filename_data);
    }

   return NULL;
}

prFileObject *text_edit_file_new(void)
{
   prFileObject *new_file = g_new(prFileObject, 1);
   new_file->scrolled_window=
            pr_scrolled_window_init(NULL,"sc",1,1,1);
   new_file->scrolled_window=
            pr_scrolled_window_create(new_file->scrolled_window);

   new_file->textview = gtk_text_view_new();
    new_file->tab_label=pr_label_init(NULL,"Untitled",0,0);
    new_file->tab_label=pr_label_create(new_file->tab_label);

   gtk_container_set_border_width(GTK_CONTAINER(
                                new_file->scrolled_window->scrolledWindow),
                                  3);
   gtk_text_view_set_left_margin(GTK_TEXT_VIEW(new_file->textview),
                                 3);
   gtk_text_view_set_right_margin(GTK_TEXT_VIEW(new_file->textview),
                                  3);
   gtk_text_view_set_pixels_above_lines(GTK_TEXT_VIEW(new_file->textview),
                                        1);
    gtk_widget_override_font(new_file->textview, desc);
   gtk_container_add(GTK_CONTAINER(new_file->scrolled_window->scrolledWindow),
                      new_file->textview);

   return new_file;
}

static void pr_signal_menu_new (GtkMenuItem *menuitem,
                                   GtkNotebook *notebook)
{

   prFileObject *f = text_edit_file_new();
   gint current_tab;

   current_tab = gtk_notebook_append_page(notebook,
                                          f->scrolled_window->scrolledWindow,
                                          f->tab_label->label);
   text_edit_register_filename("Untitled", current_tab);
   gtk_widget_show_all(GTK_WIDGET(notebook));
}




/**********************************************************************
*   Fonction   :   static void pr_signal_menu_new (void)
*   ------------------------------------------------------------------
*
*   Entre   :
*
*   Sortie  :
*/
/*****************************************************************/
static void text_edit_save_file(GtkMenuItem *menu_item,
                                GtkNotebook *notebook)
{
   GList *child_list;
   GtkWidget *dialog;
   GtkWidget *textview;
   GtkTextBuffer *buffer;
   prScrolledWindow *scrolled_win=
        (prScrolledWindow*)malloc(sizeof(prScrolledWindow));
   gint current_page;
   gint response;
   GtkWidget *tab_label;
   GtkTextIter start, end;
   gchar *filename;
   gchar *contents;

   current_page = gtk_notebook_get_current_page(notebook);
   scrolled_win->scrolledWindow = gtk_notebook_get_nth_page(notebook,
                                                            current_page);
   child_list =
        gtk_container_get_children(
                                GTK_CONTAINER(scrolled_win->scrolledWindow)
                                );
   textview = child_list->data;
   tab_label =
    gtk_notebook_get_tab_label(notebook, scrolled_win->scrolledWindow);

   if (strcmp(gtk_label_get_text(GTK_LABEL(tab_label)), "Untitled") == 0)
    {
      dialog =
        gtk_file_chooser_dialog_new("Save File",
                                    NULL,
                                    GTK_FILE_CHOOSER_ACTION_SAVE,
                                    GTK_STOCK_SAVE, GTK_RESPONSE_APPLY,
                                    GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                                    NULL);
      response = gtk_dialog_run(GTK_DIALOG(dialog));
      if (response == GTK_RESPONSE_APPLY)
       {
         filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
         buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));
         gtk_text_buffer_get_bounds(buffer, &start, &end);
         contents = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
         g_file_set_contents(filename, contents, -1, NULL);
         text_edit_register_filename(filename, current_page);
         gtk_label_set_text(GTK_LABEL(tab_label), basename(filename));
       }
      else if (response == GTK_RESPONSE_CANCEL)
       {
         gtk_widget_destroy(dialog);
         return;
       }
      gtk_widget_destroy(dialog);
    }
   else
    {
      filename = text_edit_get_filename(current_page);
      buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));
      gtk_text_buffer_get_bounds(buffer, &start, &end);
      contents = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
      g_file_set_contents(filename, contents, -1, NULL);
    }
}
static void pr_signal_menu_open (GtkMenuItem *menu_item,
                                    GtkNotebook *notebook)
{
   GList *child_list;
   GtkWidget *dialog;
   GtkWidget *save_dialog, *error_dialog;
   gint current_page;
   gint id;
   gint offset;
   gchar *filename;
   gchar *contents;
   prScrolledWindow *scrolled_win=
                (prScrolledWindow*)malloc(sizeof(prScrolledWindow));
   GtkWidget *view;
   GtkTextBuffer *buffer;
   GtkWidget *tab_name;
   GtkTextIter start, end;
   GtkTextMark *mark;
   GtkWidget *prompt_label;
   GtkWidget *content_area;


   current_page = gtk_notebook_get_current_page(notebook);
   scrolled_win->scrolledWindow =
        gtk_notebook_get_nth_page(notebook, current_page);
   child_list =
        gtk_container_get_children(
                        GTK_CONTAINER(scrolled_win->scrolledWindow)
                                   );

   view = (GTK_IS_TEXT_VIEW(child_list->data) ? child_list->data : NULL);

   if (view != NULL)
    {
      dialog = gtk_file_chooser_dialog_new("Open A File",
                                           NULL,
                                           GTK_FILE_CHOOSER_ACTION_OPEN,
                                           GTK_STOCK_OPEN,
                                           GTK_RESPONSE_ACCEPT,
                                            GTK_STOCK_CANCEL,
                                            GTK_RESPONSE_REJECT,
                                            NULL);

      id = gtk_dialog_run(GTK_DIALOG(dialog));

      tab_name = gtk_notebook_get_tab_label(notebook,
                                            scrolled_win->scrolledWindow);

      switch (id)
       {
         case GTK_RESPONSE_ACCEPT:
            filename =
                gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
            buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
            gtk_text_buffer_get_end_iter(buffer, &end);
            offset = gtk_text_iter_get_offset(&end);
            if (offset > 0)
             {
               save_dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL,
                                                    GTK_MESSAGE_INFO,
                                                    GTK_BUTTONS_NONE, NULL);
               gtk_dialog_add_buttons(GTK_DIALOG(save_dialog),
                                      GTK_STOCK_SAVE,
                                      GTK_RESPONSE_ACCEPT,
                                      GTK_STOCK_DELETE,
                                      GTK_RESPONSE_CLOSE,
                                      GTK_STOCK_CANCEL,
                                      GTK_RESPONSE_CANCEL,
                                      NULL);

            prompt_label = gtk_label_new("Save buffer contents?");
            content_area =
                gtk_dialog_get_content_area(GTK_DIALOG(save_dialog));

               gtk_box_pack_start(GTK_BOX(content_area), prompt_label,
                                   FALSE, FALSE, 0);
               gtk_widget_show_all(save_dialog);

               gtk_widget_hide(dialog);

               id = gtk_dialog_run(GTK_DIALOG(save_dialog));

               switch (id)
                {
                  case GTK_RESPONSE_ACCEPT:
                     text_edit_save_file(NULL, notebook);
                     text_edit_register_filename(filename, current_page);
                     break;

                  case GTK_RESPONSE_CLOSE:
                     gtk_text_buffer_get_bounds(buffer, &start, &end);
                     gtk_text_buffer_delete(buffer, &start, &end);
                     break;

                  case GTK_RESPONSE_CANCEL:
                     gtk_widget_destroy(save_dialog);
                     return;
                }
               gtk_widget_destroy(save_dialog);
             }

            if (g_file_test(filename, G_FILE_TEST_EXISTS))
             {
               g_file_get_contents(filename, &contents, NULL, NULL);

               mark = gtk_text_buffer_get_insert(buffer);
               gtk_text_buffer_get_iter_at_mark(buffer, &start, mark);

               gtk_text_buffer_set_text(buffer, contents, -1);

               text_edit_register_filename(filename, current_page);

               gtk_label_set_text(GTK_LABEL(tab_name), basename(filename));
             }
            else
             {
               error_dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL,
                                                     GTK_MESSAGE_ERROR,
                                                     GTK_BUTTONS_OK, NULL);
               gtk_dialog_run(GTK_DIALOG(error_dialog));
               gtk_widget_destroy(error_dialog);
             }
            break;
         case GTK_RESPONSE_REJECT:
            break;
       }
      gtk_widget_destroy(dialog);
    }
}

/****************************************************************



****************************************************************/
static void pr_signal_menu_save(GtkMenuItem *menu_item,
                                GtkNotebook *notebook)
{
   GList *child_list;
   GtkWidget *dialog;
   GtkWidget *textview;
   GtkTextBuffer *buffer;
   GtkWidget *scrolled_win;
   gint current_page;
   gint response;
   GtkWidget *tab_label;
   GtkTextIter start, end;
   gchar *filename;
   gchar *contents;

   current_page = gtk_notebook_get_current_page(notebook);
   scrolled_win = gtk_notebook_get_nth_page(notebook, current_page);
   child_list = gtk_container_get_children(GTK_CONTAINER(scrolled_win));
   textview = child_list->data;
   tab_label = gtk_notebook_get_tab_label(notebook, scrolled_win);

   if (strcmp(gtk_label_get_text(GTK_LABEL(tab_label)), "Untitled") == 0)
    {
      /**
       * File currently has no name.  Allow user to name the file.
       */

      dialog = gtk_file_chooser_dialog_new("Save File", NULL,
                                           GTK_FILE_CHOOSER_ACTION_SAVE,
                                           GTK_STOCK_SAVE,
                                           GTK_RESPONSE_APPLY,
                                           GTK_STOCK_CANCEL,
                                           GTK_RESPONSE_CANCEL,
                                           NULL);

      response = gtk_dialog_run(GTK_DIALOG(dialog));

      if (response == GTK_RESPONSE_APPLY)
       {
         filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));

         buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));
         gtk_text_buffer_get_bounds(buffer, &start, &end);
         contents = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
         g_file_set_contents(filename, contents, -1, NULL);
         text_edit_register_filename(filename, current_page);
         gtk_label_set_text(GTK_LABEL(tab_label), basename(filename));
       }
      else if (response == GTK_RESPONSE_CANCEL)
       {
         gtk_widget_destroy(dialog);
         return;
       }
      gtk_widget_destroy(dialog);
    }
   else
    {
      filename = text_edit_get_filename(current_page);
      buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));
      gtk_text_buffer_get_bounds(buffer, &start, &end);
      contents = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
      g_file_set_contents(filename, contents, -1, NULL);
    }
}
/*******************************************************************


**********************************************************************/
static void pr_signal_menu_close(GtkMenuItem *menu_item,
                                 GtkNotebook *notebook)
{
   prScrolledWindow *scrolled_win=
        (prScrolledWindow*)malloc(sizeof(prScrolledWindow));
   gint current_page;
   current_page = gtk_notebook_get_current_page(notebook);
   scrolled_win->scrolledWindow = gtk_notebook_get_nth_page(notebook,
                                                            current_page);

   gtk_widget_destroy(scrolled_win->scrolledWindow);
}
/*******************************************************************


*******************************************************************/
static void pr_signal_menu_couper(GtkMenuItem *menu_item,
                                       GtkNotebook *notebook)
{
   GList *child_list;
   GtkWidget *textview;
   GtkTextBuffer *buffer;
   GtkWidget *scrolled_win;
   gint current_page;
   GtkClipboard *clipboard =
        gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);

   current_page = gtk_notebook_get_current_page(notebook);
   scrolled_win = gtk_notebook_get_nth_page(notebook, current_page);
   child_list = gtk_container_get_children(GTK_CONTAINER(scrolled_win));
   textview = child_list->data;
   buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));
   gtk_text_buffer_cut_clipboard(buffer, clipboard, TRUE);
}

static void pr_signal_menu_copier(GtkMenuItem *menu_item,
                                        GtkNotebook *notebook)
{
   GList *child_list;
   GtkWidget *textview;
   GtkTextBuffer *buffer;
   GtkWidget *scrolled_win;
   gint current_page;
   GtkClipboard *clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);


   current_page = gtk_notebook_get_current_page(notebook);
   scrolled_win = gtk_notebook_get_nth_page(notebook, current_page);
   child_list = gtk_container_get_children(GTK_CONTAINER(scrolled_win));
   textview = child_list->data;

   buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));
   gtk_text_buffer_copy_clipboard(buffer, clipboard);
}

static void pr_signal_menu_coller(GtkMenuItem *menu_item,
                                           GtkNotebook *notebook)
{
   GList *child_list;
   GtkWidget *textview;
   GtkTextBuffer *buffer;
   GtkWidget *scrolled_win;
   gint current_page;
   GtkClipboard *clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);


   current_page = gtk_notebook_get_current_page(notebook);
   scrolled_win = gtk_notebook_get_nth_page(notebook, current_page);
   child_list = gtk_container_get_children(GTK_CONTAINER(scrolled_win));
   textview = child_list->data;

   buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));
   gtk_text_buffer_paste_clipboard(buffer, clipboard, NULL, TRUE);
}
/**********************************************************************
*   Fonction   :   static void pr_menu_add (GtkUIManager *,
                                               GtkWidget *,
                                               GtkContainer *)
*   ------------------------------------------------------------------
*      La fonction c'est dessous permet d'ajouter element de notre menu
*    apartir du fichier Xml
*   Entre   :   -Variable de type GtkUIManager qui contient
*            les informations lus apartir du fichier xml
*                - la widget qui vas adapter le signal
*                - notre container dans lequel nous avons placer le menu
*
*   Sortie  : void (ajout direct du menu a notre container)
*/

void pr_menu_add (GtkUIManager * p_uiManager, GtkWidget * p_widget,
                     GtkContainer * p_box)
{
   gtk_box_pack_start (GTK_BOX (p_box), p_widget, FALSE, FALSE, 0);
   gtk_widget_show (p_widget);
   return;
}
/**********************************************************************
*   Fonction   :   GtkWidget* pr_menu_create(GtkWidget *p_vprBox)
*   ------------------------------------------------------------------
*       La fonction suivante nous permet de creer un menu bar
*    en utilisantfichier xml
*   Entre   :   Le container ou nous allons mettre notre menu
*   Sortie  :   Notre container apres l'ajout du menu
*/
GtkWidget* pr_menu_create(GtkWidget *p_vprBox,prNotebook *note)
{
    GtkUIManager *p_uiManager = NULL;
    GtkActionGroup *p_actionGroup = NULL;
    static struct
     {
      gchar *filename;
      gchar *stock_id;
     }  stock_icons[] =
             {
              { "terminal.png", "console" },
              { "graphique.png", "graphique" },
             };
    static gint n_stock_icons = G_N_ELEMENTS (stock_icons);
     GtkIconFactory *icon_factory;
     GtkIconSet *icon_set;
     GtkIconSource *icon_source;
     gint i;

  gchar*  ici=g_get_current_dir();
  //ici=(gchar*)malloc(100*sizeof(gchar));
    //sprintf(ici,"%s","/home/abd/Bureau/App_finish_testing_BAck_up _Finale");
    icon_factory = gtk_icon_factory_new ();
for(i=0;i<n_stock_icons;i++)
{
      icon_set = gtk_icon_set_new ();
      icon_source = gtk_icon_source_new ();
      gchar *chemin=(gchar*)malloc(100*sizeof(gchar));
      sprintf(chemin,"%s/Interface/%s",ici,stock_icons[i].filename);

      gtk_icon_source_set_filename (icon_source, chemin);
      gtk_icon_set_add_source (icon_set, icon_source);
      gtk_icon_source_free (icon_source);
      gtk_icon_factory_add (icon_factory,
                            stock_icons[i].stock_id,
                            icon_set);
      gtk_icon_set_unref (icon_set);
}


  gtk_icon_factory_add_default (icon_factory);
  g_object_unref (icon_factory); /* supprimer l'objet de la mémoire */
  free(ici) ;

    GtkActionEntry entries[] = {
      {"FichierMenuAction", NULL, "Fichier", NULL, NULL, NULL},
      {"NouveauAction", GTK_STOCK_NEW, "Nouveau",
      "<Control>N", "Nouveau Fichier",
       G_CALLBACK (pr_signal_menu_new)},
      {"OuvrirAction", GTK_STOCK_OPEN, "Ouvrir", "<Control>O",
      "Ouvrir Fichier",G_CALLBACK (pr_signal_menu_open)},
      {"QuitterAction", GTK_STOCK_QUIT, "Quitter", "<control>Q",
      "Quitter",G_CALLBACK (pr_signal_menu_quit)},
       {"ViewMenuAction", NULL, "View", NULL, NULL, NULL},
       {"ConsolAction", "console", "Console", "<control>T",
       "Console",G_CALLBACK (NULL)},
       {"GraphAction", "graphique", "Graphique", "<control>G",
       "Mode Graphique",G_CALLBACK (NULL)},

       {"EditMenuAction", NULL, "Edit", NULL, NULL, NULL},
       {"CopyAction", GTK_STOCK_COPY, "Copier", "<control>C",
       "Copier",G_CALLBACK (pr_signal_menu_copier)},
       {"CutAction", GTK_STOCK_CUT, "Couper", "<control>X",
       "Couper",G_CALLBACK (pr_signal_menu_couper)},
       {"PasteAction", GTK_STOCK_PASTE, "Coller", "<control>V",
       "Coller",G_CALLBACK (pr_signal_menu_coller)},

      {"AideMenuAction", NULL, "Aide", NULL, NULL, NULL},
      {"AideAction", GTK_STOCK_HELP, "Aide", "<Release>F1",
      "Aide",G_CALLBACK (NULL)},
       {"EnregistrerAction", GTK_STOCK_SAVE, "Enregistrer", "<control>E",
       "Enregistrer",G_CALLBACK (pr_signal_menu_save)},
      {"AproposAction", GTK_STOCK_ABOUT, "A propos", "<Control>A",
      "About",G_CALLBACK (pr_signal_menu_about)},
       {"CloseAction", GTK_STOCK_CLOSE, "Close", "<Control>Z",
       "Fermer Fichier",G_CALLBACK (pr_signal_menu_close)}
   };
    p_uiManager = gtk_ui_manager_new ();
   p_actionGroup = gtk_action_group_new ("menuActionGroup");
   gtk_action_group_add_actions (p_actionGroup, entries,
                                 G_N_ELEMENTS (entries),
                                 (gpointer)note->notebook);
   gtk_ui_manager_insert_action_group (p_uiManager, p_actionGroup, 0);
   gtk_ui_manager_add_ui_from_file (p_uiManager, "menu.xml", NULL);
   g_signal_connect
      (p_uiManager, "add_widget", G_CALLBACK (pr_menu_add), p_vprBox);
      return ((GtkWidget*)p_vprBox);
}
