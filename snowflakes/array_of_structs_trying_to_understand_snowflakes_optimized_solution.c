#include <stdio.h>

typedef struct Node
{
    int value;
    struct Node * next;
} Node;

int main()
{
    Node nodes[5];
    for (int i = 0; i < 5; i++)
    {
        nodes[i].value = i + 42;
        if (i > 0)
        {
            nodes[i - 1].next = &nodes[i];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("node at %d has value %d\n", i, nodes[i].value);
        if (i > 0)
        {
            printf("node at %d has value %d\n", i - 1, nodes[i - 1].value);
            printf(
                "that node's 'next' is %p and, as expected, its 'next' has value %d\n", 
                nodes[i - 1].next, nodes[i - 1].next->value
            );
        }
    }
    return 0;
}
