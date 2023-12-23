#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main_handlers/task_addition/adding_tasks.h"
#include "main_handlers/task_viewing/viewing_tasks.h"
#include "main_handlers/task_removal/removing_tasks.h"
#include "main_handlers/task_completion/completing_tasks.h"
#include "main_handlers/buffer_clean/buffer_cleaning.h"

int main()
{   
    int continue_work = 1;
    int action = 0;
    char **all_tasks = NULL;
    int num_tasks = 0;

    while(continue_work)
    {
        printf("What do you want to do?\n" \
        "1 - Add tasks\n" \
        "2 - View tasks\n" \
        "3 - Remove tasks\n" \
        "4 - Mark tasks as complete\n" \
        "5 - Exit\n\n");
        scanf("%d", &action);
        clear_input_buffer();

        if (action == 1)
        {
            update_task_list(&all_tasks, &num_tasks);
        }
        
        else if (action == 2)
        {
            task_view(&all_tasks, &num_tasks);
        }
        else if (action == 3)
        {
            task_remove(&all_tasks, &num_tasks);
        }
        else if (action == 4)
        {
            task_complete(&all_tasks, &num_tasks);
        }
        else if (action == 5)
        {
            continue_work = 0;
            if (all_tasks != NULL) 
            {
                for (int i = 0; i < num_tasks; i++) {
                    free(all_tasks[i]);
                }
                free(all_tasks);
            }
        }   
    }
    return 0;
}
