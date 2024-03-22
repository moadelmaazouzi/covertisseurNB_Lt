#include<stdio.h>
#include<stdlib.h>
#include"ex1.h"
void menu(){
	//programation modulaires
//	int a=6,b=6,f=5,maxi;
 //	puts("entrer 3 nombres entiers:\n");	
//	scanf("%d%d%d",&a,&b,&f);

//	max=fonction_max(a,b);
//	printf("le max entre %d et %d est :%d\n",a,b,maf);
//	procedure_max(a,b);
//	procedure_max1();
//	maxi=fonction_max1();
//	printf("le max est:%d\n",maxi);
//	int f,maxi1;
//	printf("entrer un nombre \n");
//	scanf("%d",&f);
//	maxi=fonction_max3var(a,b,f);
//	printf("le max entre %d et %d et %d  est :%d\n",a,b,f,maxi);
	
}
void menu1(){

//printf("%d",fact_f(120));
//	int fact,f ;
//	printf("entrer un nombre \n");
//	scanf("%d",&f);
//	fact=fn_fact(f);
//	printf("le factoriel de %d est :%d\n",f,fact);
//	int z;
//	z=fn_rec_fact(f);
//	printf("le factoriel de %d est :%d\n",f,z);
		
}
int fct_f(int n){
if(n<0)return fct_f(-n);
else if(n>0) n*fct_f(n);
else return 1;
	
	
	
	
}

int main(){
int m;
//m= fct_f(720);
//printf("%d",m);
//menu1();
m=fact_f(-4);
printf("%d",m)	;
return 0 ;	
}
