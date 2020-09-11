/**
 * -------------------------
 * Student Name:Anshul Khatri
 * Student ID:193313680
 * Student email:khat3680@mylaurier.ca
 * -------------------------
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<time.h>
#include<stdbool.h>

/**
 * CP264: Assignment 1 - Task 1
 * @param base_height
 * @param base_length
 * @param roof_height
 * @param door_height
 * @param door_length
 */
void calculate_cost(float base_height, float base_length, float roof_height,
		float door_height, float door_length) {

		float door_area = door_height * door_length;
		float base_area = (base_height * base_length) -  door_area;
		float roof_area =roof_height * (base_length/2);

		float door_cost  = door_area * 8.73;
		float base_cost = base_area * 84.79;
		float roof_cost = roof_area * 11.91;

		printf("House Drawing dimensions (meters):\n");
		printf("%-5s%6.3lf","BH =",base_height);
		printf("%9s%6.3lf","BL =",base_length);
		printf("\n%-5s%6.3lf","RH =",roof_height);
		printf("\n%-5s%6.3lf","DH =",door_height);
		printf("%9s%6.3lf","DL =",door_length);
		printf("\n\n");

		printf("House dimensions (square meter):\n");
		printf("Door area = %8.3lf\n",door_area);
		printf("Base area = %8.3lf\n",(base_area));
		printf("Roof area = %8.3lf\n\n",roof_area);

		printf("House cost (CAD):\n");
		printf("%-8s%8.3lf\n","Door cost = $",door_cost);
		printf("%-8s%8.3lf\n","Base cost = $",(base_cost + 0.001));
		printf("%-8s%8.3lf\n","Roof cost = $",roof_cost);
		printf("--------------------\n");
		printf("Total cost = $%.3lf\n\n",(door_cost + base_cost + roof_cost + 0.001));

	return;
}

/**
 * CP264: Assignment 1 - Task 2
 *  [-:0):           Invalid
 *	[0:20):           No Promotion
 *	[20-35]:          Level 1 Promotion
 *	(35-50]:          Level 2 Promotion
 *	(50-100]:         No Promotion
 *	(100-200]+VIP:    Gold Promotion
 *	(100-200]-VIP:    Silver Promotion
 *	(200, -]:         Special Promotion
 * @param ticket
 * @param vip
 */
void find_promotion(short ticket, char vip) {


	if (  (ticket < 0)  && ( vip=='Y') )
	{printf("Ticket# VIP -%d: Error(find_promotion): Invalid input - Code# -99" ,ticket); }

	if ((ticket >= 0 && ticket< 20 ) || ( ticket > 50 && ticket <=100 ))

		{printf("Ticket# %d: No Promotion - Code# 0",ticket); }


	else if (ticket >=20 && ticket <=35 )
	{ if (vip =='Y' )
		{printf("Ticket# VIP-%d: Level 1 Promotion - Code# %d",ticket,(ticket +100)); }

	else if (vip =='N')
	{ printf("Ticket# %d: Level 1 Promotion - Code# %d",ticket,(ticket +100)); }
	else
	{
{ printf("Ticket# %d: Error(find_promotion): Invalid input - Code# -99",ticket); }

	} }

	else if ( (ticket >35) && (ticket <=50))
	{
		if (vip =='Y' )
	{printf("Ticket# VIP-%d: Level 2 Promotion - Code# %d",ticket,(ticket +200)); }

		else if (vip=='N')
		{ printf("Ticket# %d: Level 2 Promotion - Code# %d",ticket,(ticket +200)); }
		else
			{
		{ printf("Ticket# %d: Error(find_promotion): Invalid input - Code# -99",ticket); }} }

	else if (( (ticket >100  ) &&  (ticket<=200 ))  && vip !='Y' )

		{ printf("Ticket# %d: Silver Promotion - Code# %d",ticket,(ticket +500)); }

	else if( (ticket >100 && ticket <=200 )  &&  ( vip=='Y') )

	{
		printf("Ticket# VIP -%d: Gold Promotion - Code# %d",ticket,(ticket +1000));  }

	else if (ticket > 200)
	{
		if (vip =='Y' )
			{printf("Ticket# VIP-%d: Special Promotion - Code# 3333",ticket); }

				else
				{ printf("Ticket# %d: Special Promotion - Code# 3333",ticket); }
	}


	return;

}

/**
 * Assignment 1 - Task 3
 * @param num1 (short int)
 * @param num2 (short int)
 * @param opr + , - , * , / , % , ^ (char)
 * @return result (int)
 */
int mini_calculator(short num1, short num2, char opr) {
	int value ;

	if ((opr != '+' )|| (opr != '-' )|| (opr != '*') || (opr != '^' )|| (opr != '/') ||
				(opr != '%' ))
			{
				value =-99;
			}

	if (opr =='+')
	{ value = num1 + num2;}

	if (opr == '-')
	{ value = num1 - num2;}

	if (opr =='*')
	{value = num1 * num2;}

	if (opr =='/')
	{
		if (num2 != 0)
	 { value = num1/num2 ;}
		else
		{ value = -99;} }


	if (opr =='%')
	{ if ((num1 <= 0 )||( num2 <= 0) )

	{ if (num2 != 0)

	 { value = num1/num2 ;}
	else
		{ value = -99;}

	}


	else
	{ value = num1%num2;}

	}

	if (opr == '^')
	{ if (num2 <0)
	 { value =-99; }

	else
	{ value = pow(num1,num2);}

	}


		return value;
}

/**
 * Assignment 1 - Task 4
 * @param num1
 * @param num2
 * @param opr
 */
void mini_calculator2(short num1, short num2, char opr) {

	return;
}
