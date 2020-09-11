/*
 -------------------------------------
 File:    graph.h
 Project: R_Tasks
 file description
 -------------------------------------
 Author:  Zhenyang Ding
 ID:      180947980
 Email:   ding7980@mylaurier.ca
 Version  2020-07-27
 -------------------------------------
 */

#include <stdio.h>
#ifndef GRAPH_H_
#define GRAPH_H_

#include "graph_components.h"

# define BLOCK 5
# define True 1
#define False 0

typedef struct {
	int **matrix; //adjacency matrix
	Vertex *vertex_list; //list to store vertices (labels)
	int vertex_count; //num of vertices
	int edge_count; //num of edges
	int directed; //flag: 0:undirected, 1:directed
	int weighted; //flag: 0:non-weighted, 1:weighted
} Graph;

Graph* create_graph(int w, int d);
void destroy_graph(Graph **g);
void print_graph(Graph *g);

//every null graph is empty but not other way around
int is_null_graph(Graph *g); //no vertices
int is_empty_graph(Graph *g); //no edges

int add_vertex_graph(Graph *g, Vertex *v);
int has_vertex_graph(Graph *g, Vertex *v);
int remove_vertex_graph(Graph *g, Vertex *v);

int add_edge_graph(Graph *g, Edge *e);
int has_edge_graph(Graph *g, Edge *e);
int remove_edge_graph(Graph *g, Edge *e);

#endif /* GRAPH_H_ */
