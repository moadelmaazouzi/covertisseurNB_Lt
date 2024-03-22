char * SaisirChaineClavier();
char * SaisirLigneFichier(FILE * pf);
char ** CreerVecteurNombres(char *nf , unsigned int * taille);
//lecture d une chaine saisis par utilisateur
char *lecturechainetrue();
//pour la partie real
char *lecturechainetrue1();
char *lecturechainetrue2();
//on test si la chaine ne contient que des nombre
int test_nb(char *t);
//convertion d une chaine de caractere d'entier en un tableau d'entier
int * conv_chaine_int(char *ch); 
//int taille total
int tailletotal(int );
//remlisage du table
int *remplir(int *t,int taille,int met0);
int *remplir1(int *t,int taille,int met0);
//void fonction finale
void fctfin(char **ch2,int *matab2,int taille,char **TC);
//voi
char **fctfin1(char **ch2,int *matab2,int taille,char **TC,int *m);
//
char **fctfin2(char **ch2,int *matab2,int taille,char **TC,int *m);
