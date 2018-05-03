#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int a[10];
	int  n = 10, i, j, small, loc, temp;
	
	for (i = 0; i < n; i++){
		a[i] = rand() % 99;
	}
	
	printf("Unsorted List \n ");
	for (i = 0; i < n; i++){
		printf("%d ",a[i]);
	}
	
		
	printf("Sorted List  \n");
	for(i = 0 ; i < n-1 ; i++){
		small = a[i];
		loc = i;
		for(j = i+1; j < n; j++){
			if(a[j] < small){
				small = a[j];
				loc = j;
			}
		}
		if(i != loc){
			temp = a[loc];
			a[loc] = a[i];
			a[i] = temp;
		}
		
	}	

	for (i = 0; i < n; i++){
		printf("%d ",a[i]);
	}

	return 0;
}
