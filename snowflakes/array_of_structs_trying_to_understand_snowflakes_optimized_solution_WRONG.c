#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int value;
    struct Node * next;
} Node;

int main(void)
{
    Node nodes[5];
    
    for (int i = 0; i < 5; i++)
    {
        Node curr_node = { i };
        nodes[i] = curr_node;
        printf("Node in ARR current after insertion: %d\n", nodes[i].value);
        printf("Node _address_ in ARR current after insertion: %p\n", &nodes[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("Node in ARR: %d\n", nodes[i].value);
    }

    return 0;
}
