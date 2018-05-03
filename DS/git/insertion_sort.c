#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int a[10];
	int  n = 10, i, j, key;
	
	for (i = 0; i < n; i++){
		a[i] = rand() % 99;
	}
	
	printf("Unsorted List \n ");
	for (i = 0; i < n; i++){
		printf("%d ",a[i]);
	}
	
		
	printf("Sorted List  \n");
	for(i = 1 ; i < n ; i++){

		key = a[i];
		j = i-1;
		while(j >= 0 && a[j] > key ){
			a[j+1] = a[j];
			j = j - 1;	
		}
		a[j+1] = key;
		
	}	

	for (i = 0; i < n; i++){
		printf("%d ",a[i]);
	}

	return 0;
}
