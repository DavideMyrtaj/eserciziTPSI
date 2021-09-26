#include <stdio.h>

int main(){
int x1,x2;
do{
	printf("\ninserisci il primo numero maggiore di 0\n");
	scanf("%d",&x1);
	if(x1<=0)
		printf("\nnumero non valido, reinseriscilo\n");
	else
		break;

}while(1);

do{
	printf("\ninserisci il secondo numero maggiore di 0\n");
	scanf("%d",&x2);
	if(x2<=0)
		printf("\nnumero non valido, reinseriscilo\n");
	else
		break;

}while(1);
int somma=x1+x2;
	printf("\nsomma:\t%d+%d=%d\n",x1,x2,somma);
return 0;
}
