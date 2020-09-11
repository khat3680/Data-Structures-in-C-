#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "midterm.h"

void test_geometric_series();
void test_insert_item();
void test_add_big_integers();
void test_capitalize_words();

void wipe_files();
void generate_my_output();
void copy_file2(const char *in_file, const char *out_file);
void validate_all();
void validate(char *file1, char *file2, int task);

void initializeArray(int *array, const int valueArray[], int size);
void printArray(int *array, const int size, FILE *destination);

int main() {
	setbuf(stdout, NULL);

	wipe_files();

	test_geometric_series();
	test_insert_item();
	test_add_big_integers();
	test_capitalize_words();

	generate_my_output();
	validate_all();

	return 0;
}
//------------------ Task 1: Arrays  -----------------------

void test_geometric_series() {
	FILE *fptr = fopen("task1.txt", "w");
	if (!fptr) {
		printf("Error(test_geometric_series): Could not open file task1.txt\n");
		return;
	}
	fprintf(fptr, "------------------------------\n");
	fprintf(fptr, "Start: Testing geometric_series:\n\n");
	int n, a, r;
	int *series = NULL;

	fprintf(fptr, "Case 0: Invalid value of n:\n");
	n = -2;
	a = 1;
	r = 2;
	fprintf(fptr, "Geometric Series (n = %d, a = %d, r = %d):\n", n, a, r);
	series = geometric_series(n, a, r, fptr);
	fprintf(fptr, "\n\n");

	fprintf(fptr, "Case 1: Empty Series:\n");
	n = 0;
	fprintf(fptr, "Geometric Series (n = %d, a = %d, r = %d):\n", n, a, r);
	series = geometric_series(n, a, r, fptr);
	if (series == NULL)
		fprintf(fptr, "Validated: returned poitner is NULL\n");
	else
		fprintf(fptr, "Validation failed\n");
	fprintf(fptr, "\n");

	fprintf(fptr, "Case 2: Single Element Series:\n");
	n = 1;
	fprintf(fptr, "Geometric Series (n = %d, a = %d, r = %d):\n", n, a, r);
	series = geometric_series(n, a, r, fptr);
	fprintf(fptr, "series[first] = %d, series[last] = %d\n", series[0],
			series[0]);
	fprintf(fptr, "\n");
	free(series);
	series = NULL;

	fprintf(fptr, "Case 3: a = 1\n");
	n = 5;
	fprintf(fptr, "Geometric Series (n = %d, a = %d, r = %d):\n", n, a, r);
	series = geometric_series(n, a, r, fptr);
	fprintf(fptr, "series[first] = %d, series[last] = %d\n", series[0],
			series[4]);
	fprintf(fptr, "\n");
	free(series);
	series = NULL;

	fprintf(fptr, "Case 4: positive values of a and r\n");
	n = 8;
	a = 2;
	r = 3;
	fprintf(fptr, "Geometric Series (n = %d, a = %d, r = %d):\n", n, a, r);
	series = geometric_series(n, a, r, fptr);
	fprintf(fptr, "series[first] = %d, series[last] = %d\n", series[0],
			series[7]);
	fprintf(fptr, "\n");
	free(series);
	series = NULL;

	fprintf(fptr, "Case 5: a = 0\n");
	n = 4;
	a = 0;
	r = 6;
	fprintf(fptr, "Geometric Series (n = %d, a = %d, r = %d):\n", n, a, r);
	series = geometric_series(n, a, r, fptr);
	fprintf(fptr, "series[first] = %d, series[last] = %d\n", series[0],
			series[3]);
	fprintf(fptr, "\n");
	free(series);
	series = NULL;

	fprintf(fptr, "Case 6: negative value of a\n");
	n = 5;
	a = -5;
	r = 4;
	fprintf(fptr, "Geometric Series (n = %d, a = %d, r = %d):\n", n, a, r);
	series = geometric_series(n, a, r, fptr);
	fprintf(fptr, "series[first] = %d, series[last] = %d\n", series[0],
			series[4]);
	fprintf(fptr, "\n");
	free(series);
	series = NULL;

	fprintf(fptr, "Case 7: negative value of r\n");
	n = 5;
	a = 4;
	r = -2;
	fprintf(fptr, "Geometric Series (n = %d, a = %d, r = %d):\n", n, a, r);
	series = geometric_series(n, a, r, fptr);
	fprintf(fptr, "series[first] = %d, series[last] = %d\n", series[0],
			series[4]);
	fprintf(fptr, "\n");
	free(series);
	series = NULL;

	fprintf(fptr, "Case 8: r = 0\n");
	n = 8;
	a = 7;
	r = 0;
	fprintf(fptr, "Geometric Series (n = %d, a = %d, r = %d):\n", n, a, r);
	series = geometric_series(n, a, r, fptr);
	fprintf(fptr, "series[first] = %d, series[last] = %d\n", series[0],
			series[7]);
	fprintf(fptr, "\n");
	free(series);
	series = NULL;

	fprintf(fptr, "End: Testing geometric_series\n");
	fprintf(fptr, "------------------------------\n\n");
	fclose(fptr);
	return;
}

