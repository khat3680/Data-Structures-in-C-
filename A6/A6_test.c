#include <stdio.h>
#include <stdlib.h>
#include "A6.h"

void test_remove_shortest();
void test_reverse_stack();
void test_contains_stack();
void test_resize_stack();
void test_concat_stack();

int main() {
	setbuf(stdout, NULL);
	test_remove_shortest();
	test_reverse_stack();
	test_contains_stack();
	test_resize_stack();
	test_concat_stack();
	return 0;
}
void test_remove_shortest() {
	printf("------------------------------\n");
	printf("Start: Testing remove_shortest:\n\n");

	Process *processes = NULL;
	processes = (Process*) malloc(sizeof(Process) * 6);
	processes[0] = (Process ) { 111111, 20, 5 };
	processes[1] = (Process ) { 222222, 10, 7 };
	processes[2] = (Process ) { 333333, 60, 7 };
	processes[3] = (Process ) { 444444, 20, 8 };
	processes[4] = (Process ) { 555555, 30, 9 };
	processes[5] = (Process ) { 666666, 30, 9 };

	printf("Printing Processes Before Any Remove:\n");
	int i;
	for (i = 0; i < 6; i++)
		printf("[%u](%lu,%u)\n", processes[i].arrival, processes[i].PID,
				processes[i].time);
	printf("\n");

	printf("Case 0: NULL pointer:\n");
	remove_shortest(NULL, 0);
	printf("\n");

	printf("Case 1: Invalid Size:\n");
	remove_shortest(processes, 0);
	printf("\n");

	printf("Case 2: First Remove (Simple):\n");
	remove_shortest(processes, 6);
	for (i = 0; i < 5; i++)
		printf("[%u](%lu,%u)\n", processes[i].arrival, processes[i].PID,
				processes[i].time);
	printf("\n");

	printf("Case 3: Second Remove (First Element):\n");
	remove_shortest(processes, 5);
	for (i = 0; i < 4; i++)
		printf("[%u](%lu,%u)\n", processes[i].arrival, processes[i].PID,
				processes[i].time);
	printf("\n");

	printf("Case 4: Third Remove (Last Element):\n");
	remove_shortest(processes, 4);
	for (i = 0; i < 3; i++)
		printf("[%u](%lu,%u)\n", processes[i].arrival, processes[i].PID,
				processes[i].time);
	printf("\n");

	printf("Case 5: Fourth Remove (Same arrival and time):\n");
	remove_shortest(processes, 3);
	for (i = 0; i < 2; i++)
		printf("[%u](%lu,%u)\n", processes[i].arrival, processes[i].PID,
				processes[i].time);
	printf("\n");

	printf("Case 6: Fifth Remove:\n");
	remove_shortest(processes, 2);
	printf("[%u](%lu,%u)\n", processes[0].arrival, processes[0].PID,
			processes[0].time);
	printf("\n");

	printf("Case 7: Last Remove:\n");
	remove_shortest(processes, 1);
	printf("[%u](%lu,%u)\n", processes[0].arrival, processes[0].PID,
			processes[0].time);
	printf("\n");

	printf("------------------------------\n");
	printf("End of Testing remove_shortest\n\n");
	return;
}

void test_reverse_stack() {
	printf("------------------------------\n");
	printf("Start: Testing reverse_stack:\n\n");

	int size = 10;
	printf("Reversing an empty Stack:\n");
	Stack *s = create_stack(size);
	printf("Stack before reverse:\n");
	print_stack(s);
	printf("Stack after reverse:\n");
	reverse_stack(s);
	print_stack(s);
	printf("\n");

	printf("Reversing a stack of 10 random processes:\n");
	int i, pid = 1000010000, time = 10, arrival = 1;
	for (i = 0; i < size; i++)
		push_stack(s, create_process(pid++, time++, arrival++));

	printf("Printing Stack before reverse:\n");
	print_stack(s);
	printf("Stack after reverse:\n");
	reverse_stack(s);
	print_stack(s);
	printf("\n");
	destroy_stack(&s);

	printf("------------------------------\n");
	printf("End of Testing reverse_stack\n\n");
	return;

}

void test_contains_stack() {
	printf("------------------------------\n");
	printf("Start: Testing contains_stack:\n\n");

	Stack *s = create_stack(11);
	Data *processes[10];
	long pid = 1000020000;
	int time = 10, arrival = 1;
	for (int i = 0; i < 10; i++) {
		processes[i] = create_process(pid++, time++, arrival++);
		push_stack(s, processes[i]);
	}
	Data *d2 = copy_data(processes[4]);
	push_stack(s, d2);
	printf("Contents of s = \n");
	print_stack(s);
	printf("\n");

	printf("Contains ");
	print_data(processes[1]);
	printf("? = %d\n", contains_stack(s, processes[1]));

	printf("Contains ");
	print_data(processes[6]);
	printf("? = %d\n", contains_stack(s, processes[6]));

	printf("Contains ");
	processes[5]->arrival = 300;
	print_data(processes[5]);
	printf("? = %d\n", contains_stack(s, processes[5]));

	printf("Contains ");
	processes[3]->time = 57;
	print_data(processes[3]);
	printf("? = %d\n", contains_stack(s, processes[3]));
	printf("\n");

	printf("Empty Stack:\n");
	contains_stack(NULL, processes[3]);
	printf("\n");

	printf("Invalid data:\n");
	contains_stack(s, NULL);
	printf("\n");
	printf("------------------------------\n");
	printf("End of Testing contains_stack\n\n");
	return;
}

