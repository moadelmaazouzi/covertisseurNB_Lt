#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <malloc.h>

#include "module1.h"
int m,n;

void menu()
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

//fonction qui return une chaine de caractere de la partie decimale
char**menu1()
{
	
	unsigned int i=0, nbc, chiffre,len ;		
	//lecture de donnes de file
	//on latable 0_100
	char ** TC = CreerVecteurNombres("CL_FR0.txt" , &nbc) ;
	setlocale(LC_CTYPE,"") ;
	//declaration d une chaine
	char *ma_chaine;
	//lecture de la chaine
	ma_chaine=lecturechainetrue1();
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
	
	char **chaine1=NULL;
		chaine1=fctfin1(ch2,matab2,taille,TC,&j);
	m=j;
	return chaine1;
}
//fonction qui return une chaine de caractere de la partie decimale	
char **menu2(){

	unsigned int i=0, nbc, chiffre,len ;		
	//lecture de donnes de file
	//on latable 0_100
	char ** TC = CreerVecteurNombres("CL_FR0.txt" , &nbc) ;
	setlocale(LC_CTYPE,"") ;
	//declaration d une chaine
	char *ma_chaine;
	//lecture de la chaine
	ma_chaine=lecturechainetrue2();
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
	int *matab2=remplir1(matab,taille,3-met0);
	//depuis la on construire un tableau contient un nobre multiple de 3
	int j=0;
	//resultas final
	char **ch2=(char**)malloc((taille+(taille/3))*sizeof(char*));
	char **chaine2=NULL;
	chaine2=fctfin2(ch2,matab2,taille,TC,&j);
	n=j;
	return chaine2 ;
}
//la procedure qui donne le nombre real en lettres 
void menutotalreal()
{
	char **ch1=NULL,**ch2=NULL;
	ch1=menu1();
	ch2=menu2();
	int i=0;
	for(;i<m;i++)
		printf("%s ",ch1[i]);
	printf(",");
	for(i=0 ; i<=n ;i++)
		printf("%s ",ch2[i]);		
}
//procedure qui contient le programme
void fct2()
{short int i;
	printf("Pour la coversion des entiers entrer 1\n");	
	printf("Pour la coversion des reals entrer 0\n");	
	printf("Pour mets fin le programme entrer un nombre != de 1 et 0 \n");
	printf("veulliez saisir votre choix:");
	scanf("%d",&i);
	getchar();
	if((i==1) || (i==0))
	{
		do
		{
			switch (i)
			{
				case 1 :menu();
					break;
				case 0 :menutotalreal();
					break;
			}
			printf("\nveulliez saisir votre choix :");
			scanf("%d",&i);
			getchar();
		} while((i==1) || (i==0));
	}
}


int main()
{
fct2();




}
