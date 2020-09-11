/*
 * ---------------------------------
 * Student Name: Anshul Khatri
 * Student ID: 193313680
 * Student Email:khat3680@mylaurier.ca
 * ---------------------------------
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>
# include "A8.h"

/*---------------------Task 1 -----------------------------*/
void schedule(char *type, Data *processes, const int size) {
	pQueue *q = create_pqueue(size*2, 'L');
	int period = 0;


	if((strcmp(type,"FIFO")==0) && processes != NULL)
	{	for (int i =0 ;i < size ;i++)
		 insert_pqueue2(q,&processes[i]);

		schedule_FIFO(q);

	}

	else if((strcmp(type,"SJF")==0) && processes != NULL)
	{
		for (int i =0 ;i < size ;i++)
			insert_pqueue2(q,&processes[i]);

		schedule_SJF(q);

	}

	else if( type[0] == 'R' && type[1] == 'R')
			{
		period = type[2] - '0';

		for (int i =0 ;i < size ;i++)
			insert_pqueue2(q,&processes[i]);

		schedule_RR(q,period);
			}
	else
		{
		printf("Error(schedule): Unsupported scheduler type\n");
		return;}

	return;
}

/*---------------------Task 2 -----------------------------*/
void schedule_FIFO(pQueue *q) {
		Data *process = peek_pqueue(q);
		int counter = 0;int timer = 0;

		while (!is_empty_pqueue(q))
		{
			process = peek_pqueue(q);
			if (counter < process->arrival)
			{	if (timer  == 0)
							printf("[Timer:%d]: Starting FIFO Scheduler\n",timer);
						else
							printf("[Timer:%d]: Idle\n",counter);
			counter +=1 ;
			timer +=1;
			}

			else {
					process = remove_pqueue2(q);
					if (!is_empty_pqueue(q))
					{	printf("Fetching Process: ");
								print_data(process);printf("\n");

					for(int i =0;i < process->time;i++) {

						printf("[Timer:%d]: ",counter);
						print_data(process);printf("\n");
						counter++;

					}
							}
			else {


				printf("Fetching Process: ");
				print_data(process);printf("\n");
				for (int i = 0;i < process->time; i++)
				{
					printf("[Timer:%d]: ",counter);
					print_data(process);printf("\n");
					counter++;
				}
			}
			}
		}
		printf("[Timer:%d]: Closing FIFO Scheduler\n",counter);

	return;
}


/*---------------------Task 3 -----------------------------void schedule_SJF(pQueue *q) {
    int i, timer = 0, index = 0;
    Data *data1 = NULL, *temp = NULL;
    pQueue *q2 = create_pqueue(50, 'L');
    printf("[Timer:0]: Starting SJF Scheduler\n");
    timer++;
    while (!is_empty_pqueue(q)) {
        data1 = peek_pqueue2(q);
        if (len_pqueue(q2) == 0) {
            while (timer < data1->arrival) {
                printf("[Timer:%d]: Idle\n", timer);
                timer++;
            }
        }
        while (data1->arrival <= timer) {
            data1 = remove_pqueue2(q);
            if (is_empty_pqueue(q2)) {
                q2->array[0] = *copy_data(data1);
                q2->front = 0;
                q2->rear = 0;
            } else {
                index = q2->rear + 1;
                for (i = q2->front; i < q2->rear + 1; i++) {
                    Data *curr = &q2->array[i];
                    if (curr->time > data1->time) {
                        index = i;
                        break;
                    }
                }
                for (i = q2->rear + 1; i > index; i--) {
                    q2->array[i] = q2->array[i - 1];
                }
                q2->array[index] = *copy_data(data1);
                q2->rear++;
            }
            data1 = peek_pqueue2(q);
        }
        temp = remove_pqueue2(q2);
        if (temp->time < 10) {
            printf("Fetching Process: ");
            print_data(temp);
            printf("\n");
            for (i = 0; i < temp->time; i++) {
                printf("[Timer:%d]: ", timer);
                print_data(temp);
                printf("\n");
                timer++;
            }
        }
    }
    printf("[Timer:%d]: Closing SJF Scheduler\n", timer);
    return;
}*/
void schedule_SJF(pQueue *q) {
	Data *process = peek_pqueue(q);
			int counter = 0;int timer = 0;

			while (!is_empty_pqueue(q))
			{
				process = peek_pqueue(q);
				if (counter < process->arrival)
				{	if (timer  == 0)
								printf("[Timer:%d]: Starting SJF Scheduler\n",timer);
							else
								printf("[Timer:%d]: Idle\n",counter);
				counter +=1 ;
				timer +=1;
				}

				else {
						process = remove_pqueue2(q);
						if (!is_empty_pqueue(q))
						{	printf("Fetching Process: ");
									print_data(process);printf("\n");

						for(int i =0;i < process->time;i++) {

							printf("[Timer:%d]: ",counter);
							print_data(process);printf("\n");
							counter++;

						}
								}
				else {


					printf("Fetching Process: ");
					print_data(process);printf("\n");
					for (int i = 0;i < process->time; i++)
					{
						printf("[Timer:%d]: ",counter);
						print_data(process);printf("\n");
						counter++;
					}
				}
				}
			}
			printf("[Timer:%d]: Closing SJF Scheduler\n",counter);


	return;
}

/*---------------------Task 4 -----------------------------*/
void schedule_RR(pQueue *q, int period) {
    int timer = 0;
    printf("[Timer:0]: Starting RR%d Scheduler\n",period);
    timer++;

    Data *tempy = NULL;

    while (!is_empty_pqueue(q)) {
        tempy = remove_pqueue2(q);

        if (tempy->arrival > timer) {
            while (tempy->arrival > timer) {

                printf("[Timer:%d]: Idle\n", timer);
                timer++;
            }
        }

        printf("Fetching Process: ");
        print_data(tempy);
        printf("\n");
        int temp = period;
        if (tempy->time < period)
            temp = tempy->time;


        for (int i = 0; i < temp; i++) {
            printf("[Timer:%d]: ", timer);
            print_data(tempy);
            printf("\n");
            timer++;
        }

        tempy->arrival = timer;
        int new_time = tempy->time - period;
        if (new_time > 0) {
            tempy->time = new_time;
            insert_pqueue2(q, tempy);
        }
    }

    printf("[Timer:%d]: Closing RR Scheduler\n", timer);
    return;
}
