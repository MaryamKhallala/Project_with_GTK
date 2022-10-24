#include"prAbout.h"
/**************************** About Dialog **************************
*
* Fonction   :   prAbout  *pr_about_init(char *,
*                                                 char *,
*                                                 char *,
*                                                 char *,
*                                                 char* ,
*                                                 char *)
*   -----------------------------------------------------------------
*       Cette fonction permet a citer les critére que nous voullons
*    affecter pour notre boite about de l'application
*
*   Entre   :   - Le titre (Nom de l'application)
*                - La version de l'application
*                - Copyright de l'application
*                - Commentaire accompagnié
*                - site web de l'application
*                - chemin du logo de l'application
*   Sortie  :  Une variable de type prAbout apres l'initialiser
********************************************************************/
prAbout  *pr_about_init(char *nom,char *version,char *cpy,
                              char *comment,char* website,char *logo)
{
    prAbout *ab=(prAbout*)malloc(sizeof(prAbout));
   if(nom) strcpy(ab->nom,nom);
   else ab->nom[0]='\0';

   if(version) strcpy(ab->version,version);
   else ab->version[0]='\0';

   if(cpy) strcpy(ab->copy_r,cpy);
   else ab->copy_r[0]='\0';

   if(comment) strcpy(ab->comment,comment);
   else ab->comment[0]='\0';

   if(website) strcpy(ab->website,website);
   else ab->website[0]='\0';

   if(logo) strcpy(ab->url_logo,logo);
   else ab->url_logo[0]='\0';

   return ((prAbout*)ab);
}
/********************************************************************
*   Fonction   :   void    pr_about_create(prAbout *)
*   -----------------------------------------------------------------
*      Cette fonction concerne la creation d'une boite about avec des
*  critére deja initialiser.
*   Entre   :   Notre variable prAbout deja initialiser
*   Sortie  :   void (affichage direct de la boit about)
********************************************************************/
void    pr_about_create(prAbout *ab) {

  GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(ab->url_logo, NULL);
  ab->about = gtk_about_dialog_new();
  if(ab->nom)
    gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(ab->about),ab->nom);
  if(ab->version)
    gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(ab->about), ab->version);
  if(ab->copy_r)
    gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(ab->about),ab->copy_r);
  if(ab->comment)
    gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(ab->about),ab->comment);
  if(ab->website)
    gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(ab->about),ab->website);
  if(ab->url_logo)
    gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(ab->about), pixbuf);

  g_object_unref(pixbuf), pixbuf = NULL;
  pr_signal_start(ab->about);
  pr_signal_destroy(ab->about);
}

