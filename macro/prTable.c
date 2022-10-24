#include"prTable.h"
/****************************** prTable *****************************/
/**********************************************************************
*   Fonction   :   prTable* pr_table_init(GtkWidget *,
*                                               int ,
                                                int ,
                                                int )
*   ------------------------------------------------------------------
*       Cette fonction fait l allocation et initialisation des champs
*   de la structure prTable
*   Entre   :   - Le container ou on vas mettre notre table
*                - nombre de ligne de la table
*                - nombre de nb_collone
*                - les element qu'on vas mettre dans la table sont-ils
*            homogene ou non.
*
*   Sortie  : Notre Objet bien initialiser
*/
prTable* pr_table_init(GtkWidget *pere,int nb_ligne,
                             int nb_collone,int homogene)
{
    prTable *tab=(prTable*)malloc(sizeof(prTable));
    tab->pere=pere;
    tab->nbr_lignes=nb_ligne;
    tab->nbr_colonnes=nb_collone;
    tab->homogene=homogene;
    return ((prTable*)tab);
}
/**************************************************************************
*   Fonction   :   prTable* pr_table_create(prTable *)
*   ------------------------------------------------------------------
*       Cette fonction concerne la creation d'une table à certaine
*    critaire initialiser dans la meme structure
*   Entre   :  Variable de type prTable deja initialiser
*   Sortie  :  Variable de type prTable apres creation de la table
*/
prTable* pr_table_create(prTable *tab)
{
// grid
    if(tab->homogene==1)
        tab->table=gtk_table_new(tab->nbr_lignes,tab->nbr_colonnes,TRUE);
    else
        tab->table=gtk_table_new(tab->nbr_lignes,tab->nbr_colonnes,FALSE);
    return ((prTable*)tab);
}
/**********************************************************************
*   Fonction   :  void pr_table_add(prTable *,
*                                       GtkWidget *,
*                                       int ,
*                                       int ,
*                                       int ,
*                                       int )
*
*   ------------------------------------------------------------------
*       Cette fonction cert a ajouter certains widget a notre table
*   Entre   :   - notre table
                - l'element a inserer
                -la cellule située a gauche de l'element a inserer
                la cellule située a droite de l'element a inserer
                la cellule située a haut de l'element a inserer
                la cellule située a bas de l'element a inserer
*   Sortie  : void (attacher le fils au tableau)
*/
void pr_table_add(prTable *tab,GtkWidget *fils,int gauche,
                     int droite,int haut,int bas)
{
    gtk_table_attach_defaults(GTK_TABLE(tab->table),fils,gauche,droite,haut, bas);
}