//------------------ Task 2: Pointers  -----------------------
void test_insert_item() {
	FILE *fptr = fopen("task2.txt", "w");
	if (!fptr) {
		printf("Error(test_insert_item): Could not open file task2.txt\n");
		return;
	}
	fprintf(fptr, "------------------------------\n");
	fprintf(fptr, "Start: Testing insert_item:\n\n");

	int size, *array, *maxPtr, value, i;

	fprintf(fptr, "------ Case 1:invalid i ----------\n");
	size = 5;
	array = (int*) malloc(sizeof(int) * size);
	int values[5] = { 1, 2, 3, 4, 5 };
	fprintf(fptr, "Before insertion: \n\t");
	initializeArray(array, values, size);
	printArray(array, size, fptr);
	maxPtr = &array[4];
	fprintf(fptr, "\tMaxPtr points at index: %ld\n", (maxPtr - array));
	fprintf(fptr, "\tMaxPtr value = %d\n", *maxPtr);
	value = 10;
	i = 6;
	fprintf(fptr, "Inserting value %d at position %d\n\t", value, i);
	insert_item(&array, size, i, value, &maxPtr, fptr);
	fprintf(fptr, "\t");
	printArray(array, size, fptr);
	fprintf(fptr, "\tMaxPtr points at index: %ld\n", (maxPtr - array));
	fprintf(fptr, "\tMaxPtr value = %d\n", *maxPtr);


	fprintf(fptr, "------ Case 2:regular insertion ----------\n");
	fprintf(fptr, "Before insertion: \n\t");
	printArray(array, size, fptr);
	maxPtr = &array[4];
	fprintf(fptr, "\tMaxPtr points at index: %ld\n", (maxPtr - array));
	fprintf(fptr, "\tMaxPtr value = %d\n", *maxPtr);
	value = 10;
	i = 2;
	fprintf(fptr, "Inserting value %d at position %d\n\t", value, i);
	insert_item(&array, size, i, value, &maxPtr, fptr);
	printArray(array, size + 1, fptr);
	fprintf(fptr, "\tMaxPtr points at index: %ld\n", (maxPtr - array));
	fprintf(fptr, "\tMaxPtr value = %d\n", *maxPtr);
	size++;

	fprintf(fptr, "------ Case 3:Inserting at beginning ----------\n");
	fprintf(fptr, "Before insertion: \n\t");
	printArray(array, size, fptr);
	fprintf(fptr, "\tMaxPtr points at index: %ld\n", (maxPtr - array));
	fprintf(fptr, "\tMaxPtr value = %d\n", *maxPtr);
	value = 20;
	i = 0;
	fprintf(fptr, "Inserting value %d at position %d\n\t", value, i);
	insert_item(&array, size, i, value, &maxPtr, fptr);
	printArray(array, size + 1, fptr);
	fprintf(fptr, "\tMaxPtr points at index: %ld\n", (maxPtr - array));
	fprintf(fptr, "\tMaxPtr value = %d\n", *maxPtr);
	size++;

	fprintf(fptr, "------ Case 4:Inserting at end ----------\n");
	fprintf(fptr, "Before insertion: \n\t");
	printArray(array, size, fptr);
	fprintf(fptr, "\tMaxPtr points at index: %ld\n", (maxPtr - array));
	fprintf(fptr, "\tMaxPtr value = %d\n", *maxPtr);
	value = 15;
	i = size;
	fprintf(fptr, "Inserting value %d at position %d\n\t", value, i);
	insert_item(&array, size, i, value, &maxPtr, fptr);
	printArray(array, size + 1, fptr);
	fprintf(fptr, "\tMaxPtr points at index: %ld\n", (maxPtr - array));
	fprintf(fptr, "\tMaxPtr value = %d\n", *maxPtr);
	size++;
	fprintf(fptr, "\n");

	fprintf(fptr, "End: Testing insert_item\n");
	fprintf(fptr, "------------------------------\n\n");
	fclose(fptr);
	return;
}

