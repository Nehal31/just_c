#include<stdio.h>
#include<stdlib.h>

char* fun(){
	char *test =(char*)malloc(10 * sizeof(char));
	test = "Nehal\n";
	free(test);
	return test;
}

int main(){
	printf("%p %s \n",fun(),fun());
	return 0;
}
