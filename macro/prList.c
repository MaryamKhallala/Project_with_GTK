
#include"prList.h"
/************************** prList ********************************/
/**********************************************************************
*   Fonction   :   prList *pr_list_init ()
*   ------------------------------------------------------------------
*      La fonction suivante assure l'allocation de la structure
*    list a utilise
*   Entre   :   void
*
*   Sortie  :   Une variable de type prList apres l'allocation
**********************************************************************/
prList *pr_list_init ()
{
    prList * list = NULL;
    list = (prList*) malloc (sizeof (prList));
    list->list = NULL;
    return ((prList*) list);
}
/**********************************************************************
*   Fonction   :  prList *pr_list_create (prList *)
*   ------------------------------------------------------------------
*       Cette dernier consiste à allouer de l'espace mémoire du champs
*    list dans la variable prList
*        Notre list avoir comme type du data un pointeur generique
*     comme ça on l'utilise avec n'importe quelle type de variable
*   Entre   :  Une variable de type prList* apres initialiser
*   Sortie  :  LA meme variable apres que nous avons assurer
*            l'allocation du champ list .
***********************************************************************/
prList *pr_list_create (prList *list)
{
    list->list = g_slist_alloc ();
    return ((prList*) list);
}
/**********************************************************************
*   Fonction   :   prList    *pr_list_add_string (prList *,
*                                                        gchar *)
*   ------------------------------------------------------------------
*       La fonction suivante permet d'insere une chaine de caractere
*  dans notre list
*   Entre   :   -La list dans laquelle on vas inserer
*               -La chaine de caractére à inserer
*
*   Sortie  :   Notre list apres effectuer l'insertion
**********************************************************************/
prList    *pr_list_add_string (prList *list, gchar *element)
{
    list->list = g_slist_append(list->list, element);
    return ((prList*) list);
}
/**********************************************************************
*   Fonction   :  prList    *pr_list_add_int (prList *,
                                                    gint )
*   ------------------------------------------------------------------
*       La fonction suivante permet d'insere un entier
*  dans notre list
*   Entre   :   -La list dans laquelle on vas inserer
*               -L'entier à inserer
*
*   Sortie  :   Notre list apres effectuer l'insertion
*/


prList    *pr_list_add_int (prList *list, gint element)
{
    list->list = g_slist_append(list->list, GINT_TO_POINTER (element));
    return ((prList*) list);
}
