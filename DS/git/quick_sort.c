#include<stdio.h>
#include<stdlib.h>

int partition(int a[], int low, int high){
	int i, j, pivot, temp;
	i = low-1;
	j = low;
	pivot = a[high];
	printf("%d ", pivot);
	while(j < high){
		if(a[j] <= pivot){
			i++;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;	
		}
		j++;
	}
	a[high] = a[i+1];
	a[i+1] = pivot;

//	printf("%d ", i+1);
	return i+1;
}


void quick_sort(int a[], int low, int high){	
	int pivot;
	while(low < high){
		pivot =  partition(a,low,high);
		quick_sort(a, low, pivot-1);
		quick_sort(a, pivot+1, high);
	}
}

int main(){
	
	int a[10]= {1,2,4,6,7,12,8,3,5,9};
	int  n = 10, i, j, temp, test;
	
	for (i = 0; i < n; i++){
		//a[i] = rand() % 99;
	}
	
	printf("Unsorted List \n ");
	for (i = 0; i < n; i++){
		printf("%d ",a[i]);
	}
	
	quick_sort(a,0,n-1);	
	
	printf("Sorted List  \n");
	for (i = 0; i < n; i++){
		printf("%d ",a[i]);
	}

	return 0;
}
