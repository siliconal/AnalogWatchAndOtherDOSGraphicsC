UNIT SOURUNIT;

INTERFACE

uses dos;

var regs:registers;
    mx,my:word;
    c:string[30];
    intver,decver,typ,numirq:byte;
    gs,gm:integer;

function xclickgauche:WORD;

function Yclickgauche:word;

function xclickdroit:word;

function yclickdroit:word;

function initsouris:boolean;

procedure affsouris;

procedure effsouris;

function mouseX:word;

function mouseY:word;

function boutondroit:boolean;

function boutongauche:boolean;

procedure textsouris(typ,et,xou:word);

Procedure Place_Souris(colonne,ligne:word);

Procedure Fenetre_Souris(chi,lhi,clo,llo:word);

Procedure Combien_De_Fois_Actionne(var gauche,droit,centre:boolean;var nombre:byte;var ligne,colonne:word);

Procedure Combien_De_Fois_Relache(var gauche,droit,centre:boolean;var nombre:byte;var ligne,colonne:word);

Procedure Determine_Distance(var mickhor,mickvert:integer);

Procedure Active_Emul_Crayon;

Procedure Desactive_Emul_Crayon;

Procedure Definit_Rapport_Mick_Points(mick_horiz,mick_vert:integer);

Procedure Exclusion(xsupgauche,ysupgauche,xinfdroit,yinfdroit:word);

Procedure Fixe_Seuil_Vitesse(nombre:integer);

Procedure Determiner_Sensibilite(var mick_horiz,mick_vert,seuil:integer);

Procedure Fixe_Page(numero:byte);

Function RAZ_Souris(var nombre:byte):boolean;

Procedure Info_Souris(var ent_ver,dec_ver,type_souris,numero_irq:byte);

{==================================================}

IMPLEMENTATION

function xclickgauche:word;
begin
     regs.ax:=5;
     regs.bx:=0;
     intr($33,regs);
     xclickgauche:=regs.cx;
end;

function yclickgauche:word;
begin
     regs.ax:=5;
     regs.bx:=0;
     intr($33,regs);
     yclickgauche:=regs.dx;
end;

function xclickdroit:word;
begin
     regs.ax:=5;
     regs.bx:=1;
     intr($33,regs);
     xclickdroit:=regs.cx;
end;

function yclickdroit:word;
begin
     regs.ax:=5;
     regs.bx:=1;
     intr($33,regs);
     yclickdroit:=regs.dx;
end;

function initsouris:boolean;
begin
     regs.ax:=0;
     intr($33,regs);
     initsouris:=(regs.ax<>0);
end;

{===================================================}
procedure affsouris;
begin
     regs.ax:=1;
     intr($33,regs);
end;

{===================================================}
procedure effsouris;
begin
     regs.ax:=2;
     intr($33,regs);
end;

{===================================================}
function mouseX:word;
begin
     regs.ax:=3;
     intr($33,regs);
     mouseX:=regs.cx
end;

{===================================================}
function mouseY:word;
begin
     regs.ax:=3;
     intr($33,regs);
     mouseY:=regs.dx
end;

{====================================================}
function boutondroit:boolean;
begin
     regs.ax:=3;
     intr($33,regs);
     boutondroit:=((regs.bx and 2)=2);
end;

{====================================================}
function boutongauche:boolean;
begin
     regs.ax:=3;
     intr($33,regs);
     boutongauche:=((regs.bx and 1)=1);
end;

{=====================================================}
procedure textsouris(typ,et,xou:word);
begin
     regs.ax:=10;regs.bx:=typ;
     regs.cx:=et;regs.dx:=xou;
     intr($33,regs);
end;

{Cette proc‚dure permet de fixer arbitrairement la position de la souris
                 en Colonne et Ligne
========================================================}
Procedure Place_Souris(colonne,ligne:word);
Begin
  regs.ax := $04;
  regs.cx := colonne;
  regs.dx := ligne;
  intr($33 , regs);
End;

{limite le deplacement de la souris
================================================}
Procedure Fenetre_Souris(chi,lhi,clo,llo:word);
Begin
  regs.ax := $07;
  regs.cx := clo;
  regs.dx := chi;
  intr($33 , regs);
  regs.ax := $08;
  regs.cx := llo;
  regs.dx := lhi;
  intr($33 , regs);
End;

{-[P]------------------------ combien_de_fois_actionne -----------------------
D‚termine combien de fois un bouton (le bool‚en mis … vrai en entr‚e) a ‚t‚
actionn‚ depuis le dernier appel … cette proc‚dure. Elle fournit en outre
la position de la souris … ce moment.

NB : Il sera utile de v‚rifier qu'UN ET UN SEUL bool‚en est positionn‚ … vrai,
faute de quoi on sort de la proc‚dure imm‚diatement.
-------------------------------------------------------------------------}
Procedure Combien_De_Fois_Actionne(var gauche,droit,centre:boolean;var nombre:byte;var ligne,colonne:word);
Begin
  if not(gauche or droit or centre) then exit;
  if not(gauche xor droit xor centre) then exit;
  if gauche then regs.bx := 1;
  if droit then regs.bx := 2;
  if centre then regs.bx := 4;
  regs.ax := $0005;
  intr($33 , regs);
  gauche := ((regs.ax and 1) = 1);
  droit  := ((regs.ax and 2) = 2);
  centre := ((regs.ax and 4) = 4);
  nombre := regs.bx;
  ligne := regs.dx;
  colonne := regs.cx;
End;

