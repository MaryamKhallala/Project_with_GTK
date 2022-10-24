#include"prForm.h"
prForm* pr_form_init()
{
    prForm *form=(prForm*)malloc(sizeof(prForm));

    ((prForm*)form);
}
prForm* pr_form_creat(prForm* form)
{

if(form->fixed)
    form->fixed = pr_fixed_create(form->fixed);
    return((prForm*)form);
}
