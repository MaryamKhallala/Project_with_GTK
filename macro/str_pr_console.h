#ifndef str_pr_console
#define str_pr_console
#include"bibliotheque.h"

/**********************************************************
*   Structure   :   prConsole
*   --------------------------
*       Le prConsole est la structure qui nous permet de
*    creer une console à l'aide du textview
*       les composants de cette structure sont :
*     l'objet Console ( Text view ) zone de saisie
*     buffer de notre console
***********************************************************/
typedef struct
{
    GtkWidget *console;         // zone de saisie
    GtkTextBuffer *buffer;      // buffer

}prConsole;

typedef GtkTextIter prIter; // iter du position
#endif // str_pr_console
