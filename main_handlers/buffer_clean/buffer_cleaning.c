#include <stdlib.h>
#include <stdio.h>
#include "main_handlers/buffer_clean/buffer_cleaning.h"


void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {

    }
}