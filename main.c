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

void addFirst(struct list *list, int val)
{
	// create new node with val
	struct node *newNode = (struct node*)malloc( sizeof(struct node) );
	newNode->val  = val;
	newNode->next = list->head;
	
	// make new node the new head in the list
	list->head = newNode;
}

void addLast(struct list *list, int val)
{
	// create new node with val
	struct node *newNode = (struct node*)malloc( sizeof(struct node) );
	newNode->val  = val;
	newNode->next = NULL; // as newNode will become last item on the list
	
	// make newNode the new tail in the list
	if ( !isEmpty(list) )
		list->tail->next = newNode;
	else
		list->head = newNode;
	list->tail = newNode;
}

void add(struct list *list, int val)
{
	addLast(list, val);
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
		struct node *temp = current;
		current = current->next;
		free(temp);
	}
	
	free(list);
}

int main(void)
{
	struct list *myList = initList();
	
	int input;
	
	do
	{
		scanf("%i", &input);
		if (input) addFirst(myList, input);
	}
	while(input);
	
	printList(myList);
	
	clearList(myList);
	
	return 0;
}