//----------------- Task 3: Strings ---------------------
void test_add_big_integers() {
	FILE *fptr = fopen("task3.txt", "w");
	if (!fptr) {
		printf("Error(test_add_big_integers): Could not open file task3.txt\n");
		return;
	}
	fprintf(fptr, "------------------------------\n");
	fprintf(fptr, "Start: Testing add_big_integers:\n\n");

	char num1[MAX * 10], num2[MAX * 10], result[MAX * 10];

	fprintf(fptr, "Case 0: Invalid (void) number:\n");
	strcpy(num1, "123");
	strcpy(num2, "");
	strcpy(result, "");
	add_big_integers(num1, num2, result, fptr);
	fprintf(fptr, "\n");

	fprintf(fptr, "Case 1: Invalid (mismatch size):\n");
	strcpy(num1, "123");
	strcpy(num2, "1234");
	strcpy(result, "");
	add_big_integers(num1, num2, result, fptr);
	fprintf(fptr, "\n");

	fprintf(fptr, "Case 2: Simple non-carry addition:\n");
	strcpy(num1, "1234");
	strcpy(num2, "5432");
	strcpy(result, "");
	add_big_integers(num1, num2, result, fptr);
	fprintf(fptr, " %s\n %s + \n------------------\n%s\n", num1, num2, result);
	fprintf(fptr, "\n");

	fprintf(fptr, "Case 3: Simple carry-over addition:\n");
	strcpy(num1, "19");
	strcpy(num2, "22");
	strcpy(result, "");
	add_big_integers(num1, num2, result, fptr);
	fprintf(fptr, " %s\n %s + \n---------------------\n%s\n", num1, num2,
			result);
	fprintf(fptr, "\n");

	fprintf(fptr, "Case 4: Simple extra digit addition:\n");
	strcpy(num1, "91");
	strcpy(num2, "22");
	strcpy(result, "");
	add_big_integers(num1, num2, result, fptr);
	fprintf(fptr, " %s\n %s + \n---------------------\n%s\n", num1, num2,
			result);
	fprintf(fptr, "\n");

	fprintf(fptr, "Case 5: Long Addition:\n");
	strcpy(num1, "102030405060708090");
	strcpy(num2, "111111111111111111");
	strcpy(result, "");
	add_big_integers(num1, num2, result, fptr);
	fprintf(fptr, " %s\n %s + \n---------------------\n%s\n", num1, num2,
			result);
	fprintf(fptr, "\n");

	fprintf(fptr, "End: Testing add_big_integers\n");
	fprintf(fptr, "------------------------------\n\n");
	fclose(fptr);
	return;
}

//----------------- Task 4: Files  ---------------------
void test_capitalize_words() {
	copy_file2("task4_input.txt", "task4.txt");

	FILE *fptr = fopen("task4.txt", "r+");
	if (!fptr) {
		printf("Error(test_capitalize_words): Could not open file task4.txt\n");
		return;
	}

	capitalize_words(fptr);

	fclose(fptr);
	return;
}

