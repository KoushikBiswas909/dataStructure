#include <stdio.h>
#include <stdlib.h>

// Queue Implementation in C

struct queue {
	int data;
	struct queue* next;
};
struct queue* head = NULL;

struct queue* createElement(int data){
	struct queue* newElement = (struct queue*) malloc(sizeof(struct queue));
	newElement->data = data;
	newElement->next = NULL;
	return newElement;
}
// push will always push elemets at the end of the linked list and will return the head

struct queue * push(int data){
	if(head == NULL)
		head = createElement(data);
	else{
		struct queue *current, *newElement=NULL;
		current = head;
		while(current->next!=NULL){
			current = current->next;
		}
		newElement = createElement(data);
		current->next = newElement;
	}
	return head;
}

// pop will always pop the elemet at the start of the linkedlist and will return the head
struct queue* pop()
{
	if(head==NULL)
	{
		printf("The queue is empty!");
		return NULL;
	}
	struct queue *current = head;
	head = current->next;
	return head;
}

// return the first element of the linked list
int peek()
{
	if(head==NULL)
	{
		printf("The queue is empty!");
		return 0;
	}
	struct queue *current = head;
	return current->data;
}
// print the elements of the linkedList

void printQueue(struct queue* headqueue){
	if(headqueue == NULL) return;
	 struct queue * current = headqueue;
	 printf("%d\t", current->data);
	 printQueue(current->next);
}	
void printReversedQueue(struct queue* headqueue){
	if(headqueue == NULL) return;
	 struct queue * current = headqueue;
	 printReversedQueue(current->next);
 	 printf("%d\t", current->data);
}
int main()
{
	head = push(6);
	head = push(5);
	head = push(4);
	head = push(3);
	head = push(2);

	printQueue(head);
	
	printf("\n%d\n",peek());
	pop();
	printQueue(head);
	printf("\n%d\n",peek());
	printf("\n");
	//printReversedQueue(head);
	return 0;
	
}
