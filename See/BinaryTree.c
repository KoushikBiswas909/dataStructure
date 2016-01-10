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
void inOrderPrintTree(struct Node * root){
	if(root == NULL) return;
	inOrderPrintTree(root->left);
	printf("%d\t",root->data);
	inOrderPrintTree(root->right);
}
//BFS - Level Order Traversal

int main(){
	printf("How many numbers :");
	int n;
	scanf ("%d",&n);
	int count=0;
	while(count<n){
		printf("Enter number :");
		int x=0;
		scanf ("%d",&x);
		rootNode = insertNode(rootNode,x);
		count++;
	}
	printf("In :\n");
	inOrderPrintTree(rootNode);
	printf("\nPost :\n");
	postOrderPrintTree(rootNode);
	printf("\nPre :\n");
	preOrderPrintTree(rootNode);
	return 0;
}
