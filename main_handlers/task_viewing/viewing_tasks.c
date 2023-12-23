#include <stdio.h>
#include <stdlib.h>
#include "main_handlers/task_viewing/viewing_tasks.h"


void task_view(char ***all_tasks, int *num_tasks)
{
    if (*all_tasks != NULL && *num_tasks > 0)
            {
                printf("\nYour tasks:\n");
                for (int i = 0; i < *num_tasks; i++)
                {
                    printf("%d. %s\n", i + 1, (*all_tasks)[i]);
                }
                putchar('\n');
            }
            else
            {
                printf("\nNo tasks available\n\n");
            }
}