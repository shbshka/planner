#include <stdio.h>
#include <stdlib.h>
#include "main_handlers/buffer_clean/buffer_cleaning.h"
#include "main_handlers/task_removal/removing_tasks.h"

void task_remove(char ***all_tasks, int *num_tasks)
{
    int continue_removal = 1;

    while(continue_removal)
    {
        if (all_tasks != NULL && *num_tasks > 0)
        {
            int removed_task = -1;

            printf("Type the number of the task you want to remove:\n");
            for (int i = 0; i < *num_tasks; i++)
            {
                printf("%d. %s\n", i + 1, *all_tasks[i]);
            }
            putchar('\n');

            scanf("%d", &removed_task);
            clear_input_buffer();

            if (removed_task >= 1 && removed_task <= *num_tasks)
            {
                free(*all_tasks[removed_task - 1]);
                for (int i = removed_task; i < *num_tasks; i++)
                {
                    *all_tasks[i - 1] = *all_tasks[i];
                }
                num_tasks--;
                printf("Successfully removed the task from your task list\n");
            }
            else
            {
                printf("Invalid task number\n");
            }
        }
        else
        {
            printf("\nYou have no tasks now\n\n");
            continue_removal = 0;
            continue;
        }
        printf("Do you want to remove more tasks? 1 (yes) / 0 (no)");
        scanf("%d", &continue_removal);
        clear_input_buffer();
    }
}