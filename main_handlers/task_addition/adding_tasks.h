#ifndef ADDING_TASKS_H
#define ADDING_TASKS_H

char* add_task();
char** add_task_loop(char **existing_tasks, int *num_tasks);
void update_task_list(char ***all_tasks, int *num_tasks);

#endif // ADDING_TASKS_H
