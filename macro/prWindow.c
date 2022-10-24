#include"prWindow.h"
/******************** Pour prWindow ********************************/
/**********************************************************************
*   Fonction   :   prWindow * pr_window_init (gchar *,
*                                                    gchar ,
*                                                    gchar *,
*                                                    gint ,
*                                                    gint ,
*                                                    gint ,
*                                                    gchar *)
*   ------------------------------------------------------------------
*       Cette fonction permet de assurer l'allocation d'une variable de
*    type prWindow , et aussi de appliquer initialisation des champs
*    selon la fenetre qu'on veut creer
*   Entre   :   - titre de la fenetre
*                - type de la fenetre 't' TOPLEVEL ou 'p' POPLEVEL
*                - nom de la fenetere qui vas nous servir dans CSS
*               - hauteur de notre fenetre
*                - largeur de notre fenetre
*                - position par defaults de la fenetre
*                       0 = GTK_WIN_POS_NONE
*                       1 = GTK_WIN_POS_CENTER
*                       2 = GTK_WIN_POS_MOUSE
*                       3 = GTK_WIN_POS_CENTER_ALWAYS
*                       4 = GTK_WIN_POS_CENTER_ON_PARENT
*                - le lien de l'icon
*   Sortie  : Notre fentre apres l'initialisation
*/
prWindow * pr_window_init (gchar *titre, gchar type, gchar *nom,
                                  gint h, gint l,gint pos,gint resizable,
                                  gchar *icon)
{
	prWindow * window = NULL;
	window = (prWindow*) malloc (sizeof(prWindow));

    if(! window)
        {
            printf("\n erreur");
            exit(0);
        }
        window->titre=(gchar*)malloc(256*sizeof(gchar));
        window->nom=(gchar*)malloc(256*sizeof(gchar));
        window->icon=(gchar*)malloc(256*sizeof(gchar));

    if(titre) strcpy (window->titre, titre);
    else window->titre=NULL;
	if(nom)strcpy (window->nom, nom);
    else window->nom=NULL;
	if(icon)strcpy (window->icon, icon);
    else window->icon=NULL;

	window->type = type;
	window->hauteur = h;
	window->longueur =l;
	window->resizable=resizable;
    window->position=pos;
	return ((prWindow*) window);
}
/*************************************************************************
*   Fonction  :  prWindow * pr_window_create (prWindow * window)
*   ------------------------------------------------------------------
*       Cette fonction sert a la creation d'une fentre avec une certains
*    critaire
*   Entre   :   Notre structure de la fenetre deja initialiser
*
*   Sortie  :   Retourne une Variable de type prWindow avec une fenetre
*            creer par les critaire donner
*************************************************************************/
prWindow * pr_window_create (prWindow * window)
{
	if (window->type == 't' || window->type == 'T')
		window->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    else if(window->type == 'p' || window->type== 'P')
        window->window = gtk_window_new(GTK_WINDOW_POPUP);
    else
        window->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    if(window->nom)
        gtk_widget_set_name (window->window, window->nom);
    else
        gtk_widget_set_name(window->window,"fenetre");
    if(window->titre)
        gtk_window_set_title(GTK_WINDOW(window->window), window->titre);
    else
        gtk_window_set_title(GTK_WINDOW(window->window),"fenetre");
    if(window->longueur && window->hauteur)
        gtk_window_set_default_size(GTK_WINDOW(window->window),
                                (window->longueur),(window->hauteur));
    else
        gtk_window_set_default_size(GTK_WINDOW(window->window),100,100);

    /* Définition de la position */
    switch(window->position)
    {
        case 0 : gtk_window_set_position(GTK_WINDOW(window->window),
                                         GTK_WIN_POS_NONE);
                break ;
        case 1 : gtk_window_set_position(GTK_WINDOW(window->window),
                                         GTK_WIN_POS_CENTER);
                break;
        case 2 : gtk_window_set_position(GTK_WINDOW(window->window),
                                          GTK_WIN_POS_MOUSE);
                break;
        case 3 : gtk_window_set_position(GTK_WINDOW(window->window),
                                         GTK_WIN_POS_CENTER_ALWAYS);
                break;
        case 4 : gtk_window_set_position(GTK_WINDOW(window->window),
                                        GTK_WIN_POS_CENTER_ON_PARENT);
                break;
        default :
                gtk_window_set_position(GTK_WINDOW(window->window),
                                         GTK_WIN_POS_CENTER);
                break;
    }
    if(!window->resizable)
        gtk_window_set_resizable (GTK_WINDOW(window->window),FALSE);
    else
         gtk_window_set_resizable (GTK_WINDOW(window->window),TRUE);
    if (window->icon)
        gtk_window_set_icon_from_file (GTK_WINDOW(window->window),
                                       window->icon, NULL);
    window->fixed=gtk_fixed_new();
    return ((prWindow*) window);
}

