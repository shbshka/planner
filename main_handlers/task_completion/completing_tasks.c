#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../buffer_clean/buffer_cleaning.h"
#include "completing_tasks.h"

void task_complete(char ***all_tasks, int *num_tasks)
{
    int continue_completion = 1;

    while(continue_completion)
    {
        if (*all_tasks != NULL && *num_tasks > 0)
        {
            int completed_task = -1;
            char complete_notice[] = " - completed";

            printf("Type the number of the task you want to complete:\n");
            for (int i = 0; i < *num_tasks; i++)
            {
                printf("%d. %s\n", i + 1, (*all_tasks)[i]);
            }
            putchar('\n');
            scanf("%d", &completed_task);
            clear_input_buffer();
            
            if (completed_task >= 1 && completed_task <= *num_tasks)
            {
                size_t new_size = strlen((*all_tasks)[completed_task - 1]) + strlen(complete_notice) + 1;
                char *temp = realloc((*all_tasks)[completed_task - 1], new_size);
                if (temp != NULL) 
                {
                    (*all_tasks)[completed_task - 1] = temp;
                    strcat((*all_tasks)[completed_task - 1], complete_notice);
                    printf("Task \"%s\" is marked as completed\n", (*all_tasks)[completed_task - 1]);
                }
                else
                {
                    printf("Failed to mark the task as completed");
                }
                
            }
            else
            {
                printf("Invalid task number\n");
            }
        }
        else
        {
            printf("You have no tasks now\n\n");
            continue_completion = 0;
            continue;
        }
        printf("Do you have any more completed tasks? 1 (yes) / 0 (no)\n");
        scanf("%d", &continue_completion);
        clear_input_buffer();

    }
}