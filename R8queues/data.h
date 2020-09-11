/*
-------------------------------------
Author:  Anshul Khatri
ID:      193313680
Email:   khat3680@mylaurier.ca
Version  2020-06-25
-------------------------------------
 */
#ifndef DATA_H_
#define DATA_H_

#include "process.h"

typedef Process Data;

void print_data(Data *d);
void destroy_data(Data **d);
Data* copy_data(Data *d);


#endif /* DATA_H_ */
