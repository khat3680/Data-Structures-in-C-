/*
 * ---------------------------------
 * Student Name:Anshul Khatri
 * Student ID:193313680
 * Student Email:khat3680@mylaurier.ca
 * ---------------------------------
 */

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <assert.h>
#include "list.h"

//---------------- Node Implementation ------------------------

Node* create_node(Data *d, Node *n) {
	assert(d != NULL);
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = copy_data(d);
	node->next = n;
	return node;
}

void print_node(Node *n) {
	assert(n!= NULL);
	print_data(n->data);
	return;
}

Node* copy_node(Node *n) {
	assert(n != NULL);

	return create_node(n->data,n->next);
}

void destroy_node(Node **n) {
	assert( n != NULL && *n != NULL);
	//destroy_data(&(*n)->data);
	(*n)->data = NULL;
	(*n)->next = NULL;
	free(*n);

	return;
}

//---------------- Linked List Implementation ------------------------

List* create_list() {
	List* list = (List*)malloc(sizeof(List));
	list->head = NULL;
	list->size  =0;
	return list;
}

int is_empty_list(List *list) {
	assert(list != NULL);
	return ( list->head == NULL) ;
}

void print_list(List *list) {
	assert(list);

	Node *current_node = list->head;
	if(list->size == 0)
	{
		printf("NULL\n");
		return;
	}
	while(current_node != NULL){
		print_node(current_node);
		printf("-->");
		current_node = current_node->next;

	}
	if(current_node == NULL)
		printf("NULL");

	printf("\n");

	return;
}
//5-->10-->6-->NULL
void append_list(List *list, Data *d) {
	assert(list && d!= NULL);

	Node* new_node = create_node(d,NULL);

	if(is_empty_list(list))
		list->head = new_node;
	else {

		Node *current_node = list->head;

		while(current_node->next != NULL)
			current_node = current_node->next;

		current_node->next = new_node;

	}
	list->size ++;
	return;
}

void insert_front_list(List *list, Data *d) {
	assert(list && d!= NULL);

	Node* new_node = create_node(d,list->head);
	list->head = new_node;
	list->size++;
	return;
}

Data* get_data_list(List *list, int index) {
	assert(list);
	return get_node_list(list,index)->data;

}

//Return a copy of node not a reference to the node;

Node* get_node_list(List *list, int index) {
	assert(list);


		Node *current_node = list->head;
		if(index < 0 || index >= list->size)
		{
			printf("Error(get_node_list): index out of range\n");
			return NULL;
		}
		int i = 0;
		while(i < index && current_node != NULL){
				current_node = current_node->next;
				i++;

			}

		return copy_node(current_node);
}

void destroy_list(List **list) {

	while(!is_empty_list(*list))
		remove_rear_list(*list);

	(*list)->head = NULL;
	(*list)->size  = 0;
	free(*list);
	*list = NULL;

	return;
}

Data* remove_rear_list(List *list) {
	assert(list );

	if(is_empty_list(list)){
		printf("Error(remove_rear_list): list is empty\n");
		return NULL;
	}

	Node* previous = NULL;
	Node* current = list->head;

	while(current->next != NULL){
		previous = current;
		current = current->next;

		}
	Data*item = copy_data(current->data);

	if(list->size == 1)
		list->head = NULL;

	else
		previous->next = NULL;


	destroy_node(&current);
	list->size--;
	return item;
}

void reverse_list(List *list) {
	assert(list != NULL);

	if(is_empty_list(list))
		return; // do nothing

	Node* previous_node,*current_node,*next_node;
	previous_node = NULL;
	current_node = list->head;
	next_node = current_node->next;

	while(current_node->next != NULL){

		current_node->next = previous_node;
		previous_node = current_node;
		current_node  = next_node;
		next_node  = next_node->next;

	}
	current_node->next = previous_node;
	list->head = current_node;

	return;
}

List* array_to_list(Data *array, const int size) {
	assert(array);
	List * list =  NULL;

	if(size <= 0)
	{
		printf("Error(array_to_list): invalid array size\n");
		return list;
	}

	list = create_list();

	for(int i =0 ;i <size;i++)
		append_list(list,&array[i]);

	return list;
}

