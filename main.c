#include <stdlib.h>
#include <gtk/gtk.h>
#include "macro/biblioth.h"

gboolean b=FALSE;
static gboolean func(GtkWidget* w1,gpointer data)
{
    gtk_entry_set_visibility(GTK_ENTRY(data),b);
    b=!b;
}

int main (int argc, char *argv[])
{
    pr_init(argc,argv);

    prWindow *fen=NULL;
    fen=pr_window_init("Fenetre",'t',"fen",500,500,1,0,"univ.png");
    fen=pr_window_create(fen);
    pr_set_size(fen->window,500,500);

    prMenuu menuu;

    prScrolledWindow* scroll;
    scroll=pr_scrolled_window_init(NULL,"scroll",0,0,0);
    scroll=pr_scrolled_window_create(scroll);

    prBox *vbox,*hbox1,*hbox2,*hbox3,*hbox4,*hbox5,*vbox2;
    vbox=pr_box_init(NULL,'v',"vbox",1,1);
    vbox=pr_box_create(vbox);
    vbox2=pr_box_init(NULL,'v',"vbox2",1,1);
    vbox2=pr_box_create(vbox2);
    hbox1=pr_box_init(NULL,'h',"hbox1",1,1);
    hbox1=pr_box_create(hbox1);
    hbox2=pr_box_init(NULL,'h',"hbox2",1,1);
    hbox2=pr_box_create(hbox2);
    hbox3=pr_box_init(NULL,'h',"hbox3",1,1);
    hbox3=pr_box_create(hbox3);
    hbox4=pr_box_init(NULL,'h',"hbox4",1,1);
    hbox4=pr_box_create(hbox4);
    hbox5=pr_box_init(NULL,'h',"hbox5",1,1);
    hbox5=pr_box_create(hbox5);

    creer_Menu(&menuu,vbox->box);

    prRadioButton *radio1, *radio2, *radio3, *radio4;
    radio1=pr_radio_button_init("Faible","rdbtn1",0,NULL,0,0);
    radio1=pr_radio_button_create(radio1,NULL);
    radio2=pr_radio_button_init("Moyen","rdbtn2",0,NULL,0,0);
    radio2=pr_radio_button_create(radio2,radio1);
    radio3=pr_radio_button_init("Bien","rdbtn3",0,NULL,0,0);
    radio3=pr_radio_button_create(radio3,radio1);
    radio4=pr_radio_button_init("Très bien","rdbtn4",0,NULL,0,0);
    radio4=pr_radio_button_create(radio4,radio1);

    prCheckButton *check1, *check2, *check3,*check4;
    check1=pr_check_button_init("Convivial","check1",0,NULL,0,0);
    check1=pr_check_button_create(check1);
    check2=pr_check_button_init("Intéressant","check2",0,NULL,0,0);
    check2=pr_check_button_create(check2);
    check3=pr_check_button_init("Facile à utiliser","check3",0,NULL,0,0);
    check3=pr_check_button_create(check3);
    check4=pr_check_button_init("Optimise le travail","check4",0,NULL,0,0);
    check4=pr_check_button_create(check4);

    prLabel *lab1,*lab2,*lab3,*lab4;
    lab1=pr_label_init(NULL,"Vos connaissances sur GTK+",0,0);
    lab1=pr_label_create(lab1);
    lab2=pr_label_init(NULL,"Vos commentaires sur GTK+",0,0);
    lab2=pr_label_create(lab2);
    lab3=pr_label_init(NULL,"Identifiant",0,0);
    lab3=pr_label_create(lab3);
    lab4=pr_label_init(NULL,"Mot de passe",0,0);
    lab4=pr_label_create(lab4);

    prEntry *entry1, *entry2;
    entry1=pr_entry_init("","entry",1,1,0,NULL,0,0);
    entry1=pr_entry_create(entry1);
    entry2=pr_entry_init("","entry2",1,1,0,NULL,0,0);
    entry2=pr_entry_create(entry2);

    prComboBox *comboJour, *comboMois, *comboAnnee, *comboVille;
    comboJour=pr_combo_box_init(NULL,"comboJ",0,0);
    comboJour=pr_combo_box_create(comboJour);
    comboMois=pr_combo_box_init(NULL,"comboM",0,0);
    comboMois=pr_combo_box_create(comboMois);
    comboAnnee=pr_combo_box_init(NULL,"comboA",0,0);
    comboAnnee=pr_combo_box_create(comboAnnee);
    comboVille=pr_combo_box_init(NULL,"comboV",0,0);
    comboVille=pr_combo_box_create(comboVille);

    pr_combo_box_add(comboJour,"1");
    pr_combo_box_add(comboJour,"2");
    pr_combo_box_add(comboJour,"3");
    pr_combo_box_add(comboJour,"4");
    pr_combo_box_add(comboJour,"5");

    pr_combo_box_add(comboMois,"Janvier");
    pr_combo_box_add(comboMois,"Février");
    pr_combo_box_add(comboMois,"Mars");
    pr_combo_box_add(comboMois,"Avril");
    pr_combo_box_add(comboMois,"Mai");
    pr_combo_box_add(comboMois,"Juin");
    pr_combo_box_add(comboMois,"Juillet");
    pr_combo_box_add(comboMois,"Aout");
    pr_combo_box_add(comboMois,"Septembre");
    pr_combo_box_add(comboMois,"Octobre");
    pr_combo_box_add(comboMois,"Novembre");
    pr_combo_box_add(comboMois,"Décembre");

    pr_combo_box_add(comboAnnee,"1975");
    pr_combo_box_add(comboAnnee,"1976");
    pr_combo_box_add(comboAnnee,"1977");

    pr_combo_box_add(comboVille,"Agadir");
    pr_combo_box_add(comboVille,"Casablanca");
    pr_combo_box_add(comboVille,"Marrakech");
    pr_combo_box_add(comboVille,"Mohammedia");
    pr_combo_box_add(comboVille,"Rabat");

    prButton *bouton1,*bouton2;
    bouton1=pr_button_init("OK",NULL,"btn1",1,NULL,0,0,0);
    bouton1=pr_button_create(bouton1);
    bouton2=pr_button_init("Quitter",NULL,"btn2",1,NULL,0,0,0);
    bouton2=pr_button_create(bouton2);

    pr_box_add(hbox1->box,radio1->radioButton,1,1,0);
    pr_box_add(hbox1->box,radio2->radioButton,1,1,0);
    pr_box_add(hbox1->box,radio3->radioButton,1,1,0);
    pr_box_add(hbox1->box,radio4->radioButton,1,1,0);

    pr_box_add(hbox2->box,check1->checkButton,1,1,0);
    pr_box_add(hbox2->box,check2->checkButton,1,1,0);
    pr_box_add(hbox2->box,check3->checkButton,1,1,0);
    pr_box_add(hbox2->box,check4->checkButton,1,1,0);

    pr_box_add(hbox3->box,comboJour->comboBox,1,1,0);
    pr_box_add(hbox3->box,comboMois->comboBox,1,1,0);
    pr_box_add(hbox3->box,comboAnnee->comboBox,1,1,0);

    pr_box_add(vbox2->box,lab3->label,1,1,0);
    pr_box_add(vbox2->box,entry1->entry,1,1,0);
    pr_box_add(vbox2->box,lab4->label,1,1,0);
    pr_box_add(vbox2->box,entry2->entry,1,1,0);

    pr_box_add(hbox4->box,comboVille->comboBox,1,1,0);
    pr_box_add(hbox4->box,vbox2->box,1,1,0);

    pr_box_add(vbox->box,lab1->label,1,1,0);
    pr_box_add(vbox->box,hbox1->box,1,1,0);
    pr_box_add(vbox->box,lab2->label,1,1,0);
    pr_box_add(vbox->box,hbox2->box,1,1,0);
    pr_box_add(vbox->box,hbox3->box,1,1,0);
    pr_box_add(vbox->box,hbox4->box,1,1,0);
    pr_box_add(vbox->box,bouton1->button,1,1,0);
    pr_box_add(vbox->box,bouton2->button,1,1,0);

    pr_scrolled_window_add(scroll,vbox->box);

    g_signal_connect(bouton1->button,"clicked",G_CALLBACK(func),entry2->entry);
    g_signal_connect(bouton2->button,"clicked",G_CALLBACK(gtk_main_quit),NULL);

    pr_add_container(GTK_CONTAINER(fen->window),scroll->scrolledWindow);
    pr_show(fen->window);
    pr_main();

  return 0;
}
