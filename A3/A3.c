/**
 * -------------------------
 * Student Name:Anshul Khatri
 * Student ID:193313680
 * Student email:khat3680@mylaurier.ca
 * -------------------------
 */

# include <stdio.h>
#include<math.h>
# include "A3.h"

/**
 * -------------------------------------------------------------------
 * Parameters:
 * 	  array: a pointer to an array of integers (int*)
 * 	  size: size of an array (const int)
 * returns:
 * 	  last: pointer to last element that is sandwiched between its multiples (int*)
 * Description:
 *    Searches for a number that is sandwiched between its multiples
 *    If multiple numbers exist, then a pointer to the last one is returned.
 *    prints an error message and returns a NULL pointer if array pointer is NULL
 *    	or given size is non-positive
 * -------------------------------------------------------------------
 */
int* sandwich(int *array, const int size) {
	if (size <= 0)
	{
		printf("Error(sandwich): Invalid array size\n");
		return NULL;
	}

	if(array == NULL)
	{
		printf("Error(sandwich): Input array is NULL\n");
		return NULL;
	}

	int *result = NULL,i;

	for(i =1;i<size-1;i++) {

		if ((array[i-1] % array[i]==0) && (array[i+1] % array[i]==0)) { // doubt2

			result = &array[i];


		}

	}

	return result;
}

/**
 * -------------------------------------------------------------------
 * Parameters:
 * 		array: a generic pointer to an array (void*)
 * 		size: size of an array (const int)
 * 		mode: character representing array type (char)67
 * 				'C' --> character array
 * 				'L' --> integer array
 * 				'D' --> double array
 * returns:
 * 		None
 * Description:
 *    Prints contents of an array with formatting depending on printing mode
 *    Mode 1: chars "StringAppearHere"
 *    Mode 2: long { v1 , v2 , v3 , ... }
 *    Mode 3: double { v1.000 , v2.000 , v3.000 , ... }
 *    If size is <= 0 for any type --> print { }
 *    if invalid mode --> print error
 * -------------------------------------------------------------------
 */
void print_array(void *arrayPtr, const int size, char mode) {

	if (size <0)
	{
		printf("Error(print_array): Invalid array size\n");
		return;
	}

	if(arrayPtr == NULL)

	{
		printf("Error(print_array): Input array is NULL\n  ");
		return;

	}

	if (size ==0)
	{
		printf("{ }\n");
	}
	else {


	int i;

	if(mode=='L')
	{
		printf("{ ");
				for (i=0;i<size;i++)
				{
				if(i==size-1)
				{
					printf("%ld ", (((long*)arrayPtr)[i] ));
				}
				else {

				printf("%ld , ", (((long*)arrayPtr)[i] )); }
				}

				printf("}");
				printf("\n");

	}

	else if(mode=='D')
	{
		printf("{ ");
						for (i=0;i<size;i++)
						{
						if(i==size-1)
						{
							printf("%.3lf ", (((double*)arrayPtr)[i] ));
						}
						else {

						printf("%.3lf , ", (((double*)arrayPtr)[i] )); }
						}

						printf("}\n");


	}

	else if(mode == 'C')
	{	printf("\"");
		for (i=0;i<size;i++)
		{

		printf("%c", (((char*)arrayPtr)[i] ));
		}
		printf("\"\n");
	}

	else
	{
		printf("Error(print_array): unsupported mode\n");

	}
	}

	return;
}

/**
 * -------------------------------------------------------------------
 * Parameters:
 * 	  array: a pointer to an array of integers (int*)
 * 	  size: size of an array (const int)
 * returns:
 * 	  ptr: pointer to the element that is equal or closest to average (int*)
 * Description:
 *    1- Finds the average of the values within the array and print it to the console.
 *    2- The average is �ceiled�, i.e. rounded to the upper integer value.
 *    3- Search the array for an element that is equal to the average,
 *      and return a pointer to that element.
 *    4- If there are multiple values equal to the average, a pointer to the
 *      first element that equals to average is returned.
 *    5- If no value is equal to the average, a pointer to the value
 *      closest to the average is returned.
 *    6- prints an error message and returns a NULL pointer if array pointer is NULL
 *    	or given size is non-positive
 * -------------------------------------------------------------------
 */
int* find_avg_element(int *array, const int size) {
	if (size <=0)
		{
			printf("Error (find_avg_element): Invalid array size\n");
			return NULL;
		}

	if(array == NULL)

	{
		printf("Error (find_avg_element): NULL pointer\n");
		return NULL;

	}

	int i,*result = NULL;
	float sum =0,average=0;

	for(i =0;i<size;i++)
	{
		sum = sum + array[i];
	}
	average = sum/size;

	printf("Average = %.1f\n",(average));
	int closest = array[0];
	for(i=0;i<size;i++)
	{
		if(ceil(average) - array[i] == 0)
		{
			result = &array[i];
			break;

		}
		else if (fabs(average - closest) == fabs(average - array[i]) && size==2)
				{
					closest = array[0];
					result = &array[0];

				}

		else if (fabs(average - closest) > fabs(average - array[i]) )
		{
			closest = array[i];
			result = &array[i];

		}


	}


	return result;
}

/**
 * -------------------------------------------------------------------
 * Parameters:
 * 	  array: a pointer to an array of long integers (long*)
 * 	  ptrs: an array of long pointers (long* [])
 * returns:
 * 	  No reutrns
 * Description:
 *    The pointer array stores some pointers to elements in the array
 *    Access the pointer array to print the following:
 *    1-	The index of that element in the array
 *    2-	The value of the element it points to
 *    3-	The value of the previous element
 *    4-	The value of the next element
 *    The maximum size for the pointer array is MAX, and the last item is NULL.
 * -------------------------------------------------------------------
 */
void print_ptr_array(long *array, long *ptrs[]) {
	int i,j,value = (int)NULL;

	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		{
			if(array[i] == array[j] && (i!=j))
			{
				value = array[j];
				break;


			}

		}
		if(value!=(int)NULL)
		{
			break;
		}
	}

	j=0;
	for(i=0;i<MAX;i++)
	{

		if(value == array[i])
		{
			ptrs[j] = (long *)&array[i];
			ptrs[j+1] = (long *)NULL;
			j++;
		}

	}
	printf("%-13s","ArrayIndex");printf("%-13s","Previous");printf("%-13s","Current");printf("%-13s","Next");
	printf("\n");

	for(i=0;i<MAX;i++)
	{
		if(ptrs[i] == (long*)NULL)
			 {break; }


		printf("%-13ld",ptrs[i] - array);// array index


		if ((ptrs[i] - array) == 0)			//previous
			 {printf("%-13s","-1");		}

		else {
			printf("%-13ld",*(ptrs[i]-1)); }//


		printf("%-13ld",*ptrs[i]); //current


		if (ptrs[i] - array  == MAX -1)//next
			{
			printf("%-13s","-1");}

		else {
				printf("%-13ld",*(ptrs[i] +1));  }//

		printf("\n");

	}


	return;
}
