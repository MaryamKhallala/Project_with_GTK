#ifndef str_pr_about
#define str_pr_about
#include"bibliotheque.h"
/***********************************************************
*   Structure   :   prAbout
*   --------------------------
*        prAbout represente l'objet qui permete d'afficher
*    les information relatif a une application d'une maniére
*    structurer et bien organiser
*         Cette structure à comme champ :
*       nom d'application
*        version de l'application
*        copy right
*        Description
*        site web de l'application
*       logo d'application
*************************************************************/
typedef struct prAbout
{
    GtkWidget   *about;         // widget notre boire
    char        nom[256];       // nom d'application
    char        version[256];   //version d'application
    char        copy_r[256];    // copy right d'application
    char        comment[256];   // Description
    char        website[256];   // site web
    char        url_logo[256];  // url du logo
} prAbout;
#endif // str_pr_about

