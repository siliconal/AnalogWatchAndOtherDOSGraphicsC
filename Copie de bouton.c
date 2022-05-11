//{============================================================================}

//implementation

/**************************************************
definition types int8_t uint8_t int16_t et uint16_t
***************************************************/
#if !defined(uint16_t)
#define uint16_t unsigned int
#endif

#if !defined(uint8_t)
#define uint8_t unsigned char
#endif

#if !defined(int16_t)
#define int16_t int
#endif

#if !defined(int8_t)
#define int8_t char
#endif

/*********************************
definition costante boolèene
**********************************/
#if !defined(FALSE)
#define FALSE 0
#endif

#if !defined(TRUE)
#define TRUE 1
#endif

//var i:integer;
    int16_t i;
    //gs,gm:integer;
    int16_t gs,gm;
    //c:string[9];
    char c[9];
    //ch:char;
    char *ch;
    
    int16_t caractbouton[99][5];
    
//{===ecriture du texte contu‚nu dans le bouton===}
//procedure Contenu(colonne,ligne,largeur,hauteur:word;texte:string);
void Contenu(uint16_t colonne, uint16_t ligne, uint16_t largeur, uint16_t hauteur, char *texte)
//begin
{
     //settextjustify(centertext,centertext);
     settextjustify(CENTER_TEXT,CENTER_TEXT);
     //setcolor(15);
     setcolor(15);
     //outtextXY(colonne+(largeur div 2)-1,ligne+(hauteur div 2)+1,texte);
     outtextXY(colonne+(largeur / 2)-1,ligne+(hauteur / 2)+1,texte);
     //setcolor(0);
     setcolor(0);
     //outtextXY(colonne+(largeur div 2),ligne+(hauteur div 2),texte);
     outtextXY(colonne+(largeur / 2),ligne+(hauteur / 2),texte);
//end;
}


//{===trace du contour===}
//procedure contour(colonne,ligne,largeur,hauteur:word;epaisseur:byte;videoinv:boolean);
void Contour(uint16_t colonne, uint16_t ligne, uint16_t largeur, uint16_t hauteur,
		uint8_t epaisseur, uint8_t videoinv)
//var epais,x,y,x1,y1:word;
    //coulombre,couleclaire:byte;
//begin
{
     uint16_t epais,x,y,x1,y1;
     uint16_t coulombre,couleclaire;
     
     //if videoinv then
     if (videoinv)
     //begin
     {
	//coulombre:=15;
	coulombre=15;
	//couleclaire:=8;
	couleclaire=8;
     //end
     }
     //else
     else
     //begin
     {
	//coulombre:=8;
	coulombre=8;
	//couleclaire:=15;
	couleclaire=15;
     //end;
     }
     //{===contour ombre===}
     //epais:=0;
     epais=0;
     //for y:=ligne to ligne+hauteur do
     for(y=ligne; y<=ligne+hauteur; y++)
     //begin
     {
          //for x:=colonne to colonne+epais do
	for(x=colonne; x<=colonne+epais; x++)
               //putpixel(x,y,coulombre);
	     putpixel(x,y,coulombre);
          //if epais<epaisseur then inc(epais);
	if (epais<epaisseur)  epais++;
     //end;
     }
     //epais:=epaisseur;
     epais=epaisseur;
     //for y:=ligne+hauteur-epais to hauteur+ligne do
     for(y=ligne+hauteur-epais; y<=hauteur+ligne; y++)
     //begin
     {
          //for x:=colonne to colonne+largeur-epais do
	for(x=colonne; x<=colonne+largeur-epais; x++)
              //putpixel(x,y,coulombre);
	    putpixel(x,y,coulombre);
          //dec(epais);
	epais--;
     //end;
     }

     //{===contour eclaire===}
     //epais:=0;
     epais=0;
     //for y1:=y downto ligne do
     for(y1=y; y1>=ligne; y1--)
     //begin
     {
          //for x1:=x downto colonne-epais+largeur do
	for(x1=x; x1>=colonne-epais+largeur; x1--)
              //putpixel(x1,y1,couleclaire);
	    putpixel(x1,y1,couleclaire);
          //if epais<epaisseur then inc(epais);
	if (epais<epaisseur) epais++;
     //end;
     }
     //epais:=epaisseur;
     epais=epaisseur;
     //for y1:=ligne+epais downto ligne do
     for(y1=ligne+epais; y1>=ligne; y1--)
     //begin
     {
          //for x1:=x-epais downto colonne+epais do
	for(x1=x-epais; x1>=colonne+epais; x1--)
              //putpixel(x1,y1,couleclaire);
	    putpixel(x1,y1,couleclaire);
          //dec(epais);
	epais--;
     //end;
     }
//end;
}


//{===trace du bouton au repos===}
//procedure BoutonRepos(codebouton:byte);
void BoutonRepos(uint8_t codebouton)
//var x:byte;
    //ligne,colonne,largeur,hauteur:word;
    //size:word;
    //img:pointer;
