#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base_struct.h"

char * getElementById(item_t items[], int index)
{   
    char *result;
    size_t nbytes = snprintf(NULL, 0, "Element with ID: %d, City: %s, Gender: %s, Age: %d, Income: %d, Illness: %s.\n", items[index - 1].id, city_names[items[index - 1].city], gender_names[items[index - 1].gender], items[index - 1].age, items[index - 1].income, illness_values[items[index - 1].illness]) + 1; /*  find out the size to use. +1 for the '\0' */
	result = malloc(nbytes);
	snprintf(result, nbytes, "Element with ID: %d, City: %s, Gender: %s, Age: %d, Income: %d, Illness: %s.\n", items[index - 1].id, city_names[items[index - 1].city], gender_names[items[index - 1].gender], items[index - 1].age, items[index - 1].income, illness_values[items[index - 1].illness]);
    return result;
}
