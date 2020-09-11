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


typedef int Data;

void print_data(Data *d);
void print_data_array(Data*array,const int size);
void destroy_data(Data **d);
Data* copy_data(Data *d);
void swap_data(Data*d1,Data*d2);
int compare_data(Data*d1,Data*d2);


#endif /* DATA_H_ */