//begin
{
     uint8_t x;
     uint16_t ligne,colonne,largeur,hauteur;
     uint16_t size;
     void *img;
     
     //effsouris;
     effsouris();
     //x:=1;
     x=1;
     //while (x<=99) and (caractbouton[x,5]<>codebouton) do inc(x);
     while((x<=99) && (caractbouton[x][5]!=codebouton)) x++;
     //if x<=99 then
     if (x<=99)
     //begin
     {
          //ligne:=caractbouton[x,1];
	ligne=caractbouton[x][1];
          //colonne:=caractbouton[x,2];
	colonne=caractbouton[x][2];
          //largeur:=caractbouton[x,3];
	largeur=caractbouton[x][3];
          //hauteur:=caractbouton[x,4];
	hauteur=caractbouton[x][4];
     //end;
     }

     //{===trace de la ligne exterieure===}
     //setlinestyle(0,0,1);
     setlinestyle(0,0,1);
     //setcolor(0);
     setcolor(0);
     //rectangle(colonne,ligne+1,colonne+largeur,ligne+hauteur-1);
     rectangle(colonne,ligne+1,colonne+largeur,ligne+hauteur-1);
     //rectangle(colonne+1,ligne,colonne+largeur-1,ligne+hauteur);
     rectangle(colonne+1,ligne,colonne+largeur-1,ligne+hauteur);

     //contour(colonne+1,ligne+1,largeur-2,hauteur-2,1,false);
     Contour(colonne+1,ligne+1,largeur-2,hauteur-2,1,FALSE);

     //size:=imagesize(colonne+5,ligne+3,colonne+largeur-3,ligne+hauteur-5);
     size=imagesize(colonne+5,ligne+3,colonne+largeur-3,ligne+hauteur-5);
     //getmem(img,size);
     img=malloc(size);
     //getimage(colonne+5,ligne+3,colonne+largeur-3,ligne+hauteur-5,img^);
     getimage(colonne+5,ligne+3,colonne+largeur-3,ligne+hauteur-5,img);
     //setfillstyle(1,7);
     setfillstyle(1,7);
     //bar(colonne+4,ligne+4,colonne+largeur-4,ligne+hauteur-4);
     bar(colonne+4,ligne+4,colonne+largeur-4,ligne+hauteur-4);
     //putimage(colonne+4,ligne+4,img^,copyput);
     putimage(colonne+4,ligne+4,img,COPY_PUT);
     //freemem(img,size);
     free(img);
     //affsouris;
     affsouris();
//end;
}	


//{===dessin du bouton appuie===}
//Procedure BoutonAppuie(codebouton:byte);
void BoutonAppuie(uint8_t codebouton)
//var x:byte;
    //ligne,colonne,largeur,hauteur:word;
    //size:word;
    //img:pointer;
//begin
{
     uint8_t x;
     uint16_t ligne,colonne,largeur,hauteur;
     uint16_t size;
     void *img;
     
     //effsouris;
     effsouris();
     //x:=1;
     x=1;
     //while (x<=99) and (caractbouton[x,5]<>codebouton) do inc(x);
     while ( (x<=99) && (caractbouton[x][5]!=codebouton) ) x++;
     //if x<=99 then
     if (x<=99)
     //begin
     {
          //ligne:=caractbouton[x,1];
	ligne=caractbouton[x][1];
          //colonne:=caractbouton[x,2];
	colonne=caractbouton[x][2];
          //largeur:=caractbouton[x,3];
	largeur=caractbouton[x][3];
          //hauteur:=caractbouton[x,4];
	hauteur=caractbouton[x][4];
     //end;
     }
     //contour(colonne+1,ligne+1,largeur-2,hauteur-2,0,true);
     Contour(colonne+1,ligne+1,largeur-2,hauteur-2,0,TRUE);
     //delay(50);
     delay(50);
     //size:=imagesize(colonne+4,ligne+4,colonne+largeur-4,ligne+hauteur-4);
     size=imagesize(colonne+4,ligne+4,colonne+largeur-4,ligne+hauteur-4);
     //getmem(img,size);
     img=malloc(size);
     //getimage(colonne+4,ligne+4,colonne+largeur-4,ligne+hauteur-4,img^);
     getimage(colonne+4,ligne+4,colonne+largeur-4,ligne+hauteur-4,img);
     //putimage(colonne+5,ligne+3,img^,copyput);
     putimage(colonne+5,ligne+3,img,COPY_PUT);
     //freemem(img,size);
     free(img);
     //affsouris;
     affsouris();
//end;
}


//{===dessin du bouton selectionne===}
//Procedure BoutonSelect(codebouton:byte);
void BoutonSelect(uint8_t codebouton)
//var x:byte;
    //ligne,colonne,largeur,hauteur:word;
    //size:word;
    //img:pointer;
