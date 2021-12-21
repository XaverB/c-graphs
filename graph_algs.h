#ifndef GRAPH_ALGS_H
#define GRAPH_ALGS_H

#include "graph.h"

/*
* Creates a new, inverted graph
* @Param g: Pointer to graph_t struct.
* @Return: Inverted graph
*/ 
graph_t* graph_algs_invert(graph_t *g);

/*
* Determines the min degree of a passed graph.
* @Param g: Pointer to graph_t struct.
* @Return: minimum degree
*/ 
int min_degree(graph_t *g);

/*
* Determines the max degree of a passed graph.
* @Param g: Pointer to graph_t struct.
* @Return: maximum degree
*/ 
int max_degree(graph_t *g);

/*
* Determines the avg degree of a passed graph.
* @Param g: Pointer to graph_t struct.
* @Return: average degree
*/ 
double avg_degree(graph_t *g);

/*
* Prints a histogram of the passed struct to the stdout.
* @Param g: Pointer to graph_t struct.
*/ 
void print_degree_histogram(graph_t *g);

#endif