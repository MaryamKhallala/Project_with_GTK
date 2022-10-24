#ifndef str_pr_spin
#define str_pr_spin
#include"bibliotheque.h"
/*************************************************
*   Structure   :   prComboBox
*   --------------------------
*       Le prComboBox est le widget qui permete de creer
*   des listes dirolantes (dropdown)
*/
typedef struct prSpin
{
    GtkWidget *Spin;
    gdouble sMin;
    gdouble sMax;
    gdouble sPas;
    int x;
    int y;
    prPos *pox;
} prSpin;
#endif // str_pr_spin
