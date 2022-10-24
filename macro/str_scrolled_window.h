#ifndef str_pr_scrolled_window
#define str_pr_scrolled_winodw
#include"bibliotheque.h"

/************************************************************************
*   Structure   :   prScrolledWindow
*   --------------------------
*       Le prScrolledWindow est la structure qui permet de creer des
*    senseure pour un objet soit window ou une boite .
*        les composant de la structure :
*         - l'objet scrolledwindow
*         - le conteneur
*         - le fixed qui va contenir des objet
*         - le nom du scrolled
*         - hpolice et vpolice :
*            0  - la scrollbar ets toujours visible,
*                  elle est indepebndante du contenu
*            1 la scrollbar depend de la taille du contenu
*            2 la scrollbar n'apparait jamais, c la taille du
*                   contanu qui determine la taille de la prWindow
*            3  la scrollbar n'apparai jamais et la taille ne de
*                     pend pas du contenu (on peut avoir des indformartion
*                                          quin ne saffaichent pas)
*         - Shadow:
            0  pas de contour
*           1  The outline is bevelled in wards
*           2  The outline is bevelled out wards like a button
*           3  The outline has a sunken 3d appearance
*           4  The outline has a raised 3d appearance
***************************************************************************/

typedef struct prScrolledWindow
{
    GtkWidget   *scrolledWindow;    // l'objet scrolled
    GtkWidget   *racine;            // le conteneur
    GtkWidget   *fixed;             // le fixed container
    gchar       *nom;               // nom de l'objet
    gint        hpolice;            // police horizontale
    gint        vpolice;            // police verticale
    gint        shadow;             // aparence du conteur
    prPos    *pox;               // la position de l'objet
} prScrolledWindow;
#endif //pr_scrolled_window

