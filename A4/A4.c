/*
 * ---------------------------------
 * Student Name:Anshul Khatri
 * Student ID:193313680
 * Student Email:khat3680@mylaurier.ca
 * ---------------------------------
 */

#include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <math.h>
# include <stdlib.h>
# include "A4.h"

//-------------------------Task 1 ----------------------------

void format_city(char *city) {
	int j=0;

	city[0] = toupper(city[0]);

		while(!isspace(city[j])){
			j++;

		}

	city[j+1] = toupper(city[j+1]);

	while(j+1<=MAX-1)
	{
		city[j] = city[j+1];
		j++;
	}

	return;


}

void format_cities(char city_array[][MAX], const int size) {
	if(size <=0 )

	{printf("Error(format_cities): invalid size\n");
		return;
	}
	if(!city_array)
		{printf("Error(format_cities): array is NULL\n");
		return;}
	for(int i=0;i<size;i++)
	{
	format_city(city_array[i]);}
	return;
}

//-------------------------Task 2 ----------------------------

void format_str(const char *inStr, char *outStr) {
	int i=0;

	for(i=0;i<( 2 * MAX);i++)
	{
		if(isalpha(inStr[i]))
		{

		}
		else {
			break;
		}
	}
	int size = i;
	printf("	String Length = %d\n",size);
	outStr = (char *)malloc(sizeof(char)*(size+1));

	for(i=0;i<size;i++)
	{	if(i!=0 && i != size-1)
	{
		strcpy(&outStr[i],&inStr[i]);
		outStr[i] = toupper(outStr[i]);}
	else{
		strcpy(&outStr[i],&inStr[i]);
	}
	}
	i=0;
	printf("\tAfter middle caps = ");
	while(i<size)	{

		printf("%c",outStr[i]);

		i++; }printf("\n");

	//split
		if(size ==1 )
		{
			printf("\tAfter split = %c\n",outStr[0]);
		}
		else if(size == 0)
		{
			printf("\tAfter split = \n");
		}
		else{
			printf("{%lu}",sizeof(outStr));
			char *temp = (char *)realloc(outStr,sizeof(char)*(size+2));
			outStr = temp;
				int pos = size/2;
				printf("%lu\n",sizeof(outStr));
				for(int i = size; i >= pos; i--)
					outStr[i+1] =outStr[i];


				strcpy(&outStr[pos], " ");

				printf("\tAfter split = ");
				for(i=0;i<size+1;i++)
					printf("%c",outStr[i]);
				printf("\n");

		}

	return;
}

//-------------------------Task 3 ----------------------------

int* get_multiples_array1(int *multiples, const int size) {

	if(!multiples)
	{
		printf("Error(get_multiples_array1): invalid array\n");
		return multiples;
	}
	if(size <= 0){
		printf("Error(get_multiples_array1): invalid size\n");
		return multiples;

	}

	int *arr = (int*)malloc(size * NUM *(sizeof(int)));
	int i,j;

	for(i=0;i<size;i++)
	{
		for(j=0;j<NUM;j++)
		{	if ((j+1) * (multiples[i]) < 1000)	{
			*(arr + i*NUM + j) = (j+1) * (multiples[i]);


			}

		else {
			*(arr + i*NUM + j) =0;
		}

		}

	}

	return arr;
}

void print_multiples1(int *array, const int size) {
	if(!array)
		{
			printf("Error(print_multiples1): invalid array\n");
			return;
		}
		if(size <= 0){
			printf("Error(print_multiples1): invalid size\n");
			return;
		}
		int i,j;
		for(i=0;i<size;i++)
			{
				for(j=0;j<NUM;j++)
				{
					printf("%3d ",*(array + i*NUM + j));
				}
			printf("\n");}

	return;
}

//-------------------------Task 4 ----------------------------
int** get_multiples_array2(int *multiples, const int size) {
	if(!multiples)
		{
			printf("Error(get_multiples_array2): invalid array\n");
			return 0;
		}
		if(size <= 0){
			printf("Error(get_multiples_array2): invalid size\n");
			return 0;

		}
		int **arr = (int **)malloc(size* sizeof(int *));
		int i,j;

		    for (i=0; i<size; i++)
		         arr[i] = (int *)malloc(NUM * sizeof(int));

		    // Note that arr[i][j] is same as *(*(arr+i)+j)

		 for(i=0;i<size;i++)
		 {
			 for(j=0;j<NUM;j++)
			 {	if ((j+1) * (multiples[i]) < 1000)	{
					arr[i][j] = (j+1) * (multiples[i]);

					}

				else {
					arr[i][j] =0;
				}

			 }
		 }
	return arr;
}

void print_multiples2(int **array, const int size) {
	if(!array)
			{
				printf("Error(print_multiples2): invalid array\n");
				return ;
			}
			if(size <= 0){
				printf("Error(print_multiples2): invalid size\n");
				return;

			}
			int i,j;
					for(i=0;i<size;i++)
						{
							for(j=0;j<NUM;j++)
							{
								printf("%3d ",array[i][j]);
							}
						printf("\n");
						}

	return;
}
