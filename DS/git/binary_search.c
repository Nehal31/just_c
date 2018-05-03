#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int a[10] = {1,2,4,5,8,10,15,20,50,100};
	int  n = 10, low, key, high, mid;
	
	/*for (i = 0; i < n; i++){
		a[i] = rand() % 99;
	}
	*/
	for (int i = 0; i < n; i++){
		printf("%d ",a[i]);
	}
	
		
	printf("Enter the key \n");
	scanf("%d", &key);

	low = 0;
	high = n-1;

	while(low < high){
		mid = ( low + high )/ 2 ;
		if( a[mid] ==  key ){
			printf("search found at location %d \n ", mid + 1);
			break;
		}
		else if(a[mid] < key ){
			low = mid + 1;
		}
		else{
			high = mid - 1 ;
		}
	}	


	return 0;
}
