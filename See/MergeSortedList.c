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
struct Node * insertNodeAtPosition(struct Node* head, int data,int pos){
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

struct Node* mergeTwoList(struct Node * l1, struct Node* l2)
{
    struct Node* r = NULL;
    struct Node* cur  = NULL;
    struct Node* cur1 = l1;
    struct Node* cur2 = l2;
    if (l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    while(cur1!=NULL && cur2!=NULL){
       //printf("here"); 
        if(cur1->data>= cur2->data){
            if(r == NULL){
            r = createNode(cur2->data);
            cur = r;
           }else{
               cur->next = createNode(cur2->data);
               cur = cur->next;
           }
           cur2 = cur2->next;
            
        }
        else {
            
            if(r == NULL){
            r = createNode(cur1->data);
            cur = r;
           }else{
               cur->next = createNode(cur1->data);
               cur = cur->next;
           }
           cur1 = cur1->next;
        }
    }
    printLinkedList(r);
    printf("\n");
    if(cur1!=NULL){
        while(cur1){
               cur->next = createNode(cur1->data);
               cur1 = cur1->next; 
               cur = cur->next;
        }
    }
    if(cur2!=NULL){
        while(cur2){
               cur->next = createNode(cur2->data);
               cur = cur->next;
                cur2 = cur2->next; 

        }
    }
    return r;
    
}
int main()
{
    struct Node *head2 = NULL;
	head2 = insertNodeAtPosition(head2,2,1);
	head2 = insertNodeAtPosition(head2,4,2);
	head2 = insertNodeAtPosition(head2,6,3);
	
	struct Node *head1 = NULL;
	head1 = insertNodeAtPosition(head1,3,1);
	head1 = insertNodeAtPosition(head1,5,2);
	head1 = insertNodeAtPosition(head1,7,3);
	head1 = insertNodeAtPosition(head1,8,4);
	//head = insertNodeAtPosition(12,1);
	///head = insertNodeAtPosition(11,3);
	//head = insertNodeAtPosition(9,9);
	//printLinkedList(head1);
	//printf("\n");

	//printLinkedList(head2);
	//printf("\n");
	struct Node * merged = NULL;
	merged = mergeTwoList(head1,head2);
	printLinkedList(merged);

	//head = deleteNodeAtPosition(9);
	//head = deleteNodeAtPosition(1);
	//printLinkedList(head);
	//printf("\n");
		
	return 0;
	
}
