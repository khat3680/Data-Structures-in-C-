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

void print_data(Data *d){
	print_process(d);
	return;
}

void destroy_data(Data **d){
	//destroy_process(d);
	return;
}

Data* copy_data(Data *d){
	return copy_process(d);
}

