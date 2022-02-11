#ifndef LINKLIST_H
#define LINKLIST_H

typedef struct linknode {
	char *word;
	struct linknode *next;

} node;

typedef struct Linklist {
	node *tail;
	node *head;
	int count;
} linklist;

/*Create links makes a linked list with no nodes. It holds the properties
of a queue.  Insert will instead create the individual node when inserting.*/
linklist *create_links(void);

/* Create an individual node that assigns the word passed into it, as the word in the node.
The node will be inserted at the tail of all the structures.*/
linklist *enqueue(linklist * mylist, char *word);

// Print list prints all objects that are currently in the list
void print_list(linklist * mylist);

/* pop returns the first object that is at the head and moves the head forward*/
node * pop(linklist * my_list);

/* Peek is a void function that allows you to see what the head holds,
and if there is a next value then it will show that value*/
void peek(linklist ** mylist);
/*Dequeue behaves exactly like pop*/
node * dequeue(linklist * mylist);

/* Return size of my list*/
int sizeoflist(linklist * mylist);
#endif
