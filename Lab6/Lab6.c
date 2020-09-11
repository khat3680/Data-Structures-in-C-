/*
 * ---------------------------------
 * Student Name:Anshul Khatri
 * Student ID:193313680
 * Student Email:khat3680@mylaurier.ca
 * ---------------------------------
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void count_letters(const char *filename, int counters[26]);
void write_results(const char *filename, int counters[26]);
void append_sum(const char *filename, int counters[26]);

int main() {
	setbuf(stdout, NULL);

	char filename[20] = "text1.txt";
	int counters[26] = { 0 };

	count_letters(filename, counters);
	printf("");

	filename[4] = '2';
	write_results(filename, counters);

	append_sum(filename, counters);

	printf("Check text2.txt for output\n");

	return 0;
}

void count_letters(const char *filename, int counters[26]) {
	FILE* in_file = NULL;
	in_file = fopen(filename,"r");

	if (in_file == NULL) {
			printf("Error(count_letters): Could not open file %s\n",filename);
			return;
		}
	char ch;
	int index;


	while(!feof(in_file)) {

		ch = fgetc(in_file);
		ch = (int)ch;
		if(isalpha(ch))
		{
			if(islower(ch))
			{
				index = ch - 97;
			}
			else if(isupper(ch))
			{
				index = ch - 65;
			}

		counters[index]++;
		}
	}

	fclose(in_file);
	return;
}

void write_results(const char *filename, int counters[26]) {
	FILE* out_file = NULL;
		out_file = fopen(filename,"w");

		if (out_file == NULL) {
				printf("Error(write_results): Could not open file %s\n",filename);
				return;
			}
		char a= 'a';
		for(int i=0;i<26;i++)
			fprintf(out_file,"count(%c) = %d\n",(int)a++,counters[i]);

		fclose(out_file);

	return;

}

void append_sum(const char *filename, int counters[26]) {
	FILE* out_file = NULL;
			out_file = fopen(filename,"a");

			if (out_file == NULL) {
					printf("Error(write_results): Could not open file %s\n",filename);
					return;
				}
			int sum= 0;

			for(int i=0;i<26;i++)
				sum += counters[i];


			fprintf(out_file,"Total = %d",sum);
			fclose(out_file);
	return;
}

