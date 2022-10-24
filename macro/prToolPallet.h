#include"str_pr_toolpallet.h"

/* Creation du Pallet */
    prToolPallet* pr_tool_pallet_creat();

/* initialisation du Group */
    prToolPallet_group* pr_tool_pallet_group_init(gchar *);
/* Creation du Group */
    prToolPallet_group* pr_tool_pallet_group_creat(prToolPallet *,
                                                prToolPallet_group*);
/* Inialisation de l'element a inserer */
    prToolPallet_elem* pr_tool_pallet_elem_init(gchar *,
                                                      gchar *,
                                                      gpointer *);
/* Creation de l'element */
    prToolPallet_elem* pr_tool_pallet_elem_creat(prToolPallet_group*,
                                                       prToolPallet_elem*,
                                                       gpointer *);
