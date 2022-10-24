#include"pr_help.h"
void fermeture (GtkWidget *widget,GdkEvent *event, gpointer *data)
{
    gtk_widget_destroy(widget);

}//Fin de la fonction annule_fermeture
void pr_application_writer(GtkWidget *win,gpointer *data)
{
    prAssistant *assist;
    prPageAssistant *page;
    prPageAssistant *page1;
    prPageAssistant *page2;

    assist=pr_assistant_init(450,-1);
    assist=pr_assistant_create(assist);

    g_signal_connect(assist->assist, "delete-event", G_CALLBACK(fermeture), NULL);
    g_signal_connect(assist->assist, "cancel", G_CALLBACK(fermeture), NULL);
    g_signal_connect(assist->assist, "close", G_CALLBACK(fermeture), NULL);

    page=pr_page_assistant_init(
    "Vous Voulez bien Creer Des interfaces graphique ?"
    " \n\t\t Il-Interpreteur est la Solution ",
                                    " Introduction App ");
    page=pr_page_assistant_create(page,4);
    assist=pr_assistant_apply(assist,page,1);



    page1=pr_page_assistant_init(" \t\t IL-Interpreteur est develloper par \n"
    "\tEDDAOUDI ABDELOUAHID  -  BAAZIZ RACHID. \n",
                                        "  Writer ");
    page1=pr_page_assistant_create(page1,5);
    assist=pr_assistant_apply(assist,page1,2);

     page2=pr_page_assistant_init("\n Essay notre Application",
                                    " Welcome in IL-Interpteur ");
    page2=pr_page_assistant_create(page2,6);
    assist=pr_assistant_apply(assist,page2,3);

    gtk_widget_show_all(assist->assist);

}

void pr_window_help(GtkWidget *win,gpointer *data)
{
    prAssistant *assist;
    prPageAssistant *page;
    prPageAssistant *page1;
    prPageAssistant *page2;

    assist=pr_assistant_init(450,-1);
    assist=pr_assistant_create(assist);

    g_signal_connect(assist->assist, "delete-event", G_CALLBACK(fermeture), NULL);
    g_signal_connect(assist->assist, "cancel", G_CALLBACK(fermeture), NULL);
    g_signal_connect(assist->assist, "close", G_CALLBACK(fermeture), NULL);

    page=pr_page_assistant_init("Vous Voulez bien Creer Une interface graphique ?"
    " \n\t\t alors suivie les etapes",
                                    "Page 1: Problematique");
    page=pr_page_assistant_create(page,1);
    assist=pr_assistant_apply(assist,page,1);


    page1=pr_page_assistant_init(
    " \t Pour Creer une interface Graphique vous etes besoin d'une fenetre "
     "pere qui va contenir tous les autres elements . \n"
    " \t\t Ce button la qui vas vous aider .\n"
    "Il faut juste remplir le formulaire accompagnion a cette button , pour "
    "la bon creation de cette derniere .\n\n"
    "Etape 1 : Identifiant \n"
    "\t choisissez un id a votre fenetre qui doit etre unique . OBLIGATOIR !!! \n\n"
    "Etape 2 : Critere\n"
    "\t Choisis un titre a votre fenetre .\n"
    "\t Selectionner le type de votre fenetre .\n"
    "\t Remplir les dimentions de la fenetre .\n"
    "\t Choisis la position principale de la fenetre .\n"
    "\t Mettre la fenetre en mode resizable ou non a votre choix .\n"
    "\t Selectionner l'icone de la fenetre .\n\n"                                       ,
    "Page 2: Remplissage ");
    page1=pr_page_assistant_create(page1,2);
    assist=pr_assistant_apply(assist,page1,2);



     page2=pr_page_assistant_init("Finalement Click sur le button OK \n la fenetre"
     " creer avec les critere donner va etre afficher",
                                    "Page 3: Creation");
    page2=pr_page_assistant_create(page2,3);
    assist=pr_assistant_apply(assist,page2,3);

    gtk_widget_show_all(assist->assist);

}


