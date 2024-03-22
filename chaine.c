#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <malloc.h>
#include "chaine.h"


char * SaisirChaineClavier()
{
     unsigned int c, nbc = 0 ;
     char * ch = NULL ;

     while((c = getchar()) != '\n')
     {
        ch = realloc(ch, (nbc+1)*sizeof(char));
        ch[nbc++] = c ;
     }
     ch = realloc(ch, (nbc+1)*sizeof(char));
     ch[nbc] = '\0' ;

     return ch ;
}

// Fonction à adapter
char * SaisirLigneFichier(FILE * pf)
{
    unsigned int c, nbc = 0 ;
    char * ch = NULL ;

    while(((c = fgetc(pf)) != '\n') && (c != EOF))
    {
        ch = realloc(ch, (nbc+1)*sizeof(char));
        ch[nbc++] = c ;
    }
    if((nbc > 0) || (c == '\n'))
    {
        ch = realloc(ch, (nbc+1)*sizeof(char));
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
        VN = realloc(VN, (i+1)*sizeof(char*)) ;
        VN[i++] = str ;
    }

    fclose(pf) ;
    *taille = i ;
    return VN ;
}

int main()
{
    unsigned int i, nbc, chiffre ;
    char ** TC = CreerVecteurNombres("CL_FR0.txt" , &nbc) ;
    setlocale(LC_CTYPE,"") ;
    /*
    for(i = 0  ; i < nbc ; i++)
    {
        printf("\n\t %u\t%s", i, TC[i]) ;
    }
    */
    printf("\n Saisir un chiffre entre 0 et 99 : ") ;
    scanf("%u", &chiffre) ;
    getchar() ;
    printf("\n\t %u\t%s", chiffre, TC[chiffre]) ;

    getchar() ;
}

