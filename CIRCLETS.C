//program montre;
//uses crt,graph,dos;
#include <graphics.h> // Graphics library declarations
#include <string.h>   // for string functions
#include <conio.h>    // for console I/O
#include <time.h>
#include <string.h>
//#include <ctypes.h>
#include <stdlib.h>

time_t rawtime;
struct tm * timeinfo;

//var angle,x,y,x1,y1,x2,y2,i,z,xcercle,ycercle,annee,mois,jour,joursem:word;
unsigned int angle,x,y,x1,y1,x2,y2,i,z,xcercle,ycercle,annee,mois,jour,joursem;
    //c:string[9];
char c[9];
    //gs,gm:integer;
int gs,gm;
    //arcinfo1,arcinfo2,arcinfo3:arccoordstype;
struct arccoordstype arcinfo1,arcinfo2,arcinfo3;
    //text:string[2];
char text[2];
    //numero:byte;
char numero;
    //size,taille:word;
unsigned int size,taille;
    //image1,image2,image3,image4:pointer;
void *image1, *image2, *image3, *image4;
    //tabnum,tabpt:array[1..12,1..2] of word;
unsigned int tabnum[12][2], tabpt[12][2];
    //tabsec,tabsec1,tabmin,tabmin1,tabmin2,tabhr,tabhr1,tabhr2:array[1..60,1..2] of word;
unsigned int tabsec[60][2];
unsigned int tabsec1[60][2];
unsigned int tabmin[60][2];
unsigned int tabmin1[60][2];
unsigned int tabmin2[60][2];
unsigned int tabhr[60][2];
unsigned int tabhr1[60][2];
unsigned int tabhr2[60][2];
    //hr,hr1,min,sec,ctsec:word;
unsigned int hr,hr1,min,sec,ctsec;

