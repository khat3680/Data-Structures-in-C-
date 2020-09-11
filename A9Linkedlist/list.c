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
#include <stdbool.h>
# include "list.h"

/**
 * ------------------------------------------------------------
 * Parameters: 	d - a data item (Data*)
 * 				n - pointer to next node (Node*)
 * Returns: 	new node (Node*)
 * Description:	Creates a new node using the given data
 * Asserts:		data is not NULL
 * ------------------------------------------------------------
 */
Node* create_node(Data *d, Node *n) {
	assert(d);
	Node *node = (Node*) malloc(sizeof(Node));
	node->data = copy_data(d);
	node->next = n;
	return node;
}

/**
 * -------------------------------------------------------
 * Parameters: 	a node (Node*)
 * Returns: 	none
 * Description:	prints the contents of a node
 * 				invokes print_data
 * 				does not print next pointer
 * Assert:		n is not NULL
 * -------------------------------------------------------
 */
void print_node(Node *n) {
	assert(n);
	print_data(n->data);
	return;
}

/**
 * --------------------------------------------------------
 * Parameters: 	a node (Node*)
 * Returns: 	a copy node (Node*)
 * Description:	Creates a copy of the given node
 * 				The new copy has a copy version of the data
 * 				the next pointer points to the same node as the original node's next
 * Assert:		given node is not NULL
 * --------------------------------------------------------
 */
Node* copy_node(Node *n) {
	assert(n);
	return create_node(n->data, n->next);
}

/**
 * ---------------------------------------------------
 * Parameters:  a node (Node**)
 * Returns: 	none
 * Description:	destroys a node by:
 * 				- destroy the encompassed data
 * 				- setting next to NULL
 * 				- free the node pointer
 * Assert:		n and *n are not NULL
 * --------------------------------------------------
 */
void destroy_node(Node **n) {
	assert(n && *n);
	destroy_data(&(*n)->data);
	(*n)->data = NULL;
	(*n)->next = NULL;
	free(*n);
	return;
}

//-----------------------------------------------------------
/**
 * Parameters: 	None
 * Returns: 	A pointer to linked list (List*)
 * Description:	Creates an empty linked list
 * 				head is set to NULL and size to 0
 * 				Returns a pointer to the newly created linked list
 * -----------------------------------------------------------
 */
List* create_list() {
	List *list = (List*) malloc(sizeof(List));
	list->head = NULL;
	list->size = 0;
	return list;
}

/**
 * -------------------------------------------------------------------
 * Parameters: 	Pointer to a linked list (List*)
 * Returns: 	None
 * Description:	traverse through all nodes
 * 				uses print_node(Node*) to print contents of nodes
 * 				starting from list head to tail
 * 				node1-->node2-->node3-->...-->NULL
 * 				prints <NULL> if empty list
 * Assert:		list is not NULL
 * -------------------------------------------------------------------
 */
void print_list(List *list) {
	assert(list);
	Node *current_node = list->head;
	while (current_node != NULL) {
		print_node(current_node);
		printf("-->");
		current_node = current_node->next;
	}
	printf("NULL\n");
	return;
}

/**
 * ---------------------------------------------------------------
 * Parameters: 	A linked list (List*)
 * 				A data item (Data*)
 * Returns: 	None
 * Description:	appends the given data item to the tail of the linked list
 * 				updates size and may update head
 * Assert		list and d are not NULL
 * ---------------------------------------------------
 */
void append_list(List *list, Data *d) {
	assert(list && d);
	Node *new_node = create_node(d, NULL);
	if (list->head == NULL)
		list->head = new_node;
	else {
		Node *current_node = list->head;
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = new_node;
	}
	list->size++;
	return;
}

/**
 * ---------------------------------------------------------------
 * Parameters: 	a linked list (List**)
 * Returns: 	None
 * Description:	Destroys a given linked list
 * 				Deletes all nodes (which takes care of destroying data)
 * 				set head to NULL and size to 0
 * 				free list pointer
 * Assert:		**list and *list are is not Null
 * ---------------------------------------------------------------
 */
void destroy_list(List **list) {
	assert(list && *list);
	//while ((*list)->size > 0)
		//pop_list(*list, 0);
	//(*list)->head = NULL;
	//(*list)->size = 0;
	//free(*list);
	return;
}

//------------------------- Assignment -------------------------
/**
 * -------------------------------------------------------------------------
 * Parameters: 	a linked list (List*)
 * 				a data item (Data*)
 * 				an index (int)
 * Returns: 	True/False
 * Description:	Inserts the given data item at position (index) at the linked list
 * 				if given index is out of range --> print an error and return NULL
 * 				returns True if insertion is successful, False otherwise
 * Assert:		given array and data pointers are not Null
 * -------------------------------------------------------------------------
 */

