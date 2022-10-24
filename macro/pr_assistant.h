#include"str_pr_assistant.h"

    // initialiser et Creer le conteneur l'assistant
prAssistant * pr_assistant_init(int h,int w);
prAssistant* pr_assistant_create(prAssistant *);
    // initialiser et creer l'assistant page
prPageAssistant* pr_page_assistant_init(char *,char *);
prPageAssistant* pr_page_assistant_create(prPageAssistant *,int );

    //  Creer l'assistant
prAssistant* pr_assistant_apply(prAssistant *,
                                      prPageAssistant *,
                                       int );
