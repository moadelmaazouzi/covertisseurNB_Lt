#include<stdio.h>
#include<stdlib.h>
//fonction:
/*
int fonction_max(int a,int b){
	return (a>=b)?a:b;}
	
int fonction_max1(){
	int a,b;
	printf("entrer deux nombres entiers:\n");
	scanf("%d%d",&a,&b);
	getchar();
	return (a>=b)?a:b;}
	
	
int fonction_max3var(int a,int b,int c){int max;
//	if(a>=b && a>=c)max=a;
//	if(b>=a && b>=c)max=b;
//	if(c>=b && c>=a)max=c;
	max=(a>=b)?a:b;
	max=(max>=c)?max:c;
	return 	max;}
	*/
/*
int fonction_max3var(int a,int b,int c)
{
	return 	((a>=b)?a:b>=c)?((a>=b)?a:b):c;
}	
*/	
	
	
	
//procedure:		
/*void procedure_max(int a,int b){
	int max;
	if(a>=b)max=a;
	else max=b;
	printf("le max entre %d et %d est :%d\n",a,b,max)	;}
	
void procedure_max1(){int a,b,max;
	printf("entrer deux nombres entiers:\n");
	scanf("%d%d",&a,&b);
	getchar();
	max=(a>=b)?a:b;
	printf("le maximum entre %d et %d est :%d\n",a,b,max);};
	
	
//boucle
void procedure_fact(){  int f, i,p=1;
	
	printf("entrer un nombre positive :");
	scanf("%d",&f);
	getchar();
	for(i = 1 ; i <= f ; i++)
	{
		p=p*i;
	}

	
	printf("\nle factoriel du nombre %u est :%d\n",f,p);}	
	
int fn_fact(int f)
{
	int i,p=1;
	if(f==0)
		return p;
		
	else
	{
		for(i=1;i<=f;i++)
			p=p*i;
		return p;
	}
}




	/*recursivite
	int fn_rec_fact(int f)
	{
		if (f==0)
			 return 1;
		else 
			return f*fn_rec_fact(f-1);	
	}
*/

