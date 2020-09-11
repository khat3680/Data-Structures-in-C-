/*
-------------------------------------
Author:  Anshul Khatri
ID:      193313680
Email:   khat3680@mylaurier.ca
Version  2020-06-30
-------------------------------------
 */
#ifndef Queue_ARRAY_H_
#define Queue_ARRAY_H_

#include "data.h"

#define True 1
#define False 0
typedef struct {

	Data*array;		 // array contaning data items
	int rear;		//index of first item in Queue
	int front;		//index of last itenm in Queue
	int capacity;	//maximum Queue length

}Queue;


Queue* create_queue(int capacity); int is_empty_queue(Queue *q);
int len_queue(Queue *q);
int is_full_queue(Queue *q);
int insert_queue(Queue *q, Data *d); Data* peek_queue(Queue *q);
Data* remove_queue(Queue *q);
void destroy_queue(Queue **q);
void print_queue(Queue *q);
int get_capacity_queue(Queue *q);



#endif /* Queue_ARRAY_H_ */
