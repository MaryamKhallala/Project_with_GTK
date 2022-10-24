#ifndef str_pr_image
#define str_pr_image
#include"bibliotheque.h"

/**********************************************************
*   Structure   :   prPosition
*   --------------------------
*       Le prPosition qui represente la position relatif
*    a un objet donner.
***********************************************************/

typedef struct prPosition
{
    int x;          // position sur l'abscisse
    int y;          // position sur l'ordonnee
} prPosition;

/*************************************************
*   Structure   :   prImage
*   --------------------------
*       Le prImage est la struture qui concerne la creation
*    d'un objet image.
**********************************************************/
typedef struct prImage
{
    GtkWidget *image;       //widget image
    GtkWidget *event_box;   // evenment relatif a l'image
    char *chemin;           //chemin de l'image
    prPosition iPos;     //position de l'image
} prImage;
#endif // str_pr_image

