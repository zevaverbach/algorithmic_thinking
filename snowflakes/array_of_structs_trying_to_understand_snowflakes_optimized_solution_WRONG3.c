#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN 1047505

typedef struct Node
{
    int value;
    struct Node * next;
} Node;

Node * make_node(int value)
{
    Node * node = malloc(sizeof(Node));
    node->value = value;
    return node;
}

int main()
{
    Node * nodes[ARRAY_LEN];
    for (int i = 0; i < ARRAY_LEN; i++)
    {
        nodes[i] = make_node(i);
    }
    for (int i = 0; i < ARRAY_LEN; i++)
    {
        printf("Node in ARR: %d\n", nodes[i]->value);
    }
    return 0;
}
