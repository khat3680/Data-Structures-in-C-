/**
 * ---------------------------------
 * Student Name:Anshul Khatri
 * Student ID:193313680
 * Student Email:khat3680@mylaurier.ca
 * ---------------------------------
 */

/**
 * ---------------------------------
 *
 *“I certify that I completed this final exam according to academic honesty guidelines.
 *“I attest that I did not use any external help, neither in person nor virtually.
 *I understand that plagiarizing will lead to my failure in the course, in addition to other penalties according to the University policies”.
 *
 * ---------------------------------
 */

/**
 * ---------------------------------
 *
 * If you have any comments to the instructor
 * put it in this box
 *
 * ---------------------------------
 */

//---- Do not change imports -----------------
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <ctype.h>
# include <assert.h>

# include "data_structures.h"
# include "final.h"
//------------------------------------------------

//--------------------- Task 1 --------------------

// ZYBOOK USED
MData* create_mdata(void *item, char type) {


	if (item == NULL) {

		printf("Error(create_mdata): invalid pointer\n");
		return NULL;
	}

	if (type != 'i' && type != 'p') {

		printf("Error(create_data): invalid data type\n");
		return NULL;
	}
	MData *M_new = NULL;

	if (type == 'i') {

		M_new = (MData*) malloc(sizeof(int) + sizeof(char));
		int *dynamic_int = (int*) malloc(sizeof(int));
		*dynamic_int = *((int*) item);
		M_new->item = dynamic_int;
		M_new->type = 'i';

	}
	else if (type == 'p') {

		M_new = (MData*) malloc(sizeof(Process) + sizeof(char));
		Process *P = copy_process((Process*) item);
		M_new->item = P;
		M_new->type = 'p';
	}
	return M_new;
}

void destroy_mdata(MData **d) {
	assert(d!= NULL && *d != NULL);

	if ((*d)->type == 'p')
		destroy_process((Process**) &(*d)->item);

	else
		(*d)->item = 0;

	free(*d);
	*d = NULL;

	return;
}

void print_mdata(MData *d) {
	if (d == NULL) {
		printf("<NULL MData>\n");
		return;

	}
	if (d->type != 'i' && d->type != 'p') {

		printf("Error(print_mdata): unsupported data\n");
		return;
	}

	if (d->type == 'p') {
			printf("type = process, value = ");
			print_process((Process*) d->item);
			printf("\n");
		}

	if (d->type == 'i')
		printf("type = integer, value = %d\n", *((int*) d->item));

	return;
}

MData* copy_mdata(MData *d) {

	assert(d!= NULL);

	if (d->type != 'i' && d->type != 'p') {
		printf("Error(copy_mdata): unsupported data\n");
		return NULL;
	}

	if (d->type == 'i') {

		MData *copy_M = create_mdata(d->item, 'i');
		return copy_M;

	}
	else {

		MData *copy_M = create_mdata(copy_process(d->item), 'p');
		return copy_M;
	}

}