//BEGIN
main()      
{
	//clrscr;
	/*Je n'ai pas encore trouv‚ d'‚quivalent … clrscr en C*/
	//GS:=9;
	/*ces 2 affectations n'ont pas ‚t‚ traduites en C car j'ai utilis‚*/
	//GM:=2;
	/*la d‚tection automatique du driver et mode graphiques*/
	int graphdriver = DETECT, graphmode;
	//initgraph(GS,GM,'D:\tp\bgi');
	initgraph(&graphdriver, &graphmode, "..\\bgi");

	//{===affichage du message d'attente===}
	//settextstyle(triplexfont,0,5);
	settextstyle(TRIPLEX_FONT,0,5);
	//settextjustify(centertext,centertext);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	//for i:=1 to 10 do
	for(i=1;i<=10;i++)
	//begin
	{
		//setcolor(i);
		setcolor(i);
		//outtextXY(320+i,65+i,'Patientez un peu SVP...');
		outtextxy(320+i,65+i,"Patientez un peu SVP...");
	//end;
	}

	
	//{===memorisation des coordonnes des numeros et des points===}
	//numero:=1;
	numero=1;
	//angle:=0;
	angle=0;
	//while angle<360 do
	while (angle<360)
	//begin
	{
		//setcolor(0);
		setcolor(0);
		//arc(320,240,0,420-angle,135);
		arc(320,240,0,420-angle,135);
		//getarccoords(arcinfo1);
		getarccoords(&arcinfo1);
		//with arcinfo1 do
		//begin
			//tabnum[numero,1]:=xend;
		tabnum[numero-1][0]=arcinfo1.xend;
			//tabnum[numero,2]:=yend;
		tabnum[numero-1][1]=arcinfo1.yend;
		//end;
		//arc(320,240,0,420-angle,110);
		arc(320,240,0,420-angle,110);
		//getarccoords(arcinfo1);
		getarccoords(&arcinfo1);
		//with arcinfo1 do
		//begin
			//tabpt[numero,1]:=xend;
		tabpt[numero-1][0]=arcinfo1.xend;
			//tabpt[numero,2]:=yend;
		tabpt[numero-1][1]=arcinfo1.yend;
		//end;
		//angle:=angle+30;
		angle=angle+30;
		//inc(numero);
		numero++;
	//end;
	}
	   
	   
	//{===memorisation des coordonnes de deplacement sec,min,hr===}
	//x1:=0;
	x1=0;
	//x:=0;
	x=0;
	//while x<356 do
	while (x<356)
	//begin
	{
		//setcolor(0);
		setcolor(0);
		//arc(320,240,0,450-x,100);
		arc(320,240,0,450-x,100);
		//getarccoords(arcinfo1);
		getarccoords(&arcinfo1);
		//with arcinfo1 do
		//begin
			//tabsec[x1,1]:=xend;
		tabsec[x1-1][0]=arcinfo1.xend;
			//tabsec[x1,2]:=yend;
		tabsec[x1-1][1]=arcinfo1.yend;
		//end;
		//arc(320,240,0,630-x,20);
		arc(320,240,0,630-x,20);
		//getarccoords(arcinfo1);
		getarccoords(&arcinfo1);
		//with arcinfo1 do
		//begin
			//tabsec1[x1,1]:=xend;
		tabsec1[x1-1][0]=arcinfo1.xend;
			//tabsec1[x1,2]:=yend;
		tabsec1[x1-1][1]=arcinfo1.yend;
		//end;
		//arc(320,240,0,450-x,95);
		arc(320,240,0,450-x,95);
		//getarccoords(arcinfo1);
		getarccoords(&arcinfo1);
		//with arcinfo1 do
		//begin
			//tabmin[x1,1]:=xend;
		tabmin[x1-1][0]=arcinfo1.xend;
			//tabmin[x1,2]:=yend;
		tabmin[x1-1][1]=arcinfo1.yend;
		//end;
		//arc(320,240,0,450-x,80);
		arc(320,240,0,450-x,80);
		//getarccoords(arcinfo1);
		getarccoords(&arcinfo1);
		//with arcinfo1 do
		//begin
			//tabmin1[x1,1]:=xend;
		tabmin1[x1-1][0]=arcinfo1.xend;
			//tabmin1[x1,2]:=yend;
		tabmin1[x1-1][1]=arcinfo1.yend;
		//end;
		arc(320,240,0,450-x,25);
		getarccoords(&arcinfo1);
		//with arcinfo1 do
		//begin
			//tabmin2[x1,1]:=xend;
		tabmin2[x1-1][0]=arcinfo1.xend;
			//tabmin2[x1,2]:=yend;
		tabmin2[x1-1][1]=arcinfo1.yend;
		//end;
		arc(320,240,0,450-x,65);
		getarccoords(&arcinfo1);
		//with arcinfo1 do
		//begin
			//tabhr[x1,1]:=xend;
		tabhr[x1-1][0]=arcinfo1.xend;
			//tabhr[x1,2]:=yend;
		tabhr[x1-1][1]=arcinfo1.yend;
		//end;
		arc(320,240,0,450-x,50);
		getarccoords(&arcinfo1);
		//with arcinfo1 do
		//begin
			//tabhr1[x1,1]:=xend;
		tabhr1[x1-1][0]=arcinfo1.xend;
			//tabhr1[x1,2]:=yend;
		tabhr1[x1-1][1]=arcinfo1.yend;
		//end;
		//x:=x+6;
		x=x+6;
		//inc(x1);
		x1++;
	//end;
	}
     
	//cleardevice;
	cleardevice();

	//{===remplissage de la surface de la montre===}
	//setfillstyle(solidfill,6);
	setfillstyle(SOLID_FILL,6);
	//sector(320,240,130,150,179,179);
	sector(320,240,130,150,179,179);
	//setfillstyle(solidfill,0);
	setfillstyle(SOLID_FILL,0);
	//sector(320,240,130,150,163,163);
	sector(320,240,130,150,163,163);
	//setfillstyle(solidfill,6);
	setfillstyle(SOLID_FILL,6);
	//sector(320,240,10,30,179,179);
	sector(320,240,10,30,179,179);
	//setfillstyle(solidfill,0);
	setfillstyle(SOLID_FILL,0);
	//sector(320,240,10,30,163,163);
	sector(320,240,10,30,163,163);
	//setfillstyle(solidfill,6);
	setfillstyle(SOLID_FILL,6);
	//sector(320,240,199,220,179,179);
	sector(320,240,199,220,179,179);
	//setfillstyle(solidfill,0);
	setfillstyle(SOLID_FILL,0);
	//sector(320,240,199,220,163,163);
	sector(320,240,199,220,163,163);
	//setfillstyle(solidfill,6);
	setfillstyle(SOLID_FILL,6);
	//sector(320,240,300,330,179,179);
	sector(320,240,300,330,179,179);
	//setfillstyle(solidfill,0);
	setfillstyle(SOLID_FILL,0);
	//sector(320,240,300,330,163,163);
	sector(320,240,300,330,163,163);	
	//setfillstyle(linefill,9);
	setfillstyle(LINE_FILL,9);
	//bar(500,210,520,270);
	bar(500,210,520,270);
	//setfillstyle(hatchfill,9);
	setfillstyle(HATCH_FILL,9);
	//bar(520,215,525,265);
	bar(520,215,525,265);
	//bar(525,230,527,250);
	bar(525,230,527,250);
	//setlinestyle(solidln,0,3);
	setlinestyle(SOLID_LINE,0,3);
	//setcolor(8);
	setcolor(8);
	//circle(320,240,160);
	circle(320,240,160);
	//setlinestyle(solidln,0,1);
	setlinestyle(SOLID_LINE,0,1);
	//circle(320,240,165);
	circle(320,240,165);
	//circle(320,240,180);
	circle(320,240,180);
	//setfillstyle(widedotfill,1);
	setfillstyle(WIDE_DOT_FILL,1);
	//fillellipse(320,240,160,160);
	fillellipse(320,240,160,160);
	//setfillstyle(ltbkslashfill,8);
	setfillstyle(LTBKSLASH_FILL,8);
	//fillellipse(320,240,85,85);
	fillellipse(320,240,85,85);
	//line(175,130,190,30);
	line(175,130,190,30);
	//line(640-175,130,640-190,30);
	line(640-175,130,640-190,30);
	//line(175,480-130,190,480-30);
	line(175,480-130,190,480-30);
	//line(640-175,480-130,640-190,480-30);
	line(640-175,480-130,640-190,480-30);
	//line(200,105,200,30);
	line(200,105,200,30);
	//line(640-200,105,640-200,30);
	line(640-200,105,640-200,30);
	//line(200,480-105,200,480-30);
	line(200,480-105,200,480-30);
	//line(640-200,480-105,640-200,480-30);
	line(640-200,480-105,640-200,480-30);
	//line(190,30,200,30);
	line(190,30,200,30);
	//line(640-190,30,640-200,30);
	line(640-190,30,640-200,30);
	//line(190,480-30,200,480-30);
	line(190,480-30,200,480-30);
	//line(640-190,480-30,640-200,480-30);
	line(640-190,480-30,640-200,480-30);
	//setfillstyle(solidfill,3);
	setfillstyle(SOLID_FILL,3);
	//bar(201,35,204,50);
	bar(201,35,204,50);
	//bar(640-201,35,640-204,50);
	bar(640-201,35,640-204,50);
	//bar(201,480-35,204,480-50);
	bar(201,480-35,204,480-50);
	//bar(640-201,480-35,640-204,480-50);
	bar(640-201,480-35,640-204,480-50);
	//setfillstyle(xhatchfill,2);
	setfillstyle(XHATCH_FILL,2);
	//bar(205,2,640-205,57);
	bar(205,2,640-205,57);
	//bar(205,480-2,640-205,480-57);
	bar(205,480-2,640-205,480-57);
	//setcolor(0);
	setcolor(0);
	//setlinestyle(solidln,0,1);
	setlinestyle(SOLID_LINE,0,1);
	//line(205,30,640-205,30);
	line(205,30,640-205,30);
	//line(205,480-30,640-205,480-30);
	line(205,480-30,640-205,480-30);
     
     
	//{===ecriture du jour===}
	//setfillstyle(solidfill,0);
	setfillstyle(SOLID_FILL,0);
	//setcolor(0);
	setcolor(0);
	//bar(347,235,408,249);
	bar(347,235,408,249);
	//setlinestyle(solidln,0,1);
	setlinestyle(SOLID_LINE,0,1);
	//setcolor(3);
	setcolor(3);
	//rectangle(346,234,409,250);
	rectangle(346,234,409,250);
	//getdate(annee,mois,jour,joursem);
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	joursem = timeinfo->tm_wday;
	//case joursem of
		//0:c:='DIMANCHE';
		//1:c:='LUNDI';
		//2:c:='MARDI';
		//3:c:='MERCREDI';
		//4:c:='JEUDI';
		//5:c:='VENDREDI';
		//6:c:='SAMEDI';
		
	//end;
	switch (joursem)
	{
		case 0: strcpy(c,"DIMANCHE");
		        break;
		case 1: strcpy(c,"LUNDI");
		        break;
		case 2: strcpy(c,"MARDI");
		        break;
		case 3: strcpy(c,"MERCREDI");
		        break;
		case 4: strcpy(c,"JEUDI");
		        break;
		case 5: strcpy(c,"VENDREDI");
		        break;
		case 6: strcpy(c,"SAMEDI");
		        break;
	}
	//settextstyle(smallfont,0,5);
	settextstyle(SMALL_FONT ,0,5);
	//settextjustify(centertext,centertext);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	//outtextXY(378,240,c);
	outtextxy(378,240,c);
	
	
	//{====dessin des numeros====}
	//setcolor(7);
	setcolor(7);
	//circle(320,240,2);
	circle(320,240,2);
	//circle(320,240,3);
	circle(320,240,3);
	//settextstyle(sansseriffont,horizdir,4);
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
	//angle:=0;
	angle=0;
	//numero:=1;
	numero=1;
	//while numero<13 do
	while (numero<13)
	//begin
	{
		//x:=tabpt[numero,1];
		x=tabpt[numero-1][0];
		//y:=tabpt[numero][1];
		y=tabpt[numero-1][2];
		//setlinestyle(solidln,0,1);
		setlinestyle(SOLID_LINE,0,1);
		//if numero<>3 then
		if (numero!=3)
		//begin
		{
			//setcolor(15);
			setcolor(15);
			//circle(x,y,1);
			circle(x,y,1);
			//circle(x,y,2);
			circle(x,y,2);
			//circle(x,y,3);
			circle(x,y,3);
		//end
		}
		//else
		else
		//begin
		{
			//setfillstyle(emptyfill,0);
			setfillstyle(EMPTY_FILL,0);
			//fillellipse(x-3,y+2,13,13);
			fillellipse(x-3,y+2,13,13);
			//setlinestyle(solidln,0,3);
			setlinestyle(SOLID_LINE,0,3);
			//setcolor(10);
			setcolor(10);
			//circle(x-3,y+2,16);
			circle(x-3,y+2,16);
			//xcercle:=x-3;
			xcercle=x-3;
			//ycercle:=y+2;
			ycercle=y+2;
			//setcolor(8);
			setcolor(8);
			//setlinestyle(solidln,0,1);
			setlinestyle(SOLID_LINE,0,1);
			//circle(x-3,y+2,13);
			circle(x-3,y+2,13);
			//setcolor(7);
			setcolor(7);
			//settextstyle(triplexfont,horizdir,1);
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
			//settextjustify(centertext,centertext);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			//getdate(annee,mois,jour,joursem);
			time(&rawtime);
			timeinfo = localtime(&rawtime);
			joursem = timeinfo->tm_mday;
	
			//str(jour,text);
			sprintf(text, "%d", joursem);
			//outtextXY(x-2,y-1,text);
			outtextxy(x-2,y-1,text);
			//settextstyle(sansseriffont,horizdir,4);
			settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
		//end;
		}
		//x:=tabnum[numero,1];
		x=tabnum[numero-1][0];
		//y:=tabnum[numero,2];
		y=tabnum[numero-1][1];
		//setcolor(7);
		setcolor(7);
		//settextjustify(centertext,centertext);
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		//str(numero,text);
		sprintf(text, "%d", numero);
		//outtextXY(x,y,text);
		outtextxy(x,y,text);
		//inc(numero);
		numero++;
		//angle:=angle+30;
		angle=angle+30;
	//end;
	}
     
     
	//{===signature===}
	//setcolor(7);
	setcolor(7);
	//settextstyle(smallfont,horizdir,4);
	settextstyle(SMALL_FONT,HORIZ_DIR,4);
	//settextjustify(centertext,centertext);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	//outtextXY(320,280,'Made in Morocco by');
	outtextxy(320,280,"Made in Morocco by");
	//settextstyle(gothicfont,horizdir,2);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,2);
	//outtextXY(320,293,'Abderrahim');
	outtextxy(320,293,"Abderrahim");
	//outtextXY(320,310,'Sahli');
	outtextxy(320,310,"Sahli");

	//size:=imagesize(220,140,420,340);
	size=imagesize(220,140,420,340);
	//getmem(image1,size);
	image1=malloc(size);
	//getimage(220,140,420,340,image1^);
	getimage(220,140,420,340,image1);
	
	//taille:=imagesize(347,235,420,249);
	taille=imagesize(347,235,420,249);
	//getmem(image4,taille);
	image4=malloc(taille);
	//getimage(347,235,420,249,image4^);
	getimage(347,235,420,249,image4);
	     
	//gettime(hr,min,sec,ctsec);
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	hr = timeinfo->tm_hour;
	min = timeinfo->tm_min;
	sec = timeinfo->tm_sec;
	
	//{=====heures====}
	//i:=min;
	i=min;
	//if hr>12 then hr1:=hr-12 else hr1:=hr;
	if (hr>12) hr1=hr-12; else hr1=hr;
	
	sprintf(text, "%d", hr);
	outtextxy(50,380,text);
	
	sprintf(text, "%d", min);
	outtextxy(50,400,text);
	
	sprintf(text, "%d", sec);
	outtextxy(50,420,text);
	
	//z:=(hr1*5)+(min div 12);
	z=(hr1*5)+(min/12);
	//while not keypressed do
	while (!getch())
	//begin
	{
		//if (hr=0) and (min=0) and (sec=0) then
		if ((hr==0) && (min==0) && (sec==0))
		//begin
		{
			//freemem(image4,taille);
			free(image4);
			//z:=0;
			z=0;
			//setfillstyle(emptyfill,0);
			setfillstyle(EMPTY_FILL,0);
			//fillellipse(xcercle,ycercle,12,12);
			fillellipse(xcercle,ycercle,12,12);
			//setcolor(7);
			setcolor(7);
			//settextstyle(triplexfont,horizdir,1);
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
			//settextjustify(centertext,centertext);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			//getdate(annee,mois,jour,joursem);
			time(&rawtime);
			timeinfo = localtime(&rawtime);
			jour = timeinfo->tm_mday;
			joursem = timeinfo->tm_wday;
			//str(jour,text);
			sprintf(text, "%d", jour);
			//outtextXY(xcercle+1,ycercle-3,text);
			outtextxy(xcercle+1,ycercle-3,text);
			//setfillstyle(solidfill,0);
			setfillstyle(SOLID_FILL,0);
			//setcolor(0);
			setcolor(0);
			//bar(347,235,408,249);
			bar(347,235,408,249);
			//setcolor(3);
			setcolor(3);
			//case joursem of
				//0:c:='DIMANCHE';
				//1:c:='LUNDI';
				//2:c:='MARDI';
				//3:c:='MERCREDI';
				//4:c:='JEUDI';
				//5:c:='VENDREDI';
				//6:c:='SAMEDI';
			//end;
			switch (joursem)
			{
				case 0: strcpy(c,"DIMANCHE");
				        break;
				case 1: strcpy(c,"LUNDI");
				        break;
				case 2: strcpy(c,"MARDI");
				        break;
				case 3: strcpy(c,"MERCREDI");
				        break;
				case 4: strcpy(c,"JEUDI");
				        break;
				case 5: strcpy(c,"VENDREDI");
				        break;
				case 6: strcpy(c,"SAMEDI");
				        break;
			}
			//settextstyle(smallfont,0,5);
			settextstyle(SMALL_FONT,0,5);
			//settextjustify(centertext,centertext);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			//outtextXY(378,240,c);
			outtextxy(378,240,c);

			//taille:=imagesize(347,235,420,249);
			taille=imagesize(347,235,420,249);
			//getmem(image4,taille);
			image4=malloc(taille);
			//getimage(347,235,420,249,image4^);
			getimage(347,235,420,249,image4);			
		//end;
		}
		//setcolor(15);
		setcolor(15);
		//setlinestyle(solidln,0,3);
		setlinestyle(SOLID_LINE,0,3);
		//x:=tabhr[z,1];
		x=tabhr[z-1][0];
		//y:=tabhr[z,2];
		y=tabhr[z-1][1];
		//x1:=tabhr1[z,1];
		x1=tabhr1[z-1][0];
		//y1:=tabhr1[z,2];
		y1=tabhr1[z-1][1];
		//putimage(220,140,image1^,copyput);
		putimage(220,140,image1,COPY_PUT);
		
		//line(320,240,x,y);
		line(320,240,x,y);
		//setcolor(0);
		setcolor(0);
		//setlinestyle(solidln,0,2);
		setlinestyle(SOLID_LINE,0,2);
		//line(320,240,x1,y1);
		line(320,240,x1,y1);

		//getmem(image2,size);
		image2=malloc(size);
		//getimage(220,140,420,340,image2^);
		getimage(220,140,420,340,image2);
		
		
		//{====minutes=====}
		//if i>59 then i:=0;
		if (i>59) i=0;
		//while ((i mod 12)<>0) and (not keypressed) do
		while (((i % 12)!=0) && (!getch()))
		//begin
		{
			//gettime(hr,min,sec,ctsec);
			time(&rawtime);
			timeinfo = localtime(&rawtime);
			hr = timeinfo->tm_hour;
			min = timeinfo->tm_min;
			sec = timeinfo->tm_sec;
			//setcolor(15);
			setcolor(15);
			//setlinestyle(solidln,0,3);
			setlinestyle(SOLID_LINE,0,3);
			//x:=tabmin[min,1];
			x=tabmin[min-1][0];
			//y:=tabmin[min,2];
			y=tabmin[min-1][1];
			//x1:=tabmin1[min,1];
			x1=tabmin1[min-1][0];
			//y1:=tabmin1[min,2];
			y1=tabmin1[min-1][1];
			//x2:=tabmin2[min,1];
			x2=tabmin2[min-1][0];
			//y2:=tabmin2[min,2];
			y2=tabmin2[min-1][1];
			//putimage(220,140,image2^,copyput);
			putimage(220,140,image2,COPY_PUT);
		
			//line(320,240,x,y);
			line(320,240,x,y);
			//setcolor(0);
			setcolor(0);
			//setlinestyle(solidln,0,2);
			setlinestyle(SOLID_LINE,0,2);
			//line(x2,y2,x1,y1);
			line(x2,y2,x1,y1);
			
			//getmem(image3,size);
			image3=malloc(size);
			//getimage(220,140,420,340,image3^);
			getimage(220,140,420,340,image3);
		
		
			//{====secondes===}
			//setlinestyle(solidln,0,1);
			setlinestyle(SOLID_LINE,0,1);
			//repeat
			do
			{
						//sound(490);
				//sound(490);
				//delay(4);
				//delay(4);
				//nosound;
				//nosound;
				//x:=tabsec[sec,1];
				x=tabsec[sec-1][0];
				//y:=tabsec[sec,2];
				y=tabsec[sec-1][1];
				//x1:=tabsec1[sec,1];
				x1=tabsec1[sec-1][0];
				//y1:=tabsec1[sec,2];
				y1=tabsec1[sec-1][1];
				//setcolor(10);
				setcolor(10);
				//putimage(220,140,image3^,copyput);
				putimage(220,140,image3,COPY_PUT);
		
				//circle(320,240,2);
				circle(320,240,2);
				//line(320,240,x,y);
				line(320,240,x,y);
				//line(320,240,x1,y1);
				line(320,240,x1,y1);
				//setcolor(0);
				setcolor(0);
				//circle(320,240,1);
				circle(320,240,1);
				//sound(340);
				//sound(340);
				//delay(4);
				//delay(4);
				//nosound;
				//nosound;
				//x1:=sec;
				x1=sec;
				//repeat
				do
				{
					//gettime(hr,min,sec,ctsec);
					time(&rawtime);
					timeinfo = localtime(&rawtime);
					hr = timeinfo->tm_hour;
					min = timeinfo->tm_min;
					sec = timeinfo->tm_sec;			
				//until sec<>x1;
				}
				while(sec==x1);
			//until (sec=0) or (keypressed);
			}
			while((sec!=0) && (!getch()));
			//inc(i);
			i++;
			//freemem(image3,size);
			free(image3);
		//end;
		}
		//inc(z);
		z++;
		//inc(i);
		i++;
		//freemem(image2,size);
		free(image2);
	//end;
	}
	//freemem(image1,size);
	free(image1);    

	//closegraph;
	closegraph();
	return 0;
//END.
}

//--------------------------------Pascal-----------------------------------
/*
*/