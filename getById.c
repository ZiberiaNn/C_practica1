#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base_struct.h"

void getElementById(item_t items[], int size, int index)
{
    printf("Element with ID: %d, id: %d \n", index, items[index - 1].id);
}
