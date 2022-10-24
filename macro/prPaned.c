#include"prPaned.h"
prPaned* pr_paned_init(gchar type)
{
    prPaned *paned=(prPaned*)malloc(sizeof(prPaned));
    paned->type=type;

  return((prPaned*)paned);
}
prPaned* pr_paned_creat(prPaned *paned)
{

    if(paned->type == 'h')
        paned->paned= gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
    else
        paned->paned= gtk_paned_new(GTK_ORIENTATION_VERTICAL);
  return((prPaned*)paned);
}
prPaned* pr_paned_add(prPaned *paned,
                            GtkWidget *element,
                            gchar emplacement)
{
    if(emplacement == 'g' || emplacement == 'G')
        gtk_paned_pack1(GTK_PANED(paned->paned),element,FALSE,FALSE);
    else if (emplacement == 'd' || emplacement == 'D')
        gtk_paned_pack2(GTK_PANED(paned->paned),element,FALSE,FALSE);
    return((prPaned*)paned);
}
