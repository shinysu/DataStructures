#include<stdio.h>
#include<conio.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(value){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
  
  
struct node* insert(struct node* root, int data)
{
    if (root == NULL) 
		return createNode(data);

    if (data < root->data)
        root->left  = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);   
 
    return root;
}

void inorder(struct node* root)
{
	printf("inorder traversal");
    if(root!= NULL) 
	{
    	inorder(root->left);
    	printf("%d ->", root->data);
    	inorder(root->right);
	}
}

void preorder(struct node* root)
{
	printf("preorder traversal");
    if(root!= NULL) 
	{
    	printf("%d ->", root->data);
    	preorder(root->left);
    	preorder(root->right);
	}
}
void postorder(struct node* root)
{
	printf("postorder traversal");
    if(root!= NULL) 
	{
    	postorder(root->left);
    	postorder(root->right);
    	printf("%d ->", root->data);
    	
	}
}

int main(){
    struct node *root = NULL;
    int i,n;
    printf(" \n1. Insert");
    printf(" \n2. Inorder traversal");
    printf(" \n3. preorder traversal");
    printf(" \n4. postorder traversal");
    printf(" \n5. Exit");
    while(1)
    {
	  	printf(" \nChoose Option: ");
	  	scanf("%d",&i);
	  	switch(i)
	  	{
	       	case 1:
	       		printf("\nEnter the node: ");
	       		scanf("%d",&n);
	 			if(root==NULL)
	 				root=insert(root,n);
	 			else
	 				insert(root,n);
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
    		default:
    			exit(0);
    			break;
    	}
    }
}

/*int main(){
    struct node *root = NULL;
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 1);
    insert(root, 6);
    insert(root, 7);
    insert(root, 10);
    insert(root, 14);
    insert(root, 4);

    inorder(root);
    preorder(root);
    postorder(root);
}*/
