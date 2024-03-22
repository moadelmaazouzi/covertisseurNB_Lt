#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <malloc.h>



char * SaisirChaineClavier()
{
     unsigned int c, nbc = 0 ;
     char * ch = NULL ;

     while((c = getchar()) != '\n')
     {
        ch = (char*)realloc(ch, (nbc+1)*sizeof(char));
        ch[nbc++] = c ;
     }
     ch = (char*)realloc(ch, (nbc+1)*sizeof(char));
     ch[nbc] = '\0' ;

     return ch ;
}

// Fonction Ã  adapter
char * SaisirLigneFichier(FILE * pf)
{
    unsigned int c, nbc = 0 ;
    char * ch = NULL ;

    while(((c = fgetc(pf)) != '\n') && (c != EOF))
    {
        ch = (char*)realloc(ch, (nbc+1)*sizeof(char));
        ch[nbc++] = c ;
    }
    if((nbc > 0) || (c == '\n'))
    {
        ch =(char*)realloc(ch, (nbc+1)*sizeof(char));
        ch[nbc] = '\0' ;
        return ch ;
    }

    return NULL ;
}


char ** CreerVecteurNombres(char *nf , unsigned int * taille)
{
    FILE * pf = fopen(nf, "r") ;
    char * str = NULL ;
    unsigned int i = 0 ;
    char ** VN = NULL ;

    if(pf == NULL)
    {
        printf("\n probleme lors de l ouverture du fichier %s\n", nf) ;
        fclose(pf) ;
        *taille = 0 ;
        return NULL ;
    }

    while((str = SaisirLigneFichier(pf)) != NULL)
    {
        VN =(char**)realloc(VN, (i+1)*sizeof(char*)) ;
        VN[i++] = str ;
    }

    fclose(pf) ;
    *taille = i ;
    return VN ;
}

//
//on test si la chaine ne contient que des nombre
int test_nb(char *t,int taille)
{
	int i=0,k=1;
	for(i = 0 ; i < taille ; i++)
	{
		if( (t[i]<48)  ||  (t[i]>57)  )
			return 0;	
	}

	return k;		
}



//lecture d une chaine saisis par utilisateur
char *lecturechainetrue()
{char *ch;int len;

do
{
	printf("Saisir votre nombre Entier :");
	ch=SaisirChaineClavier();
	len=strlen(ch);
	if(test_nb(ch,len)==0)
	{printf("\nVous avez entrer un nombre non valide\n");	
	}
}while(test_nb(ch,len)==0);
return ch;
}
//saisir chaine pour la partie real
char *lecturechainetrue1()
{char *ch;int len;
do
{
	printf("saisir la partie entier:");
	ch=SaisirChaineClavier();
	len=strlen(ch);
	if(test_nb(ch,len)==0)
	{printf("\nVous avez entrer un nombre non valide\n");	
	}
}while(test_nb(ch,len)==0);
return ch;
}

char *lecturechainetrue2()
{char *ch;int len;
do
{
	printf("Saisir la partie decimale:");
	ch=SaisirChaineClavier();
	len=strlen(ch);
	if(test_nb(ch,len)==0)
	{printf("\nVous avez entrer un nombre non valide\n");	
	}
}while(test_nb(ch,len)==0);
return ch;
}

//convertion d une chaine de caractere d'entier en un tableau d'entier
int * conv_chaine_int(char *ch)
	{int i,taille;
	taille=strlen(ch);
	int *t=(int*)malloc(taille*sizeof(int));
		for(i = 0 ; i < taille ; i++)
			t[i]=ch[i] - 48;
	return t;	
	}

//taille totale
int tailletotal(int t){
	
if((t%3)==0 )
	return t;
else 
	return t + (3 - (t % 3));
}

//remlisage du table
int *remplir(int *t,int taille,int met0)
{
	int i=0;
	int *l=(int*)malloc(taille*sizeof(int));	
	for(i = 0 ; i < taille; i++)
	if(met0!=3)
		{
			if(i<met0)
				l[i]=0;
			else
				l[i]=t[i-met0];
		}
	else{
		l[i]=t[i];
	}
	
	return l;
}
//remplissage pour la partie real
int *remplir1(int *t,int taille,int met0)
{
	int i=0;
	int *l=(int*)malloc(taille*sizeof(int));
	for(i = 0 ; i < taille; i++)
		if(met0!=3)
		{
			if(i<taille-met0)
				l[i]=t[i];
			else
				l[i]=0;		
		}
		else 
			l[i]=t[i];
	
	return l;
	
}
//void fonction finale