void wipe_files() {
	char filename[4][30] =
			{ "task1.txt", "task2.txt", "task3.txt", "task4.txt", };
	FILE *fptr = NULL;
	for (int i = 0; i < 4; i++) {
		fptr = fopen(filename[i], "w");
		if (fptr == NULL) {
			printf("Error(wipe_files): Could not open file %s\n", filename[i]);
			return;
		}
		fclose(fptr);
		fptr = NULL;
	}
	return;
}

void generate_my_output() {
	char out_file[] = "my_output.txt";
	FILE *destination = NULL;
	destination = fopen(out_file, "w");
	if (out_file == NULL) {
		printf("Error(generate_my_output): Could not open file %s\n", out_file);
		return;
	}

	char character, filename[4][30] = { "task1.txt", "task2.txt", "task3.txt",
			"task4.txt" };
	FILE *source = NULL;
	for (int i = 0; i < 4; i++) {
		source = fopen(filename[i], "r");
		if (source == NULL) {
			printf("Error(generate_my_output): Could not open file %s\n",
					filename[i]);
			fclose(destination);
			return;
		}
		character = fgetc(source);
		while (character != EOF) {
			fprintf(destination, "%c", character);
			character = fgetc(source);
		}
		fclose(source);
		source = NULL;
	}
	fclose(destination);
	return;
}

void printArray(int *array, const int size, FILE *destination) {
	int i;
	if (size < 0) {
		fprintf(destination, "Error (PrintArray): invalid array size\n");
		return;
	}

	if (size == 0)
		fprintf(destination, "[ ]\n");
	else {
		fprintf(destination, "[ ");
		for (i = 0; i < size - 1; i++)
			fprintf(destination, "%d , ", array[i]);
		fprintf(destination, "%d ]\n", array[i]);
	}
}

void initializeArray(int *array, const int valueArray[], int size) {
	int i;
	for (i = 0; i < size; i++)
		array[i] = valueArray[i];
	return;
}

void copy_file2(const char *in_file, const char *out_file) {
	FILE *source = NULL, *destination = NULL;
	source = fopen(in_file, "r");
	if (source == NULL) {
		printf("Error(copy_file2): Could not open file %s\n", in_file);
		return;
	}

	destination = fopen(out_file, "w");
	if (destination == NULL) {
		printf("Error (copy_file2): Could not open file %s\n", out_file);
		return;
	}

	char line[MAX];
	while (fgets(line, sizeof(line), source) != NULL)
		fprintf(destination, "%s", line);

	fclose(source);
	fclose(destination);
	return;
}

void validate_all() {
	char infile1[4][30] = { "task1.txt", "task2.txt", "task3.txt", "task4.txt" };
	char infile2[4][30] = { "task1_output.txt", "task2_output.txt",
			"task3_output.txt", "task4_output.txt" };
	int task = 1;
	for (int i = 0; i < 4; i++)
		validate(infile1[i], infile2[i], task++);
	return;
}
void validate(char *file1, char *file2, int task) {
	int counter = 1, mismatch = 0;
	char char1, char2;

	FILE *infile1 = fopen(file1, "r");
	FILE *infile2 = fopen(file2, "r");

	if (infile1 == NULL || infile2 == NULL) {
		printf("Error(file_match): Unable to open one of the files");
		return;
	}

	char1 = fgetc(infile1);
	while (char1 != EOF) {
		char2 = fgetc(infile2);
		if ((char2 != char1) || (char2 == EOF && char1 != EOF)) {
			mismatch = counter;
			break;
		}
		if (char1 == '\n')
			counter++;
		char1 = fgetc(infile1);
	}

	if (mismatch)
		printf("Task %d: Fail: mismatch at line %d in %s\n", task, mismatch,
				file1);
	else
		printf("Task %d: Pass: 100%% match\n", task);

	fclose(infile1);
	fclose(infile2);
	return;
}
