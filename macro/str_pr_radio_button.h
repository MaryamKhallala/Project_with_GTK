#ifndef str_pr_radio_button
#define str_pr_radio_button
#include"bibliotheque.h"
#  define _(String) (String)
#  define N_(String) (String)
/***************************************************************
*   Structure   :   prRadioButton
*   --------------------------
*       Le prRadioButton est la structure qui permet de creer
*    un group de button radio .
*        les champs de la structure :
*            - l'objet radio button
*            - le conteneur
*            - le pere du group
*            - liste des buttons appartient au meme group
*            - label du button
*            - nom du l'objet
*            - la mnemonic de l'objet
*            - la position de l'objet
****************************************************************/
typedef struct prRadioButton
{

	GtkWidget   *radioButton;       // l'objet button radio
    GtkWidget   *racine;            // Le conteneur
    GtkWidget   *rad2;              // le pere du group
	GSList      *group;             // group des buttons creer
	gchar       *label;             // label du button
	char        *nom;               //Le nom du radio (pour le css)
	int          mnemonic;          //1 si creation avec mnemonic, 0 sinon
	prPos    *pox;               // position du bouton
} prRadioButton;
#endif // str_pr_radio_button