void test_resize_stack() {
	printf("------------------------------\n");
	printf("Start: Testing resize_stack:\n\n");

	printf("Creating a stack with 10 elements\n");
	Stack *s = create_stack(10);
	int i, time = 10, arrival = 1;
	unsigned long pid = 1000010000;
	for (i = 0; i < 10; i++)
		push_stack(s, create_process(pid++, time++, arrival++));
	printf("Capacity = %d, ", s->capacity);
	print_stack(s);
	printf("\n");

	printf("Resize to 5:\n");
	resize_stack(s, 5);
	printf("Capacity = %d, ", s->capacity);
	print_stack(s);
	printf("\n");

	printf("Resize to 9:\n");
	resize_stack(s, 9);
	printf("Capacity = %d, ", s->capacity);
	print_stack(s);
	printf("\n");

	printf("Resize to 6:\n");
	resize_stack(s, 6);
	printf("Capacity = %d, ", s->capacity);
	print_stack(s);
	printf("\n");

	printf("Resize to 3:\n");
	resize_stack(s, 3);
	printf("Capacity = %d, ", s->capacity);
	print_stack(s);
	printf("\n");

	printf("Resize to 0:\n");
	resize_stack(s, 0);
	printf("Capacity = %d, ", s->capacity);
	print_stack(s);
	printf("\n");

	printf("Destroy stack\n");
	destroy_stack(&s);

	printf("------------------------------\n");
	printf("End of Testing resize_stack\n\n");
	return;
}

void test_concat_stack() {
	printf("------------------------------\n");
	printf("Start: Testing concat_stack:\n\n");

	int time = 10, arrival = 1;
	unsigned long pid = 1000010000;

	printf("Case 0: Two Empty Stacks:\n");
	Stack *s1 = create_stack(3);
	Stack *s2 = create_stack(2);
	printf("Stacks Before Concatenation:\n");
	printf("Stack 1: Capacity = %d, ", s1->capacity);
	print_stack(s1);
	printf("Stack 2: Capacity = %d, ", s2->capacity);
	print_stack(s2);
	printf("\n");
	Stack *s3 = concat_stack(s1, s2);
	printf("Stacks After Concatenation:\n");
	printf("Stack 3: Capacity = %d, ", s3->capacity);
	print_stack(s3);
	printf("Stack 1: Capacity = %d, ", s1->capacity);
	print_stack(s1);
	printf("Stack 2: Capacity = %d, ", s2->capacity);
	print_stack(s2);
	printf("\n\n");

	printf("Case 1: Non-empty to empty stack:\n");
	push_stack(s2, create_process(pid++, time++, arrival++));
	push_stack(s2, create_process(pid++, time++, arrival++));
	printf("Stacks Before Concatenation:\n");
	printf("Stack 1: Capacity = %d, ", s1->capacity);
	print_stack(s1);
	printf("Stack 2: Capacity = %d, ", s2->capacity);
	print_stack(s2);
	printf("\n");
	Stack *s4 = concat_stack(s1, s2);
	printf("Stacks After Concatenation:\n");
	printf("Stack 4: Capacity = %d, ", s4->capacity);
	print_stack(s4);
	printf("Stack 1: Capacity = %d, ", s1->capacity);
	print_stack(s1);
	printf("Stack 2: Capacity = %d, ", s2->capacity);
	print_stack(s2);
	printf("\n\n");

	printf("Case 2: Two non-empty stacks:\n");
	push_stack(s1, create_process(pid++, time++, arrival++));
	push_stack(s1, create_process(pid++, time++, arrival++));
	push_stack(s1, create_process(pid++, time++, arrival++));

	printf("Stacks Before Concatenation:\n");
	printf("Stack 1: Capacity = %d, ", s1->capacity);
	print_stack(s1);
	printf("Stack 2: Capacity = %d, ", s2->capacity);
	print_stack(s2);
	printf("\n");
	Stack *s5 = concat_stack(s1, s2);
	printf("Stacks After Concatenation:\n");
	printf("Stack 5: Capacity = %d, ", s5->capacity);
	print_stack(s5);
	printf("Stack 1: Capacity = %d, ", s1->capacity);
	print_stack(s1);
	printf("Stack 2: Capacity = %d, ", s2->capacity);
	print_stack(s2);
	printf("\n\n");

	printf("Destroy stack 1\n");
	destroy_stack(&s1);
	printf("Destroy stack 2\n");
	destroy_stack(&s2);
	printf("Destroy stack 3\n");
	destroy_stack(&s3);
	printf("Destroy stack 4\n");
	destroy_stack(&s4);
	printf("Destroy stack 5\n");
	destroy_stack(&s5);
	printf("\n");

	printf("------------------------------\n");
	printf("End of Testing concat_stack\n\n");

	return;
}

