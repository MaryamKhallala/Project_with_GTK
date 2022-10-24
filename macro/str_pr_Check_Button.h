#ifndef str_pr_check_button
#define str_pr_check_button
#include"bibliotheque.h"
#  define _(String) (String)
#  define N_(String) (String)
/***************************************************************************
*   Structure   :   prCheckButton
*   --------------------------
*       Le prCheckButton est la structure qui nous donne la possiblite
*    de creer des cases à cocher.
*        cette structure à comme champs :
*            l'objet check button
*            leur conteneur
*           label du button
*            nom du button
*            mnemonic ou non
*****************************************************************************/
typedef struct prCheckButton

{

   GtkWidget   *checkButton;//Le button

   GtkWidget   *racine;        //Le container du

   gchar       *label;         //le text du prLabel

   char        *nom;           //Le nom du checkButton (pour le css)

   int         mnemonic ;      //1 si creation avec mnemonic, 0 sinon
   prPos *pox;

} prCheckButton;

#endif //str_pr_check_button

