#include<stdio.h>
#include<stdlib.h>

int main(){
	int *i = (int*)malloc(10 * sizeof(int));
	i[0] = 10;
	i[1] = 20;
	i[2] = 30;
	i[3] = 40;
	
	int *j = i;
	//int *j = (int*)malloc(sizeof(int));
	j[9] = 20;
		
	printf("%d %d \n", i[0],j[1]);

	free(i);


	printf("%d %d \n", i[0],j[1]);

	return 0;
}
