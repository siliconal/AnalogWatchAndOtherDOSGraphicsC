//fonction traduite de Pascal
//procedure segment(coldep,ligdep,colarr,ligarr:word;couleur:byte);
void segment(uint16_t coldep,uint16_t ligdep,uint16_t colarr,uint16_t ligarr,uint16_t couleur)
{
  uint16_t x,y;
  uint16_t coldep2,ligdep2,colarr2,ligarr2;
     ligdep2=ligdep;
     coldep2=coldep;
     ligarr2=ligarr;
     colarr2=colarr;
     if (ligarr<ligdep) ligdep2=ligarr+(ligarr-ligdep);
     x=coldep;
     y=ligdep;
     while (x!=colarr)
     {
          putpixel(x,319-y,couleur);
          if ((colarr2-coldep2)<(ligarr2-ligdep2))
          {
               if ((float)((y-ligdep) % ((ligarr2-ligdep2) / (colarr2-coldep2)))==0)
                  {if (ligdep<ligarr) x++; else x--;}
               y++;
          }
          else
          {
               if ((float)((x-coldep) % ((colarr2-coldep2) / (ligarr2-ligdep2)))==0)
                  {if (ligdep<ligarr) y++; else y--;}
               x++;
          }
     }
}
