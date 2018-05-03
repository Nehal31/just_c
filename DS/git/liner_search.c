/*
Linear Search 28/04/2018 
rand() function is used to gererate n random number


*/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int a[10], n = 10, key, i;
	for (i = 0; i < n; i++){
		a[i] = rand() % 99;
	}
	for (i = 0; i < n; i++){
		printf("%d ",a[i]);
	}
		
	printf("Enter the key \n");
	scanf("%d", &key);

	for(i = 0; i < n; i++){
		if( a[i]==key ){
			printf("search found at location %d \n ", i);
		}
	}	


	return 0;
}	
