#include<stdio.h>
#include<stdlib.h>

typedef struct stack_block{
	int data;
	struct stack_block *prev;
	
}stack;

void push(stack **t, int item){
	stack *temp = (stack*)malloc(sizeof(stack));
	temp->data = item;
		
	if(*t == NULL){
		temp->prev = NULL;
		*t = temp;
	}
	else{
		temp->prev = *t;
		*t = temp; 
	}
}

void pop(stack **t){

	if(*t == NULL){
		printf("stack is empty \n");
	}
	else{
		printf("Item %d is going to delete \n",(*t)->data);
		*t = (*t)->prev;
	}
	
}

void disp(stack *t){
	printf("\n");
	printf("\t==========\n");
	if(t == NULL){
		printf("\tstack is empty \n");
	}
	else{
		while(t!=NULL){
			printf("\t----------\n\t--%6d--\n\t----------\n",t->data);
			t = t->prev;
		}
	}
	printf("\t==========\n");	
}

int main(){
	stack *top=NULL;
	int option,temp; 
	while(1){
		printf("------------This is stack menu------------ \n");
		printf("------------Press 1 for push operation --- \n");
		printf("------------Press 2 for pop operation ---- \n");
		printf("------------Press 3 for list all items --- \n");
		printf("------------Press 0 quit ----------------- \n");
		printf("------------select your option ----------- \n");
		printf("===========>");
	
		scanf("%d",&option);
		switch(option){
			case 0:
				exit(0);

			case 1: 
				do{
					printf("\n------------");
					printf("Enter number for push in stack \n");	
					printf("===========>");
					scanf("%d",&temp);
					push(&top,temp);
					printf("\n------------");
					printf("Do You want to continue ??\n");
					printf("\n------------");
					printf("Yes/No - press 1/0\n");
					printf("===========>");
					scanf("%d",&temp);
										
				}while(temp);
				break;
			case 2:
				pop(&top);
				break;

			case 3:
				disp(top);
				break;

			default:
				printf("correct your option \n");
				printf("===========>");

		}
	}	
	

	return 0;
}
