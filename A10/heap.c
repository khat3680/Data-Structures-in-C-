/*
 * ---------------------------------
 * Student Name: Anshul Khatri
 * Student ID: 193313680
 * Student Email:khat3680@mylaurier.ca
 * ---------------------------------
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>
# include <math.h>
# include "heap.h"
# include "queue_array.h"
# include "stack_array.h"

Node* find_node_heap_aux(Node *n, Data *d);
int contains_heap_aux(Heap *h, Node *n, Data *d);
int is_full_heap_aux(Node *root);

//------------------------ A10 Task 1 -------------------------
/**
 * ------------------------------------------------------------
 * Parameters: 	d - 	a data item (Data*)
 * 				parent- pointer to parent (Node*)
 * 				left - 	pointer to left child (Node*)
 * 				right - pointer to right child (Node*)
 * Returns: 	node -	new heap node (Node*)
 * Description:	Creates a new heap node using the given data and pointers
 * Asserts:		data is not NULL
 * ------------------------------------------------------------
 */
Node* create_node(Data *d, Node *parent, Node *left, Node *right) {
	assert(d != NULL);

	Node *n = (Node*)malloc(sizeof(Node));
	n->data = copy_data(d);

	n->parent = parent;
	n->left = left;
	n->right = right;

	return n;
}


/**
 * -------------------------------------------------------
 * Parameters: 	n - a node (Node*)
 * Returns: 	none
 * Description:	prints the contents of a heap node
 * 				invokes print_data, does not print parent, left and right
 * 				if node is NULL prints <NULL Node>
 * Assert:		None
 * -------------------------------------------------------
 */
void print_node(Node *n) {

	if (n == NULL){
		printf("<NULL Node>");
		return;
	}
	print_data(n->data);
	return;
}

/**
 * --------------------------------------------------------
 * Parameters: 	n - 	a node (Node*)
 * Returns: 	n2 -	a copy node (Node*)
 * Description:	Creates a copy of the given heap node
 * 				The new node has a duplicate copy of data and
 * 				same parent, left and right child
 * Assert:		given node is not NULL
 * --------------------------------------------------------
 */
Node* copy_node(Node *n) {
	assert(n != NULL);
	Node* n2 = (Node*)malloc(sizeof(Node));

	n2->data = copy_data(n->data);
	n2->parent = n->parent;
	n2->left = n->left;
	n2->right = n->right;

	return n2;
}

/**
 * ---------------------------------------------------
 * Parameters:  n - a node (Node**)
 * Returns: 	none
 * Description:	destroys a heap node by:
 * 				- destroy the encompassed data
 * 				- setting parent, left and right to NULL
 * 				- free the node pointer, and set it to NULL
 * Assert:		n and *n are not NULL
 * --------------------------------------------------
 */
void destroy_node(Node **n) {
	assert(n != NULL && *n!= NULL);

	(*n)->left = NULL;
	(*n)->right = NULL;
	(*n)->parent = NULL;

	destroy_data(&(*n)->data);
	free(*n);
	*n = NULL;

	return;
}

//------------------------ A10 Task 2 -------------------------

/**
 * ------------------------------------------------------------
 * Parameters: 	type - heap type (max or min) (char*)
 * Returns: 	h - new heap (Heap*)
 * Description:	Creates a new heap of given type
 * 				Heap root is set to NULL and size to 0
 * 				if type is not "max" or "min" print error msg, set to "max"
 * Asserts:		none
 * ------------------------------------------------------------
 */
Heap* create_heap(char *type) {

	Heap *h = (Heap*)malloc(sizeof(Heap));
	h->size =0;
	h->root = NULL;

	if((strcmp("max",type)!=0) && (strcmp(type,"min")!=0))
	{
		printf("Error(create_heap): invalid type, set to max\n");
		strcpy(h->type,"max");
	}

	else
		strcpy(h->type,type);

	return h;
}

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap**)
 * Returns: 	none
 * Description:	destroys a heap by:
 * 				- removing all items
 * 				- setting root to NULL and size to 0 and type to empty string
 * 				- free the heap pointer, and set it to NULL
 * Assert:		h and *h are not NULL
 * --------------------------------------------------
 */
