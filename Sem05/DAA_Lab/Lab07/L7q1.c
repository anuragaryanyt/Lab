/* Given an undirected weighted connected graph G(V, E) and starring vertex ‘s’. Maintain a Min-Priority Queue ‘Q’ from the vertex set V and apply Prim’s algorithm to
-> Find the minimum spanning tree T(V, E’). Display the cost adjacency matrix of ‘T’.
-> Display total cost of the minimum spanning tree T.
Note# Nodes will be numbered consecutively from 1 to n (user input), and edges will have varying weight. The graph G can be read from an input file “inUnAdjMat.dat” that contains cost adjacency matrix. The expected output could be displayed as the cost adjacency matrix of the minimum spanning tree and total cost of the tree. */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 100

int readGraph(char *fileName, int matrix[MAX_SIZE][MAX_SIZE])
{
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int n;
    if (fscanf(file, "%d", &n) != 1)
    {
        fprintf(stderr, "Error reading number of vertices from file.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (fscanf(file, "%d", &matrix[i][j]) != 1)
            {
                fprintf(stderr, "Error reading edge weight from file.\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(file);
    return n;
}

void prim(int n, int matrix[MAX_SIZE][MAX_SIZE], int start)
{
    int visited[MAX_SIZE] = {0};
    int totalCost = 0;
    int parent[MAX_SIZE] = {0};

    // step1:
    //  set cost to infinity
    int key[MAX_SIZE];
    for (int i = 0; i < n; ++i)
    {
        key[i] = INT_MAX;
    }
    // step2:
    //souce node=0
    key[start] = 0;

    for (int count = 0; count < n - 1; ++count)
    {
        // Find the minimum key vertex
        int minKey = INT_MAX, minIndex;
        for (int v = 0; v < n; ++v)
        {
            if (!visited[v] && key[v] < minKey)
            {
                minKey = key[v];
                minIndex = v;
            }
        }

        visited[minIndex] = 1;
        totalCost += minKey;

        // Update key values for adjacent vertices
        for (int v = 0; v < n; ++v)
        {
            if (matrix[minIndex][v] && !visited[v] && matrix[minIndex][v] < key[v])
            {
                parent[v] = minIndex;
                key[v] = matrix[minIndex][v];
            }
        }
    }

    printf("Cost Adjacency Matrix of Minimum Spanning Tree:\n");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d ", (i == parent[j] || j == parent[i]) ? matrix[i][j] : 0);
        }
        printf("\n");
    }

    printf("\nTotal Cost of Minimum Spanning Tree: %d\n", totalCost);
}

int main()
{
    char fileName[] = "inUnAdjMat2.dat";
    int matrix[MAX_SIZE][MAX_SIZE];
    int n = readGraph(fileName, matrix);

    int start;
    printf("Enter the starting vertex (1 to %d): ", n);
    scanf("%d", &start);
    --start;

    prim(n, matrix, start);

    return 0;
}

