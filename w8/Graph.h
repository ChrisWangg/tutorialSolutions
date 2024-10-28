// Graph.h
#ifndef GRAPH_H
#define GRAPH_H

typedef int Vertex;

typedef struct GraphRep *Graph;

/**
 * Creates a new graph with a specified number of vertices.
 *
 * @param nV The number of vertices in the graph.
 * @return A new Graph instance.
 */
Graph newGraph(int nV);

/**
 * Frees all memory associated with the graph.
 *
 * @param g The graph to dispose of.
 */
void disposeGraph(Graph g);

/**
 * Adds an edge from the source vertex to the destination vertex.
 *
 * @param g The graph to which the edge will be added.
 * @param src The source vertex of the edge.
 * @param dest The destination vertex of the edge.
 */
void addEdge(Graph g, Vertex src, Vertex dest);

/**
 * Checks if there is an edge from the source vertex to the destination vertex.
 *
 * @param g The graph to check.
 * @param src The source vertex.
 * @param dest The destination vertex.
 * @return 1 if an edge exists from src to dest, 0 otherwise.
 */
int adjacent(Graph g, Vertex src, Vertex dest);

/**
 * Displays the graph's structure in a readable format.
 *
 * @param g The graph to display.
 */
void showGraph(Graph g);

/**
 * Retrieves the number of vertices in the graph.
 *
 * @param g The graph whose vertex count is to be retrieved.
 * @return The number of vertices in the graph.
 */
int numOfVertices(Graph g);

#endif
