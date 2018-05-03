#include<stdio.h>
#include<stdlib.h>

void merge_sort(int a[], int low, int high){
	while(low < high){
		mid = (low + high)/2;
		merge_sort(a, low, mid);
		merge_sort(a, mid+1,high);
		merge(a, low, mid, high);
	}
}

void merge(int a[], int low, int mid, int high){
	int i = low;
	int j = mid;
	int k = mid+1;
	int m = low;

	while(low < high){
		while()

	}

}
int main(){
	int i;
	
	return 0;
}
