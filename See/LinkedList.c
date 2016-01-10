
//References :  Some codes from geekforgeeks

#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct node
{
	int data;
	struct node* next;
};

/* Reverses the linked list in groups of size k and returns the
pointer to the new head node. */
struct node *reverse (struct node *head, int k)
{

printf("here %d",head->data);
struct node * temp = head;
struct node * nextptr = NULL;
struct node *prevptr = NULL;
int count = 0;

 while(temp != NULL && count <k){
	 nextptr = temp->next;
	 temp->next = prevptr;
     prevptr = temp;
     temp = nextptr;
	 count ++;
 }
 printf("\n %d",prevptr->data);
 if (nextptr != NULL)
 head->next = reverse(nextptr,k);
head = prevptr;
 return head;
}


void push(struct node** head_ref, int new_data)
{
	/* allocate node */
	struct node* new_node =
			(struct node*) malloc(sizeof(struct node));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}
struct node *reverseRecursion (struct node *head, int k)
{
	struct node* temp = head;
	int count = 0;
	if(temp->next == NULL && count < k){
		head = temp;
		return head;
		count++;
	}
	printf("\n head is %d",head->data);
	head = reverseRecursion(head->next,3);
	struct node *q = temp->next;
	q->next = temp;
	temp->next = NULL;
	return head;
}

/* Function to print linked list */
void printList(struct node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

/* Drier program to test above function*/
int main(void)
{
	/* Start with the empty list */
	struct node* head = NULL;

	/* Created Linked list is 1->2->3->4->5->6->7->8->9 */
	push(&head, 9);
	push(&head, 8);
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	printList(head);
	head = reverse(head, 3);

	printf("\nReversed Linked list \n");
	printList(head);

	return(0);
}
