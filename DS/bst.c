#include<stdio.h>
#include<stdlib.h>

/*	
* Node structure of binary search tree
*/

typedef struct node{
    struct node *parent;
    int data;
    struct node *left;
    struct node *right;
}node;

/*	
* function declaration of binary search tree
*/

node* create(int);
void insert(node**, int );
void preorder(node*);
void postorder(node*);
void inorder(node*);
int delete(node**,int);
int maximum(node*);
int minimum(node*);
node* search(node*,int);
node* min_in_right(node*);
node* max_in_left(node*);


/*	
* begining of the main method
*/

int main(){
	int temp,option;
    node *root = NULL;

	
	insert(&root, 40);
	insert(&root, 50);
	insert(&root, 60);
	insert(&root, 35);
	insert(&root, 25);
	insert(&root, 30);
	printf("%d \n ",root->data);
	printf("%d \n ",root->right->data);
	printf("%d \n ",root->right->right->data);
	//printf("%d \n ",root->right->right->right->data);
	printf("%d \n ",root->data);
	printf("%d \n ",root->left->data);
	printf("%d \n ",root->left->left->data);
	printf("%d \n ",root->left->left->right->data);

	

	while(1){
		printf("\n------------This is BST menu ------------------- \n");
		printf("------------Press 1 for INSERT A NODE ---------- \n");
		printf("------------Press 2 for INORDER TRAVERSAL ------ \n");
		printf("------------Press 3 for PREORDER TRAVERSAL ----- \n");
		printf("------------Press 4 for POSTORDER TRAVERSAL ---- \n");
		printf("------------Press 5 for DELETE a Node ---------- \n");
		printf("------------Press 6 for SEARCH a Node ---------- \n");		
		printf("------------Press 7 for find a MIN Node -------- \n");
		printf("------------Press 8 for find a MAX Node -------- \n");
		printf("------------Press 0 QUIT ----------------------- \n");
		printf("------------select your option ----------------- \n");
		printf("===========>");
	
		scanf("%d",&option);
		switch(option){
			case 0:
				exit(0);

			case 1: 
				do{
					printf("\n------------");
					printf("Enter Node data \n");	
					printf("===========>");
					scanf("%d",&temp);
					insert(&root,temp);
					printf("\n------------");
					printf("Do You want to Insert more Nodes ??\n");
					printf("\n------------");
					printf("Yes/No - press 1/0\n");
					printf("===========>");
					scanf("%d",&temp);
										
				}while(temp);
				break;

			case 2:
				inorder(root);
				break;

			case 3:
				preorder(root);
				break;

			case 4:
				postorder(root);
				break;

			case 5:
				do{
					printf("\n------------");
					printf("Enter Node data to be deleted \n");	
					printf("===========>");
					scanf("%d",&temp);
					delete(&root,temp);
					printf("\n------------");
					printf("Do You want to Delete more Nodes ??\n");
					printf("\n------------");
					printf("Yes/No - press 1/0\n");
					printf("===========>");
					scanf("%d",&temp);
										
				}while(temp);
				break;
				
			case 6:
				do{
					printf("\n------------");
					printf("Enter Node data to be searched \n");	
					printf("===========>");
					scanf("%d",&temp);
					if(search(root,temp)){
						printf("\n------------");
						printf("Search Found Successfuly \n");
						printf("\n------------");	
					}
					else{
						printf("\n------------");
						printf("Search Not Found  \n");
						printf("\n------------");
					}
					printf("\n------------");
					printf("Do You want to search another Nodes ??\n");
					printf("\n------------");
					printf("Yes/No - press 1/0\n");
					printf("===========>");
					scanf("%d",&temp);
										
				}while(temp);
				break;
				
			case 7:
				if(root != NULL){
					printf("\n------------");
					printf("Minimum value Node is : %d \n", minimum(root));
					printf("\n------------");			
				}
				else{
					printf("\n------------");
					printf("Tree is Empty   \n");
					printf("\n------------");
				}
				break;

			case 8:
				if( root != NULL){
					printf("\n------------");
					printf("Maximum value Node is : %d \n", maximum(root));
					printf("\n------------");			
				}
				else{
					printf("\n------------");
					printf("Tree is Empty   \n");
					printf("\n------------");
				}
				break;

			default:
				printf("correct your option \n");
				printf("===========>");

		}
	}	
    
    return 0;
}

/*	
* function defination of binary search tree
* insert() function having two parameters 
* 1. root address of bst
* 2. value to be inserted 
*/

void insert(node **root, int value){
    
    node *temp = *root;
    node *prnt = NULL;
        
    if(*root == NULL){
        *root =  create(value);
    }
    else{
        while( temp!= NULL){
	    	prnt = temp;
            if(temp->data < value ){
                temp = temp->right;
            }
            else{
                temp = temp->left;
            }
        }

		if(prnt->data < value ){
          	prnt->right = create(value);
			prnt->right->parent = prnt;
       	}
		else{
			prnt->left = create(value);	
			prnt->left->parent = prnt;	
		}
    }
    
}


node* create(int value){
    node *temp_node = (node *) malloc(sizeof(node));
	temp_node->data = value;
    temp_node->left = NULL;
    temp_node->right= NULL;
    temp_node->parent = NULL;
    
    return temp_node;
}

void preorder(node* root){
	if(root != NULL){
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node* root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

void inorder(node* root){
	if(root != NULL){
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);	
	}

}

int delete(node** root,int value){
	node *parent, *left, *right;	
	int is_left_child,is_right_child;

	node *searched = search(*root, value);
	
	if(!searched){
		return -1;
	}
	else{
		parent = searched->parent;
		left = searched->left;
		right = searched->right;
		
		if(parent->data > value){
			is_left_child = 1;
			is_right_child = 0;
		}
		else{
			is_left_child = 0;
			is_right_child = 1;
		}		
		
		if(left == NULL && right == NULL){
			free(searched);
			if(is_left_child){
				parent->left = NULL;
			}
			else{
				parent->right = NULL;
			}		
		}	
		
		else if( left != NULL && right != NULL){
		////////////////
	
		
	

		////////////////
		}

		else if(left == NULL){
			free(searched);
			if(is_left_child){
				parent->left = left;				
			}
			else{
				parent->right = left;
			}
		}
		else{
			free(searched);
			if(is_left_child){
				parent->left = right;				
			}
			else{
				parent->right = right;
			}			
		}
		
	}
}

node* search(node* root,int value){

	while(root != NULL){
		if(root->data == value){
			return root;
		}
		else if(root->data < value){
			root = root->right;
		}
		else{
			root = root->left;
		}
	}
	return NULL;
}

node* max_in_right(node *root){
	node *max_node = NULL;
	while(root != NULL){
		max_node = root;
		root = root->right;	
	}
	return max_node ;		
}

node* min_in_left(node *root){
	node *min_node = NULL;
	while(root != NULL){
		min_node = root;
		root = root->left;	
	}
	return min_node ;	
}

int maximum(node *root){
	node *max_node = NULL;
	while(root != NULL){
		max_node = root;
		root = root->right;	
	}
	return max_node->data ;	
}

int minimum(node *root){
	node *min_node = NULL;
	while(root != NULL){
		min_node = root;
		root = root->left;	
	}
	return min_node->data ;	
}

















