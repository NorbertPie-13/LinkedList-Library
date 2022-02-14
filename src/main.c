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
        printf("Node Popped: %s\n\n", mynode->word);
        free(mynode);
        
        print_list(mylist);
        peek(mylist);

        node * temp2 = dequeue(mylist);
        printf("Node Dequeued: %s\n\n", temp2->word);
        free(temp2);


        
        peek(mylist);
        printf("Size of list: %d\n", sizeoflist(mylist));
        push(mylist, "zero");
        push(mylist, "five");
        push(mylist, "six");

        print_list(mylist);
        printf("The Tail: %s", mylist->tail->word);

        destroy_list(mylist);
}