//------------------------ Task 2 -----------------------------
//A9 AND R8 USED
void schedule_SJFS(Queue *q) {
    Stack *s = create_stack(q->capacity);
    int i, j, size = len_queue(q), min_indx;
    Data *array = (Data*)malloc(sizeof(Data) * size);

    printf("Launching SJFS Scheduler:\n");
    printf("\n");

    printf("Received the following Queue:\n");
    print_queue(q);
    printf("\n");
    printf("Converting Queue to Stack:\n");
    for (i = 0; i < size; i++)
        array[i] = *remove_queue(q);

    //selection sort from R9, remember to cite!!
    for (i = 0; i < size - 1;i++){
        min_indx = i;
        for (j = i + 1; j< size; j++)
            if (compare_data(&array[j], &array[min_indx]) == 2)
                min_indx = j;
        swap_data(&array[min_indx], &array[i]);
    }

    for (i = size - 1; i >= 0; i--){
        push_stack(s, &array[i]);
    }
    print_stack(s);
    printf("\n");

    //From A8
    int timer = 0;
    printf("[Timer:0]: Starting SJFS Scheduler\n");
    timer++;
    Data *buffer[s->capacity];
    while (!is_empty_stack(s)) {
        int buffer_index = 0;
        int g = 0;
        if (peek_stack(s)->arrival > timer) {
            while (peek_stack(s)->arrival > timer) {
                printf("[Timer:%d]: idle\n", timer);
                timer++;
            }
        }
        while (g <= 3 && !is_empty_stack(s)) {
            if (peek_stack(s)->arrival <= timer){
                buffer[buffer_index] = pop_stack(s);
                buffer_index++;
            }
            g++;
        }
        int shortest_time = buffer[0]->time, shortest_index = 0;
        for (int i = 0; i < buffer_index; i++) {
            if (buffer[i]->time < shortest_time) {
                shortest_time = buffer[i]->time;
                shortest_index = i;
            }
            else if (buffer[i]->time == shortest_time && buffer[i]->arrival < buffer[shortest_index]->arrival){
                shortest_time = buffer[i]->time;
                shortest_index = i;
            }
        }
        printf("Fetching Process: ");
        print_data(buffer[shortest_index]);
        printf("\n");
        for (int i = 0; i < buffer[shortest_index]->time; i++) {
            printf("[Timer:%d]: ", timer);
            print_data(buffer[shortest_index]);
            printf("\n");
            timer++;
        }

        for (int i = 0; i < shortest_index; i++) {
            push_stack(s, buffer[i]);
            destroy_data(&buffer[i]);
        }
        for (int i = shortest_index + 1; i < buffer_index; i++) {
            push_stack(s, buffer[i]);
            destroy_data(&buffer[i]);
        }
        destroy_data(&buffer[shortest_index]);
    }
    printf("[Timer:%d]: Closing SJFS Scheduler\n", timer);

    return;
}


//----------------------------- Task 3 -----------------------------
Stack* slice_stack(Stack *s1, int index) {

	Stack *s2 = create_stack(s1->capacity);

	if (is_empty_stack(s1)) {

		printf("Error(slice_stack): cannot slice an empty stack\n");
	    return s2;
	}

	if (index < 0) {
	     printf("Error(slice_stack): invalid index\n");
	     return s2;
	 }

	int position = len_stack(s1);
	Stack *s_temp = create_stack(s1->capacity);


	while (position != index && position > 0) {
	       push_stack(s_temp, pop_stack(s1));
	       position--;
	        }

	while (!is_empty_stack(s_temp))
		push_stack(s2, pop_stack(s_temp));

	return s2;


}

//---------------------------- Task 4 -------------------------
// ZYBOOK USED
void shift_queue(Queue *q, int shifts, char direction) {

	if (is_empty_queue(q)) {
		printf("Error(shift_queue): Queue is empty\n");
		return;
	}

	if (shifts < 0) {
		printf("Error(shift_queue): Invalid shifts\n");
		return;
	}

	if (direction != 'R' && direction != 'L'){

		printf("Error(shift_queue): Invalid direction\n");
		return;
	}

	 if (direction == 'R') {
		int size = len_queue(q);
		for (int i = 0; i < size - shifts % size; i++)
			 insert_queue(q, remove_queue(q));

	    }

	 else {
		 for (int k = 0; k < shifts; k++)
		 	  insert_queue(q, remove_queue(q));
	    }

	return;
}

//-------------------- Task 5 -------------------------
int find_distnace(Graph *g, Vertex *v1, Vertex *v2) {
	assert(v1 != NULL && v2 != NULL);
	assert(g != NULL);

	int distance = 0;
	printf("Path from Vertex (%d) to Vertex (%d):\n",v1->num,v2->num);


	if (g->matrix[v1->num][v2->num] == 1)
	{		distance = 1;
	        printf("(%d)-->(%d)\n", v1->num, v2->num);
	        return distance;
	}
	else if (g->matrix[v1->num][v2->num - 1] == 1) {
			distance = 2;
	        printf("(%d)-->(%d)-->(%d)\n", v1->num, v2->num-1,v2->num);

	        return distance;

	}
	else if (g->matrix[v1->num][v2->num - 2] == 1 )
	{
		distance = 3;
		printf("(%d)-->(%d)-->(%d)-->(%d)\n", v1->num, v2->num-2,v2->num-1,v2->num);
		return distance;
	}
	if (distance == 0)
			printf("no path was found\n");


	return distance;
}

