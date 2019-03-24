#include <stdio.h>
#include <stdlib.h>

/*
* Linked List implementation for integer data
* Author: Yusuf Dalva
* Date: 24.03.2019
*/

/* Type definition of Node */
typedef struct Node { // node definition
	int data;
	struct Node *next;
} node_t;


/* Checking whether the list is empty*/
int isEmpty(node_t *start) { // Checks whether the list is empty
	return start == NULL;
}

/* Inserts a single element to the linked list. Inserts element to the beginning of the list */
void insert(int data, node_t **start) { // Insertion to the list
	node_t *newNode = NULL;
	newNode = malloc(sizeof(node_t));
	newNode->data = data;
	newNode->next = *start;
	*start = newNode;
}

/* Deletes the first element from the linked list */
int deleteFirst(node_t **start) {
	if(isEmpty(*start)) {
		printf("List is empty\n");
		return -1;	
	}
	node_t *current = *start;
	*start = (*start)->next;
	free(current);
}

/* Deletes the specified node having the specified data, only deletes the first occurance */
int delete (int data, node_t **start) {
	node_t *previous = NULL;
	if (isEmpty(*start)) {
		printf("List is empty\n");			
		return -1;	
	}
	node_t *current = *start;
	while (current->data != data) { 
		if (current == NULL) {
			return -1;		
		}
		previous = current;
		current = current->next;
	}

	if (current == *start) {
		*start = (*start)->next;
	}
	else {
		previous->next = current->next;	
	}
	free(current);
	printf("Success\n");
	return 1;
}

/* Prints the contents of the list */
void printList(node_t *start) {
	node_t *current = start;
	int index = 0;
	while (current != NULL) {
		printf("list[%d]: %d\n", index, current->data);
		current = current->next;
		index += 1;
	}
}

/* Testing with sample data */
int main() {
	node_t *start = NULL;
	int size = 5;
	int toInsert[5] = {10, 20, 30, 40, 50};
	int index;
	for (index = 0; index < size; index++) {
		insert(toInsert[index], &start);	
	}
	printList(start);
	deleteFirst(&start);
	printf("\n");
	printList(start);
}
