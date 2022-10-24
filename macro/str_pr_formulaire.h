#ifndef str_pr_form
#define str_pr_form
#include"bibliotheque.h"

#include"prButton.h"
#include"prRadioButton.h"
#include"prCheckButton.h"
#include"prFrame.h"
#include"prFixed.h"
#include"prEntry.h"
#include"prCombobox.h"
#include"pr_spin.h"
#include"prLabel.h"
#include"prBox.h"
#include"prImage.h"
#include"prNotebook.h"
#include"prBox.h"
#define MAX_TAILL 20

// les objets creer par la plateforme de l'application
enum
{
    WINDOW,
    WIDGET,
    CADRE,
    ONGLET,
    PAGE_ONGLET,
    COMBOBOX,
    RADIO,
    SCROLLED,
    BOX,
    BOITE
};


/*************************************************************************
*   Structure   :   prForm
*   --------------------------
*       Le prForm est la structure qui rassemble tous les autres objets
*    pour creer un formulaire complete avec ces composants que vous voulez .
*        les composants possibles du formulaires :
*      prFrame le cadre
*      prFixed le fix conteneur des objets
*      prEntry zone de saisie
*      prButton les button
*      prCheckButton les cases a cocher
*      prRadioButton les radio
*      prComboBox listes durolante
*      prLabel    etiquette
*      prSpin     compteur
****************************************************************************/

typedef struct prForm
{
    prFrame* frame;
    prFixed* fixed;
    prEntry* entry[MAX_TAILL];
    prButton* btn[MAX_TAILL];
    prCheckButton* cb[MAX_TAILL];
    prComboBox* com[MAX_TAILL];
    prRadioButton* radiobutton[MAX_TAILL];
    prLabel* label;
    prSpin *sp[MAX_TAILL];
} prForm;
#endif // str_pr_Form
