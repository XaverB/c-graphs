#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

struct graph_t;
typedef struct graph graph_t;

/*
* Creates a new graph_t struct with 1 to n nodes and returns a pointer to it.
* @Param n: Count of nodes to create.
*/
graph_t* create(int n);

/*
* Destroys a graph_t struct.
* @Param g: Pointer to graph_t struct.
*/
void destroy(graph_t *g);


/*
* Inserts a new edge to the graph_t struct.
* Prints a message on the stdout if IndexOutOfBound or NullReference error occurs.
* @Param g: Pointer to graph_t struct.
* @Param source: Id of source node
* @Param target: Id of target node
* @Param weight: Weight for edge source to target
*/
void insert_edge(graph_t *g, int source, int target, double weight);

/*
* Removes a edge.
* Prints a message on the stdout if IndexOutOfBound or NullReference error occurs.
* @Param g: Pointer to graph_t struct.
* @Param source: Id of source node
* @Param target: Id of target node
* @Param weight: Weight for edge source to target
*/
void remove_edge(graph_t *g, int source, int target);

/*
* Checks if a edge exists.
* Prints a message on the stdout if IndexOutOfBound or NullReference error occurs.
* @Param g: Pointer to graph_t struct.
* @Param source: Id of source node
* @Param target: Id of target node
* @Return: True if edge source -> target exists, else false.
*/
bool has_edge(graph_t *g, int source, int target);

/*
* Gets the weight of a specific edge.
* Prints a message on the stdout if IndexOutOfBound or NullReference error occurs.
* @Param g: Pointer to graph_t struct.
* @Param source: Id of source node
* @Param target: Id of target node
* @Return: Weight of edge source -> target
*/
double get_weight(graph_t *g, int source, int target);

/*
* Prints the graph in the stdout.
* @Param g: Pointer to graph_t struct.
*/
void print(graph_t *g);

/*
* Returns the size (node count) of the passed graph.
* @Param g: Pointer to graph_t struct.
* @Return: Size of graph. 
*/
int get_size(graph_t *);

#endif