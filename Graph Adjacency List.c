// Coded by MidhunMike
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Graph implementation
struct Graph
{
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Function to create a new graph
struct Graph *createGraph(int numVertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    int i, j;
    for (i = 0; i < numVertices; i++)
    {
        for (j = 0; j < numVertices; j++)
        {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest)
{
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

// Function to print the adjacency matrix of the graph
void printGraph(struct Graph *graph)
{
    int i, j;
    for (i = 0; i < graph->numVertices; i++)
    {
        for (j = 0; j < graph->numVertices; j++)
        {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // Take input for number of vertices
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // Create a graph with given number of vertices
    struct Graph *graph = createGraph(numVertices);

    // Take input for edges of the graph
    int numEdges;
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    int i, src, dest;
    for (i = 0; i < numEdges; i++)
    {
        printf("Enter edge %d: ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    // Print the adjacency matrix of the graph
    printf("Adjacency Matrix:\n");
    printGraph(graph);

    return 0;
}