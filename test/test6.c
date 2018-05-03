#include<stdio.h>
#include<stdlib.h>

int main(){
	int *p = (int*) malloc(sizeof(int));
	*p=10;
	printf("%d %p \n",*p,p);

//	free(p);

	int *j =  (int*) malloc(sizeof(int));
	*j=20;
	printf("%d %p \n",*j,j);
	printf("%d %p %d %p \n",*p,p,*j,j);

	return 0;
	

}
