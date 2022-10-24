#include"prEntry.h"
/**************************** prEntry ******************************/
/**********************************************************************
*   Fonction : prEntry *pr_entry_init (gchar*,
                                             gchar*,
                                             int,
                                             int,
                                             int,
                                             GtkWidget*)
*   ------------------------------------------------------------------
*       Cette fonction fait l allocation et initialisation des champs
*   de la structure prEntry avec tous les critaire que nous voullons
*   Entre   :  - Text informatif par defaut de l'entry
*              - Le nom donner à l'entry (pour le CSS)
*              - ContenetForm la maniére avec la quelle le message de
*           l'entry vas s'afficher sois en gris (arriere-plan) ,ou
*             text normale a l'interieur du buffer
*              - L'ecriture dans l'entry soit visible ou non
*              - Si non visible alors et ce qu'il est en mode password
*             ou pin(rien qui s'affiche).
*              - Le container qui vas porter notre entry
*   Sortie  :  - Entry apres initialiser
***************************************************************************/
prEntry *pr_entry_init (gchar *text, gchar *nom, int contentForm,
                              int visibility, int invisibleChar,
                              GtkWidget *racine,int x ,int y)
{
    prEntry *entry = NULL;
    entry = (prEntry*) malloc (256*sizeof (prEntry));
entry->pox=(prPos*)malloc(sizeof(prPos));
    if (text)
    {
        entry->text = (gchar*) malloc (256*sizeof (gchar));
        strcpy (entry->text, text);
    }
    else entry->text =NULL;
    if (nom)
    {
        entry->nom = (gchar*) malloc (256*sizeof (gchar));
        strcpy (entry->nom, nom);
    }
    else entry->text =NULL;
    entry->contentForm = contentForm;
    entry->visibility = visibility;
    entry->invisibleChar = invisibleChar;

    entry->racine = racine;
    entry->pox->x=x;
    entry->pox->y=y;
    return ((prEntry*) entry);
}
/***************************************************************************
*   Fonction   :  prEntry *pr_entry_create (prEntry *entry)
*   ------------------------------------------------------------------
*       La Fonction suivante nous offres la creation d'une entry à certains
* critaires.
*   Entre   :   Une variable de type prEntry deja initialiser
*
*   Sortie  :   L'entry creer avec les critaires citer
***************************************************************************/
prEntry *pr_entry_create (prEntry *entry)
{
    entry->entry = gtk_entry_new ();
    if (entry->text)
    {
        if (! entry->contentForm)
            gtk_entry_set_placeholder_text(GTK_ENTRY(entry->entry),
                                           entry->text);
        else if (entry->contentForm == 1)
            gtk_entry_set_buffer (GTK_ENTRY(entry->entry),
                                  gtk_entry_buffer_new (entry->text, -1));
    }
    if (! entry->visibility)
    {
        if (! entry->invisibleChar)
            gtk_entry_set_visibility (GTK_ENTRY(entry->entry),
                                          FALSE);
        else gtk_entry_set_visibility (GTK_ENTRY(entry->entry),
                                           TRUE);
    }
    gtk_widget_set_name (entry->entry, entry->nom);
    return ((prEntry*) entry);
}

