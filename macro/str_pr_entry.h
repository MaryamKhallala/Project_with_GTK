#ifndef str_pr_entry
#define str_pr_entry
#include"bibliotheque.h"
/*******************************************************************
*   Structure   :   prEntry
*   --------------------------
*       Le prEntry est la structure qui permet de creer une zone
*    saisie , avec leur critaires.
*       les champs de la strucures :
*     l'objet entry
*     le conteneur de l'objet
*     text indicatif interieur de la zone
*     nom de l'objet
*        text doit etre afficher ou non
*     visibiliter de l'ecriture
*        mot de pass ou un Simple
********************************************************************/
typedef struct prEntry
{
	GtkWidget   *entry;             //  l'objet entry
    GtkWidget   *racine;            //  Le container
	gchar       *text;              //  Le text par defaut du champ
    gchar       *nom;               //  Le nom du champ (pour le css)
	int         contentForm;        //  0 pour placeholder,
                                    //  1 pour buffer, x pour vide
	int         visibility;         //  1 pour visible, 0 invisible
	int         invisibleChar;      //  0 pour password, 1 pour PIN
	prPos *pox;
} prEntry;
#endif // str_pr_entry

