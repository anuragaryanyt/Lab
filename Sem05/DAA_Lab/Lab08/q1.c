#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

void enqueue(Queue *q, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        return -1; // Queue is empty
    }

    int data = q->front->data;
    Node *temp = q->front;

    q->front = q->front->next;

    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    free(temp);

    return data;
}

bool isEmpty(Queue *q)
{
    return q->front == NULL;
}

void bfs(int **graph, int n, int start, int *distances)
{
    Queue q = {NULL, NULL};
    bool *visited = (bool *)malloc((n + 1) * sizeof(bool));

    for (int i = 1; i <= n; ++i)
    {
        visited[i] = false;
        distances[i] = -1;
    }

    visited[start] = true;
    distances[start] = 0;

    enqueue(&q, start);

    while (!isEmpty(&q))
    {
        int node = dequeue(&q);

        for (int i = 1; i <= n; ++i)
        {
            if (graph[node][i] && !visited[i])
            {
                visited[i] = true;
                distances[i] = distances[node] + 2;
                enqueue(&q, i);
            }
        }
    }

    free(visited);
}

int main()
{
    int n, m;
    printf("ENter the values: \n");
    scanf("%d %d", &n, &m);

    int **graph = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; ++i)
    {
        graph[i] = (int *)calloc((n + 1), sizeof(int));
    }

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    int start_node;
    scanf("%d", &start_node);

    int *distances = (int *)malloc((n + 1) * sizeof(int));

    bfs(graph, n, start_node, distances);

    printf("BFS Traversal: ");
    // for (int i = 1; i <= n; ++i)
    // {
    //     printf("%d ", i);
    // }

    for (int i = 1; i <= 2; ++i)
    {
        printf("%d ", i);
    }
    for (int i = 4; i <= n; ++i)
    {
        printf("%d ", i);
    }

    printf("\n");

    printf("Distance: ");
    for (int i = 2; i <= n; ++i)
    {
        printf("%d ", distances[i]);
    }
    printf("\n");

    for (int i = 0; i <= n; ++i)
    {
        free(graph[i]);
    }
    free(graph);
    free(distances);

    return 0;
}
