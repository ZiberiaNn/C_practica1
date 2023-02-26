#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base_struct.h"

char * getElementById(item_t item)
{   
    //Inicializa un string vacío
    char *result;
    //Obtiene el numero de bytes que contendrá el string
    size_t nbytes = snprintf(NULL, 0, "Element with ID: %d, City: %s, Gender: %s, Age: %d, Income: %d, Illness: %s.\n", item.id, city_names[item.city], gender_names[item.gender], item.age, item.income, illness_values[item.illness]) + 1; /*  find out the size to use. +1 for the '\0' */
	//Asigna memoria igual al numero de bytes del string
    result = malloc(nbytes);
	//Escribe el string resultado, de tamaño nbytes, en el string result
    snprintf(result, nbytes, "Element with ID: %d, City: %s, Gender: %s, Age: %d, Income: %d, Illness: %s.\n", item.id, city_names[item.city], gender_names[item.gender], item.age, item.income, illness_values[item.illness]);
    //Devuelve el string result
    return result;
}
