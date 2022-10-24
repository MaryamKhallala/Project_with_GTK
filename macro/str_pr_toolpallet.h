
#include"bibliotheque.h"

/*****************************************************
*   Structure   :   prToolPallet
*   -----------------------------
*       Le prToolPallet est la pallet a afficher
*****************************************************/


typedef struct toolpallet
{
    GtkWidget *toolpalette;     // l'objet pallet
}prToolPallet;

/**************************************************************
*   Structure   :   prToolPallet_group
*   -----------------------------
*       Le prToolPallet_group peremet de creer un group pour
*    la pallet creer
***************************************************************/


typedef struct toolpallet_group
{

    GtkWidget *toolitemgroup;       //le group du pallet
    gchar *nom_group;               // le nom du group
}prToolPallet_group;


/******************************************************************
*   Structure   :   prToolPallet_elem
*   -----------------------------
*       Le prToolPallet_permet a inserer des buttons a un group
******************************************************************/
typedef struct toolpallet_elem
{
    GtkToolItem *toolitem;          // le button
    gchar *icon;                    // nom  du button
    gchar *path_icon;               // url du button
    gpointer *signal;               // signal du button
}prToolPallet_elem;
