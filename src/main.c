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
	printf("Count of the links: %d\n", mylist->count);
	
        print_list(mylist);
        node * mynode = pop(mylist);
        printf("Node Popped: %s\n", mynode->word);
        print_list(mylist);
        peek(mylist);
        node * temp2 = dequeue(mylist);
        peek(mylist);
        printf("Size of list: %d\n", sizeoflist(mylist));
}
