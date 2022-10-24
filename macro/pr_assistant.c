#include"pr_assistant.h"
prAssistant * pr_assistant_init(int h,int w)
{
    prAssistant *assist=(prAssistant*)malloc(sizeof(prAssistant));
    assist->h=h;
    assist->w=w;

    return((prAssistant*)assist);
}

prAssistant* pr_assistant_create(prAssistant *assist)
{
    assist ->assist = gtk_assistant_new();
    gtk_window_set_default_size(GTK_WINDOW(assist->assist), assist->h,assist->w);

    return((prAssistant*)assist);
}

prPageAssistant* pr_page_assistant_init(char *contenue_page,char *titel_page)
{
    prPageAssistant *page=(prPageAssistant*)malloc(sizeof(prPageAssistant));
    page->contenue_page=(char*)malloc(10000*sizeof(char));
    page->titel_page=(char*)malloc(256*sizeof(char));
    strcpy(page->contenue_page,contenue_page);
    strcpy(page->titel_page,titel_page);

    return((prPageAssistant*)page);
}

prPageAssistant* pr_page_assistant_create(prPageAssistant *page,int img)
{
    prImage *image;
    page->box=gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    switch(img)
    {

        int x=100,y=100;
        char *url[200];
        case 1:

                strcpy(url,"Interface/120-1.ico");
                image=pr_image_init(url,x,y);
                image=pr_image_create(image);
                gtk_box_pack_start(GTK_BOX(page->box), image->image, TRUE, TRUE, 5);
                break;
        case 2:
                strcpy(url,"Interface/120-2.ico");
                image=pr_image_init(url,x,y);
                image=pr_image_create(image);
                gtk_box_pack_start(GTK_BOX(page->box), image->image, TRUE, TRUE, 5);
                break;
        case 3 :
                strcpy(url,"Interface/120-3.ico");
                image=pr_image_init(url,x,y);
                image=pr_image_create(image);
                gtk_box_pack_start(GTK_BOX(page->box), image->image, TRUE, TRUE, 5);
                break;
        case 4:
                strcpy(url,"Interface/il-inter_icon.png");
                image=pr_image_init(url,x,y);
                image=pr_image_create(image);
                gtk_box_pack_start(GTK_BOX(page->box), image->image, TRUE, TRUE, 5);
                break;
        case 5:

                strcpy(url,"Interface/abdlelouahid.png");
                image=pr_image_init(url,x,y);
                image=pr_image_create(image);
                gtk_box_pack_start(GTK_BOX(box), image->image, TRUE, TRUE, 5);
                 strcpy(url,"Interface/rachide.png");
                image=pr_image_init(url,x,y);
                image=pr_image_create(image);
                gtk_box_pack_start(GTK_BOX(box), image->image, TRUE, TRUE, 5);
                gtk_box_pack_start(GTK_BOX(page->box), box, TRUE, TRUE, 5);
                break;
        case 6:
                strcpy(url,"Interface/bienvenue2.png");
                image=pr_image_init(url,x,y);
                image=pr_image_create(image);
                gtk_box_pack_start(GTK_BOX(page->box), image->image, TRUE, TRUE, 5);
                strcpy(url,"Interface/pr-logo-1.png");
                image=pr_image_init(url,x,y);
                image=pr_image_create(image);

                break;
        default : break;
    }
    page->label=gtk_label_new(page->contenue_page);
    gtk_box_pack_start(GTK_BOX(page->box), page->label, TRUE, TRUE, 5);
    if(img==6)
        gtk_box_pack_start(GTK_BOX(page->box), image->image, TRUE, TRUE, 5);

        return((prPageAssistant*)page);
}
prAssistant* pr_assistant_apply(prAssistant *assist,prPageAssistant *page, int type)
{
    gtk_assistant_append_page(GTK_ASSISTANT(assist->assist), page->box);
    gtk_assistant_set_page_title(GTK_ASSISTANT(assist->assist), page->box, page->titel_page);
    switch(type)
    {
        case 1 :
                gtk_assistant_set_page_type(GTK_ASSISTANT(assist->assist), page->box, GTK_ASSISTANT_PAGE_INTRO);
                break;
        case 2:
                gtk_assistant_set_page_type(GTK_ASSISTANT(assist->assist), page->box, GTK_ASSISTANT_PAGE_CONTENT);
                break;
        case 3:
                gtk_assistant_set_page_type(GTK_ASSISTANT(assist->assist), page->box, GTK_ASSISTANT_PAGE_CONFIRM);
                break;

    }
    gtk_assistant_set_page_complete(GTK_ASSISTANT(assist->assist), page->box, TRUE);
    return((prAssistant*)assist);
}
