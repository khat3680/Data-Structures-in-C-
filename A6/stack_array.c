/*
-------------------------------------
Author:  Anshul Khatri
ID:      193313680
Email:   khat3680@mylaurier.ca
Version  2020-06-25
-------------------------------------
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "stack_array.h"

Stack* create_stack(int stack_capacity){
	Stack *s = (Stack*)malloc(sizeof(Stack));
	if(stack_capacity < 1)
	{
		fprintf(stderr,"Error(create_stack): invalid capacity, set to 10\n");
		s->capacity = 10;	}
	else
		s->capacity = stack_capacity;

	s->array = (Data*)malloc(sizeof(Data)*(s->capacity));
	s->top = -1;
	return s;
}

void destroy_stack(Stack **s){
	assert(s != NULL);
	Data *data = NULL;

	while (!(is_empty_stack(*s))){
		data = pop_stack(*s);
		destroy_data(&data);

	}

	free((*s)->array);
	(*s)->array = NULL;
	(*s)->top = 0;
	(*s)->capacity = 0;
	free(*s);
	*s = NULL;

	return;

}
Data* pop_stack(Stack *s){
	assert(s != NULL);
	Data *d = NULL;

	if(is_empty_stack(s)){
		printf("Error(pop_stack): stack is empty\n");
		return d;
	}
	d = copy_data(&s->array[s->top]);
	Data* temp = &s->array[s->top];
	destroy_data(&temp);
	s->top--;
	return d;
}


int push_stack(Stack*s,Data* d){
	assert(s != NULL && d!= NULL);
	if(is_full_stack(s)){
		printf("Error(push_stack): stack is full\n");
		return False;
	}
	s->top++;
	s->array[s->top] = *copy_data(d);
	return True;
}
void print_stack(Stack *s){
	assert(s != NULL);
	printf("Stack Size = %d\n",len_stack(s));

	if(is_empty_stack(s))
		printf("<empty_stack>\n");

	for(int i = s->top;i>=0;i--)
	{
		print_data(&s->array[i]);
		printf("\n");
	}
}
Data* peek_stack(Stack *s){
	assert(s != NULL);
	if(is_empty_stack(s))	{
		printf("Error(peek_stack): stack is empty\n");
		return NULL;
	}
	return copy_data(&(s->array[s->top]));
}

int len_stack(Stack *s){
	assert(s!=NULL);
	return s->top +1;
}

int is_empty_stack(Stack *s){
	assert(s!=NULL);
	return(s->top == -1);

}
int is_full_stack(Stack *s){
	assert(s!=NULL);
	return (s->top == s->capacity - 1);
}
Stack* copy_stack(Stack *s){
	assert(s != NULL);
	Stack *s2 = create_stack(s->capacity);
	int i,size = len_stack(s);
	Data* array = (Data*)malloc(sizeof(Data)*size);

	for(i=0;i<size;i++)
		array[i] = *pop_stack(s);

	for(i=size-1 ;i>=0;i--){
		push_stack(s,&array[i]);
		push_stack(s2,&array[i]);

	}
	free(array);

	return  s2;
}
