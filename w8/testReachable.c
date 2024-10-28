// testReachable.c
#include <stdio.h>
#include "Graph.h"
#include "Set.h"

Set reachable(Graph g, Vertex src);

void showEdges(Graph g) {
    printf("Graph edges:\n");
    for (int i = 0; i < numOfVertices(g); i++) {
        for (int j = 0; j < numOfVertices(g); j++) {
            if (adjacent(g, i, j)) {
                printf("%d -> %d\n", i, j);
            }
        }
    }
}

int main() {
    int nV = 5;
    Graph g = newGraph(nV);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 2, 0);
    addEdge(g, 2, 3);
    addEdge(g, 3, 3);
    // Add more edges if necessary

    printf("Graph:\n");
    showGraph(g);  // Shows adjacency lists

    // Optional: Show edges as pairs
    showEdges(g);

    Vertex src = 2;
    Set reach = reachable(g, src);
    printf("Vertices reachable from %d: ", src);
    SetShow(reach);

    disposeSet(reach);
    disposeGraph(g);

    return 0;
}
