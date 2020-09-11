/*
-------------------------------------
Author:  Anshul Khatri
ID:      193313680
Email:   khat3680@mylaurier.ca
Version  2020-07-25
-------------------------------------
 */

#include	<stdio.h>
#include	<stdlib.h>
#include	<assert.h>
#include	"heap.h"

void heapify_up(Heap *h,int i);
void heapify_down(Heap *h,int i);

Heap* create_heap(int capacity){

	Heap *h = (Heap*)malloc(sizeof(Heap));
	if(capacity <= 0){
		printf("Error(create_heap): invalid capacity, capacity set to 1\n");
		h->capacity = 1;
	}
	else
		h->capacity = capacity;

	h->size = 0;
	h->array = (Data*)malloc(sizeof(Data)*h->capacity);


	return h;

}
void destroy_heap(Heap **h){

	assert(h && *h);

	while(!is_empty_heap(*h)){
		remove_heap(*h);
	}

	free((*h)->array);
	(*h)->array = NULL;
	(*h)->size  =0;
	(*h)->capacity = 0;
	free(*h);
	*h = NULL;


	return;

}

int is_empty_heap(Heap *h){
	assert(h != NULL);
	return (h->size == 0);
}


void insert_heap(Heap *h, Data *d){
	assert(h != NULL && d!= NULL);
	if(contains_heap(h,d)){
		printf("Error(insert_heap): cannot insert a duplicate\n");
		return;
	}

	// if heap is full --> expand memeory (double the size)
	if ( h->capacity == h->size){
		h->capacity = h->capacity * 2;
		h->array = realloc(h->array , sizeof(Data)*h->capacity);
	}

	h->array[h->size] = *copy_data(d);
	h->size++;
	heapify_up(h,h->size -1);

	return;
}

void heapify_up(Heap *h,int i){
	assert(h !=NULL);

	if (i <= 0)
		return;

	if(compare_data(&h->array[i],&h->array[Parent(i)]) == 1){
	swap_data(&h->array[i],&h->array[Parent(i)]);
	heapify_up(h,Parent(i));
	}
}
Data* peek_heap(Heap *h){
	assert(h != NULL);
	if(is_empty_heap(h)){
		printf("Error(peek_heap): heap is empty\n");
		return NULL;
	}
	return copy_data(&h->array[0]);
}

void remove_heap(Heap *h){
	assert(h);
	if(is_empty_heap(h)){
		printf("Error(remove_heap): Cannot delete from an empty heap\n");
		return ;
	}

	h->size--;
	//if less than 1/3 of heap is utilised --? shrink  capacity (1/2 capacnity)
	if ( h->size < h->capacity/3){
			h->capacity = h->capacity/2;
			h->array = realloc(h->array,sizeof(Data)*h->capacity);
		}


	h->array[0] = *copy_data(&h->array[h->size]);

	heapify_down(h,0);

	return ;
}

void heapify_down(Heap *h, int i){

	assert(h);
	// Base case if heap has single or empty --> no nned to heapify
	if (h->size <= 1)
		return;

	Data*  node = &h->array[i];
	Data*left = NULL,*right = NULL;
	if (Left(i) < h->size)
		left = &h->array[Left(i)];

	if (Right(i) < h->size)
		right = &h->array[Right(i)];

//	Base Case: if node has no children -->stop

	if(!left && !right)
		return;

	// only single child
	if(!right) { //left node only
		if(compare_data(left,node) == 1) {
			swap_data(left,node);
			heapify_down(h,Left(i));
			return;
		}
		else
			return;
	}

	//Note: not posible to have only right child
	//Two children

	//Case 1: left is the largest

	if(compare_data(left,node) == 1 && compare_data(left,right) == 1) {
		swap_data(node,left);
		heapify_down(h,Left(i));
		return;
	}

	//CAse2: right is the largest.

	if(compare_data(right,node) == 1 && compare_data(right,left) == 1){
		swap_data(node,right);
		heapify_down(h,Right(i));
		return;
	}

	//Case 3: node is the largest

	return;
}


int contains_heap(Heap *h, Data *d){
	assert(h != NULL && d != NULL);

	if(is_empty_heap(h))
		return False;

	for(int i =0;i < h->size;i++)
		if(compare_data(d,&h->array[i]) == 0)
			return True;


	return False;

}
void print_heap(Heap *h){
	assert(h != NULL);
	printf("heap Capacity = %d, size = %d\n",h->capacity,h->size);

	if(is_empty_heap(h)){
		printf("<empty heap>\n");
		return;
	}


	printf("[");
	for(int i =0;i < h->size -1 ;i++ )
	{
		print_data(&h->array[i]);
		printf(" , ");
	}
	printf("%d]\n",h->array[h->size -1]);
	return ;
}

/*
 * ----------------------------------------------------
 * Algorithm name:		Heap Sort
 *
 * Time Complexity:
 * 					Comparisons		Swaps
 * Worst Case:		O(log(n))		O(log n)
 * Best Case:		O(1)			O(1)
 * Average Case:	O(log n)		O(log n)
 *
 * Memory: O(n)
 *
 * ----------------------------------------------------
 */
void heap_sort(Data *array, const int size){

	Heap *h = create_heap(size);

	int i;
	for(i =0; i<size;i++)
		insert_heap(h,&array[i]);

	for(i =0;i <size;i++){
		array[i] = *peek_heap(h);
		remove_heap(h);
	}

	destroy_heap(&h);

	return;
}
