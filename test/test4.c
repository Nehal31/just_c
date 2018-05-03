#include<stdio.h>

int main(){
	int i = -10;
	-i; // only +,- is allowed
	printf("%d %d %d \n",i,+i,-i);
	return 0;
}