{-[P]------------------------ combien_de_fois_relache -----------------------
D‚termine combien de fois un bouton (le bool‚en mis … vrai en entree) a ‚t‚
relach‚ depuis le dernier appel … cette proc‚dure. Elle fournit en outre
la position de la souris … ce moment.

NB : Il sera utile de v‚rifier qu'UN ET UN SEUL bool‚en est positionn‚ … vrai,
faute de quoi on sort de la proc‚dure imm‚diatement.
-------------------------------------------------------------------------}
Procedure Combien_De_Fois_Relache(var gauche,droit,centre:boolean;var nombre:byte;var ligne,colonne:word);
Begin
  if not(gauche or droit or centre) then exit;
  if not(gauche xor droit xor centre) then exit;
  if gauche then regs.bx := 1;
  if droit then regs.bx := 2;
  if centre then regs.bx := 4;
  regs.ax := $0006;
  intr($33 , regs);
  gauche := ((regs.ax and 1) = 1);
  droit  := ((regs.ax and 2) = 2);
  centre := ((regs.ax and 4) = 4);
  nombre := regs.bx;
  ligne := regs.dx;
  colonne := regs.cx;
End;

{ -[P]------------------------- determine_distance --------------------------
D‚termine la distance entre la position actuelle de la souris et la position
qu'elle occupait lors du dernier appel de cette proc‚dure.

ATTENTION : les resultats sont renvoy‚s en MICKEYS, et non en points ou en
lignes. (Voir le chapitre consacr‚ … la souris dans ce manuel).
--------------------------------------------------------------------------}
Procedure Determine_Distance(var mickhor,mickvert:integer);
Begin
  regs.ax := $000b;
  intr($33 , regs);
  mickvert := regs.dx;
  mickhor := regs.cx;
End;

{ -[P]---------------------------- active_emul_crayon ---------------------
Active l'‚mulation du crayon optique.
-------------------------------------------------------------------------}
Procedure Active_Emul_Crayon;
Begin
  regs.ax := $000d;
  intr($33 , regs);
End;

{ -[P]------------------------- desactive_emul_crayon ---------------------
D‚sactive l'‚mulation du crayon optique.
-------------------------------------------------------------------------}
Procedure Desactive_Emul_Crayon;
Begin
  regs.ax := $000e;
  intr($33 , regs);
End;

{ --[P]------------------------- definit_rapport_mick_points ----------------
D‚finit le rapport entre les Mickeys et les points. Permet de d‚finir la
rapidit‚ de la souris … l'‚cran.
--------------------------------------------------------------------------}
Procedure Definit_Rapport_Mick_Points(mick_horiz,mick_vert:integer);
Begin
  regs.ax := $000f;
  regs.cx := mick_horiz;
  regs.dx := mick_vert;
  intr($33 , regs);
End;

{ --[P]---------------------------- exclusion -----------------------------
D‚finit une zone dans laquelle le curseur sera cach‚, tout en continuant …
pouvoir g‚rer ses mouvements.
Cette fonction s'annule en affichant la souris, ou en la r‚initialisant.
------------------------------------------------------------------------}
Procedure Exclusion(xsupgauche,ysupgauche,xinfdroit,yinfdroit:word);
Begin
  regs.ax := $0010;
  regs.cx := xsupgauche;
  regs.dx := ysupgauche;
  regs.si := xinfdroit;
  regs.di := yinfdroit;
  intr($33 , regs);
End;

{ -[P]-------------------------- fixe_seuil_vitesse -----------------------
Fixe le seuil en Mickeys par seconde au del… duquel le d‚placement … l'‚cran
sera doubl‚.
----------------------------------------------------------------------}
Procedure Fixe_Seuil_Vitesse(nombre:integer);
Begin
  regs.ax := $0013;
  regs.dx := nombre;
  intr($33 , regs);
End;

{ -[P]-------------------------- determiner_sensibilit‚ -----------------------
Renvoie la sensibilit‚ de la souris, qu'on peut ensuite modifier par les
fonctions
   Definit_rapport_mick_points et
   fixe_seuil_vitesse.
-------------------------------------------------------------------------}
Procedure Determiner_Sensibilite(var mick_horiz,mick_vert,seuil:integer);
Begin
  regs.ax := $001b;
  intr($33 , regs);
  mick_horiz := regs.bx;
  mick_vert := regs.cx;
  seuil := regs.dx;
End;

{ -[P]------------------------------ fixe_page -------------------------------
Fixe la page sur laquelle le curseur sera affich‚.
----------------------------------------------------------------------------}
Procedure Fixe_Page(numero:byte);
Begin
  regs.ax := $001d;
  regs.bx := numero;
  intr($33 , regs);
End;

{ -[F]------------------------------ determine_page -------------------------------
Fixe la page sur laquelle le curseur sera affich‚.
----------------------------------------------------------------------------}
Function Determine_Page:byte;
Begin
  regs.ax := $001d;
  intr($33 , regs);
  determine_page := regs.bx;
End;

{ --[F]------------------------ RAZ_souris ---------------------------
Remet … z‚ro le driver souris : cache le curseur et d‚sactive tous les
gestionnaire pr‚sents.
--------------------------------------------------------------------}
Function RAZ_Souris(var nombre:byte):boolean;
Begin
  regs.ax := $0021;
  intr($33 , regs);
  if regs.ax  = $021 then
    begin
      raz_souris := true;
      nombre := regs.bx;
    end else raz_souris  := false;
End;

{ -[P]---------------------------- Info_Souris -----------------------------
Fournit les informations sur la souris dans les paramŠtres pass‚s par
variable.
-------------------------------------------------------------------------}
Procedure Info_Souris(var ent_ver,dec_ver,type_souris,numero_irq:byte);
Begin
  regs.ax := $0024;
  intr($33 , regs);
  ent_ver := regs.bh;
  dec_ver := regs.bl;
  type_souris := regs.ch;
  numero_irq := regs.cl;
end;

END.



