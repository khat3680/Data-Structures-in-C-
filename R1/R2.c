/**
 * -------------------------
 * Student Name:Anshul Khatri
 * Student ID: 193313680
 * Student email:khat3680@mylaurier.ca
 * -------------------------
 */
#include<stdio.h>
#include<math.h>
#include<string.h>
/**
 * --------------------------------------------------------
 * Finds the factorial of a given number using recursion
 * The input is an integer and the return value is of type unsigned long
 * If the given input is less than 0, the function prints the following error msg:
 * 		Error(factorial): Invalid input
 * and returns 0
 * ----------------------------------------------------------
 */
unsigned long factorial(int n) {

			int result;

			if (n < 0) {
				printf("Error(factorial): Invalid input\n");
				result = 0;
			}
			else if ( n == 0 ) {
				result = 1; 	}

			else
			{
				result = n * (factorial(n-1));
			}

			return result;
}

/*
 * --------------------------------------------------------
 * Computes the value of a using the four integer input parameters: r,y,x and b.
 * The value of a is computed according to the following equation:
 *		a = floor((cube(3)-y)/x) - square_root(b to power 4))
 * The function prints the output in a format similar to the following
 *		[r = 2, y = 3, x = 2, b = 2] --> a = -2.0
 * The function also returns the value of a, which is of type double
 * ----------------------------------------------------------
 */
double solve(int r, int y, int x, int b) {
	double a;
	a = floor((pow(r,3) - y)  / (x) ) - sqrt(pow(b,4) );

	printf("[r = %d, y = %d, x = %d, b = %d] --> a = %.1lf\n",r,y,x,b,a);

	return a;
}

/**
 * --------------------------------------------------------
 * Checks if a given number is a whole number or not.
 * If the number is whole, e.g. 1.0 or 200.00, the function returns 0
 * If the number is not whole (double), the function returns 1.
 * Note that double here does not mean the data type double,
 * it simply means non-whole numbers.
 * ----------------------------------------------------------
 */
int is_double(double x) {
	int result;

	if ( x >= 0 ) {
		if (floor(x) == x){
			result = 0;
		}
		else {result = 1;}
	}
	else
	{ result = 1;}

	return result;
}

/**
 * --------------------------------------------------------
 * Checks if a given number is a fraction in the range (-1,1), excluding 0
 * Examples of fractions: 0.34, -0.69, 0.9999
 * Invalid fractions include -1, 1 ,2.3 ,1.4 ,0
 * If the given number is a fraction the function returns true
 * Otherwise, returns false
 * ----------------------------------------------------------
 */
int is_fraction(double x) {
	int result ;

	if ( x > -1 && x < 1 && x!=0) {
		result =1;
	}

	else {result = 0;}
	return result;
}

/**
 * --------------------------------------------------------
 * Finds the number of days in a given month
 * The function asks the user to enter a number, and the uses switch statement
 * to print one of the following outputs:
 * 		31 days
 * 		30 days
 * 		28/29 days
 * 		Invalid input
 * The function receives no parameters and makes no returns
 * ----------------------------------------------------------
 */
void get_month() {
    int month_;

    printf("Enter month number(1-12): ");

	scanf("%d", &month_);

	switch(month_)
	    {
	        /* Group all 31 days cases together */
	        case 1:
	        case 3:
	        case 5:
	        case 7:
	        case 8:
	        case 10:
	        case 12:
	            printf("31 days\n");
	            break;

	        /* Group all 30 days cases together */
	        case 4:
	        case 6:
	        case 9:
	        case 11:
	            printf("30 days\n");
	            break;

	        /* Remaining case */
	        case 2:
	            printf("28/29 days\n");
	            break;

	        default:
	            printf("Invalid input!\n");
	    }

	return;
}

/**
 * --------------------------------------------------------
 * Classify an input integer in terms of being even/odd and positive/negative
 * The function is implemented using the ternary operator
 * The function prints one of the following outputs:
 * 		This is an even positive number
 * 		This is an even negative number
 * 		This is an odd positive number
 * 		This is an odd negative number
 * The function does not provide a proper classification for the number 0
 * The function does not return any value.
 * ----------------------------------------------------------
 */
void classify_num1(int num) {
	char result[10],res2[10];
	char p[ ] = "positive",n[] ="negative";
	char e[] = "even" , o[] ="odd";

	(num > 0) ? strcpy(result,p) : strcpy(result,n) ;

	(num%2 == 0) ? strcpy(res2,e) : strcpy(res2,o) ;


	printf("This is an %s %s number\n",res2,result);

	return;
}

/**
 * --------------------------------------------------------
 * Classify an input integer in terms of being even/odd and positive/negative
 * The function is implemented using goto commands
 * The function prints one of the following outputs:
 * 		This is an even positive number
 * 		This is an even negative number
 * 		This is an odd positive number
 * 		This is an odd negative number
 * 		This is a zero!
 * The function does not return any value.
 * ----------------------------------------------------------
 */
void classify_num2(int num) {

	char result[10],res2[10];
	char p[ ] = "positive",n[] ="negative";
	char e[] = "even" , o[] ="odd";

if ( num ==0 ) {
	printf("This is a zero!\n");
}
else if (num > 0){

	strcpy(result,p);
	goto odd_even;

}
else{
	strcpy(result,n);

goto odd_even;

}


odd_even:
if ( num !=0 ) {
	if (num%2 == 0){

		strcpy(res2,e);

	}

	else
	{ strcpy(res2,o);}

printf("This is an %s %s number\n",res2,result); }

	return;
}