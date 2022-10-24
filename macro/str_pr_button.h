#ifndef str_pr_button
#define str_pr_button
#include"bibliotheque.h"
#  define _(String) (String)
#  define N_(String) (String)

/*********************************************************************
*   Structure   :   prButton
*   --------------------------
*       Le prButton represente le widget button  avec ces cretaire
*    qui nous facilite de le gere.
*        cette structure à comme champ
*            l'objet button
*            le conteneur
*            label du button
*            button du stock
*            nom du button
*            avec mnemonic
*            button special
*            position du button
*
*********************************************************************/
typedef struct prButton
{
    GtkWidget   *button;        // l'objet button
    GtkWidget   *racine;        // le conteneur
    gchar       *label;         // label du button
    gchar       *stock_icon;    // button du stock
    char        *nom;           // nom du button
    int         mnemonic ;      // mnemonic
    int type_special;           // button special
    prPos *pox;              // position du button
} prButton ;
#endif // str_pr_button

