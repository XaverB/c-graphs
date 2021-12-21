#include <stdlib.h>
#include <stdio.h>

#include "graph.h"
#include "graph_algs.h"

void build_demo_graph(graph_t *g) {
    printf("--- building demo graph with insert_edge ---\n");
    insert_edge(g, 1, 2, 1.2);
    insert_edge(g, 1, 6, 1.3);
    insert_edge(g, 2, 6, 5);
    insert_edge(g, 2, 3, 1.7);
    insert_edge(g, 3, 4, 11.1);
    insert_edge(g, 3, 5, 2.7);
    insert_edge(g, 4, 5, 7.2);
    insert_edge(g, 5, 6, 2.2);
    insert_edge(g, 6, 3, 3.1);
}

void test_remove_edge(graph_t *g) {
    printf("--- testing remove edge ---\n");
    // middle element
    remove_edge(g, 3,5);
    if(get_weight(g, 3,5) != 0.0) {
        printf("remove edge error!\n");
    }
    if(has_edge(g, 3,5)) {
        printf("remove edge error!\n");
    }

    // first element
    remove_edge(g, 1,2);
    if(get_weight(g, 1,2) != 0.0) {
        printf("remove edge error!\n");
    }
    if(has_edge(g, 1,2)) {
        printf("remove edge error!\n");
    }
}

void test_get_weight(graph_t *g) {
    int source, target;
    printf("--- testing get weigth valid ---\n");
    // check valid
    source = 1;
    target = 2;
    if(get_weight(g, source, target) != 1.2)
        printf("get_weight failed for source %d, target %d", source, target);

    source = 1;
    target =6;
    if(get_weight(g, source, target) != 1.3)
        printf("get_weight failed for source %d, target %d", source, target);

    source = 2;
    target = 6;
    if(get_weight(g, source, target) != 5)
        printf("get_weight failed for source %d, target %d", source, target);

    source = 2;
    target = 3;
    if(get_weight(g, source, target) != 1.7)
        printf("get_weight failed for source %d, target %d", source, target);

    source = 3;
    target = 4;
    if(get_weight(g, source, target) != 11.1)
        printf("get_weight failed for source %d, target %d", source, target);

    source = 3;
    target = 5;
    if(get_weight(g, source, target) != 2.7)
        printf("get_weight failed for source %d, target %d", source, target);

    source = 4;
    target = 5;
    if(get_weight(g, source, target) != 7.2)
        printf("get_weight failed for source %d, target %d", source, target);

    source = 5;
    target = 6;
    if(get_weight(g, source, target) != 2.2)
        printf("get_weight failed for source %d, target %d", source, target);

    source = 6;
    target = 3;
    if(get_weight(g, source, target) != 3.1)
        printf("get_weight failed for source %d, target %d", source, target);

    // check invalid
    printf("--- testing get weight invalid - expecting OutOfBounds message ---\n");
    source = 14;
    target = 100;
    if(get_weight(g, source, target) != 0.0) {
        printf("get_weight failed for source %d, target %d", source, target);
    }
    source = 10;
    target = 10;
    if(get_weight(g, source, target) != 0.0) {
        printf("get_weight failed for source %d, target %d", source, target);
    }
}

void test_get_edge(graph_t *g) {
    int source, target;
    printf("--- testing get edge valid ---\n");
    // check valid
    source = 1;
    target = 2;
    if(!has_edge(g, source, target))
        printf("has_edge failed for source %d, target %d", source, target);

    source = 1;
    target =6;
    if(!has_edge(g, source, target))
        printf("has_edge failed for source %d, target %d", source, target);

    source = 2;
    target = 6;
    if(!has_edge(g, source, target))
        printf("has_edge failed for source %d, target %d", source, target);

    source = 2;
    target = 3;
    if(!has_edge(g, source, target))
        printf("has_edge failed for source %d, target %d", source, target);

    source = 3;
    target = 4;
    if(!has_edge(g, source, target))
        printf("has_edge failed for source %d, target %d", source, target);

    source = 3;
    target = 5;
    if(!has_edge(g, source, target))
        printf("has_edge failed for source %d, target %d", source, target);

    source = 4;
    target = 5;
    if(!has_edge(g, source, target))
        printf("has_edge failed for source %d, target %d", source, target);

    source = 5;
    target = 6;
    if(!has_edge(g, source, target))
        printf("has_edge failed for source %d, target %d", source, target);

    source = 6;
    target = 3;
    if(!has_edge(g, source, target))
        printf("has_edge failed for source %d, target %d", source, target);

    // check invalid
    printf("--- testing get edge invalid - expecting OutOfBounds message ---\n");
    source = 14;
    target = 100;
    if(has_edge(g, source, target)) {
        printf("has_edge failed for source %d, target %d", source, target);
    }
    source = 10;
    target = 10;
    if(has_edge(g, source, target)) {
        printf("has_edge failed for source %d, target %d", source, target);
    }
}

void test_invert(graph_t* g) {
    printf("--- test invert ---\n");
    graph_t* inverted = graph_algs_invert(g);
    printf("Printing invert:\n");
    print(inverted);
    print_degree_histogram(inverted);
    printf("min: %d, max: %d, avg: %3.2f\n", min_degree(g), max_degree(g), avg_degree(g));
}

void test_histogram(graph_t* g) {
    printf("--- test histogram ---\n");
    print_degree_histogram(g);
    printf("min: %d, max: %d, avg: %3.2f\n", min_degree(g), max_degree(g), avg_degree(g));
}

int main(void) {
    graph_t *g = create(6);
    if(g == NULL)
        printf("Create FAILED\n");

    build_demo_graph(g);
    printf("--- printing graph ---\n");
    print(g);

    test_histogram(g);
    test_invert(g);

    test_get_edge(g);
    test_get_weight(g);
    test_remove_edge(g);
    
    destroy(g);
}