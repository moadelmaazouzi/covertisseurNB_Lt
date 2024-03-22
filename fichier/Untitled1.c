#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{int i=0,j=0,k;
	char *cb[5],b[50],c;
		FILE *p=NULL;
		p=fopen("EL_file.txt","r");
		if(p==NULL)
		printf("le fichier n exist pas \n");
	else
		while(((c=fgetc(p))!=EOF )){
			
			b[i]=c;
			
			
			i++;
			if(c=='\n')
				{b[i-1]='\0';
					cb[j]=b;
					i=0;
					printf("\n%s\n",cb[j]);
					j++;
				}
			
				
		}
		//for(k=0 ; k<j ; k++)
		//	printf("%s",cb[k]);
		
		
		return 0;
}
