// reachable.c
#include "Graph.h"
#include "Set.h"

static void dfs(Graph g, Vertex v, Set visited);

Set reachable(Graph g, Vertex src) {
    Set visited = newSet(numOfVertices(g));
    dfs(g, src, visited);
    return visited;
}

static void dfs(Graph g, Vertex v, Set visited) {
    SetInsert(visited, v);
    for (int w = 0; w < numOfVertices(g); w++) {
        if (adjacent(g, v, w) && !SetMember(visited, w)) {
            dfs(g, w, visited);
        }
    }
}

