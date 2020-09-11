/*
-------------------------------------
Author:  Anshul Khatri
ID:      193313680
Email:   khat3680@mylaurier.ca
Version  2020-06-25
-------------------------------------
 */
#ifndef PROCESS_H_
#define PROCESS_H_

#define True 1
#define False 0

typedef struct{
	unsigned long PID; // porcess id (10-digits)
	unsigned int time; // requested processing time
	unsigned int arrival; //arrival time


}Process;


Process* create_process(long p_pid, int p_time, int arrival_time);
void destroy_process(Process **p);
void print_process(Process *p);
Process* copy_process(Process *p);
void get_process_info(Process *p, char *info);
int is_equal_process(Process *p1, Process *p2);
unsigned long get_UPID();

#endif /* PROCESS_H_ */
