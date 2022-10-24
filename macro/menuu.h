typedef struct _Menu prMenuu;
struct _Menu
{
    GtkWidget  *Menu_bar, *Menu_champ, *sous_menu;
};


static void menu_event(GtkWidget *source, gpointer data)
{
    if(!strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(source)),"Exit"))
    {
        gtk_main_quit();

    }
return ;
}

void creer_Menu(prMenuu *menu,GtkBox *vbox)
{
    //const char* file[] = {""};
     const char* help[] = {"Sous Menu21","Sous Menu22","Sous Menu23"};
     //const char* help[] = {""};

    GtkWidget *hbox,*separator,*menuu;

        menuu=gtk_menu_new();
        menu->Menu_bar=gtk_menu_bar_new();
        menu->Menu_champ=gtk_menu_item_new_with_mnemonic("_MonMenu1");
                menu->sous_menu=gtk_menu_item_new_with_label("");
                gtk_menu_shell_append(GTK_MENU_SHELL(menuu),menu->sous_menu);
                g_signal_connect(menu->sous_menu,"activate",G_CALLBACK(menu_event),NULL);

        gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu->Menu_champ),menuu);
        gtk_menu_shell_append(GTK_MENU_SHELL(menu->Menu_bar),menu->Menu_champ);

        menuu=gtk_menu_new();
        menu->Menu_champ=gtk_menu_item_new_with_mnemonic("_MonMenu2");
        for(int i=0;i<3;i++)
        {
                menu->sous_menu=gtk_menu_item_new_with_label(help[i]);
                gtk_menu_shell_append(GTK_MENU_SHELL(menuu),menu->sous_menu);
                g_signal_connect(menu->sous_menu,"activate",G_CALLBACK(menu_event),NULL);
        }
        gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu->Menu_champ),menuu);
        gtk_menu_shell_append(GTK_MENU_SHELL(menu->Menu_bar),menu->Menu_champ);

        menuu=gtk_menu_new();
        menu->Menu_champ=gtk_menu_item_new_with_mnemonic("_MonMenu3");
                menu->sous_menu=gtk_menu_item_new_with_label("");
                gtk_menu_shell_append(GTK_MENU_SHELL(menuu),menu->sous_menu);
                g_signal_connect(menu->sous_menu,"activate",G_CALLBACK(menu_event),NULL);

        gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu->Menu_champ),menuu);
        gtk_menu_shell_append(GTK_MENU_SHELL(menu->Menu_bar),menu->Menu_champ);

        gtk_box_pack_start(GTK_BOX(vbox),menu->Menu_bar,0,0,0);

}
