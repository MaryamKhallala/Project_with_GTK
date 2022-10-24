#include"str_pr_dialog.h"
/******************* Boite Dialog ********************************/
void pr_dialog_add(prDialog *dialog,GtkWidget *elem);
prDialog* pr_dialog_init(int flag,int type_boutton,
                               char *titre,gint h,gint l);
prDialog* pr_dialog_create(prDialog *dialog);

