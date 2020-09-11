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
#include <stdlib.h>

void print_data(Data *d){
	printf("%d",*d);
	return;
}
void print_data_array(Data*array,const int size){

	assert(array);
	assert(size >=1);

	int i;
	printf("[");
	for(i=0;i < size ; i++)
	{
		printf("%d",array[i]);
		if (i!=size -1)
			printf(",");

	}
	printf("]\n");
	return;
}
void destroy_data(Data **d){
	assert(*d!= NULL && d != NULL);
	free(*d);
	*d = NULL;
	return;
}

Data* copy_data(Data *d1){
	assert(d1!= NULL);
	int *d2 = (int*)malloc(sizeof(int));
	*d2 = *d1;

	return (d2);
}


void swap_data(Data* d1,Data* d2) {
	assert(d1 && d2);
	Data temp  = *d1;
	*d1 = *d2;
	*d2 = temp;
	return;
}

int compare_data(Data *d1, Data *d2){
	assert(d1 && d2);
	if(*d1 > *d2)
		return 1;

	if(*d1 < *d2)
		return 2;

	return 0;
}
