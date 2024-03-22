#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <malloc.h>
#include "module1.h"
void menu6()
{
unsigned int i=0, nbc, chiffre,len ;		
//lecture de donnes de file
//on latable 0_100
char ** TC = CreerVecteurNombres("CL_FR0.txt" , &nbc) ;
setlocale(LC_CTYPE,"") ;
//declaration d une chaine
char *ma_chaine;
//lecture de la chaine
ma_chaine=lecturechainetrue();
//declaration d'un tableau motab contient des valeurs que utilisateur saisir;
len=strlen(ma_chaine);
int *matab;
matab=conv_chaine_int(ma_chaine);

//tailletotal
int taille ;
taille=tailletotal(len);

//mette 0 au case ajoute
int met0=len % 3;
//craetion d' un autre table de taille <taille>
i=0;//remplir
int *matab2=remplir(matab,taille,3-met0);
//depuis la on construire un tableau contient un nobre multiple de 3
int j=0;
//resultas final
char **ch2=(char**)malloc((taille+(taille/3))*sizeof(char*));

	fctfin(ch2,matab2,taille,TC);	
}















