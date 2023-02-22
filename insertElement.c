#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "insertElement.h"
#include "base_struct.h"



char *insertElement(item_t items[], int size){
    item_t element = getElementFromInput(size);
	for(int i = size; i >= size/2; i--)
	{
        items[i] = items[i-1];
        items[i].id = items[i].id +1;
	}
    items[(size/2)-1]=element; 
    char *result;
    size_t nbytes = snprintf(NULL, 0, "Elemento insertado: ID: %d, City: %s, Gender: %s, Age: %d, Income: %d, Illness: %s.\n", items[(size/2)-1].id, city_names[items[(size/2)-1].city], gender_names[items[(size/2)-1].gender], items[(size/2)-1].age, items[(size/2)-1].income, illness_values[items[(size/2)-1].illness]) + 1; /*  find out the size to use. +1 for the '\0' */
	result = malloc(nbytes);
	snprintf(result, nbytes, "Elemento insertado: ID: %d, City: %s, Gender: %s, Age: %d, Income: %d, Illness: %s.\n", items[(size/2)-1].id, city_names[items[(size/2)-1].city], gender_names[items[(size/2)-1].gender], items[(size/2)-1].age, items[(size/2)-1].income, illness_values[items[(size/2)-1].illness]);
    return result;
}

item_t getElementFromInput(int size){
    item_t element;
    int age, income;
    char city[25], gender[8], illness[5];
    printf("===== PUNTO 5. Ingresar elemento a la mitad de los datos (id = 75000) =====\n");

    printf("Ingrese la ciudad entre las opciones: Dallas, New York City, Los Angeles, Mountain View, Boston, Washington D.C., San Diego, Austin.\n* ");
    scanf("%[^\n]s",city);

    printf("Ingrese el género entre las opciones: Male, Female.\n* ");
    scanf("%s",gender);

    printf("Ingrese la edad: \n* ");
    scanf("%d", &age);

    printf("Ingrese el valor de los ingresos: \n* ");
    scanf("%d", &income);

    printf("Ingrese si tiene una enfermedad: Yes, No.\n* ");
    scanf("%s", illness);

    element.id=(size/2);
    element.city=get_city_t(city);
    element.gender=get_gender_t(gender);
    element.age=age;
    element.income=income;
    element.illness=get_illness_t(illness);

    return element;
}