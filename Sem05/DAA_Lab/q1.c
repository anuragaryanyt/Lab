#include <stdio.h>
#include <stdlib.h>
struct SYMBOL
{
    char alphabet;
    int frequency;
};
struct Node
{
    struct SYMBOL symbol;
    struct Node *left;
    struct Node *right;
};

struct MinPriorityQueue
{
    int size;
    struct Node **array;
};
struct Node *createNode(struct SYMBOL symbol)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->symbol = symbol;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}   
struct MinPriorityQueue *createQueue(int capacity)
{
    struct MinPriorityQueue *queue = (struct MinPriorityQueue *)malloc(sizeof(struct MinPriorityQueue));
    queue->size = 0;
    queue->array = (struct Node **)malloc(capacity * sizeof(struct Node *));
    return queue;
}
void swapNodes(struct Node **a, struct Node **b)
{
    struct Node *temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int num_symbols;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &num_symbols);
    struct SYMBOL symbols[num_symbols];
    for (int i = 0; i < num_symbols; i++)
    {
        printf("Enter the alphabets: ");
        scanf(" %c", &symbols[i].alphabet);
        printf("Enter its frequencies: ");
        scanf("%d", &symbols[i].frequency);
    }
    struct Node *root = buildHuffmanTree(symbols, num_symbols);
    printf("In-order traversal of the tree (Huffman): ");
    inorderTraversal(root);
    printf("\n");
    return 0;
}
