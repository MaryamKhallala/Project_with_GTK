#ifndef str_pr_list
#define str_pr_list
#include"bibliotheque.h"
/******************************************************
*   Structure   :   prList
*   --------------------------
*       Le prList est la liste generique qui peut
*    contenir n'import qu'il informatique avec
*    le pointeur generique .
******************************************************/
typedef struct prList
{
    GSList *list; // l'objet liste
} prList;
#endif // str_pr_list

