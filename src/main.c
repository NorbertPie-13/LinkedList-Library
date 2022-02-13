#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

int main(void)
{
	linklist *mylist = create_links();

	printf("Count of the links: %d\n", mylist->count);
        print_list(mylist);
	enqueue(mylist, "one");
        enqueue(mylist, "two");
        enqueue(mylist, "three");
	printf("Count of the links: %d\n\n", mylist->count);
	
        print_list(mylist);
        node * mynode = pop(mylist);
        free(mynode);
        printf("Node Popped: %s\n\n", mynode->word);
        print_list(mylist);
        peek(mylist);
        node * temp2 = dequeue(mylist);
        free(temp2);
        printf("Node Dequeued: %s\n\n", temp2->word);
        peek(mylist);
        printf("Size of list: %d\n", sizeoflist(mylist));
        push(mylist, "zero");
        print_list(mylist);
        printf("The Tail: %s", mylist->tail->word);
        destroy_list(mylist);
}
