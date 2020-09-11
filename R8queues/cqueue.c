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


#include "cqueue.h"

cQueue* create_cqueue(int capacity){
	cQueue *q = (cQueue*)malloc(sizeof(cQueue));
		if(capacity < 1)
			{
				printf("Error(create_queue): invalid cqueue capacity, set to 10\n");
				capacity = 10;
			}

		q->capacity = capacity;
		q->array = (Data*)malloc(sizeof(Data)* capacity);
		q->front = -1;
		q->rear = -1;
		q->size = 0;

		return q;

}

int len_cqueue(cQueue* q)  {
	assert(!q);
	return q->size;
}
int is_empty_cqueue(cQueue *q) {
	assert(!q);
	return (q->size == 0);
}
int is_full_cqueue(cQueue *q){
	assert(!q);
	return (q->size == q->capacity);
}
int insert_cqueue(cQueue *q, Data *d){
 	assert(!q && !d);
	if(is_full_cqueue(q))
	{
		printf("Error(insert_cqueue): cqueue is full\n");
		return False;
	}
	if(is_empty_cqueue(q))
		q->front++; // front =0 lab


	q->rear = (q->rear + 1) % q->capacity;
	q->array[q->rear] = *copy_data(d);
	q->size++;
	return True;
}

Data* peek_cqueue(cQueue *q){ //O(1)
	assert(q!=NULL);
	if(is_empty_cqueue(q)) {
		printf("Error(peek_cqueue): cQueue is empty\n");
		return NULL;
	}

	return copy_data(&q->array[q->front]);
}

Data* remove_cqueue(cQueue *q){
	assert(q!=NULL);
		Data* d = NULL;
		if(is_empty_cqueue(q))
		{
			printf("Error(remove_cqueue): cqueue is empty\n");
			return d;
		}
		d = copy_data(&q->array[q->front]);
		Data *temp = &q->array[q->front];
		destroy_data(&temp);


		q->front = (q->front +1) % q->capacity;
		q->size--;

		if(q->size == 0){
			q->front = -1;
			q->rear = -1;
		}


		return d;
}

void destroy_cqueue(cQueue **q){
	assert(q!=NULL);
	Data *d = NULL;
	while (!is_empty_cqueue(*q)){
		d = remove_cqueue(*q);
		destroy_data(&d);
	}
	free((*q)->array);
	(*q)->array = NULL;
	(*q)->capacity = 0;
	(*q)->front = 0;
	(*q)->rear = 0;
	(*q)->size = 0;
	free(*q);
	*q = NULL;
	return;
}


void print_cqueue(cQueue *q){
	assert(q!= NULL);
		int i;
		printf("Capacity = %d, Size = %d, front = %d, rear = %d\n",q->capacity,len_cqueue(q),q->front,q->rear);
		if(is_empty_cqueue(q))
			printf("<empty_cqueue>\n");
		else {
			int counter = 0;
			for(i = q->front;i != q->rear ;i = (i+1)%q->capacity)
			{
				print_data(&q->array[i]);

				if((counter + 1 )%5 == 0 && counter != len_cqueue(q) - 1 )
					printf("\n");
				else
					printf("\t");
				counter++;
			}
			printf("\n");	}
	return;

		}









