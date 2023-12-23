#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../buffer_clean/buffer_cleaning.h"
#include "adding_tasks.h"

char* add_task()
{
    char buffer[256];
    printf("\nEnter a task for your planner: ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0';
        }
    

        char *task = malloc(strlen(buffer) + 1);
        if (task != NULL)
        {
            strcpy(task, buffer);
        }

        printf("You've added task \"%s\"\n", task);

        return task;
    }

    return NULL;
}


char **add_task_loop(char **existing_tasks, int *num_tasks)
{
    int capacity = *num_tasks + 10;
    char **all_tasks = realloc(existing_tasks, capacity * sizeof(char*));

    if (all_tasks == NULL)
    {
        perror("Failed to allocate memory for task list");
        return NULL;
    }

    int local_num_tasks = 0;
    int continue_adding = 1;

    while(continue_adding)
    {
        char *new_task = add_task();

        if (new_task != NULL)
        {
            if (*num_tasks + local_num_tasks >= capacity)
            {
                capacity *= 2;
                char **temp = realloc(all_tasks, capacity * sizeof(char*));
                if (temp == NULL)
                {
                    perror("Failed to resize task list");
                    free(new_task);
                    break;
                }
                all_tasks = temp;
            }
            all_tasks[*num_tasks + local_num_tasks] = new_task;
            local_num_tasks++;
            printf("Do you want to add more tasks? 1 (yes) / 0 (no)");
            scanf("%d", &continue_adding);
            clear_input_buffer();
        }
        else
        {
            continue_adding = 0;
        }
    }
    
    *num_tasks += local_num_tasks;
    return all_tasks;
}

void update_task_list(char ***all_tasks, int *num_tasks)
{
    char **new_tasks = add_task_loop(*all_tasks, num_tasks);

    if (new_tasks != NULL)
    {
        *all_tasks = new_tasks;
        printf("\nYour added tasks:\n");
        for (int i = 0; i < *num_tasks; i++)
        {
            printf("%d. %s\n", i + 1, (*all_tasks)[i]);
        }
        putchar('\n');
    }
}