void fctfin(char **ch2,int *matab2,int taille,char **TC)
{int i=0,j=0;



	for(i=0 ; j<taille ;j=j+3,i=i+4)
	{
		ch2[i]=TC[matab2[j]];
		ch2[i+1]="cent";
		
		ch2[i+2]=TC[matab2[j+1] * 10 +matab2[j+2]];
		{
		
		if(taille-j==27) 
			ch2[i+3]="quatrillion";
		if(taille-j==24) 
			ch2[i+3]="Trilliards";
		if(taille-j==21) 
			ch2[i+3]="trilions";
		if(taille-j==18) 
			ch2[i+3]="billiards";
		if(taille-j==15) 
			ch2[i+3]="billions";
		if(taille-j==12) 
			ch2[i+3]="milliards";
		if(taille-j==9) 
			ch2[i+3]="millions";
		if(taille-j==6) 
			ch2[i+3]="mille";
		if(taille-j==3) 
			ch2[i+3]="";}
		//filtre0
	if(matab2[j]==0)
	{
		ch2[i]="";
		ch2[i+1]="";
	}
	
	if(matab2[j+1] * 10 +matab2[j+2]==0)
	{
		ch2[i+2]="";
		ch2[i+3]="";
	}
	//filtre1	
	if(matab2[j]==1) 
		ch2[i]="";
		
		
			
		//printf(" %s %s %s %s ",ch2[i],ch2[i+1],ch2[i+2],ch2[i+3]);

	}
char **k=(char**)malloc(1*sizeof(char*));
k[0]="";j=0;
char **ch_final=NULL;

	for(i=0 ; i<(taille+(taille/3));i++)
	{
		if(ch2[i]==k[0])
			continue;
		else 
		{
			ch_final=(char**)realloc(ch_final,(j+1)*sizeof(char*));
			ch_final[j++]=ch2[i];	
		}
	}
	if(j==0)
	{
		printf("zéro");
	}
	else
	{
		for(i=0 ; i<j ;i++)
	{
		printf("%s ",ch_final[i]);
	}
	}

}
/*partie2_decimal*ppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp*/

char **fctfin1(char **ch2,int *matab2,int taille,char **TC,int *m)
{int i=0,j=0;



	for(i=0 ; j<taille ;j=j+3,i=i+4)
	{
		ch2[i]=TC[matab2[j]];
		ch2[i+1]="cent";
		
		ch2[i+2]=TC[matab2[j+1] * 10 +matab2[j+2]];
		{
		
		if(taille-j==27) 
			ch2[i+3]="quatrillion";
		if(taille-j==24) 
			ch2[i+3]="Trilliards";
		if(taille-j==21) 
			ch2[i+3]="trilions";
		if(taille-j==18) 
			ch2[i+3]="billiards";
		if(taille-j==15) 
			ch2[i+3]="billions";
		if(taille-j==12) 
			ch2[i+3]="milliards";
		if(taille-j==9) 
			ch2[i+3]="millions";
		if(taille-j==6) 
			ch2[i+3]="mille";
		if(taille-j==3) 
			ch2[i+3]="";}
		//filtre0
	if(matab2[j]==0)
	{
		ch2[i]="";
		ch2[i+1]="";
	}
	
	if(matab2[j+1] * 10 +matab2[j+2]==0)
	{
		ch2[i+2]="";
		ch2[i+3]="";
	}
	//filtre1	
	if(matab2[j]==1) 
		ch2[i]="";
		
		
			
		//printf(" %s %s %s %s ",ch2[i],ch2[i+1],ch2[i+2],ch2[i+3]);

	}
char **k=(char**)malloc(1*sizeof(char*));
k[0]="";j=0;
char **ch_final=NULL;

	for(i=0 ; i<(taille+(taille/3));i++)
	{
		if(ch2[i]==k[0])
			continue;
		else 
		{
			ch_final=(char**)realloc(ch_final,(j+1)*sizeof(char*));
			ch_final[j++]=ch2[i];	
		}
	}
	if(j==0)
	{
		ch_final=(char**)realloc(ch_final,(j+1)*sizeof(char*));
			ch_final[j++]="zero";	
	}

*m=j;
return ch_final;
}
//llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll
char **fctfin2(char **ch2,int *matab2,int taille,char **TC,int *m)
{int i=0,j=0;



	for(i=0 ; j<taille ;j=j+3,i=i+4)
	{
		ch2[i]=TC[matab2[j]];
		ch2[i+1]="cent";
		
		ch2[i+2]=TC[matab2[j+1] * 10 +matab2[j+2]];
		{
		
		if(taille-j==27) 
			ch2[i+3]="quatrillion";
		if(taille-j==24) 
			ch2[i+3]="Trilliards";
		if(taille-j==21) 
			ch2[i+3]="trilions";
		if(taille-j==18) 
			ch2[i+3]="billiards";
		if(taille-j==15) 
			ch2[i+3]="billions";
		if(taille-j==12) 
			ch2[i+3]="milliards";
		if(taille-j==9) 
			ch2[i+3]="millions";
		if(taille-j==6) 
			ch2[i+3]="mille";
		if(taille-j==3) 
			ch2[i+3]="";}
		//filtre0

	//filtre1	
	if(matab2[j]==1) 
		ch2[i]="";
		
		
			
		//printf(" %s %s %s %s ",ch2[i],ch2[i+1],ch2[i+2],ch2[i+3]);

	}
	*m=j;
return ch2;
}


















