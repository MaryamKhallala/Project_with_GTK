#include"str_pr_message.h"
/**************** Boite Message **************************/
/* initalisation */
prMessage* pr_message_init(int flag,
                                 int type,
                                 int type_boutton,
                                 char *message_afficher);
/* creation */
prMessage* pr_message_create(prMessage *dialog);

