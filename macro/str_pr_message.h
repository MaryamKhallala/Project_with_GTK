#ifndef str_pr_message
#define str_pr_message
#include"bibliotheque.h"

/********************************************************************
*   Structure   :   prMessage
*   --------------------------
*       Le prMessage est la strucutre qui peremet de creer
*    boite message , avec leur critère .
*        les champs de la structures:
*     - l'objet message
*     - le conteneur de l'objet
*     - type de message a afficher
*     - type de button appartient a la boite
*     - le message à afficher
*
********************************************************************/
typedef struct prMessage
{
  GtkWidget *message;           // l'objet creer message
  GtkWidget *pere;              // le conteneur de l'objet
  int flag;                    /* valeurs possibles:
                                    1: MODAL ( separer )
                                    2: DESTROY_WITH_PARENT
                                        ( en relation avec le pere);
                                */
  int type_message;            /* valeurs possibles:
                                    i: GTK_MESSAGE_INFO;
                                    w: GTK_MESSAGE_WARNING;
                                    q: GTK_MESSAGE_QUESTION
                                    e: GTK_MESSAGE_ERROR
                                */
  int type_boutton;             /*
                                    0 : sans button
                                    1 : OK
                                    2 : CLOSE
                                    3 : CANCEL
                                    4 : YES_NO
                                    5 : OK_CANCEL
                              */
  char *message_a_afficher;     // le message a afficher
}prMessage;
#endif // str_pr_message

