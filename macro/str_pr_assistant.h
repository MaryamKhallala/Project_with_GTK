#include "bibliotheque.h"
#include "prImage.h"
typedef struct assistant
{
    GtkWidget *assist;
    int h;
    int w;
}prAssistant;

typedef struct page_assistant
{
    GtkWidget *label;
    GtkWidget *box;
    char *titel_page;
    char *contenue_page;
}prPageAssistant;