//[1](1000010001,10)-->NULL
//[1](1000010001,10)-->[2](1000010002,20)-->NULL
int insert_list(List *list, Data *d, int index) {

	assert(list != NULL && d != NULL);

	if(index < 0 || index > list->size)
	{
		printf("Error(insert_list): index out of range\n");
		return (int)NULL;
	}
	Node * new_node  = create_node(d,NULL);
	Node *current = list ->head;

	if(index == 0)
	{
		new_node->next = current;
		list->head = new_node;
		list->size++;

		return True;
	}

	if( index > list->size - 1){

		append_list(list, d);
		return True;}

	int i = 0;

	Node *previous = NULL;

	while( i < index)
	{
		previous = current;
		current = current->next;
		i++;
	}
	if (i == index)
	{	new_node = create_node(d,current);
		previous->next = new_node;
	}

	list->size++;
	return True;
}

/**
 * -----------------------------------------------------------------
 * Parameters: 	list - a linked list (List*)
 * 				i - an index (int)
 * Returns: 	True/False
 * Description:	deletes the node at position (index) at the linked list
 * 				A copy of the data in the removed node is returned.
 * 				if given index is out of range --> print an error and return NULL
 * 				if given linked list is empty --> print an error and return NULL
 * Asserts:		given linked list is not NULL
 * ------------------------------------------------------------------
 */
Data* pop_list(List *list, int index) {
	assert(list != NULL);

	if (index == 0 && list->head == NULL)
	{
		printf("Error(pop_list): list is empty\n");
		return NULL;
	}

	if(index < 0 || index >= list->size )
	{
		printf("Error(pop_list): index out of range\n");
		return NULL;
	}

	if( list->head == NULL && list->size == 0)
	{
		printf("Error(pop_list): list is empty\n");
		return NULL;
	}

	Node *previous = NULL;
	Node * current = list->head;
	Data *deleted_item = NULL;


	if (list->size == 1)
	{
		list->head = NULL;
		list->size = 0;
		return copy_data(current->data);
	}

	if (index == 0){
		list->head = current->next;
		current->next = NULL;
		list->size--;
		return copy_data(current->data);

	}
	else if(index == list->size -1)
	{
		int i =0;
		while( i < index)
			{
				previous = current;
				current = current->next;
				i++;
			}
		if (i == index) {


		deleted_item = current->data;
		current = previous;
		current->next = NULL;
		list->size--;

		}
		previous = list->head;
		i =0;
		while( i!= (list->size -2)){
			i++;
			previous = previous->next;
		}

		return deleted_item;
	}

	else {
		int i =0;
		while( i < index)
			{
			previous = current;
			current = current->next;
			i++;
			}
		if (i == index) {
				deleted_item = current->data;
				previous->next = current->next;
				current = current->next;
				list->size--;

				}
	}


	return deleted_item;
}

/**
 * ---------------------------------------------------------------------
 * Parameters: 	a linked List (List*)
 * 				start index (int)
 * 				end index  (int)
 * Returns: 	None
 * Description:	deletes items from the list from index start to end (inclusive both ends)
 * 				Updates head and size as necessary
 * 				if given list is empty, print error and return
 *				if given start or end indices are out of range --> print error msg and return
 * Assert:		linked list is not NULL
 * ---------------------------------------------------------------------
 */
void cut_list(List *list, int start, int end) {

	assert(list != NULL);

	if (list->head == NULL){
		printf("Error(cut_list): Linked List is empty\n");
		return ;
	}
	if((start < 0 || start >= list->size))
		{
			printf("Error(cut_list): Invalid start index\n");
			return ;
		}
	if(end < 0 || end >= list->size){

		printf("Error(cut_list): Invalid end index\n");
		return;
	}
	if (start > end){
		printf("Error(cut_list): Invalid end index\n");
		return;
	}

	if((end - start + 1) == list->size){
			list->head = NULL;
			list->size = 0;
			return ;
		}


	Node* previous = NULL;
	Node* current = list->head;



	if (start == end){
		int i =0;
		while( i < start)
			{
			previous = current;
			current = current->next;
			i++;
			}
		if (i == start) {
			previous->next = current->next;
			current = current->next;


			}

		previous->next = current;

	}

	else {
		int i =0;
		while( i < start)
		{
			previous = current;
			current = current->next;
			i++;
		}

		Node *curr_end = current;
		Node *prev_end = NULL;

		while ( i < end){
			prev_end = curr_end;
			curr_end = curr_end->next;
			i++;
					}

		if (start == 0 ){
			list->head = curr_end->next;
		}

		previous->next = curr_end->next;


	}


	list->size -= (end - start + 1);
	return;
}