void destroy_heap(Heap **h) {

	assert(h && *h);

		while(!is_empty_heap(*h)){
			remove_heap(*h);
		}

		free((*h)->root);
		(*h)->root = NULL;
		(*h)->size  =0;
		strcpy((*h)->type,"");
		free(*h);
		*h = NULL;

	return;
}

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * Returns: 	True/False
 * Description:	check if heap is empty
 * Assert:		h is not NULL
 * --------------------------------------------------
 */
int is_empty_heap(Heap *h) {
	assert(h != NULL);
	return (h->size == 0);

}

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * Returns: 	copy of data at the heap root
 * Description:	Returns a duplicate copy of the data item at the root
 * 				if heap is empty prints error msg, returns NULL
 * Assert:		h is not NULL
 * --------------------------------------------------
 */
Data* peek_heap(Heap *h) {
	assert(h != NULL);
		if(is_empty_heap(h)){
			printf("Error(peek_heap): heap is empty\n");
			return NULL;
		}
		return copy_data(h->root->data);

}

//------------------------ A10 Task 3 -------------------------

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * 				d - a data item (Data*)
 * Returns: 	pointer to a node
 * Description:	Returns a pointer to the node that contains given data
 * 				if not found returns NULL
 * Assert:		h and are not NULL
 * --------------------------------------------------
 */


Node* find_node_heap(Heap *h, Data *d) {

	assert(h!= NULL && d!= NULL);
	Node *n = NULL;
	n = find_node_heap_aux(h->root, d);
	 return n;
	}


/**
 * ---------------------------------------------------
 * Parameters:  n - a node (Node*)
 * Returns: 	a pointer to  a node
 * Description:	private helper function for find_node_heap
 * 				Uses recursion.
 * 				Search through given node and recurse to other nodes
 * Assert:		None
 * --------------------------------------------------
 */
Node* find_node_heap_aux(Node *n, Data *d) {
	 if (n == NULL)
		 return NULL;
	 Node *temp;

	 if (compare_data(n->data, d) == 0)
		 return n;

	 temp = find_node_heap_aux(n->left, d);

	if (temp)
		return temp;
	else
		return find_node_heap_aux(n->right,d);
}

//------------------------ A10 Task 4 -------------------------

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * Returns: 	None
 * Description:	Prints contents of a heap
 * 				if heap is empty prints <empty heap>
 * 				if heap is NULL prints <NULL Heap>
 * 				prints type and size of heap, then prints items in levelorder
 * 				Uses a queue.
 * 				items are separated by a space
 * Asserts:		None
 * --------------------------------------------------
 */
void print_heap(Heap *h) {

	if (h == NULL){
			printf("<NULL Heap>\n");
			return;
		}

	printf("heap type = %s, size = %d\n",h->type,h->size);

	if(is_empty_heap(h)){
		printf("<empty heap>\n");
		return;
	}




	return;
}

//------------------------ A10 Task 5 -------------------------

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * 				d - data to search for (Data*)
 * Returns: 	True/False
 * Description:	Check if a heap contains a data item
 * 				recurse through all nodes to check
 * 					if any node contains the data
 * 				returns True if found and False otherwise
 * Asserts:		h and d are not NULL
 * --------------------------------------------------
 */
int contains_heap(Heap *h, Data *d) {

	assert(h != NULL && d!= NULL);

	return 	contains_heap_aux(h,h->root,d)
;
}

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * 				n - current node to check if it contains the data (Node*)
 * 				d - data to search for (Data*)
 * Returns: 	True/False
 * Description:	Private helper function for contains_heap
 * 				recurse through all nodes to check if node contains data
 * 				returns True if found and False otherwise
 * Asserts:		None
 * --------------------------------------------------
 */
int contains_heap_aux(Heap *h, Node *n, Data *d) {

	 if (h->root == NULL)
	        return 0;

	    if (compare_data(h->root -> data, n->data)==0)
	        return True;

	    int result = contains_heap_aux(h,h->root->left,d);
	    if (result != False)
	        return result;

	    result  = contains_heap_aux(h,h->root->right,d);
	    return result;

	return 0;
}
//------------------------ A10 Task 6 -------------------------

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * 				start - a node for starting the search, normally the root (Node*)
 * 				node - the node to search for its level (Node*)
 * 				level - keeps track for level so far (int)
 * Returns: 	node_level - level of "node" in the heap (int)
 * Description:	Private helper method. Uses recursion.
 * 				Finds the level of a given node in a heap
 * 				if not found returns -1
 * Asserts:		heap is not NULL
 * --------------------------------------------------
 */
