#include"str_pr_frame.h"
/********************* prFrame **********************/
    /*initialisation*/
prFrame* pr_frame_init(GtkWidget *widget,
                             GtkWidget *pere,
                             char titre[20],
                             float pos_H,
                             float pos_V,
                             int style_cadre);
    /* Creation */
prFrame* pr_frame_create(prFrame *f);

