/*
-------------------------------------
Author:  Anshul Khatri
ID:      193313680
Email:   khat3680@mylaurier.ca
Version  2020-07-14
-------------------------------------
 */
#ifndef LIST_H_
#define LIST_H_
#include "data.h"
#define True 1
#define False 0

typedef struct linkedListNode{
	Data* data;
	struct linkedListNode *next;

}Node;


Node* create_node(Data *d, Node *n);
void destroy_node(Node **n);
void print_node(Node *n);
Node* copy_node(Node *n);


typedef struct{
	Node *head;	//pointer to the head node
	int size; 	//number of nodes in linked list

}List;

//Unsorted,Ordered,Indexed Linked List

List* create_list();
int is_empty_list(List *list);
void print_list(List *list);
void append_list(List *list, Data *d);
void insert_front_list(List *list, Data *d);
Data* get_data_list(List *list, int index);
Node* get_node_list(List *list, int index);
void destroy_list(List **list);
Data* remove_rear_list(List *list);
void reverse_list(List *list);
List* array_to_list(Data *array, const int size);


#endif /* LIST_H_ */