/**
 * ---------------------------------------------------------------------
 * Parameters: 	a linked list (List*)
 * 				start index (int)
 * 				end index  (int)
 * Returns: 	a linkedList (List*)
 * Description:	Constructs and returns a new linked list.
 * 				The new list contains elements from start to end (inclusive both ends)
 * 				if list is empty, print error msg and return empty list
 * 				if start/end is out of scope, print error msg and return empty list
 * 				Check if end index is greater than or requal to start index
 * Asserts:		list is not NULL
 * ---------------------------------------------------------------------
 */
List* sub_list(List *list, int start, int end) {

	assert(list != NULL);

	List * new_list = create_list();

	if (list->head == NULL){
						printf("Error(sub_list): Linked list is empty\n");
						return new_list;
					}


		if(start < 0 || start >= list->size)
			{
				printf("Error(sub_list): Invalid start index\n");

				return new_list;

			}
		if(end < 0 || end >= list->size){

			printf("Error(sub_list): Invalid end index\n");

			return new_list;
		}
		if (start > end){
			printf("Error(sub_list): Invalid end index\n");

			return new_list;		}


		if((end - start + 1) == list->size){
				new_list->head = list->head;
				new_list->size = list->size;
				return new_list;
			}

		Node* previous = NULL;
		Node* current = list->head;

		if (start == end){
			int i =0;
			while( i < start)
				{
				previous = current;
				current = current->next;
				i++;
				}

			append_list(new_list,current->data);

		}
		else {

			int i =0;
			while( i < start)
					{
						previous = current;
						current = current->next;
						i++;
					}
			while(i <= end ){

				append_list(new_list,current->data);
				previous = current;
				current = current->next;
				i++;

				}


		}



	return new_list;
}

/**
 * ---------------------------------------------------------------------
 * Parameters: 	a pointer to a linked list (List*)
 * 				i - index of first item (int)
 * 				j - index of second item (int)
 * Returns: 	None
 * Description:	swaps items i and j in the list
 * 				if invalid i and j, print error msg and return
 * Asserts:		asserts given linked list is not Null
 * ---------------------------------------------------------------------
 */
void swap_list(List *list, int i, int j) {
	    assert(list);

	    if (list->head == NULL) {
	        printf("Error(swap_list): list is empty\n");
	        return;
	    }

	    if (i < 0 || j < 0 || i >= list->size || j >= list->size) {
	        printf("Error (swap_list): Invalid value of i or j\n");
	        return;
	    }


	    Node *first = list->head;
	    Node *swaped = NULL;
	    int val1 = 0;


	    while (val1 < i) {
	        swaped = first;
	        first = first->next;
	        val1++;
	    }


	    Node *curr_1 = list->head;
	    Node *swaped_1 = NULL;
	    int val2 = 0;


	    while (val2 < j) {
	        swaped_1 = curr_1;
	        curr_1 = curr_1->next;
	        val2++;
	    }


	    if (swaped != NULL)
	        swaped->next = curr_1;
	    else
	        list->head = curr_1;


	    if (swaped_1 != NULL)

	        swaped_1->next = first;
	    else

	        list->head = first;

	    Node *short_val = NULL;
	    short_val = curr_1->next;
	    curr_1->next = first->next;
	    first->next = short_val;


	    return;
	}
/**
 * ---------------------------------------------------------------------
 * Parameters: 	first linked list (List*)
 * 				second linked list (List*)
 * Returns: 	new list (List*)
 * Description:	Creates a new list that contains items which appear in both lists
 * 				No duplicates allowed
 * Assert:		both linked lists are not NULL
 * ---------------------------------------------------------------------
 */

/**
 * ---------------------------------------------------------------------
 * Parameters: 	linked list (List*)
 * Returns: 	1 if item found in list, -1 if not found(int)
 * Description:	Looks for the item in the list
 * ---------------------------------------------------------------------
 */
int find (List * list, Data* item) {


	Node * current = list->head;

	while (current != NULL)

	{
	if(compare_data(current->data,item)==0)
			break;

	current = current->next;

	}
	int result =0 ;
	if (current != NULL)
		result = 1;
	else
		result = -1;
	return result;

}
List* intersection_list(List *list1, List *list2) {
	assert(list1 != NULL);
	assert(list2 != NULL);

	List * new_list = create_list();


	if(list1->head == NULL || list2->head == NULL){
		return new_list;
	}

	Node * current = list1->head;
	Node * current_2 = list2->head;


	if(list1->size == 1 && list2->size == 1)
		{

		if(current_2->data != current->data)
		{	return new_list;}
		}

	while (current != NULL){

		if (find(list2,current->data) == 1)
		{

			append_list(new_list,(current->data));
		}
		current = current->next;
	}


	return new_list;
}
