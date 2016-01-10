#include <stdio.h>
#include <stdlib.h>

// Stack Implementaton in C
struct stack {
	int data;
	struct stack* next;
};
struct stack* head = NULL;

struct stack* createElement(int data){
	struct stack* newElement = (struct stack*) malloc(sizeof(struct stack));
	newElement->data = data;
	newElement->next = NULL;
	return newElement;
}
// push will always push elemets at the end of the linked list and will return the head

struct stack * push(int data){
	if(head == NULL)
		head = createElement(data);
	else{
		struct stack *current, *newElement=NULL;
		current = head;
		while(current->next!=NULL){
			current = current->next;
		}
		newElement = createElement(data);
		current->next = newElement;
	}
	return head;
}

// pop will always pop the elemet at the end of the linkedlist and will return the head
struct stack* pop()
{
	if(head==NULL)
	{
		printf("The stack is empty!");
		return NULL;
	}
	else if (head ->next == NULL){
		free(head->next);
		head = NULL;
	}
	else{
		struct stack *current = head;
		struct stack *prev = NULL;
		while(current->next!=NULL){
			prev = current;
			current = current->next;
		}
		free(prev->next);
		prev->next = NULL;
	}
	return head;
}

// return the first element of the linked list
int peek()
{
	if(head==NULL)
	{
		printf("The stack is empty!");
		return 0;
	}
	struct stack *current = head;
		while(current->next!=NULL){
			current = current->next;
		}
	return current->data;
}
// print the elements of the linkedList

void printstack(struct stack* headstack){
	if(headstack == NULL) return;
	 struct stack * current = headstack;
	 printf("%d\t", current->data);
	 printstack(current->next);
}	
void printReversedstack(struct stack* headstack){
	if(headstack == NULL) return;
	 struct stack * current = headstack;
	 printReversedstack(current->next);
 	 printf("%d\t", current->data);
}
int main()
{
	head = push(6);
	head = push(5);
	head = push(4);
	head = push(3);
	head = push(2);

	printstack(head);
	
	printf("\n%d\n",peek());
	pop();
	head = push(21);
	printf("\n");
	printstack(head);
	printf("\n%d\n",peek());
	pop();
	printf("\n%d\n",peek());
	printstack(head);
	//printf("\n%d\n",peek());
	//printf("\n");
	//printReversedstack(head);
	return 0;
	
}

