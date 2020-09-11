
/**
 -------------------------
 Student Name: Anshul Khatri
 Student ID: 193313680
 Student email: khat3680@mylaurier.ca
 -------------------------
 **/
#include <stdio.h>
#include <stdlib.h>

void t2();
void t1();
void t3();

int main() {
	setbuf(stdout, NULL);
	t1();
	printf("\n");
	printf("\n");
	t2();
	printf("\n");
	printf("\n");
	t3();
	return 0;
}

void t1() {
	int tall;
	int short_trees;
	double total;
	double avg_height;
	char symbol = 84;
	const int val = 43;

	printf("Enter number of tall trees: ");
	scanf("%d", &tall);
	printf("Enter number of short trees: ");
	scanf("%d", &short_trees);
	total = tall + short_trees;
	avg_height = val/total;
	//printing report
	printf("Number of %c trees = %d\n", symbol, tall);
	printf("Number of %c trees = %d\n",(symbol-1),short_trees);
	printf("Average height = %.2lf", (avg_height));
	return ;
}

void t2(){
	unsigned int year;
	short month;
	int day;
	char university[30];

	printf("Enter year: ");
	scanf("%u",&year);
	printf("Enter month:");
	scanf("%hd",&month);
	printf("Enter day:");
	scanf("%d",&day);
	printf("Enter University:");
	scanf("%s",university);

	printf("This is %s University\n", university);
	printf("Today is : %d/%hd/%u\n",day,month,year);
	return;
}

void t3(){

	printf("Hints for C Language:\n");
	printf("Insert \\n at end of printf for newline.\n");
	printf("Use \"double quote\" not 'single quotes' for strings.\n");
	printf("Use %%d for integer, %%f for float and %%lf for double.\n");

	return;
}
