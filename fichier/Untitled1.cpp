#include<stdio.h>
#include<stdlib.h>
int main()
{
FILE *fi;
char c[30];
fi=fopen("EL_file.txt","r");
while(!feof(fi))
{
c=fgets(c,fi);
printf("%s\n",c);}

return 1;}










