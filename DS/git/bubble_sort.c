#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int a[10];
	int  n = 10, i, j, temp, test;
	
	for (i = 0; i < n; i++){
		a[i] = rand() % 99;
	}
	
	printf("Unsorted List \n ");
	for (i = 0; i < n; i++){
		printf("%d ",a[i]);
	}
	
		
	printf("Sorted List  \n");
	for(i = 0 ; i < n-1 ; i++){
		test = 0;
		for(j = 0 ; j < n-(i+1); j++){
			if(a[j] > a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				test =1;
			}	
		}
		if(test == 0){
			break;
		}
	}	

	for (i = 0; i < n; i++){
		printf("%d ",a[i]);
	}

	return 0;
}
