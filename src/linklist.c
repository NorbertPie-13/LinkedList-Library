#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linklist.h"

/*Create links makes a linked list with no nodes. It holds the properties
of a queue.  Insert will instead create the individual node when inserting.*/
linklist *create_links(del_f delete)
{				// Save linkedlist onto the heap setting everthing to 0
	linklist *linkedlist = calloc(1, sizeof(*linkedlist));
	if (linkedlist == NULL) {
		fprintf(stderr, "Cannout create LinkedList struct\n");
		return NULL;
	}
	linkedlist->delete = delete;
	return linkedlist;
}

static node *create_node(void *data)
{
	if (NULL == data) {
		fprintf(stderr, "Cannot create node with an invalid pointer\n");
		return NULL;
	}
	node *mynode = calloc(1, sizeof(*mynode));
	// Check the pointer
	if (mynode == NULL) {
		fprintf(stderr, "Could not create node containing");
		return NULL;
	}
	mynode->data = data;

	return mynode;
}

/* Create an individual node that assigns the word passed into it, as the word in the node.
The node will be inserted at the tail of all the structures.*/
linklist *enqueue(linklist * mylist, void *data)
{
	if (NULL == mylist) {
		fprintf(stderr, "Invalid pointer to link list in enqueue\n");
		return NULL;
	}
	node *mynode = create_node(data);
	// If there is nothing in the queue, then head will be empty
	if (mylist->head == NULL) {
		// assign head to my node
		mylist->head = mynode;
		// assign tail to head
		mylist->tail = mylist->head;
		//increase the count of the queue
		mylist->count++;
	} else {
		// otherwise go to the tail node and access their next value
		// and set it to node
		mylist->tail->next = mynode;
		// now assign tail to node
		mylist->tail = mynode;
		// increase count
		mylist->count++;
	}

	return mylist;
}

/* pop returns the first object that is at the head and moves the head forward*/
void *pop(linklist * my_list)
{
	// check the pointer
	if (NULL == my_list) {
		fprintf(stderr, "Cannot pop() as list does not exist\n");
		return NULL;
	}
	// make a temporary value to hold head
	node *temphead = my_list->head;
	if (NULL == temphead) {
		fprintf(stderr, "Head is empty.\n");
		return NULL;
	}
	// assign head to the temporary's value next pointer
	my_list->head = temphead->next;
	// reduce the count
	my_list->count--;
	// set the temp pointer to NULL so to not track next
	temphead->next = NULL;

	//return temporary structure
	void *data = temphead->data;
	if (NULL == temphead->data) {
		fprintf(stderr, "Head data is empty.\n");
		return NULL;
	}
	free(temphead);
	return data;

}

/* Peek is a void function that allows you to see what the head holds,
and if there is a next value then it will show that value*/
void *peek(linklist * mylist)
{
	// check the pointer
	if (NULL == mylist) {
		printf("Cannot peek, nothing in list\n");
		return NULL;
	}
	// print the current word
	if (NULL != mylist->head) {
		return mylist->head;
	} else {
		return NULL;
	}

}

/*Dequeue behaves exactly like pop*/
void *dequeue(linklist * mylist)
{
	return pop(mylist);	// call pop and return the item that was removed.
}

/* Return size of my list*/
int sizeoflist(linklist * mylist)
{
	return mylist->count;	// return the count of the elements in the LinkList
}

/*create a node and insert at the head of the queue. Returns void*/
void push(linklist * mylist, void *word)
{
	if (NULL == mylist || NULL == word) {
		fprintf(stderr, "Cannnot push, invalid pointer provided\n");
		return;
	}
	node *node_inserted = create_node(word);	// create a node data structure by calling create node
	node_inserted->next = mylist->head;	// set the next of the node being inserted to the current head
	mylist->head = node_inserted;	// set the head to the node inserted
	mylist->count++;	// increase the count of the linklist
}

/* Frees all nodes in the LinkList and then frees the wrapper for the LinkList*/
void destroy_list(linklist * mylist)
{
	if (NULL == mylist)	// check to see if the list exists
	{
		fprintf(stderr, "Cannot destroy linklist.\n");	// if it doesnt print to stderr and leave func
		return;
	}
	node *my_node = mylist->head;	// set a pointer to the head node of the linklist(LL)
	while (my_node)		// while that node is not NULL
	{
		node *temp = my_node->next;	// create a pointer to the next node in the LL
		if (mylist->delete)	// if a delete function exists
		{
			mylist->delete(temp->data);	// call the delete function on the next node
		}
		free(temp);	// then free that node.
	}
	free(mylist);		// then free the wrapper
}

/* NOP Function, does nothing and returns nothing */
void nop_delete_func(void *item)
{
	(void)item;
}

/*Purge list keeps the linklist allocation, but removes all elements and frees
 all elements while keeping the wrapper. */
void purge_list(linklist * mylist)
{
	if (NULL == mylist)	// if the linklist pointer is NULL
	{
		fprintf(stderr, "Cannot destroy linklist.\n");	// Call fprint F and leave the function
		return;
	}
	node *mynode = mylist->head;	// Set a pointer to the head
	while (mynode)		// while the head is not null
	{
		node *temp = mynode->next;	// create a node pointer that holds the next item in the linklist
		free(mynode);	// free the current item
		mynode = temp;	// set the current item to the next item and go back to start of loop
	}
	mylist->count = 0;	// set the count of items to zero
	mylist->head = NULL;	// set the head to NULL
	mylist->tail = NULL;	// set the tail to NULL
}

/* Check to see if the linklist is empty. If there is an error, -1 is returned.
If the linklist is empty then 1 is returned, if not empty, zero is returned. */
int is_empty(linklist * list)
{
	if (NULL == list)	// if the linklist is NULL
	{
		fprintf(stderr, "List is null.\n");	// Print to stderr and return -1 for error.
		return -1;
	}
	if (0 == sizeoflist(list))	// call sizeoflist that returned the count of elements in a list
	{
		return 1;	// if there is 0 elements, then return 1 for True
	} else {
		return 0;	// if there is less than or more that 0 elements, return 0 for False
	}

	return -1;		// If the code made it here, there is an error that is undefined.
}
