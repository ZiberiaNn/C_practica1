#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base_struct.h"

void getElementById(item_t items[], int index)
{   
    printf("%s", city_names[1]);
    printf("Element with ID: %d, city: %d, age: %d, gender: %d, income: %d, illness: %d \n", items[index - 1].id, items[index - 1].city, items[index - 1].age, items[index - 1].gender, items[index - 1].income, items[index - 1].illness);
}
