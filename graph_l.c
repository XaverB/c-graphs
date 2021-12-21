#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct vertex {
    int v; // target vertex
    double w; // edge weight
    struct vertex *next;
} vertex_t;

typedef struct graph {
    int element_count;
    vertex_t *adj_list; // array of vertex nodes
} graph_t;

/*
* Creates a new graph_t struct with 1 to n nodes and returns a pointer to it.
* @Param n: Count of nodes to create.
*/
graph_t* create(int n) {
    n += 1;
    
    // get memory for struct
    graph_t *g = malloc(sizeof(graph_t));
    if(g == NULL) {
        printf("No memory available for graph_t\n");
    }
    
    g->element_count = n;

    g->adj_list = malloc(n * sizeof(vertex_t));
    if(g->adj_list == NULL) {
        printf("No memory available for vertex list\n");
    }

    for(int i = 0; i < n; i++) {
        g->adj_list[i].w = 0.0;
        g->adj_list[i].v = 0;
        g->adj_list[i].next = NULL;
    }
    return g;
}


/*
* Destroys a graph_t struct.
* @Param g: Pointer to graph_t struct.
*/
void destroy(graph_t *g){
    // free list entries
    for(int i = 1; i < g->element_count; i++) {
        vertex_t* node = NULL;
        node = g->adj_list->next;

        while(node != NULL) {
            vertex_t* next = node->next;
            free(node);
            node = next;
        }
    } 

    // free array
    free(g->adj_list);
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
void insert_edge(graph_t *g, int source, int target, double weight){
    if(g == NULL || g->adj_list == NULL) {
        printf("Parameter g is not initialized\n");
        return;
    }

    if(g->element_count <= source || g->element_count <= target) {
        printf("Source or Target is OutOfBounds!\n");
        return;
    }

    vertex_t *node, *prev; 
    node = &g->adj_list[source];    


    while(node != NULL && node->v != target && node->v != 0) {
        prev = node;
        node = node->next;
    }
    // edge exists => update weight
    if(node != NULL) {
        node->w = weight;
        node->v = target;
    } else {
        // new node
        vertex_t *new = malloc(sizeof(vertex_t));
        new->v = target;
        new->w = weight;
        new->next = NULL;
        prev->next = new;
    }

}

/*
* Removes a edge.
* Prints a message on the stdout if IndexOutOfBound or NullReference error occurs.
* @Param g: Pointer to graph_t struct.
* @Param source: Id of source node
* @Param target: Id of target node
* @Param weight: Weight for edge source to target
*/
void remove_edge(graph_t *g, int source, int target){
    if(g == NULL || g->adj_list == NULL) {
        printf("Parameter g is not initialized\n");
        return;
    }

    if(g->element_count < source || g->element_count < target) {
        printf("Source or Target is OutOfBounds!\n");
        return;
    }

    vertex_t *prev, *node;
    prev = node = &g->adj_list[source];

    // find the desired target
    while(node != NULL && node->v != target) {
        node = node->next; 
        prev = node;
    }

    // node not found
    if(node == NULL)
        return;

    // first element 
    if(prev == &g->adj_list[source]) {
        // first element has successor
        if(node->next != NULL) {
            node->v = node->next->v;
            node->w = node->next->w;
            node->next = node->next->next;
            free(node->next);

            // first element does not have a successor
        } else {
            node->v = 0;
            node->w = 0.0;
        }

        // last element
    } else if(node->next == NULL) {
        prev->next = NULL;
        free(node);

        // middle element
    } else {
        prev->next = node->next;
        free(node);
    }
}

/*
* Checks if a edge exists.
* Prints a message on the stdout if IndexOutOfBound or NullReference error occurs.
* @Param g: Pointer to graph_t struct.
* @Param source: Id of source node
* @Param target: Id of target node
* @Return: True if edge source -> target exists, else false.
*/
bool has_edge(graph_t *g, int source, int target) {
    if(g == NULL || g->adj_list == NULL) {
        printf("Parameter g is not initialized\n");
        return false;
    }

    if(g->element_count < source || g->element_count < target) {
        printf("Source or Target is OutOfBounds!\n");
        return false;
    }

    vertex_t *node;
    node = &g->adj_list[source];

    while(node != NULL && node->v != target) {
        node = node->next;
    }

    return node != NULL && node->v == target;
}

/*
* Gets the weight of a specific edge.
* Prints a message on the stdout if IndexOutOfBound or NullReference error occurs.
* @Param g: Pointer to graph_t struct.
* @Param source: Id of source node
* @Param target: Id of target node
* @Return: Weight of edge source -> target
*/
double get_weight(graph_t *g, int source, int target){
    if(g == NULL || g->adj_list == NULL)
        printf("Parameter g is not initialized\n");

    if(g->element_count < source || g->element_count < target)
        printf("Source or Target is OutOfBounds!\n");

    vertex_t *node = &g->adj_list[source];

    while(node != NULL && node->v != target) {
        node = node->next;
    }

    return (node != NULL && node->v == target) ? node->w : 0.0;
}

/*
* Prints the graph in the stdout.
* @Param g: Pointer to graph_t struct.
*/
void print(graph_t *g) {
    if(g == NULL || g->adj_list == NULL) {
        printf("Parameter g is not initialized\n");
        return;
    }

    for(int i = 1; i < g->element_count; i++) {
        vertex_t *node = &g->adj_list[i];

        printf("%d : ", i);
        while(node != NULL) {
            printf("-(%3.1f)-> %d\t", node->w, node->v);
            node = node->next;
        }
        printf("\n\n");

    }
}

/*
* Returns the size (node count) of the passed graph.
* @Param g: Pointer to graph_t struct.
* @Return: Size of graph. 
*/
int get_size(graph_t *g) {
    return g == NULL ? 0 : g->element_count;
}