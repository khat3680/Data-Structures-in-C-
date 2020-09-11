/*
 * ---------------------------------
 * Student Name:
 * Student ID:
 * Student Email:
 * ---------------------------------
 */

#ifndef MIDTERM_H_
#define MIDTERM_H_

# define True 1
# define False 0
# define MAX 100

int* geometric_series(int n, int a, int r, FILE *destination);
void insert_item(int **array, const int size, int i, int value, int **max_ptr,
		FILE *destination);
void add_big_integers(char *num1, char *num2, char *result, FILE *destination);
void capitalize_words(FILE *source);

#endif /* MIDTERM_H_ */
