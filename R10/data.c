/*
-------------------------------------
Author:  Anshul Khatri
ID:      193313680
Email:   khat3680@mylaurier.ca
Version  2020-06-25
-------------------------------------
 */

#include "data.h"
#include <stdio.h>
#include <assert.h>

void print_data(Data *d){
	print_process(d);
	return;
}
void print_data_array(Data*array,const int size){

	assert(array);
	assert(size >=1);

	int i;
	for(i=0;i<size; i++)
	{
		print_process(&array[i]);
		if (i!=size -1)
			printf(",");

	}
	return;
}
void destroy_data(Data **d){
	//destroy_process(d);
	return;
}

Data* copy_data(Data *d){
	return copy_process(d);
}


void swap_data(Data* d1,Data*d2) {
	assert(d1 && d2);
	Data temp  = *d1;
	*d1 = *d2;
	*d2 = temp;
	return;
}

int compare_data(Data *d1, Data *d2){

	if (d1->arrival > d2->arrival)
		return 1;

	else if(d1->arrival <  d2->arrival)
		return 2;

	else if(d1->arrival == d2->arrival)
	{
		if(d1->time > d2->time)
			return 1;

		else if(d1->time < d2->time)
			return 2;

		else if(d1->time == d2->time)
		{
			if (d1->PID > d2->PID)
				return 1;

			else if(d1->PID < d2->PID)
				return 2;

			else if(d1->PID == d2->PID)
				return 0;
		}

	}

	return  -1;
}
