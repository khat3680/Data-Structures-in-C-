/*
 * ---------------------------------
 * Student Name:Anshul Khatri
 * Student ID:193313680
 * Student Email:khat3680@mylaurier.ca
 * ---------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "A6.h"

void remove_shortest(Process *processes, const int size) {
	if (processes == NULL)
	{
		printf("Error(remove_shortest): given pointer is NULL\n");return;
	}
	if(size <=0)
	{
		printf("Error(remove_shortest): invalid array size\n");return;
	}
	//p.arrival,p.PID,p.time)
	Process min_temp ;
	min_temp.time = processes[0].time ;
	min_temp.arrival = processes[0].arrival;
	min_temp.PID = processes[0].PID ;
	int index;
	for(int i=0;i<size;i++)
	{
/////////////////////

		if(processes[i].time  < min_temp.time)
	{
			min_temp.time = processes[i].time ;
			min_temp.arrival = processes[i].arrival;
				min_temp.PID = processes[i].PID ;
		index = i;

	}
	else if(processes[i].time  == min_temp.time) {

		if(processes[i].arrival < min_temp.arrival)
		{
			min_temp.time = processes[i].time ;
			min_temp.arrival = processes[i].arrival;
			min_temp.PID = processes[i].PID ;
			index = i;
		}
		else if(processes[i].arrival ==  min_temp.arrival){

			if(processes[i].PID < min_temp.PID){
				min_temp.time = processes[i].time ;
				min_temp.arrival = processes[i].arrival;
				min_temp.PID = processes[i].PID ;
				index  =i;
			}
		}

	}

//////////////////
	}
	printf("Shortest Process is: %lu\n",min_temp.PID);
	for(int i= index; i <size -1;i++)	{

		processes[i] = processes[i+1];	}

	processes = realloc(processes,(size -1)*sizeof(Process));

	return;
}


void reverse_stack(Stack *s) {
	assert(s != NULL);

    int value = len_stack(s);
    Data *array = (Data*) malloc(sizeof(Data)*value);


    for(int i = 0; i < value; i++){
        array[i] = *pop_stack(s);
    }

    for(int k = 0; k < value; k++){
        push_stack(s,&array[k]);
    }
    free(array);
    return;
}
//p.arrival,p.PID,p.time
int is_equal_data(Data*d1,Data*d2) {
	int result = 0;

	if (d1->arrival == d2->arrival && d1->PID == d2->PID && d1->time == d2->time)
	{
		result = 1;
	}

	return result;
}

int contains_stack(Stack *s, Data *value) {

	if(s == NULL){

	printf("Error(contains_stack): invalid stack\n");
	return 0;
	}

	if(value == NULL){
		printf("Error(contains_stack): invalid data\n");
		return 0;
	}
	int size  = len_stack(s),result =0 ;
	Data *array = (Data*) malloc(sizeof(Data)*size);

	int i;
	for(i = 0; i < size; i++)	{
	        array[i] = *pop_stack(s);
	        result = is_equal_data(value,&array[i]);
	        if(result == 1)
	        	break;
	    }
	if (result != 1)
	{
	for(int k = 0; k < size; k++){

		push_stack(s,&array[k]);
	    }
	}

	else{
		for(int k = i+1; k < size; k++)	{
			array[k] = *pop_stack(s);
			    }
		for(int k = 0; k < size; k++){

				push_stack(s,&array[k]);
			    }

	}
	reverse_stack(s); // preserving order of stack.

	free(array);
	return result;
}

int resize_stack(Stack *s, int new_capacity) {

	if(s == NULL){

		printf("Error(contains_stack): invalid stack\n");
		return 0;
		}
	int result = 0;

	if(new_capacity <=0 )
	{
		printf("Error(resize_stack): invalid capacity size.\n");
		return 0;
	}
	if(new_capacity == len_stack(s))
	{
		return 0;
	}
	if (new_capacity > len_stack(s))
	{

		s->capacity = new_capacity; //not sure if we need to update top?

		result = 1;
	}
	if(new_capacity < len_stack(s)) {
		int i;

		int size = len_stack(s);

		for(i = size; i > new_capacity;i--)
		{
			pop_stack(s);
		}

		s->capacity = new_capacity;
		result = 1;
	}
	return result;
}


Stack* concat_stack(Stack *s1, Stack *s2) {

	int size_s2 = len_stack(s2), size_s1 = len_stack(s1);

	int value = size_s2 + size_s1;
	if (value < 1)
	{
		value +=1;
	}
	Stack *s3 = create_stack(value);

	Data *array_s1 = (Data*) malloc(sizeof(Data)*size_s1);
	Data *array_s2 = (Data*) malloc(sizeof(Data)*size_s2);
	if((s1 != NULL))
		reverse_stack(s1);

	if((s2 != NULL))
		reverse_stack(s2);

	 for(int i = 0; i < size_s1; i++)	{
		 	 array_s1[i] = *pop_stack(s1);
	        push_stack(s3,&array_s1[i]);
	    }

	 for(int k = 0; k < size_s2; k++) {

		 	array_s2[k] = *pop_stack(s2);
	        push_stack(s3,&array_s2[k]);
	    }
	 for(int i = 0; i < size_s1; i++)	{

		        push_stack(s1,&array_s1[i]);
		    }
	 for(int i = 0; i < size_s2; i++)	{

		        push_stack(s2,&array_s2[i]);
		    }

	 s3->capacity = s1->capacity + s2->capacity;

	 // Couldnt use free , system error # eclipse error.
	return s3;
}





