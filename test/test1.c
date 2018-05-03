#include<stdio.h>

void main(){
int a = 5, *j;
void  *k;
printf("\n %p %p ",&a,j);
printf("\n %p %p ",j++,k++);

j=k=&a;
printf("\n %p %p ",j++,k++);

}
