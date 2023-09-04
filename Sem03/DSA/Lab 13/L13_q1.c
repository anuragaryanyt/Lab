#include <stdio.h>
#include <stdlib.h>
struct edge_2105986;
struct Node_2105986
{
    int data;
    struct node_2105986 *nextNode;
    struct edge_2105986 *next;
};

struct edge_2105986
{
    struct node_2105986 *next;
    struct edge_2105986 *link;
};

void addvertex_2105986(int val, struct Node_2105986 *root)
{
    struct Node_2105986 *node_2105986 = (struct Node_2105986 *)malloc(sizeof(struct Node_2105986));
    node_2105986->data = val;
    node_2105986->nextNode = NULL;
    node_2105986->next = NULL;

    if (!root)
        *root = node_2105986;

    else
    {
        struct Node_2105986 *temp_2105986 = root;
        while (temp_2105986->nextNode != NULL)
            temp_2105986 = temp_2105986->nextNode;

        temp_2105986->nextNode = node_2105986;
    }
}

void addEdge(int val, int linkVal, struct Node_2105986 *root)
{
    if (!root)
    {
        printf("Unable to add Edge as no vertices found\n");
        return;
    }
    struct node_2105986 *temp_2105986 = root;
    int status_2105986 = 0;
    while (temp_2105986)
    {
        if (temp_2105986->data == val)
        {
            status_2105986 = 1;
            break;
        }
        temp_2105986 = temp_2105986->nextNode;
    }

    if (status_2105986 == 0)
        printf("Vertice Not Found\n");

    else
    {
        struct edge_2105986 *edge_2105986 = temp_2105986->next;
        struct node_2105986 *tempLink = root;

        status_2105986 = 0;
        while (tempLink)
        {
            if (tempLink->data == linkVal)
            {
                status_2105986 = 1;
                break;
            }
            tempLink = tempLink->nextNode;
        }

        if (status_2105986 == 0)
            printf("Link Vertice Not Found\n");

        else
        {
            struct edge_2105986 *node_2105986 = (struct edge_2105986 *)malloc(sizeof(struct edge_2105986));
            node_2105986->next = NULL;
            node_2105986->link = tempLink;
            if (edge_2105986 == NULL)
                temp_2105986->next = node_2105986;
            else
            {
                while (edge_2105986->next != NULL)
                    edge_2105986 = edge_2105986->next;

                edge_2105986->next = node_2105986;
            }
        }
    }
}
