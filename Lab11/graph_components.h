/*
 -------------------------------------
 File:    graph_components.h
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
#ifndef GRAPH_COMPONENTS_H_
#define GRAPH_COMPONENTS_H_

#define True 1
#define False 0

typedef struct {
	int num; //a unique for the vertex
	char name[20];
} Vertex;

Vertex* create_vertex(int num, char *name);
void print_vertex(Vertex *v);
void destroy_vertex(Vertex **v);
int is_equal_vertex(Vertex *v1, Vertex *v2);

typedef struct {
	Vertex *v1; //1st vertex
	Vertex *v2; //2nd vertex
	int weight; //non-weighted graphs set to 0
	int directed; //undirected graphs set to 0
} Edge;

Edge* create_edge(Vertex *v1, Vertex *v2, int w, int d);
void print_edge(Edge *e);
void destroy_edge(Edge **e);
int is_equal_edge(Edge *e1, Edge *e2);

#endif /* GRAPH_COMPONENTS_H_ */
