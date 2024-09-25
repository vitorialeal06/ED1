
#include "TLinkedList.h"
#include <stdio.h>

int main()
{
    TLinkedList *list = TLinkedList_create();
    int V[] = {7, 5, 1};
    int W[] = {1, 2, 3};
    for (int i = 0; i < 3; i++)
    {
        TLinkedList_insert_begin(list, W[i]);
        TLinkedList_insert_end(list, V[i]);
    }
    TLinkedList_print(list);
    return 0;
}
