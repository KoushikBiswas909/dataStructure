#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
    struct Node* left ;
    struct Node* right;
};
struct Node* rootNode = NULL;

struct Node * getNewNode(int data){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}
struct Node* insertNode(struct Node * root, int data)
{
	if (root == NULL){
		root = getNewNode(data);
		return root;
	}
	else if(data<=root->data){
		 root->left = insertNode(root->left,data);
	}
	else{
		root->right = insertNode(root->right,data);
	}
	return root;
}
// DFS
void preOrderPrintTree(struct Node * root){
	if(root == NULL) return;
	printf("%d\t",root->data);
	preOrderPrintTree(root->left);
	preOrderPrintTree(root->right);
}
void postOrderPrintTree(struct Node * root){
	if(root == NULL) return;
	postOrderPrintTree(root->left);
	postOrderPrintTree(root->right);
	printf("%d\t",root->data);
}
void inOrderPrintTree(struct Node ** root){
	struct Node* current = *root;
	if(current == NULL) return;
	inOrderPrintTree(&(current->left));
	printf("%d\t",current->data);
	inOrderPrintTree(&(current->right));
}
//BFS - Level Order Traversal

int findMinimum(struct Node * root){
	if(root->left == NULL)
		return root->data;
	else return findMinimum(root->left);
}	
int findMaximum(struct Node * root){
	if(root->right == NULL)
		return root->data;
	else return findMaximum(root->right);
}
struct Node* FindMin(struct Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}
struct Node* deleteANode(struct Node* root, int data){
	if(root==NULL)
		return root;
	else if(root->data < data)// right subtree
	{
		root->right = deleteANode(root->right, data);
	}
	else if (root->data > data){
		rootNode->left= deleteANode(root->left, data);
	}
	else{
		// if its a leaf node simply delete it
		if(root->right == NULL && root->left == NULL){
			printf("\nhere right/left is null and root data is %d",root->data);
			free(root);
			root = NULL;
		}
		else if	(root->right == NULL)
		{
			struct Node* temp = root;
			root = root->left;
			free(temp);
		}
		else if(root->left == NULL){
			struct Node * temp = root;
			root = root->right;
			free(temp);
		}
		else{
			struct Node * temp = FindMin(root->right);
			root->data = temp ->data;
			printf("\n root data is equal to data to be deleted %d, %d", root->data, temp->data);
			root->right = deleteANode(root->right, temp->data);
		}
	}
	printf("\n here returning root %p",root);
			return root;
			 
			
}


struct Node* Delete(struct Node *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			free(root);
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			struct Node *temp = root;
			root = root->right;
			free(temp);
		}
		else if(root->right == NULL) {
			struct Node *temp = root;
			root = root->left;
			free(temp);
		}
		// case 3: 2 children
		else { 
			struct Node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
int size(struct Node * head)
{
	if (head == NULL) return 0;
	int c = 1;
	c += size(head->left);
	c += size(head->right);
	return c;
}

int sameTree(struct Node*a, struct Node*b)
{
	if(a == NULL && b == NULL) return 1;
	if(a->data != b->data) return 0;
	else return(sameTree(a->left, b->left) && sameTree(a->right, b->right));
	return 1;
}

int isBST(struct Node* node) {
	if (node==NULL) return(1);
	if (node->left!=NULL && findMaximum(node->left) > node->data)
		return(0);
	if (node->right!=NULL && findMinimum(node->right) <= node->data)
		return(0);
	if (!isBST(node->left) || !isBST(node->right))
		return(0);
	return(1);
}

struct Node *a = NULL;
struct Node *b = NULL;
int main(){
	//~ printf("How many numbers :");
	//~ int n;
	//~ 
	//~ scanf ("%d",&n);
	//~ int count=0;
	//~ while(count<n){
		//~ printf("Enter number :");
		//~ int x=0;
		//~ scanf ("%d",&x);
		//~ a = insertNode(rootNode,x);
		//~ count++;
	//~ }
	//~ printf("In :\n");
	//~ inOrderPrintTree(&a);
	//~ 
	//~ printf("How many numbers :");
	//~ n=0;
	//~ scanf ("%d",&n);
	//~ count=0;
	//~ 
	//~ while(count<n){
		//~ printf("Enter number :");
		//~ int x=0;
		//~ scanf ("%d",&x);
		//~ b = insertNode(rootNode,x);
		//~ count++;
	//~ }
	//~ printf("In :\n");
	//~ inOrderPrintTree(&b);
	//print("\n");
	//printf("\nPost :\n");
	//postOrderPrintTree(rootNode);
	////printf("\nPre :\n");
	//preOrderPrintTree(rootNode);
	//struct Node *  min = findMinimum(rootNode);
	//printf("\nMinimum is %d",min->data);
	//printf("\nMaximum is %d",findMaximum(rootNode));
	//printf("Enter number to delete :");
	//int y=0;
	//scanf ("%d",&y);
	//rootNode = deleteANode(rootNode,y);
		printf("\nIn :\n");
	//inOrderPrintTree(rootNode);
	struct Node *isB = getNewNode(5);
	isB->left = getNewNode(3);
	isB->right = getNewNode(7);
	isB->left->left = getNewNode(1);
	isB->left->right = getNewNode(4);
	isB->right->left = getNewNode(6);
	isB->right->right = getNewNode(2);
	//printf("\n same tree is %d",sameTree(a,b));
	printf("\n Is BST %d",isBST(isB));

	return 0;
}


	
