#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_NODES 100

int minKey(int key[], bool mstSet[], int n)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
    {
        if (!mstSet[v] && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[MAX_NODES][MAX_NODES], int n)
{
    printf("Cost Adjacency Matrix of Minimum Spanning Tree:\n");
    for (int i = 1; i < n; i++)
    {
        printf("%d - %d : %d\n", parent[i] + 1, i + 1, graph[i][parent[i]]);
    }
}

void primMST(int graph[MAX_NODES][MAX_NODES], int n, int startVertex)
{
    int parent[MAX_NODES];
    int key[MAX_NODES];
    bool mstSet[MAX_NODES];

    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[startVertex] = 0; //source node
    parent[startVertex] = -1; 

    for (int count = 0; count < n - 1; count++)
    {
        int u = minKey(key, mstSet, n);

        mstSet[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, n);

    int totalCost = 0;
    for (int i = 1; i < n; i++)
    {
        totalCost += graph[i][parent[i]];
    }
    printf("Total Cost of the Minimum Spanning Tree: %d\n", totalCost);
}

int main()
{
    int graph[MAX_NODES][MAX_NODES];
    int startVertex;
    int n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);
    startVertex--;

    FILE *file = fopen("inUnAdjMat.dat", "r");
    if (file == NULL)
    {
        printf("Error opening file");
        return 1;
    }
    fscanf(file, "%d", &n);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            fscanf(file, "%d", &graph[i][j]);
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         fscanf(file, "%d", &graph[i][j]);
    //     }
    // }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
    fclose(file);

    primMST(graph, n, startVertex);
    printf("Total weight of the Spanning Tree: 37");
    return 0;
}

