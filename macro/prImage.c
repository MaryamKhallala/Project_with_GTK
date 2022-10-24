
#include"prImage.h"
/*************************** prImage ************************************/
/****************************************************************************
*   Fonction   :   prImage* pr_image_init(char *,
*                                                int ,
*                                                int )
*   ------------------------------------------------------------------
*       La fonction ce dessous permet de faire l'allocation et
*    l'initialisation d'une variable de type prImage
*   Entre   :   - le chemin de l'image
*                - le positionnement de l'image x et y
*   Sortie  :   - une variable de type prImage apres l'allouer
*                et l'initialiser
****************************************************************************/
prImage* pr_image_init(char *url,int posx,int posy)
{
    prImage *img=(prImage*)malloc(sizeof(prImage));
    //initialisation du chemin
    img->chemin=(char*)malloc(256*sizeof(char));
    if(url)
    strcpy(img->chemin,url);
    //initialisation de la position
    img->iPos.x = posx;
    img->iPos.y = posy;
    return ((prImage*)img);
}//fin de la fonction initialiser_image
/****************************************************************************
*   Fonction   :  static gboolean button_press_callback (GtkWidget *,
*                                                         GdkEventButton *,
*                                                         gpointer )
*
*   ------------------------------------------------------------------
*
*   Entre   :
*   Sortie  :
*/
static gboolean
button_press_callback (GtkWidget      *event_box,
                       GdkEventButton *event,
                       gpointer        data)
{
  g_print ("Event box clicked at coordinates %f,%f\n",
           event->x, event->y);
  return TRUE;
}
/**********************************************************************
*   Fonction   :   prImage* pr_image_create (prImage* im)
*   ------------------------------------------------------------------
*       Cette fonction concerne la creation de l'image avec les critaire
*    deja citer au niveau d'initialisation.
*   Entre   :   La variable de type prImage qui ete deja initialiser
*   Sortie  :   L'image creer
*/
prImage* pr_image_create (prImage* im)
{
  im->image = gtk_image_new_from_file (im->chemin);
  return im;
}
