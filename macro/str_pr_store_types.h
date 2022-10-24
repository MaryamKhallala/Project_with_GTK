#ifndef str_pr_store_types
#define str_pr_store_types
#include"bibliotheque.h"
/*****************************************************************
*   Structure   :   prStoreTypes
*   --------------------------
*       Le prStoreTypes la liste des objets inserer dans
*   la textview.
*****************************************************************/
typedef struct prStoreTypes
{
    GType   *storeTypes;        // la liste des objets
    gint    n_cols;             /* numero de collone dans la quel on
                                 insert*/
} prStoreTypes;
#endif // str_pr_store_types

