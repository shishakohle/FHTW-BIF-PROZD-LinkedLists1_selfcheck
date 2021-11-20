#include <stdlib.h>
#include <stdio.h>

struct node
{
	int val;
	struct node *next;
};

struct list
{
	struct node *head;
	struct node *tail;
};

struct list* initList(void)
{
	struct list *newList = (struct list*)malloc( sizeof(struct list) );
	newList->head = NULL;
	newList->tail = NULL;
	
	return newList;
}

int isEmpty(struct list *list)
{
	return list->head == NULL ? 1 : 0;
}

void add(struct list *list, int val)
{
	// create new node with val
	struct node *newNode = (struct node*)malloc( sizeof(struct node) );
	newNode->val  = val;
	newNode->next = NULL; // as newNode will become last item on the list
	
	// make newNode the new tail in the list
	if ( !isEmpty(list) )
	{
		list->tail->next = newNode;
		list->tail       = newNode;
	}
	else
	{
		list->head = newNode;
		list->tail = newNode;
	}
}

void printList(struct list *list)
{
	struct node *current = list->head;

	while( current != NULL )
	{
		printf("%i ", current->val);
		current = current->next;
	}
}

void clearList(struct list *list)
{
	struct node *current = list->head;

	while( current != NULL )
	{
		free(current);
		current = current->next;
	}
	
	free(list);
	
	list = initList();
}

int main(void)
{
	struct list *myList = initList();
	
	int input;
	
	do
	{
		scanf("%i", &input);
		if (input) add(myList, input);
	}
	while(input);
	
	printList(myList);
	
	clearList(myList);
	
	return 0;
}
