#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
struct Node* head = NULL;

struct Node* createNode(int data){
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
struct Node * insertNodeAtPosition(int data,int pos){
	if(head == NULL)
		head = createNode(data);
	else{
		struct Node *current, *nextNode, *newNode=NULL;
		current = head;
		newNode = createNode(data);
		if(pos == 1){// there is only one node in the linked list
			head = newNode;
			newNode->next = current;
		}
		else{ // otherwise insert at pos
			int counter = 0;
				while(counter<pos-2){
				current = current->next;
				counter++;
				}
			nextNode = current->next;
			current->next = newNode;
			newNode->next = nextNode;
		}	
	}
	return head;
}
// delete a node at a position
struct Node * deleteNodeAtPosition(int pos){
	if(head == NULL) return NULL;
	if(pos == 1){
		struct Node *next, *current = NULL;
		current = head;
		next = current->next;
		free(current);
		head = next;
	}
	else{
		struct Node *current = head;
		struct Node *prev = NULL;
		int count = 0;
		while(count < pos -1){
			prev = current;
			current = current->next;
			count ++;
		}
		prev->next = current->next;
		free(current);
	}
	return head;
		
}
// print the elements of the linkedList

void printLinkedList(struct Node* headNode){
	if(headNode == NULL) return;
	 struct Node * current = headNode;
	 printf("%d\t", current->data);
	 printLinkedList(current->next);
}	
void printReversedLinkedList(struct Node* headNode){
	if(headNode == NULL) return;
	 struct Node * current = headNode;
	 printReversedLinkedList(current->next);
 	 printf("%d\t", current->data);
}
int main()
{
	head = insertNodeAtPosition(6,1);
	head = insertNodeAtPosition(5,2);
	head = insertNodeAtPosition(4,3);
	head = insertNodeAtPosition(3,4);
	head = insertNodeAtPosition(2,5);
	head = insertNodeAtPosition(1,6);
	head = insertNodeAtPosition(12,1);
	head = insertNodeAtPosition(11,3);
	head = insertNodeAtPosition(9,9);
	printLinkedList(head);
	printf("\n");
	head = deleteNodeAtPosition(9);
	head = deleteNodeAtPosition(1);
	printLinkedList(head);
	printf("\n");
		
	return 0;
	
}
