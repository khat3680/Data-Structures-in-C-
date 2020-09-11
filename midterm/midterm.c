/**
 * ---------------------------------
 * Student Name: Anshul Khatri
 * Student ID: 193313680
 * Student Email:khat3680@mylaurier.ca
 * ---------------------------------
 */

/**
 * ---------------------------------
 *
 * “I certify that I completed this midterm according to academic honesty guidelines.
 * I attest that I did not use any external help, neither in person nor virtually.
 * I understand that plagiarizing will lead to my failure in the course, in addition to other penalties according to the University policies”.
 *
 * ---------------------------------
 */

/**
 * ---------------------------------
 *
 * There are issues with inbuilt validator,however all the outputs match the required output files, when validated separately.
 *
 * ---------------------------------
 */
//---- Do not change imports -----------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "midterm.h"
//---------------------------------------------

//----------------- Task 1: Arrays ---------------------
int* geometric_series(int n, int a, int r, FILE *fptr) {

	if(n < 0)
	{
		fprintf(fptr,"Error(geometric_series): Invalueid valueue of n");
		return NULL;		}
	if(n ==0)
	{return NULL;	}

	int *array = (int*)malloc(n*sizeof(int));int i,sum=0;

	for(i=0;i<n;i++)
	{
		array[i] = a * pow(r,i);
		fprintf(fptr,"(%d)", (int)(a * pow(r,i)));

		if(i != n-1)
			fprintf(fptr," + ");

		sum += a*pow(r,i);
	}
	fprintf(fptr,"\n");

	fprintf(fptr,"Sum = %d\n",sum);

	return array;
}

//----------------- Task 2: Pointers ---------------------
void insert_item(int **array, const int size, int i, int valueue, int **max_ptr,
        FILE *destination) {


    if (i > size || i < 0 )
        fprintf(destination, "Error(insert_item): illegal valueue for i\n");


    else if (*max_ptr == NULL || *array == NULL)
        fprintf(destination, "Error(insert_item): invalueid pointer\n");


    else {
        int temp_array[size];

        for (int j = 0; j < size; j++)
            temp_array[j] = (*array)[j];

        free(*array);
        *array = (int*) malloc(sizeof(int) * (size + 1));

        for (int j = 0; j < i; j++)
            (*array)[j] = temp_array[j];


        (*array)[i] = valueue;

        for (int j = (i + 1); j < (size + 1); j++)
            (*array)[j] = temp_array[j - 1];

        if (valueue > **max_ptr)
            *max_ptr = &((*array)[i]);

    }
    return;
}

//----------------- Task 3: Strings ---------------------
void add_big_integers(char *num1, char *num2, char *result, FILE *destination) {

    if (strlen(num1) == 0 || strlen(num2) == 0) {
        fprintf(destination,
                "Error(add_big_integers): One of the numbers is void\n");
        return;    }

    if (strlen(num1) != strlen(num2)) {
        fprintf(destination, "Error(add_big_integers): Size Mismatch\n");
        return;    }

    int numbers = 0;
    long long k = (strtol(num1, NULL, 0) + strtol(num2, NULL, 0));
    long long value = k;


    while (value != 0) {
        value /= 10;
        numbers++;
    }

    if (numbers > strlen(num1))
        sprintf(result, "%lld", k);

    else
        sprintf(result, " %lld", k);

    return;
}
//----------------- Task 4: Files ---------------------
void capitalize_words(FILE *source) {

	char ch;
	    fscanf(source, "%c", &ch);
	    if (ch >= 'a' && ch <= 'z')
	    {
	        fseek(source, -1, 1);

	        fprintf(source, "%c", ch - 32);
	    }

	    while (ch != EOF) {

	        if (isspace(ch) || ch == '\n') {

	            ch = fgetc(source);
	            if (ch >= 'a' && ch <= 'z') {

	                fseek(source, -1, 1);
	                fprintf(source, "%c", ch - 32);
	            }

	        }
	        else
	        {
	            ch = fgetc(source);
	        }
	    }
	return;
}

