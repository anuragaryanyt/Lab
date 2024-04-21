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
void minHeapify(struct MinPriorityQueue *queue, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < queue->size && queue->array[left]->symbol.frequency < queue->array[smallest]->symbol.frequency)
        smallest = left;
    if (right < queue->size && queue->array[right]->symbol.frequency < queue->array[smallest]->symbol.frequency)
        smallest = right;
    if (smallest != index)
    {
        swapNodes(&queue->array[index], &queue->array[smallest]);
        minHeapify(queue, smallest);
    }
}
void insertQueue(struct MinPriorityQueue *queue, struct Node *node)
{
    int i = queue->size;
    queue->size++;
    while (i > 0 && node->symbol.frequency < queue->array[(i - 1) / 2]->symbol.frequency)
    {
        queue->array[i] = queue->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    queue->array[i] = node;
}
struct Node *extractMin(struct MinPriorityQueue *queue)
{
    if (queue->size <= 0)
        return NULL;
    struct Node *minNode = queue->array[0];
    queue->array[0] = queue->array[queue->size - 1];
    queue->size--;
    minHeapify(queue, 0);
    return minNode;
}
struct Node *buildHuffmanTree(struct SYMBOL symbols[], int num_symbols)
{
    struct MinPriorityQueue *queue = createQueue(num_symbols);
    for (int i = 0; i < num_symbols; i++)
    {
        struct Node *node = createNode(symbols[i]);
        insertQueue(queue, node);
    }
    while (queue->size > 1)
    {
        struct Node *left = extractMin(queue);
        struct Node *right = extractMin(queue);
        struct SYMBOL symbol = {'-', left->symbol.frequency + right->symbol.frequency};
        struct Node *mergedNode = createNode(symbol);
        mergedNode->left = left;
        mergedNode->right = right;
        insertQueue(queue, mergedNode);
    }
    return extractMin(queue);
}
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%c ", root->symbol.alphabet);
        inorderTraversal(root->right);
    }
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
