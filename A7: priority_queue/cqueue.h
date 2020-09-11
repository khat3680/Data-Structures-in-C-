/*
-------------------------------------
Author:  Anshul Khatri
ID:      193313680
Email:   khat3680@mylaurier.ca
Version  2020-06-30
-------------------------------------
 */
#ifndef cQueue_ARRAY_H_
#define cQueue_ARRAY_H_

#include "data.h"

#define True 1
#define False 0
typedef struct {

	Data*array;		 // array contaning data items
	int rear;		//index of first item in cQueue
	int front;		//index of last itenm in cQueue
	int capacity;	//maximum cQueue length
	int size;
}cQueue;


cQueue* create_cqueue(int capacity);
int is_empty_cqueue(cQueue *q);
int len_cqueue(cQueue *q);
int is_full_cqueue(cQueue *q);
int insert_cqueue(cQueue *q, Data *d);
Data* peek_cqueue(cQueue *q);
Data* remove_cqueue(cQueue *q);
void destroy_cqueue(cQueue **q);
void print_cqueue(cQueue *q);
int get_capacity_cqueue(cQueue *q);



#endif /* cQueue_ARRAY_H_ */
