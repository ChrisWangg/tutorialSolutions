// Graph.c
#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

struct GraphRep {
    int **edges;
    int nV;
};

Graph newGraph(int nV) {
    Graph g = malloc(sizeof(struct GraphRep));
    g->nV = nV;
    g->edges = malloc(nV * sizeof(int *));
    for (int i = 0; i < nV; i++) {
        g->edges[i] = calloc(nV, sizeof(int));
    }
    return g;
}

void disposeGraph(Graph g) {
    for (int i = 0; i < g->nV; i++) {
        free(g->edges[i]);
    }
    free(g->edges);
    free(g);
}

void addEdge(Graph g, Vertex src, Vertex dest) {
    g->edges[src][dest] = 1;
    // For undirected graphs, uncomment the next line
    // g->edges[dest][src] = 1;
}

int adjacent(Graph g, Vertex src, Vertex dest) {
    return g->edges[src][dest];
}

void showGraph(Graph g) {
    printf("Graph representation (Adjacency Lists):\n");
    for (int i = 0; i < g->nV; i++) {
        printf("Vertex %d:", i);
        for (int j = 0; j < g->nV; j++) {
            if (g->edges[i][j]) {
                printf(" %d", j);
            }
        }
        printf("\n");
    }
}
int numOfVertices(Graph g) {
    return g->nV;
}