int find_node_level_heap_aux(Node *start, Node *node, int level) {


    if (start == NULL)
        return 0;

    if (compare_data(start -> data, node->data)==0)
        return level;


    int downlevel = find_node_level_heap_aux(start->left, node ,level+1);
    if (downlevel != 0)
        return downlevel;

    downlevel  = find_node_level_heap_aux(start->right, node ,level+1);

    return downlevel;

}

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * 				node - the node to search for its level (Node*)
 * Returns: 	node_level - level of "node" in the heap (int)
 * Description:	Finds the level of a given node in a heap
 * 				if not found returns -1
 * 				Root is assumed to be at level 1
 * Asserts:		heap is not NULL
 * --------------------------------------------------
 */
int find_node_level_heap(Heap *h, Node *node) {
	assert(h != NULL);

	int k = find_node_level_heap_aux(h->root,node,1);

	return k;
}

//------------------------ A10 Task 7 -------------------------

/**
 * ---------------------------------------------------
 * Parameters:  root - pointer to root node (Node*)
 * Returns: 	True/False
 * Description:	A private helper function for is_full_heap function
 * 				Uses recursion
 * 				Returns True if heap is full and False otherwise
 * Asserts:		heap is not None
 * --------------------------------------------------
 */
int is_full_heap_aux(Node *root) {
	//your code here
	return 0;
}

/**
 * ---------------------------------------------------
 * Parameters:  h - pointer to a heap (Heap*)
 * Returns: 	True/False
 * Description:	Returns True if heap is full and False otherwise
 * 				A full heap is a heap in which each node has 0 or 2 children
 * 				An empty heap is considered a full heap
 * Asserts:		heap is not None
 * --------------------------------------------------
 */
int is_full_heap(Heap *h) {
	//your code here
	return 0;
}

//------------------------ A10 Task 8 -------------------------
/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * Returns: 	d - copy of data with max data
 * Description:	Returns a duplicate copy of maximum item in heap
 * 				steps are different depending on max/min heap
 * 				if heap is empty, print error msg and return NULL
 * Asserts:		heap is not None
 * --------------------------------------------------
 */
Node* find_max_heap_aux(Node *current, Node *node) {

    Node *res;
    if (compare_data(node->data, current->data) == 2) {
        res = current;
    } else
        res = node;

    if (current->left)
        res = find_max_heap_aux(current->left, res);
    if (compare_data(res->data, res->data) == 1)
        return copy_node(res);

    if (current->right)
        res = find_max_heap_aux(current->right, res);
    if (compare_data(res->data, res->data) == 1)
        return copy_node(res);

    return copy_node(res);
}

Data *find_max_heap(Heap *h) {
    assert(h);

    if (strcmp(h->type, "max") == 0) {
        if (h->size == 0) {
            printf("Error(find_max_heap): empty heap\n");
            return NULL;
        } else {
            return copy_data(h->root->data);
        }
    }
    Node *res = (Node*) malloc(sizeof(Node));

    if (strcmp(h->type, "min") == 0) {
        if (h->size == 0) {
            printf("Error(find_max_heap): empty heap\n");
            return NULL;
        }
        Node *current = h->root;
        res = find_max_heap_aux(current, h->root);

    }

    return copy_data(res->data);
}

/**
 * ---------------------------------------------------
 * Parameters:  h - a heap (Heap*)
 * Returns: 	d - copy of data with min data
 * Description:	Returns a duplicate copy of minimum item in heap
 * 				steps are different depending on max/min heap
 * 				if heap is empty, print error msg and return NULL
 * Asserts:		heap is not None
 * --------------------------------------------------
 */
Data* find_min_heap(Heap *h) {
	//your code here
	return NULL;
}

//------------------------ Do not change these -------------------------
void insert_heap(Heap *h, Data *d) {
	return;
}

void remove_heap(Heap *h) {
	return;
}
