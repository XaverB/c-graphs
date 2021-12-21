#include "graph_algs.h"
#include <stdio.h>
#include <stdlib.h>

/*
* Creates a new, inverted graph
* @Param g: Pointer to graph_t struct.
* @Return: Inverted graph
*/ 
graph_t* graph_algs_invert(graph_t *g){
    int count = get_size(g);
    // -1 because we do not count the zero in this lib for nicer adresses
    graph_t *invert = create(count-1);

    for(int i = 1; i < count; i++) {
        for(int j = 1; j < count; j++) {
            bool hasEdge = has_edge(g, i, j);
            if(!hasEdge)
                continue;
            double weight = get_weight(g, i, j);
            insert_edge(invert, j, i, weight);
        }
    }
    return invert;
}

/*
* Determines the min degree of a passed graph.
* @Param g: Pointer to graph_t struct.
* @Return: minimum degree
*/ 
int min_degree(graph_t *g){
    int count = get_size(g);
    if(count == 0)
        return 0;

    int min = __INT_MAX__; // some high init value

    for(int i = 1; i < count; i++) {
        int current_degrees = 0;
        for(int j = 1; j < count; j++) {  
            bool hasEdge = has_edge(g, i, j);
            if(!hasEdge)
                continue;
            current_degrees++;
        }
        // we found new min!
        if(current_degrees < min)
            min = current_degrees;
    }

    return min;
}

/*
* Determines the max degree of a passed graph.
* @Param g: Pointer to graph_t struct.
* @Return: maximum degree
*/ 
int max_degree(graph_t *g){
    int count = get_size(g);
    if(count == 0)
        return 0;

    int max = 0;

    for(int i = 1; i < count; i++) {
        int current_degrees = 0;
        for(int j = 1; j < count; j++) {  
            bool hasEdge = has_edge(g, i, j);
            if(!hasEdge)
                continue;
            current_degrees++;
        }
        // we found new min!
        if(current_degrees > max)
            max = current_degrees;
    }

    return max;
}

/*
* Determines the avg degree of a passed graph.
* @Param g: Pointer to graph_t struct.
* @Return: average degree
*/ 
double avg_degree(graph_t *g){
    int count = get_size(g);
    if(count == 0)
        return 0.0;

    double average = 0.0;

    for(int i = 1; i < count; i++) {
        for(int j = 1; j < count; j++) {  
            bool hasEdge = has_edge(g, i, j);
            if(!hasEdge)
                continue;
            average++;
        }
    }

    average /= (double) count;
    return average;
}

/*
* Prints a histogram of the passed struct to the stdout.
* @Param g: Pointer to graph_t struct.
*/ 
void print_degree_histogram(graph_t *g){
    int count = get_size(g);
    if(count == 0)
        return;

    int *degrees;
    degrees = (int*)malloc(sizeof(int) * count);
    

    for(int i = 1; i < count; i++) {
        for(int j = 1; j < count; j++) {  
            bool hasEdge = has_edge(g, i, j);
            if(!hasEdge)
                continue;
            degrees[i]++;
        }
    }

    printf("\n---------Histogramm----------\n");
    for(int i = 1; i < count; i++) {
        printf("%d: ", i);
        for(int j = 0; j < degrees[i]; j++) {
            printf("|||");
        }
        printf("\n-----------------------------\n");
    }
}

