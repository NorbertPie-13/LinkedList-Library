#ifndef LINKLIST_H
#define LINKLIST_H


typedef void (*del_f)(void *data);

typedef struct linknode {
	void *data;
	struct linknode *next;

} node;

typedef struct Linklist {
	node *tail;
	node *head;
        del_f delete;
	int count;
} linklist;



/*Create links makes a linked list with no nodes. It holds the properties
of a queue.  Insert will instead create the individual node when inserting.*/
linklist *create_links(del_f del);

int is_empty(linklist * list);

/* Create an individual node that assigns the word passed into it, as the word in the node.
The node will be inserted at the tail of all the structures.*/
linklist *enqueue(linklist * mylist, void * data);


/* pop returns the first object that is at the head and moves the head forward*/
void * pop(linklist * my_list);

/* Peek is a void function that allows you to see what the head holds,
and if there is a next value then it will show that value*/
void *peek(linklist * mylist);

void nop_delete_func(void *item);

/*Dequeue behaves exactly like pop*/
void * dequeue(linklist * mylist);

/* Return size of my list*/
int sizeoflist(linklist * mylist);
/*create a node and insert at the head of the queue. Returns void*/
void push (linklist * mylist, char * word);
/* Frees all nodes and then the wrapper for the queue*/
void destroy_list(linklist * mylist);
void purge_list (linklist * mylist);


#endif