void pr_dialog_help(GtkWidget *win,gpointer *data)
{
    prAssistant *assist;
    prPageAssistant *page;
    prPageAssistant *page1;
    prPageAssistant *page2;

    assist=pr_assistant_init(450,-1);
    assist=pr_assistant_create(assist);

    g_signal_connect(assist->assist, "delete-event", G_CALLBACK(fermeture), NULL);
    g_signal_connect(assist->assist, "cancel", G_CALLBACK(fermeture), NULL);
    g_signal_connect(assist->assist, "close", G_CALLBACK(fermeture), NULL);

    page=pr_page_assistant_init("Vous Voulez bien Creer Une Boite de dialog ? "
    "\n\t\t alors suivie les etapes et cliquer sur suivant",
                                    "Page 1: Problematique");
    page=pr_page_assistant_create(page,1);
    assist=pr_assistant_apply(assist,page,1);


    page1=pr_page_assistant_init(
    " \t Rq:  Cette fois vous etes pas besoin d'une fenetre pere . \n"
    " \t\t Ce button la qui vas vous aider .\n"
    "Il faut juste remplir le formulaire accompagnion a cette Boite "
    "de dialog, pour la bon creation de cette derniere .\n\n"
    "Etape 1 : Identifiant \n"
    "\t choisissez un id a votre fenetre qui doit etre unique"
    ". OBLIGATOIR !!! \n\n"
    "Etape 2 : Critere\n"
    "\t Choisis un titre a votre Boite.\n"
    "\t Choisis le elements de la fenetre ( label / button )\n"
    "\t\t\t Choisis le type de button standard\n"
    "\t Remplir les dimentions de la boite .\n"                                     ,
    "Page 2: Remplissage ");
    page1=pr_page_assistant_create(page1,2);
    assist=pr_assistant_apply(assist,page1,2);



     page2=pr_page_assistant_init("Finalement Click sur le button OK \n la"
     "boite creer avec les critere donner va etre afficher\n"
     " \n Si Vous voulez maintenant enregistrer votre Boite just clicker sur "
     "Button Enregistrer et choisis l'emplacement",
    "Page 3: Creation");
    page2=pr_page_assistant_create(page2,3);
    assist=pr_assistant_apply(assist,page2,3);

    gtk_widget_show_all(assist->assist);

}
/********************************************/
void pr_message_help(GtkWidget *win,gpointer *data)
{
    prAssistant *assist;
    prPageAssistant *page;
    prPageAssistant *page1;
    prPageAssistant *page2;

    assist=pr_assistant_init(450,-1);
    assist=pr_assistant_create(assist);

    g_signal_connect(assist->assist, "delete-event", G_CALLBACK(fermeture), NULL);
    g_signal_connect(assist->assist, "cancel", G_CALLBACK(fermeture), NULL);
    g_signal_connect(assist->assist, "close", G_CALLBACK(fermeture), NULL);

    page=pr_page_assistant_init("Vous Voulez bien Creer Une Boite Message ?"
            "\n\t\t alors suivie les etapes et cliquer sur suivant",
                                    "Page 1: Problematique");
    page=pr_page_assistant_create(page,1);
    assist=pr_assistant_apply(assist,page,1);


    page1=
        pr_page_assistant_init(" \t Rq:  Cette fois vous etes pas besoin"
                                    "d'une fenetre pere . \n"
                                    " \t\t Ce button la qui vas vous aider .\n"
                                    "Il faut juste remplir le formulaire"
                                    "accompagnion a cette Boite Message, "
                                    "pour la bon creation de cette derniere ."
                                    "\n\nEtape 1 : Identifiant \n"
                                    "\t choisissez un id a votre fenetre qui"
                                    "doit etre unique . OBLIGATOIR !!! \n\n"
                                     "Etape 2 : Critere\n"
                                    "\t Choisis le type de message "
                            "(warning / information / questions / erreru).\n"
                            "\t Choisis le type de button standard\n"
                            "\t Remplir le Contenue \E0 afficher par"
                            "ce Boite Message .\n"                                     ,
                            "Page 2: Remplissage ");
    page1=pr_page_assistant_create(page1,2);
    assist=pr_assistant_apply(assist,page1,2);



     page2=pr_page_assistant_init("Finalement Click sur le button OK \n"
            "la boite creer avec les critere donner va etre afficher\n"
            " \n Si Vous voulez maintenant enregistrer votre Boite just"
            "clicker sur Button Enregistrer et choisis l'emplacement",
             "Page 3: Creation");
    page2=pr_page_assistant_create(page2,3);
    assist=pr_assistant_apply(assist,page2,3);

    gtk_widget_show_all(assist->assist);
}
/***************************************************/
void pr_about_help(GtkWidget *win,gpointer *data)
{
        prAssistant *assist;
    prPageAssistant *page;
    prPageAssistant *page1;
    prPageAssistant *page2;

    assist=pr_assistant_init(450,-1);
    assist=pr_assistant_create(assist);

 g_signal_connect(assist->assist, "delete-event", G_CALLBACK(fermeture), NULL);
 g_signal_connect(assist->assist, "cancel", G_CALLBACK(fermeture), NULL);
 g_signal_connect(assist->assist, "close", G_CALLBACK(fermeture), NULL);

    page=pr_page_assistant_init("Vous Voulez bien Creer Une Boite About ? "
                                    "\n\t\t alors suivie les etapes et cliquer"
                                    "sur suivant",
                                    "Page 1: Problematique");
    page=pr_page_assistant_create(page,1);
    assist=pr_assistant_apply(assist,page,1);


    page1=pr_page_assistant_init(" \t Rq:  Cette fois vous etes pas besoin"
                                    "d'une fenetre pere . \n"
                                    " \t\t Ce button la qui vas vous aider .\n"
                                    "Il faut juste remplir le formulaire"
                                    "accompagnion a cette Boite de dialog,"
                                    "pour la bon creation de cette derniere .\n\n"
                                    "Etape 1 : Identifiant \n"
                                    "\t choisissez un id a votre fenetre qui doit"
                                    "etre unique . OBLIGATOIR !!! \n\n"
                                    "Etape 2 : Replissage\n"
                                    "\t Remplis Nom de l'application.\n"
                                    "\t Remplis la version de l'application \n"
                                    "\t Remplis Copyright\n"
                                    "\t Remplis Commentaire de l'application\n"
                                    "\t Citer le site de l'application  .\n"                                     ,
                                    "Page 2: Remplissage ");
    page1=pr_page_assistant_create(page1,2);
    assist=pr_assistant_apply(assist,page1,2);



     page2=pr_page_assistant_init("Finalement Click sur le button OK \n"
                                    "la boite creer avec les critere donner"
                                    "va etre afficher\n"
                                    " \n Si Vous voulez maintenant enregistrer"
                                     "votre Boite just clicker sur Button"
                                     "Enregistrer et choisis l'emplacement",
                                    "Page 3: Creation");
    page2=pr_page_assistant_create(page2,3);
    assist=pr_assistant_apply(assist,page2,3);

    gtk_widget_show_all(assist->assist);

}
/****************************************************************/
void pr_arithmetique_help(GtkWidget *win,gpointer *data)
{
        prAssistant *assist;
    prPageAssistant *page;
    prPageAssistant *page1;
    prPageAssistant *page2;

    assist=pr_assistant_init(450,-1);
    assist=pr_assistant_create(assist);

g_signal_connect(assist->assist,"delete-event", G_CALLBACK(fermeture), NULL);
g_signal_connect(assist->assist,"cancel", G_CALLBACK(fermeture), NULL);
g_signal_connect(assist->assist,"close", G_CALLBACK(fermeture), NULL);

    page=pr_page_assistant_init("\t\t\t Fonction Arithmetique : \n\n"
                     " \n Addition : \n"
                     " \t\t (add elem1 elem2 elem3 ...)"
                     " \n Soustraction : \n"
                     " \t\t (sub elem1 elem2 elem3 ...)"
                     " \n Multiplication : \n"
                     " \t\t (mul elem1 elem2 elem3,...)"
                     " \n Division : \n"
                     " \t\t (div elem1 elem2 elem3 ...)",
                     "Page 1: Prototype");
    page=pr_page_assistant_create(page,1);
    assist=pr_assistant_apply(assist,page,1);

     page1=pr_page_assistant_init(" \t\t Exemple  . \n"
                    " \n---------------------------------------------"
                    " \n|         Exemple           |   Res  "
                    " \n|--------------------------------------------"
                    " \n|   (add 20 2)              |   22   "
                    " \n|--------------------------------------------  "
                    " \n|   (sub 30 10 2)         |   18     "
                    " \n|-------------------------------------------- "
                    " \n|   (mul 11 2 3 -1.0)   |   -66.0    "
                    " \n|-------------------------------------------- "
                    " \n|   (div 5 2)                |   2.5 "
                    " \n|-----------------------------------------  ",
                    "Page 2: Exemple ");
    page1=pr_page_assistant_create(page1,2);
    assist=pr_assistant_apply(assist,page1,3);

    gtk_widget_show_all(assist->assist);

}
