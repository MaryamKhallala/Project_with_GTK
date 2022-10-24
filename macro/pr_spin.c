#include"pr_spin.h"

prSpin* pr_spin_init( gdouble sMin,gdouble sMax,gdouble sPas,int w,int h,int x,int y)
{
  prSpin *spin=(prSpin*)malloc(sizeof(prSpin));
  spin->pox=(prPos*)malloc(sizeof(prPos));
  spin->sMin=sMin;
  spin->sMax=sMax;
  spin->sPas=sPas;
  spin->x=w;
  spin->y=h;
  spin->pox->x=x;
  spin->pox->y=y;
  return((prSpin*)spin);
}
prSpin* pr_spin_creat( prSpin* sp)
{
    sp->Spin= gtk_spin_button_new_with_range(sp->sMin,sp->sMax, sp->sPas);
    gtk_widget_set_size_request(sp->Spin , sp->x , sp->y);
    return((prSpin*)sp);
}