//begin
{
     uint8_t x;
     uint16_t ligne,colonne,largeur,hauteur;
     uint16_t size;
     void *img;
     
     //effsouris;
     effsouris();
     //x:=1;
     x=1;
     //while (x<=99) and (caractbouton[x,5]<>codebouton) do inc(x);
     while ((x<=99) && (caractbouton[x][5]!=codebouton)) x++;
     //if x<=99 then
     if (x<=99)
     //begin
     {
          //ligne:=caractbouton[x,1];
	ligne=caractbouton[x][1];
          //colonne:=caractbouton[x,2];
	colonne=caractbouton[x][2];
          //largeur:=caractbouton[x,3];
	largeur=caractbouton[x][3];
          //hauteur:=caractbouton[x,4];
	hauteur=caractbouton[x][4];
     //end;
     }
	
     //{===sauvegarde du contenu du bouton===}
     //size:=imagesize(colonne+4,ligne+4,colonne+largeur-4,ligne+hauteur-4);
     size=imagesize(colonne+4,ligne+4,colonne+largeur-4,ligne+hauteur-4);
     //getmem(img,size);
     img=malloc(size);
     //getimage(colonne+4,ligne+4,colonne+largeur-4,ligne+hauteur-4,img^);
     getimage(colonne+4,ligne+4,colonne+largeur-4,ligne+hauteur-4,img);
     //setfillstyle(1,7);
     setfillstyle(1,7);
     //putimage(colonne+4,ligne+4,img^,notput);
     putimage(colonne+4,ligne+4,img,NOT_PUT);
     //freemem(img,size);
     free(img);
     //affsouris;
     affsouris();
//end;
}


//{===dessin du bouton deselectionne===}
//Procedure BoutonDeSelect(codebouton:byte);
void BoutonDeSelect(uint8_t codebouton)
//begin
{
     //boutonselect(codebouton);
     boutonselect(codebouton);
//end;
}


//{===dessin du bouton===}
//Procedure AffBouton(colonne,ligne,largeur,hauteur:word;textcontenu:string;codebouton:byte);
void AffBouton(uint16_t colonne, uint16_t ligne, uint16_t largeur, uint16_t hauteur,
	     char *textcontenu, uint8_t codebouton)
//var x:byte;
//begin
{
     uint8_t x;
     
     //x:=1;
     x=1;
     //while (x<=99) and (caractbouton[x,5]<>codebouton) do inc(x);
     while ((x<=99) && (caractbouton[x][5]!=codebouton)) x++;
     //if x>99 then
     if (x>99)
     //begin
     {
          //inc(i);
	i++;
          //caractbouton[i,1]:=ligne;
	caractbouton[i][1]=ligne;
          //caractbouton[i,2]:=colonne;
	caractbouton[i][2]=colonne;
          //caractbouton[i,3]:=largeur;
	caractbouton[i][3]=largeur;
          //caractbouton[i,4]:=hauteur;
	caractbouton[i][4]=hauteur;
          //caractbouton[i,5]:=codebouton;
	caractbouton[i][5]=codebouton;
     //end;
     }
     //{===trace du contour externe===}
     //{contour(colonne-1,ligne-1,largeur+2,hauteur+2,2,false);}
     //contour(colonne-1,ligne-1,largeur+2,hauteur+2,2,FALSE);

     //{===sommet du bouton===}
     //setfillstyle(1,7);
     setfillstyle(1,7);
     //bar(colonne+2,ligne+2,colonne+largeur-2,ligne+hauteur-2);
     bar(colonne+2,ligne+2,colonne+largeur-2,ligne+hauteur-2);

     //{===affichage du contenu===}
     //contenu(colonne,ligne,largeur,hauteur,textcontenu);
     contenu(colonne,ligne,largeur,hauteur,textcontenu);

     //{===trace de la ligne exterieure===}
     //setlinestyle(0,0,1);
     setlinestyle(0,0,1);
     //setcolor(0);
     setcolor(0);
     //rectangle(colonne,ligne+1,colonne+largeur,ligne+hauteur-1);
     rectangle(colonne,ligne+1,colonne+largeur,ligne+hauteur-1);
     //rectangle(colonne+1,ligne,colonne+largeur-1,ligne+hauteur);
     rectangle(colonne+1,ligne,colonne+largeur-1,ligne+hauteur);

     //contour(colonne+1,ligne+1,largeur-2,hauteur-2,1,false);
     Contour(colonne+1,ligne+1,largeur-2,hauteur-2,1,FALSE);
//end;
}


//procedure Aff2Bouton(colonne,ligne,largeur,hauteur:word;textcontenu:string;codebouton:byte);
void Aff2Bouton(uint16_t colonne, uint16_t ligne, uint16_t largeur, uint16_t hauteur,
	      char *textcontenu, uint8_t codebouton)
//begin
{
     //affbouton(colonne,ligne,largeur,hauteur,textcontenu,codebouton);
     AffBouton(colonne,ligne,largeur,hauteur,textcontenu,codebouton);
     //putpixel(colonne,ligne,0);
     putpixel(colonne,ligne,0);
     //putpixel(colonne+largeur,ligne,0);
     putpixel(colonne+largeur,ligne,0);
     //putpixel(colonne,ligne+hauteur,0);
     putpixel(colonne,ligne+hauteur,0);
     //putpixel(colonne+largeur,ligne+hauteur,0);
     putpixel(colonne+largeur,ligne+hauteur,0);
//end;
}
