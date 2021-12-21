#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct graph
{
    int element_count;
    double **adj_matrix; // adj_matrix[SOURCE_NODE][TARGET_NODE] = WEIGHT
} graph_t;

/*
* Creates a new graph_t struct with 1 to n nodes and returns a pointer to it.
* @Param n: Count of nodes to create.
*/
graph_t *create(int n)
{
    // get memory for struct
    graph_t *g = malloc(sizeof(graph_t));
    if (g == NULL)
    {
        printf("No memory available for graph_t\n");
        return g;
    }
    // we will ignore the 0 space, but increasing the size by one makes everything nicer
    // otherwise we would need to do +1 for every insert, ..
    n += 1;
    g->element_count = n;

    // get memory for array pointers
    g->adj_matrix = (double **)malloc(n * sizeof(double *));
    if (g->adj_matrix == NULL)
    {
        printf("No memory available for matrix\n");
        return g;
    }

    for (int i = 0; i < n; i++)
    {
        // get memory for arrays
        g->adj_matrix[i] = (double *)malloc(n * sizeof(double));
        if (g->adj_matrix[i] == NULL)
        {
            printf("No memory available for matrix\n");
            return g;
        }
    }

    // init weight with 0.0
    // we could have used calloc instead of malloc to avoid this step
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *(*(g->adj_matrix + i) + j) = 0.0;
        }
    }

    return g;
}

/*
* Destroys a graph_t struct.
* @Param g: Pointer to graph_t struct.
*/
void destroy(graph_t *g)
{
    for (int i = 0; i < g->element_count; i++)
    {
        // free 2 dimensional arrays
        free(g->adj_matrix[i]);
    }
    // free array
    free(g->adj_matrix);
    // free struct
    free(g);
}

/*
* Inserts a new edge to the graph_t struct.
* Prints a message on the stdout if IndexOutOfBound or NullReference error occurs.
* @Param g: Pointer to graph_t struct.
* @Param source: Id of source node
* @Param target: Id of target node
* @Param weight: Weight for edge source to target
*/
void insert_edge(graph_t *g, int source, int target, double weight)
{
    if (g == NULL || g->adj_matrix == NULL)
    {
        printf("Parameter g is not initialized\n");
        return;
    }

    if (g->element_count < source || g->element_count < target)
    {
        printf("Source or Target is OutOfBounds!\n");
        return;
    }

    *(*(g->adj_matrix + source) + target) = weight;
}

/*
* Removes a edge.
* Prints a message on the stdout if IndexOutOfBound or NullReference error occurs.
* @Param g: Pointer to graph_t struct.
* @Param source: Id of source node
* @Param target: Id of target node
* @Param weight: Weight for edge source to target
*/
void remove_edge(graph_t *g, int source, int target)
{
    if (g == NULL || g->adj_matrix == NULL)
    {
        printf("Parameter g is not initialized\n");
        return;
    }

    if (g->element_count < source || g->element_count < target)
    {
        printf("Source or Target is OutOfBounds!\n");
        return;
    }

    *(*(g->adj_matrix + source) + target) = 0.0;
}

/*
* Checks if a edge exists.
* Prints a message on the stdout if IndexOutOfBound or NullReference error occurs.
* @Param g: Pointer to graph_t struct.
* @Param source: Id of source node
* @Param target: Id of target node
* @Return: True if edge source -> target exists, else false.
*/
bool has_edge(graph_t *g, int source, int target)
{
    if (g == NULL || g->adj_matrix == NULL)
    {
        printf("Parameter g is not initialized\n");
        return false;
    }

    if (g->element_count < source || g->element_count < target)
    {
        printf("Source or Target is OutOfBounds!\n");
        return false;
    }

    double value = *(*(g->adj_matrix + source) + target);
    return value == 0.0 ? false : true;
}

/*
* Gets the weight of a specific edge.
* Prints a message on the stdout if IndexOutOfBound or NullReference error occurs.
* @Param g: Pointer to graph_t struct.
* @Param source: Id of source node
* @Param target: Id of target node
* @Return: Weight of edge source -> target
*/
double get_weight(graph_t *g, int source, int target)
{
    if (g == NULL || g->adj_matrix == NULL)
    {
        printf("Parameter g is not initialized\n");
        return 0.0;
    }

    if (g->element_count < source || g->element_count < target)
    {
        printf("Source or Target is OutOfBounds!\n");
        return 0.0;
    }

    double value = *(*(g->adj_matrix + source) + target);
    return value;

    return 0.0;
}

/*
* Prints the graph in the stdout.
* @Param g: Pointer to graph_t struct.
*/
void print(graph_t *g)
{
    if (g == NULL || g->adj_matrix == NULL)
    {
        printf("Parameter g is not initialized\n");
        return;
    }
    int count = g->element_count;
    double **matrix = g->adj_matrix;

    printf("  \t");
    for (int i = 1; i < count; i++)
    {
        printf("%-3d\t", i);
    }
    printf("\n  ");
    for (int i = 1; i < count; i++)
    {
        printf("---------");
    }
    printf("\n");

    for (int i = 1; i < count; i++)
    {
        printf("%d|\t", i);
        for (int j = 1; j < count; j++)
        {
            double value = *(*(matrix + i) + j);
            if (value == 0.0)
                printf("   \t");
            else
                printf("%-3.1f\t", value);
        }
        printf(" |\n \n");
    }
    printf("  ");
    for (int i = 1; i < count; i++)
    {
        printf("---------");
    }
    printf("\n");
}

/*
* Returns the size (node count) of the passed graph.
* @Param g: Pointer to graph_t struct.
* @Return: Size of graph. 
*/
int get_size(graph_t *g)
{
    return g == NULL ? 0 : g->element_count;
}