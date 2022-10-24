#include"prToolPallet.h"
prToolPallet* pr_tool_pallet_creat()
{
    prToolPallet* pallet=
        (prToolPallet*)malloc(sizeof(prToolPallet));
    pallet->toolpalette= gtk_tool_palette_new();
    return((prToolPallet*)pallet);
}

prToolPallet_group* pr_tool_pallet_group_init(gchar * nom_group)
{
    prToolPallet_group *groupe=
        (prToolPallet_group*)malloc(sizeof(prToolPallet_group));
     groupe->nom_group=(gchar*)malloc(256*sizeof(gchar));
    if(nom_group)strcpy(groupe->nom_group,nom_group);
    else groupe->nom_group=NULL;

    return((prToolPallet_group*)groupe);
}

prToolPallet_group* pr_tool_pallet_group_creat(
                                            prToolPallet *pallet,
                                            prToolPallet_group* group)
{
    group->toolitemgroup = gtk_tool_item_group_new(group->nom_group);
    gtk_container_add(GTK_CONTAINER(pallet->toolpalette),
                      group->toolitemgroup);
    return((prToolPallet_group*)group);
}


prToolPallet_elem* pr_tool_pallet_elem_init(gchar *icon,
                                                  gchar *path_icon,
                                                  gpointer *signal)
{
    prToolPallet_elem *pallet=
            (prToolPallet_elem*)malloc(sizeof(prToolPallet_elem));

    pallet->path_icon=(gchar*)malloc(256*sizeof(gchar));
    pallet->icon=(gchar*)malloc(256*sizeof(gchar));

    if(path_icon) strcpy(pallet->path_icon,path_icon);
    else pallet->path_icon=NULL;

    if(icon)strcpy(pallet->icon,icon);
    else pallet->icon=NULL;

     pallet->signal=signal;

    return ((prToolPallet_elem*)pallet);

}

prToolPallet_elem* pr_tool_pallet_elem_creat(
                                        prToolPallet_group* group,
                                        prToolPallet_elem *pallet,gpointer *data)
{
  gchar *path=(gchar*)malloc(256*sizeof(gchar));
  sprintf(path,"%s/%s","Interface",
          pallet->path_icon);

  GtkWidget *image = gtk_image_new_from_file (path);
  pallet->toolitem = gtk_tool_button_new(image, pallet->icon);

  gtk_tool_item_set_tooltip_markup (pallet->toolitem,pallet->icon);
  gtk_tool_item_group_insert(GTK_TOOL_ITEM_GROUP(group->toolitemgroup),
                             pallet->toolitem, -1);
  if(pallet->signal) g_signal_connect(GTK_WIDGET(pallet->toolitem),
                                      "clicked",G_CALLBACK(pallet->signal),
                                      data);
    return((prToolPallet_elem*)pallet);
}

