/*
-------------------------------------
Author:  Anshul Khatri
ID:      193313680
Email:   khat3680@mylaurier.ca
Version  2020-06-30
-------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "queue_array.h"

void adjust_queue(Queue*q);

Queue* create_queue(int capacity){
	Queue *q = (Queue*)malloc(sizeof(Queue));
	if(capacity < 1)
		{
			printf("Error(create_queue): invalid queue capacity, set to 10\n");
			capacity = 10;
		}

	q->capacity = capacity;
	q->array = (Data*)malloc(sizeof(Data)* capacity);
	q->front = -1;
	q->rear = -1;

	return q;

}

int is_empty_queue(Queue *q){
	assert(q!=NULL);
	return (len_queue(q) == 0);
	// return (q->front == -1)
}

int len_queue(Queue *q){
	assert(q!=NULL);
	if(q->front == -1)
		return 0;

	return q->rear - q->front +1 ;
}

int is_full_queue(Queue *q){

	assert(q!=NULL);
	return (len_queue(q) == q->capacity);

}

int insert_queue(Queue *q, Data *d){ // O(1) + O(adjust_queue) # worst case : O(n) # best case: O(1)
 	assert(q!=NULL && d!=NULL);
	if(is_full_queue(q))
	{
		printf("Error(insert_queue): queue is full\n");
		return False;
	}
	if(is_empty_queue(q))
		q->front = 0;
	else if(q->rear == q->capacity -1)
		adjust_queue(q);

	 q->rear++;
	 q->array[q->rear] = *copy_data(d);
	return True;
}

void adjust_queue(Queue*q){ // wrost case :O(n)
	assert(q!= NULL);
	int length = len_queue(q);
	for(int i =0;i<length;i++)

		q->array[i] = q->array[i + q->front];

	q->front =0;
	q->rear = length -1;
	return;
}


Data* peek_queue(Queue *q){    //O(1)
	assert(q!=NULL);
	if(is_empty_queue(q)) {
		printf("Error(peek_queue): Queue is empty\n");
		return NULL;
	}

	return copy_data(&q->array[q->front]);
}

Data* remove_queue(Queue *q){ //O(1)
	assert(q!=NULL);
	Data* d = NULL;
	if(is_empty_queue(q))
	{
		printf("Error(remove_queue): queue is empty\n");
		return d;
	}
	d = copy_data(&q->array[q->front]);
	Data *temp = &q->array[q->front];
	destroy_data(&temp);

	q->front++;

	if(len_queue(q) == 0){
		q->front = -1;
		q->rear = -1;
	}

	return d;
}

void destroy_queue(Queue **q){
	assert(q!=NULL);
	Data *d = NULL;
	while (!is_empty_queue(*q)){
		d = remove_queue(*q);
		destroy_data(&d);
	}
	free((*q)->array);
	(*q)->array = NULL;
	(*q)->capacity = 0;
	(*q)->front = 0;
	(*q)->rear = 0;
	free(*q);
	*q = NULL;
	return;
}

void print_queue(Queue *q){
	assert(q!= NULL);
	int i;
	printf("Capacity = %d, Size = %d, front = %d, rear = %d\n",q->capacity,len_queue(q),q->front,q->rear);
	if(is_empty_queue(q))
		printf("<empty_queue>\n");
	else {
		int counter = 0;
		for(i = q->front;i <= q->rear ;i ++ )
		{
			print_data(&q->array[i]);
			if((counter + 1 )%5 == 0 && counter != len_queue(q) - 1 )
				printf("\n");
			else
				printf("\t");
			counter++;
		}
		printf("\n");
	}
	return;
}

int get_capacity_queue(Queue *q){
	assert(q!=NULL);
	return q->capacity;
}
