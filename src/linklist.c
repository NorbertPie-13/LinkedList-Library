#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

/*Create links makes a linked list with no nodes. It holds the properties
of a queue.  Insert will instead create the individual node when inserting.*/
linklist *create_links(void)
{       // Save linkedlist onto the heap setting everthing to 0
	linklist *linkedlist = calloc(1, sizeof(*linkedlist));
	if (linkedlist == NULL) {
		fprintf(stderr, "Cannout create LinkedList struct\n");
		return NULL;
	}
	return linkedlist;
}

/* Create an individual node that assigns the word passed into it, as the word in the node.
The node will be inserted at the tail of all the structures.*/
linklist *enqueue(linklist * mylist, char *word)
{
	node *mynode = calloc(1, sizeof(*mynode));
        // Check the pointer
	if (mynode == NULL || word == NULL) {
		fprintf(stderr, "Could not create node containing %s", word);
		return NULL;
	}
        // Assign the node's word to word
	mynode->word = word;
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
node * pop(linklist * my_list){
        // check the pointer
        if (NULL == my_list){
                fprintf(stderr, "Cannot pop() as list does not exist\n");
                return NULL;
        }
        // make a temporary value to hold head
        node * temphead = my_list->head;
        // assign head to the temporary's value next pointer
        my_list->head = temphead->next;
        // reduce the count
        my_list->count--;
        // set the temp pointer to NULL so to not track next
        temphead->next = NULL;
        
        //return temporary structure
        return temphead;

}



// Print list prints all objects that are currently in the list
void print_list(linklist * mylist)
{       //Check the pointer exists
        if (!mylist) {
                return;
        }
        // set a temp struct to the head
        node *temp = mylist->head;
        // while temp exists,
        while(temp) {
                // print what temp is and assign to next
                printf("%s -> ", temp->word);
                temp = temp->next;
        }
        printf("\n");
}
/* Peek is a void function that allows you to see what the head holds,
and if there is a next value then it will show that value*/
void peek(linklist * mylist){
        // check the pointer
        if (NULL == mylist){
                printf("Cannot peek, nothing in list\n");
        }
        // print the current word
        printf("Current Head: %s\n", mylist->head->word);
        // if there is a next, print that too!
        if (NULL != mylist->head->next){
                printf("Next Node: %s\n", mylist->head->next->word);
        }
}

/*Dequeue behaves exactly like pop*/
node * dequeue(linklist * mylist){
        return pop(mylist);
}
/* Return size of my list*/
int sizeoflist(linklist * mylist){
        return mylist->count;
}

