#if !defined(__BOUTON_H)
#define __BOUTON_H
#endif

#if !defined(__GRAPHICS_H)
#define __GRAPHICS_H
#endif

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

//unit boutunit;

//interface

//uses crt,graph,sourunit;
#include <graphics.h> // Graphics library declarations
#include <string.h>   // for string functions
//#include <conio.h>    // for console I/O
#include <time.h>
#include <stdlib.h>

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

//caractbouton:array[1..99,1..5] of word;
extern int16_t caractbouton[99][5];

//procedure Contenu(colonne,ligne,largeur,hauteur:word;texte:string);
extern void Contenu(uint16_t colonne, uint16_t ligne, uint16_t largeur, uint16_t hauteur, 
		char *texte);

//procedure Contour(colonne,ligne,largeur,hauteur:word;epaisseur:byte;videoinv:boolean);
extern void Contour(uint16_t colonne, uint16_t ligne, uint16_t largeur, uint16_t hauteur, 
		uint8_t epaisseur, uint8_t videoinv);

//procedure BoutonRepos(codebouton:byte);
extern void BoutonRepos(uint8_t codebouton);

//Procedure BoutonAppuie(codebouton:byte);
extern void BoutonAppuie(uint8_t codebouton);

//Procedure BoutonSelect(codebouton:byte);
extern void BoutonSelect(uint8_t codebouton);

//Procedure BoutonDeSelect(codebouton:byte);
extern void BoutonDeSelect(uint8_t codebouton);

//Procedure AffBouton(colonne,ligne,largeur,hauteur:word;textcontenu:string;codebouton:byte);
extern void AffBouton(uint16_t colonne, uint16_t ligne, uint16_t largeur, uint16_t hauteur, 
		char *textcontenu, uint8_t codebouton);

//procedure Aff2Bouton(colonne,ligne,largeur,hauteur:word;textcontenu:string;codebouton:byte);
extern void Aff2Bouton(uint16_t colonne, uint16_t ligne, uint16_t largeur, uint16_t hauteur, 
		char *textcontenu, uint8_t codebouton);

//END.